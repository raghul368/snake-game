# 🐍 Snake Game in C

A classic Snake Game built entirely in C programming language. This is a console-based game featuring turn-based gameplay that works on any platform.

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

## 📖 About The Project

This Snake Game is a simple yet engaging console-based game developed in C. The player controls a snake that moves around the screen, eating food to grow longer while avoiding collisions with walls and itself.

### Built With

- C Programming Language
- Standard C Libraries (stdio.h, stdlib.h, time.h)

## 🎮 Features

- Classic snake gameplay
- Turn-based controls (W, A, S, D)
- Score tracking system
- Snake length indicator
- Collision detection (walls & self)
- Random food generation
- Play again option
- Cross-platform compatibility

## 🚀 Getting Started

### Prerequisites

- GCC Compiler or any C compiler
- Terminal / Command Prompt

### Installation

1. Clone the repository
```bash
git clone https://github.com/yourusername/snake-game-c.git
```

2. Navigate to the project directory
```bash
cd snake-game-c
```

3. Compile the program
```bash
gcc snake.c -o snake
```

4. Run the game
```bash
./snake        # Linux/Mac
snake.exe      # Windows
```

### Run Online

You can also run this game on online compilers:
- [OnlineGDB](https://www.onlinegdb.com/online_c_compiler)
- [Programiz](https://www.programiz.com/c-programming/online-compiler/)
- [Replit](https://replit.com/)

## 🕹️ How To Play

| Key | Action |
|-----|--------|
| `W` | Move Up |
| `S` | Move Down |
| `A` | Move Left |
| `D` | Move Right |
| `X` | Quit Game |

> **Note:** Press the key and then press `Enter` to make a move.

### Rules

1. Control the snake to eat the food (`*`)
2. Each food eaten = +10 points
3. Snake grows longer with each food
4. Avoid hitting the walls
5. Avoid hitting your own body
6. Try to get the highest score!

## 📸 Game Preview

```
  +--------------------+
  |                    |
  |       @oo          |
  |              *     |
  |                    |
  +--------------------+
  Score: 20  |  Length: 4
```

| Symbol | Meaning |
|--------|---------|
| `@` | Snake Head |
| `o` | Snake Body |
| `*` | Food |

## 📂 Project Structure

```
snake-game-c/
│
├── snake.c          # Main source code
├── README.md        # Project documentation
└── LICENSE          # License file
```

## 🛠️ Future Enhancements

- [ ] Add difficulty levels
- [ ] Implement high score saving
- [ ] Add obstacles
- [ ] Add color support
- [ ] Implement multiplayer mode

## 🤝 Contributing

Contributions are welcome!

1. Fork the project
2. Create your feature branch (`git checkout -b feature/NewFeature`)
3. Commit your changes (`git commit -m 'Add NewFeature'`)
4. Push to the branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

## 📝 License

Distributed under the MIT License.
