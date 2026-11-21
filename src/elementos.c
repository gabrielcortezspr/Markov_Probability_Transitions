#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MODULUS 549755813881ULL
#define MULTIPLIER 10014146ULL

uint64_t state = 123456789;

uint32_t mlcg_random() {
    state = (MULTIPLIER * state) % MODULUS;
    return (uint32_t)(state & 0xFFFFFFFF);
}

typedef struct {
    const char* name;
    const char* nurtures;
    const char* destroys;
} Element;

int main() {
    Element elements[] = {
        {"Madeira", "Fogo", "Terra"},
        {"Fogo", "Terra", "Metal"},
        {"Terra", "Metal", "Água"},
        {"Metal", "Água", "Madeira"},
        {"Água", "Madeira", "Fogo"}
    };
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    int current_index = mlcg_random() % num_elements;
    Element current_element = elements[current_index];

    printf("Elemento inicial: %s\n", current_element.name);
    for (int step = 0; step < 10; step++) {
        printf("Passo %d: %s\n", step + 1, current_element.name);

        int transition_choice = mlcg_random() % 2;
        if (transition_choice == 0) {
            printf("  Nutrindo: %s\n", current_element.nurtures);
            for (int i = 0; i < num_elements; i++) {
                if (strcmp(elements[i].name, current_element.nurtures) == 0) {
                    current_element = elements[i];
                    break;
                }
            }
        } else {
            printf("  Destruindo: %s\n", current_element.destroys);
            for (int i = 0; i < num_elements; i++) {
                if (strcmp(elements[i].name, current_element.destroys) == 0) {
                    current_element = elements[i];
                    break;
                }
            }
        }
    }

    return 0;
}
