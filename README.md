# Conway's Game of Life in C

![Language](https://img.shields.io/badge/language-C-blue?style=for-the-badge&logo=c)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/status-Active-success?style=for-the-badge)

> A lightweight, efficient implementation of John Conway's famous cellular automaton, written in C.

## 🧬 About The Project

This project simulates **Conway's Game of Life**, a zero-player game that mimics the evolution of life based on a simple set of deterministic rules.

I developed this simulation to explore:
* **Cellular Automata:** How complex biological patterns emerge from simple rules.
* **C Programming:** Efficient memory usage and logic implementation.
* **Algorithmic Logic:** Iterating through grid generations and neighbor checking.

## 🚀 Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites
You need a C compiler (GCC or Clang) installed on your system.

### Installation & Compilation

1.  **Clone the repository**
    ```bash
    git clone https://github.com/Kr1sshna/Game_of_life.git
    ```

2.  **Navigate to the project directory**
    ```bash
    cd Game_of_life
    ```

3.  **Compile the code**
    ```bash
    gcc Game_of_life.c -o game
    ```

## 🕹️ Usage

Run the compiled executable from your terminal:

```bash
./game
```

## The Rules of Life
The universe of the Game of Life is a grid of cells. Every cell interacts with its eight neighbors based on these four rules:

1. **Underpopulation: A live cell with fewer than 2 live neighbors dies.**

2. **Survival: A live cell with 2 or 3 live neighbors lives on to the next generation.**

3. **Overpopulation: A live cell with more than 3 live neighbors dies.**

4. **Reproduction: A dead cell with exactly 3 live neighbors becomes a live cell.**

## 🔮 Future Improvements

1. Implement a GUI (using SDL2 or Raylib) for better visualization.

2. Add functionality to load custom patterns from a text file.

3. Optimize for infinite grid handling.

4.  Add raw key controls

## 🤝 Contributing
Contributions are welcome! If you have ideas for optimizing the logic or adding new features, feel free to fork the repository and submit a pull request.

## 📜 License
Distributed under the MIT License. See LICENSE for more information.

## 👤 Author

Krishna
    GitHub: @Kr1sshna
