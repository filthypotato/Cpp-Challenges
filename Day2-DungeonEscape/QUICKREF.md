# 📝 Quick Reference - Implementation Cheat Sheet

## 🚀 Quick Start

```bash
# Build and run:
make run

# Or manually:
g++ -std=c++17 main.cpp Player.cpp Enemy.cpp -o dungeon_escape
./dungeon_escape
```

## 🎲 Random Number Formulas

```cpp
// Formula: rand() % range + minimum
rand() % 11 + 5   // → 5 to 15
rand() % 16 + 5   // → 5 to 20
rand() % 16 + 10  // → 10 to 25
rand() % 100 + 1  // → 1 to 100 (for percentages)
```

## ✅ TODO Checklist

### Player.cpp
- [ ] `attack()` - Deal damage, return damage dealt
- [ ] `drinkPotion()` - Add 20 HP (cap at 100), decrease count, return success
- [ ] `attemptRun()` - 10% chance returns true, else false

### Enemy.cpp
- [ ] `attack()` - Normal: 5-20, Hard: 10-25, call player.takeDamage()

### main.cpp
- [ ] `getValidInput()` - Loop until valid 1-4, handle cin.fail()
- [ ] `generatePlayerAttackPower()` - Return 5-15
- [ ] Game loop switch cases:
  - Case 1: player.attack(), then enemy.attack()
  - Case 2: player.drinkPotion()
  - Case 3: player.defend(), then enemy.attack()
  - Case 4: if (player.attemptRun()) win, else enemy.attack(true)
- [ ] Check if player died or escaped after each action

## 🎯 Win/Lose Logic

```cpp
// In game loop after each action:
if (player.getHealth() <= 0) {
    gameOver = true;
    playerWon = false;
}

// After successful run:
if (player.attemptRun()) {
    playerWon = true;
    gameOver = true;
}

// After loop ends:
if (player.getHealth() > 0 && currentTurn > MAX_TURNS) {
    playerWon = true; // Survived 10 turns
}
```

## 🔍 Input Validation Pattern

```cpp
while (true) {
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again: ";
        continue;
    }
    if (choice >= 1 && choice <= 4) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
    cout << "Must be 1-4: ";
}
```

## 📊 Example Values

| Stat | Value |
|------|-------|
| Player Start HP | 100 |
| Max HP | 100 |
| Starting Potions | 3 |
| Potion Heal | +20 |
| Player Attack | 5-15 (random per turn) |
| Enemy Attack | 5-20 |
| Enemy Hard Attack | 10-25 |
| Defend Multiplier | 0.5x (half damage) |
| Run Success | 10% |
| Max Turns | 10 |

## 🐛 Common Mistakes

❌ `health = health + 20` → Exceeds 100!  
✅ `health = min(health + 20, maxHealth)`

❌ `rand() % 10 + 5` → Gives 5-14, not 5-15!  
✅ `rand() % 11 + 5` → Gives 5-15

❌ Forgetting to call `player.resetDefense()` each turn  
✅ Call it at the start of every turn

❌ Enemy attacks after drinking potion (design choice)  
✅ Typically potions don't trigger enemy attacks

## 💻 Compile Commands

**Standard:**
```bash
g++ -std=c++17 main.cpp Player.cpp Enemy.cpp -o dungeon_escape
```

**With warnings:**
```bash
g++ -std=c++17 -Wall -Wextra main.cpp Player.cpp Enemy.cpp -o dungeon_escape
```

**Debug mode:**
```bash
g++ -std=c++17 -g main.cpp Player.cpp Enemy.cpp -o dungeon_escape
gdb ./dungeon_escape
```

## 📂 File Overview

| File | Purpose | What to Implement |
|------|---------|-------------------|
| `Player.hpp` | Player interface | Nothing (already done) |
| `Player.cpp` | Player logic | attack, drinkPotion, attemptRun |
| `Enemy.hpp` | Enemy interface | Nothing (already done) |
| `Enemy.cpp` | Enemy logic | attack |
| `main.cpp` | Game loop | Input validation, game loop logic |
| `Makefile` | Build system | Nothing (ready to use) |
| `README.md` | Documentation | Nothing (reference only) |

## 🎮 Game Flow

```
Start Game
  ↓
Turn 1-10 Loop:
  • Set random attack power (5-15)
  • Reset defense flag
  • Show status & menu
  • Get player choice (1-4)
  • Execute action:
    - Attack → enemy counter-attacks
    - Potion → heal (no counter)
    - Defend → enemy attacks (½ damage)
    - Run → 10% escape or hard attack
  • Check death/escape
  • Next turn
  ↓
End Game (death, escape, or 10 turns survived)
```

## 🏆 Testing Commands

```bash
# Test compilation
make clean && make

# Run game
./dungeon_escape

# Test with different inputs
echo -e "1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n" | ./dungeon_escape
```

---

**Ready to code? Start with `Player::drinkPotion()` - it's the easiest! 🎯**
