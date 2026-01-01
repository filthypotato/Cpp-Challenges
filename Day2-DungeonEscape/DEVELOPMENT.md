# 🛠️ Development Guide

This document provides implementation hints and guidance for completing the TODOs in the codebase.

## Implementation Order

Follow this order for the smoothest development experience:

1. **Player Actions** (Player.cpp)
   - `drinkPotion()` - Easiest, good warmup
   - `attemptRun()` - Practice with random numbers
   - `attack()` - Slightly more complex

2. **Enemy Actions** (Enemy.cpp)
   - `attack()` - Uses random numbers and player interaction

3. **Main Game Loop** (main.cpp)
   - `getValidInput()` - Input validation
   - `generatePlayerAttackPower()` - Simple random generation
   - Main game loop logic - Ties everything together

##  Random Number Generation Guide

### Basic Syntax
```cpp
// Already seeded in main.cpp with:
srand(static_cast<unsigned int>(time(nullptr)));

// Generate random numbers:
int random = rand() % range + min;
```

### Common Ranges Needed
```cpp
// 5-15 (player attack power)
int attack = rand() % 11 + 5;

// 5-20 (enemy normal attack)
int damage = rand() % 16 + 5;

// 10-25 (enemy hard attack)
int hardDamage = rand() % 16 + 10;

// 1-100 (for percentage checks)
int chance = rand() % 100 + 1;
if (chance <= 10) {
    // 10% chance occurred
}
```

## Implementation Hints by Function

### Player::drinkPotion()
```cpp
bool Player::drinkPotion() {
    // Step 1: Check if potions available
    if (potionCount <= 0) {
        cout << "No potions left!\n";
        return false;
    }
    
    // Step 2: Calculate new health (don't exceed maxHealth)
    health += 20;
    if (health > maxHealth) {
        health = maxHealth;
    }
    // Alternative: health = std::min(health + 20, maxHealth);
    
    // Step 3: Use up a potion
    potionCount--;
    
    // Step 4: Print success message
    cout << "You drink a potion! Restored 20 HP.\n";
    
    return true;
}
```

### Player::attemptRun()
```cpp
bool Player::attemptRun() {
    // Generate 1-100
    int chance = rand() % 100 + 1;
    
    // 10% chance means values 1-10
    if (chance <= 10) {
        cout << "You successfully escaped!\n";
        return true;
    }
    
    cout << "You failed to escape!\n";
    return false;
}
```

### Player::attack()
```cpp
int Player::attack(Enemy& enemy) {
    // Use the attackPower that was set this turn
    int damage = attackPower;
    
    // Optional: Add critical hit logic (10% chance for double damage)
    // int critChance = rand() % 100 + 1;
    // if (critChance <= 10) {
    //     damage *= 2;
    //     cout << "CRITICAL HIT!\n";
    // }
    
    // Apply damage to enemy
    enemy.takeDamage(damage);
    
    cout << "You attack for " << damage << " damage!\n";
    
    return damage;
}
```

### Enemy::attack()
```cpp
void Enemy::attack(Player& player, bool hardAttack) {
    int damage;
    
    if (hardAttack) {
        // Hard attack: 10-25 damage
        damage = rand() % 16 + 10;
        cout << "Enemy strikes with a BRUTAL attack!\n";
    } else {
        // Normal attack: 5-20 damage
        damage = rand() % 16 + 5;
        cout << "Enemy attacks!\n";
    }
    
    // Let player handle the damage (considers defense)
    player.takeDamage(damage);
}
```

### getValidInput()
```cpp
int getValidInput() {
    int choice;
    
    while (true) {
        cin >> choice;
        
        // Check if input failed (non-integer entered)
        if (cin.fail()) {
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input! Enter a number 1-4: ";
            continue;
        }
        
        // Check if choice is in valid range
        if (choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline
            return choice;
        }
        
        cout << "Invalid choice! Enter 1-4: ";
    }
}
```

### Main Game Loop Structure
```cpp
while (player.getHealth() > 0 && currentTurn <= MAX_TURNS && !gameOver) {
    // 1. Setup turn
    player.setAttackPower(generatePlayerAttackPower());
    player.resetDefense();
    
    // 2. Display info
    printStatus(currentTurn, player);
    printMenu();
    
    // 3. Get and handle input
    int choice = getValidInput();
    
    switch (choice) {
        case 1: // Attack
            player.attack(enemy);
            // Enemy counter-attacks
            enemy.attack(player, false);
            break;
            
        case 2: // Drink potion
            if (player.drinkPotion()) {
                // Potion used successfully - no enemy attack
            } else {
                // No potions - enemy attacks anyway? (your choice)
            }
            break;
            
        case 3: // Defend
            player.defend();
            // Enemy attacks, but damage will be halved
            enemy.attack(player, false);
            break;
            
        case 4: // Run
            if (player.attemptRun()) {
                // Escaped!
                playerWon = true;
                gameOver = true;
            } else {
                // Failed run - enemy hard attack
                enemy.attack(player, true);
            }
            break;
    }
    
    // 4. Check if player died
    if (player.getHealth() <= 0) {
        gameOver = true;
        playerWon = false;
    }
    
    // 5. Next turn
    currentTurn++;
    
    // Pause for readability
    cout << "\nPress Enter to continue...";
    cin.get();
}
```

## Testing Checklist

After implementation, test these scenarios:

- [ ] Can survive 10 turns
- [ ] Can die before turn 10
- [ ] Potion restores health correctly
- [ ] Potion caps at 100 HP
- [ ] "No potions" message when empty
- [ ] Defend reduces damage
- [ ] Run can escape (might need multiple tries)
- [ ] Failed run causes hard attack
- [ ] Invalid menu input handled gracefully
- [ ] Non-integer input handled
- [ ] Game ends properly on death
- [ ] Game ends properly on escape
- [ ] Attack power changes each turn

## Common Bugs to Avoid

1. **Forgetting to seed random** - Already done in main()
2. **Wrong random ranges** - Use the formulas above
3. **Not capping health** - Health shouldn't exceed maxHealth
4. **Not clearing cin after validation** - Use cin.ignore()
5. **Enemy attacking after potion** - Your design choice, but typically no attack
6. **Not resetting defense flag** - Call resetDefense() each turn
7. **Off-by-one errors** - Turn should go from 1 to 10 inclusive

## Bonus Features Ideas

Once the basic game works, try adding:

### Critical Hits
```cpp
// In Player::attack()
int critChance = rand() % 100 + 1;
if (critChance <= 10) {  // 10% chance
    damage *= 2;
    cout << "💥 CRITICAL HIT! 💥\n";
}
```

### Random Events
```cpp
// In main loop, after player action
int eventChance = rand() % 100 + 1;
if (eventChance <= 5) {  // 5% chance
    cout << "🎁 You found a potion!\n";
    player.setPotionCount(player.getPotionCount() + 1);
}
```

### Difficulty Modes
```cpp
enum Difficulty { EASY, NORMAL, HARD };

// Modify damage ranges based on difficulty
if (difficulty == EASY) {
    damage = rand() % 11 + 3;  // 3-13 instead of 5-20
} else if (difficulty == HARD) {
    damage = rand() % 21 + 10;  // 10-30
}
```

## Additional Resources

- **C++ Random Numbers**: https://en.cppreference.com/w/cpp/numeric/random
- **Input Validation**: https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
- **Game Loop Pattern**: https://gameprogrammingpatterns.com/game-loop.html

## Need Help?

If you get stuck:
1. Check the comments in the code
2. Review this guide
3. Test small pieces individually
4. Use cout statements to debug
5. Make sure random is seeded

Good luck! 🎮
