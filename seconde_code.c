
### 2. Arquivos de Código:

#### Arquivo `first_code.c`
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STATES 5

typedef enum {
    MUITO_AZAR,
    AZAR,
    NEUTRO,
    SORTE,
    MUITA_SORTE
} State;

float transition_matrix[NUM_STATES][NUM_STATES] = {
    {0.50, 0.30, 0.10, 0.05, 0.05}, 
    {0.20, 0.50, 0.20, 0.05, 0.05}, 
    {0.20, 0.20, 0.20, 0.20, 0.20}, 
    {0.05, 0.05, 0.20, 0.50, 0.20}, 
    {0.05, 0.05, 0.10, 0.30, 0.50}  
};

unsigned long long mlcg(unsigned long long seed, unsigned long long a, unsigned long long m) {
    return (seed * a) % m;
}

State next_state(State current_state, unsigned long long *seed, unsigned long long a, unsigned long long m) {
    *seed = mlcg(*seed, a, m);
    float rand_value = (float)(*seed % 1000000) / 1000000.0; 
    float cumulative_probability = 0.0;

    for (int i = 0; i < NUM_STATES; i++) {
        cumulative_probability += transition_matrix[current_state][i];
        if (rand_value < cumulative_probability) {
            return (State)i;
        }
    }
    return current_state;
}

const char* state_to_string(State state) {
    switch (state) {
        case MUITO_AZAR: return "MUITO AZAR";
        case AZAR: return "AZAR";
        case NEUTRO: return "NEUTRO";
        case SORTE: return "SORTE";
        case MUITA_SORTE: return "MUITA SORTE";
        default: return "UNKNOWN";
    }
}

int main() {
    unsigned long long seed = time(NULL); 
    unsigned long long a = 25708129; 
    unsigned long long m = 549755813881; 

    State current_state = NEUTRO;

    for (int i = 0; i < 20; i++) { 
        printf("Passo %d: %s\n", i + 1, state_to_string(current_state));
        current_state = next_state(current_state, &seed, a, m);
    }

    return 0;
}
