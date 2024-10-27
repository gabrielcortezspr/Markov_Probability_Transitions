# Markov Chain Probability Transition Simulation

This repository contains three different C/C++ programs, each demonstrating different implementations of probability-based transitions using Markov Chains. The primary focus is on simulating random events and color transitions based on probabilistic rules.

## Content
- **first_code.c**: A program that simulates states of luck using a Markov Chain transition matrix.
- **second_code.c**: Another simulation using Markov Chains, incorporating randomness with a Multiplicative Linear Congruential Generator (MLCG) to simulate states of fortune.
- **third_code.cpp**: A program that transitions between primary and complementary colors based on probabilities using a custom MLCG.

### Markov Chains in Programming
Markov Chains are mathematical systems that undergo transitions from one state to another, with each state depending only on the previous state and a set of probabilities. In programming, Markov Chains are used to model randomness, simulations, and even AI algorithms.

### Explanation of the Codes:

#### 1. **first_code.c**
This program defines five possible states:
- **MUITO AZAR (Very Unlucky)**
- **AZAR (Unlucky)**
- **NEUTRO (Neutral)**
- **SORTE (Lucky)**
- **MUITA SORTE (Very Lucky)**

The program uses a predefined probability transition matrix, where each state has specific chances of transitioning to another state. A basic random number generator from the C standard library (`rand()`) is used to decide the next state based on these probabilities.

#### 2. **second_code.c**
In this code, a **Multiplicative Linear Congruential Generator (MLCG)** is introduced, which generates random numbers to decide the transitions between the states of fortune. The MLCG allows for better control over randomness and avoids some limitations of the `rand()` function. The code runs a series of steps where the next state is calculated using the MLCG and the predefined transition matrix.

#### 3. **third_code.cpp**
This program demonstrates color transitions using a probabilistic model. Primary colors (Red, Blue, Yellow) transition to their complementary colors with a 70% chance and to other primary colors with a 30% chance. It uses a custom MLCG for generating random values to drive the transitions. The program highlights how Markov Chains can be applied to systems outside of basic state transitions, like color shifts.

### How to Run
Each file can be compiled and run using GCC (for C files) or G++ (for the C++ file).

For `first_code.c`:
```bash
gcc first_code.c -o first_code
./first_code
