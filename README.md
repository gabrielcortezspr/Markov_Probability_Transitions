# Markov Chain Simulations

![C](https://img.shields.io/badge/C-99-A8B9CC?logo=c&logoColor=black)
![C++](https://img.shields.io/badge/C%2B%2B-11-00599C?logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green)

Three small C/C++ programs that simulate state transitions with Markov chains, driven by a
hand-written **Multiplicative Linear Congruential Generator (MLCG)** instead of the standard
library's `rand()`.

| Program | States | Transition rule |
|---|---|---|
| [`src/elementos.c`](src/elementos.c) | The five Wu Xing elements (wood, fire, earth, metal, water) | Each step the MLCG picks between the element it *nurtures* and the one it *destroys* |
| [`src/sorte.c`](src/sorte.c) | Five luck levels, from "very unlucky" to "very lucky" | 5×5 transition matrix; the MLCG output is sampled against each row's cumulative probabilities |
| [`src/cores.cpp`](src/cores.cpp) | Primary colors and their complements | 70% chance to jump to the complement, 30% to another primary; from a complement, 70% back to its primary |

## Build and run

```sh
gcc -Wall -o elementos src/elementos.c && ./elementos
gcc -Wall -o sorte     src/sorte.c     && ./sorte
g++ -Wall -o cores     src/cores.cpp   && ./cores
```

Each program prints the sequence of visited states (output in Portuguese), e.g. `sorte`:

```
Passo 1: NEUTRO
Passo 2: SORTE
Passo 3: SORTE
Passo 4: SORTE
Passo 5: AZAR
```

## License

[MIT](LICENSE)
