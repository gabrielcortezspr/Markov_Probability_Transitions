# Markov Chain Simulations

This project contains three different C/C++ programs that simulate transitions between states using Markov Chains and pseudo-random number generation.

## 1. first_code.c (Markov Chain Elemental Transitions)
This program simulates transitions between different elements based on their nurturing and destructive relationships, inspired by the classical elements like Fire, Earth, Water, etc. The transition is guided by a Multiplicative Linear Congruential Generator (MLCG) to make random choices.

### Key Concepts:
- Simulates how elements like Fire, Water, Earth interact by nurturing or destroying each other.
- Uses MLCG to randomly decide between nurturing or destructive actions.

## 2. second_code.c (Markov Chain Luck Simulation)
This program models the transition between different states of luck (from bad luck to good luck) using a transition matrix and MLCG for randomness. Each state has a probability of transitioning to another, controlled by a predefined probability matrix.

### Key Concepts:
- Luck is divided into five states: "Very Unlucky", "Unlucky", "Neutral", "Lucky", and "Very Lucky".
- Uses a transition matrix to determine the probability of moving from one state to another.
- MLCG generates random numbers to simulate transitions.

## 3. third_code.cpp (Primary and Complementary Color Transitions)
This C++ program simulates color transitions based on primary and complementary colors using Markov Chains. The transitions are governed by a MLCG, which decides if the next color will be complementary or another random primary color.

### Key Concepts:
- Handles color transitions between primary colors (Red, Yellow, Blue) and their complementary colors (Green, Purple, Orange).
- 70% chance of transitioning to a complementary color and 30% chance of moving to a different primary color.
- If already in a complementary color, there's a 70% chance of returning to the primary color.

## Project Structure
- first_code.c: Markov Chain simulation for element transitions.
- second_code.c: Markov Chain simulation for luck transitions.
- third_code.cpp: Markov Chain simulation for color transitions.
- README.md: Project overview and instructions.
