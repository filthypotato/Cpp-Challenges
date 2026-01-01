# 🎮 Dungeon Escape

A command-line dungeon survival game written in C++. Survive 10 turns or find a way to escape!

## 📋 Overview

You're trapped in a dangerous dungeon with limited resources. Each turn presents new challenges as you fight to survive against a relentless enemy. Make strategic choices to manage your health, potions, and attacks.

## ✨ Features

- **Turn-based combat system** - Make strategic decisions each turn
- **Resource management** - Limited potions and random attack power
- **Multiple actions** - Attack, defend, heal, or attempt to escape
- **Random elements** - Keeps each playthrough unique
- **Win conditions** - Survive 10 turns OR successfully escape

## 🎯 Game Mechanics

### Player Stats
- **Health**: 100 HP (starts full)
- **Potions**: 3 (restore +20 HP each)
- **Attack Power**: 5-15 (randomized each turn)

### Actions
1. **Attack** - Deal damage to the enemy, enemy counter-attacks
2. **Drink Potion** - Restore 20 HP (capped at 100), no enemy attack
3. **Defend** - Take half damage from enemy attack
4. **Run** - 10% chance to escape, failure results in hard attack (10-25 damage)

### Enemy
- Deals 5-20 damage per attack
- Deals 10-25 damage on hard attacks (failed run attempts)

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++17 support (g++, clang++, or MSVC)
- Terminal/Command line

### Building the Game

**Linux/Mac:**
```bash
g++ -std=c++17 main.cpp Player.cpp Enemy.cpp -o dungeon_escape
./dungeon_escape
```

**Windows (MinGW):**
```bash
g++ -std=c++17 main.cpp Player.cpp Enemy.cpp -o dungeon_escape.exe
dungeon_escape.exe
```

**Windows (MSVC):**
```bash
cl /EHsc /std:c++17 main.cpp Player.cpp Enemy.cpp /Fe:dungeon_escape.exe
dungeon_escape.exe
```

## 📁 Project Structure

```
dungeon_escape/
├── main.cpp          # Game loop and UI
├── Player.hpp        # Player class interface
├── Player.cpp        # Player class implementation
├── Enemy.hpp         # Enemy class interface
├── Enemy.cpp         # Enemy class implementation
├── Makefile          # Build automation
└── README.md         # This file
```

## 🎓 Learning Objectives

This project demonstrates:
- Object-oriented programming (classes, encapsulation)
- Game loop implementation
- Random number generation
- Input validation
- State management
- Function decomposition

## 🏆 Bonus Features (Optional)

Want to extend the game? Try adding:
- [ ] Critical hits (10% chance for double damage)
- [ ] Random events ("You found a potion!")
- [ ] Difficulty modes (easy/normal/hard)
- [ ] ASCII art title screen
- [ ] Enemy health tracking
- [ ] High score system
- [ ] Save/load game state
- [ ] Multiple enemy types
- [ ] Special abilities/items

## 📝 TODO List

Check `main.cpp`, `Player.cpp`, and `Enemy.cpp` for implementation tasks:
- [ ] Complete `Player::attack()` method
- [ ] Complete `Player::drinkPotion()` method
- [ ] Complete `Player::attemptRun()` method
- [ ] Complete `Enemy::attack()` method
- [ ] Implement main game loop logic
- [ ] Add input validation in `getValidInput()`
- [ ] Handle all four player action choices

## 🐛 Known Issues

- Input validation needs improvement
- No save/load functionality yet
- Terminal output could be prettier

## 🤝 Contributing

This is a learning project! Feel free to:
1. Fork the repository
2. Create a feature branch
3. Implement your changes
4. Test thoroughly
5. Submit a pull request

## 📜 License

This project is created for educational purposes. Feel free to use and modify as needed for learning.

## 👤 Author

**Your Name**
- Challenge: Daily Coding Challenge - Day 2
- Date: 2025

## 🙏 Acknowledgments

- Built as part of a beginner-to-intermediate C++ learning path
- Focus on practical game development concepts
- Emphasis on clean code and good practices

---

**Good luck escaping the dungeon! 🗡️**
