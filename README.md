# Tetris Game - README

## Introduction
Welcome to the Tetris game built using C++ and the SFML library! This classic puzzle game has been implemented with all the fundamental features you love. Move and rotate the falling tetrominoes to create complete lines, which will disappear to earn you points. The game will get progressively faster as you play, so try to keep up and set a high score!

## Features
- **Smooth Gameplay:** Experience fluid movement and rotation of tetrominoes.
- **Simple Controls:** Easy-to-use controls with arrow keys and spacebar.
- **Classic Design:** A faithful recreation of the original Tetris experience.
- **Scoring System:** Earn points for every line you complete.
- **Increasing Difficulty:** The speed increases as you clear more lines.

## Requirements
To run this game, you need:
- A C++ compiler (supporting C++11 or later)
- SFML library installed (version 2.5 or later)

## Installation
1. **Clone the repository** to your local machine:
    ```
    git clone https://github.com/yourusername/tetris-game.git
    ```
2. **Navigate** to the directory:
    ```
    cd tetris-game
    ```
3. **Compile** the game using your C++ compiler:
    ```
    g++ -std=c++11 -o tetris main.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```
    Make sure to adjust the include paths and linker flags according to your SFML installation.

4. **Run** the game:
    ```
    ./tetris
    ```

## Controls
- **Left Arrow:** Move tetromino left
- **Right Arrow:** Move tetromino right
- **Up Arrow:** Rotate tetromino
- **Down Arrow:** Soft drop tetromino
- **Spacebar:** Hard drop tetromino

## Game Rules
- The game consists of a grid where tetrominoes (shapes) fall from the top.
- The objective is to fit these tetrominoes into the grid to form complete horizontal lines.
- When a line is completed, it disappears, and the player earns points.
- The game ends when the grid is full and no more tetrominoes can be placed.

## Known Issues
- List any known bugs or issues here.

## Future Improvements
- Add a high score system.
- Implement sound effects and music.
- Create a more polished user interface.

## Credits
This game was developed using:
- **C++:** The core programming language.
- **SFML:** The Simple and Fast Multimedia Library for graphics, input, and window management.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

---

Thank you for playing! If you have any feedback or find any bugs, feel free to open an issue on the GitHub repository. Enjoy the game!
