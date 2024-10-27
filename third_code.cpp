#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Multiplicative Linear Congruential Generator (MLCG)
struct MLCG {
    uint64_t state;
    const uint64_t multiplier;

    MLCG(uint64_t seed, uint64_t multiplier) : state(seed), multiplier(multiplier) {
        if (state == 0)
            cerr << "Error: Seed value cannot be zero." << endl;
    }

    uint64_t next() {
        state *= multiplier;
        return state;
    }

    uint32_t high32() const {
        return static_cast<uint32_t>(state >> 32);
    }
};

struct Color {
    float r, g, b;
};

// Função para gerar a cor complementar
Color get_opposite_color(const Color& color) {
    if (color.r == 255 && color.g == 0 && color.b == 0) return {0, 255, 0};    // Vermelho -> Verde
    if (color.r == 255 && color.g == 255 && color.b == 0) return {128, 0, 128}; // Amarelo -> Roxo
    if (color.r == 0 && color.g == 0 && color.b == 255) return {255, 165, 0};   // Azul -> Laranja
    if (color.r == 0 && color.g == 255 && color.b == 0) return {255, 0, 0};     // Verde -> Vermelho
    if (color.r == 128 && color.g == 0 && color.b == 128) return {255, 255, 0}; // Roxo -> Amarelo
    if (color.r == 255 && color.g == 165 && color.b == 0) return {0, 0, 255};   // Laranja -> Azul
    return color; // Caso padrão (não deve acontecer)
}

int main() {
    const uint64_t seed = 4768777513237032717; // Semente para MLCG
    const uint64_t multiplier = 5813247752730957461; // Multiplicador para MLCG
    MLCG generator(seed, multiplier); // Inicializa o gerador MLCG

    // Cores principais (normais)
    Color colors[] = {
        {255, 0, 0},       // Vermelho
        {255, 255, 0},     // Amarelo
        {0, 0, 255}        // Azul
    };

    // Simular uma iteração de transição de cores
    Color current_color = colors[0]; // Começar com vermelho
    for (int step = 0; step < 10; ++step) { // Número de passos
        Color opposite_color = get_opposite_color(current_color);
        float rand_value = static_cast<float>(generator.next()) / UINT32_MAX; // Valor aleatório entre 0 e 1

        Color new_color;
        if (rand_value < 0.7) { // 70% chance de ir para a cor complementar
            new_color = opposite_color;
        } else { // 30% chance de ir para outra cor normal
            int random_index;
            do {
                random_index = generator.next() % 3; // Escolhe aleatoriamente entre 0 e 2
            } while (colors[random_index].r == current_color.r && colors[random_index].g == current_color.g && colors[random_index].b == current_color.b);
            new_color = colors[random_index];
        }

        // Se a nova cor for complementar, decidir se volta ou vai para outra complementar
        if (new_color.r != current_color.r || new_color.g != current_color.g || new_color.b != current_color.b) {
            rand_value = static_cast<float>(generator.next()) / UINT32_MAX; // Novo valor aleatório
            if (new_color.r == opposite_color.r && new_color.g == opposite_color.g && new_color.b == opposite_color.b) {
                // 70% chance de voltar à cor normal
                if (rand_value < 0.7) {
                    new_color = current_color; // Voltar para a cor normal
                } else {
                    // 30% chance de ir para outra cor complementar
                    do {
                        int random_index = generator.next() % 3; // Escolhe aleatoriamente entre 0 e 2
                        new_color = get_opposite_color(colors[random_index]); // Vai para a complementar
                    } while (new_color.r == opposite_color.r && new_color.g == opposite_color.g && new_color.b == opposite_color.b);
                }
            }
        }

        // Exibir resultado
        std::cout << "Cor atual: (" << current_color.r << ", " << current_color.g << ", " << current_color.b << ") ";
        std::cout << "Nova cor: (" << new_color.r << ", " << new_color.g << ", " << new_color.b << ")\n";

        // Atualizar a cor atual
        current_color = new_color;
    }

    return 0;
}
