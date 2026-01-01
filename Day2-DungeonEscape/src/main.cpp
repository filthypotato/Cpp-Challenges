/**
 * @file main.cpp
 * @brief Dungeon Escape - A CLI survival game
 * @author Your Name
 * @date 2025
 * 
 * OBJECTIVE: Survive 10 turns or escape from the dungeon!
 * 
 * Build instructions:
 *   g++ -std=c++17 main.cpp Player.cpp Enemy.cpp -o dungeon_escape
 *   ./dungeon_escape
 */

#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()
#include <limits>   // For input validation

using namespace std;

// ============================================
// HELPER FUNCTIONS
// ============================================

/**
 * @brief Print the game title screen
 * TODO: Add ASCII art if you want (bonus)
 */
void printTitleScreen() {
    cout << "\n";
    cout << "╔═══════════════════════════════════╗\n";
    cout << "║      DUNGEON ESCAPE v1.0          ║\n";
    cout << "║   Survive 10 turns or escape!     ║\n";
    cout << "╚═══════════════════════════════════╝\n";
    cout << "\n";
}

/**
 * @brief Print the current game status
 * @param turn Current turn number
 * @param player Player object reference
 */
void printStatus(int turn, const Player& player) {
    cout << "\n─────────────────────────────────\n";
    cout << "Turn " << turn << " / 10\n";
    cout << "Health: " << player.getHealth() << " / " << player.getMaxHealth();
    cout << " | Potions: " << player.getPotionCount() << "\n";
    cout << "Attack Power: " << player.getAttackPower() << "\n";
    cout << "─────────────────────────────────\n";
}

/**
 * @brief Print the action menu
 */
void printMenu() {
    cout << "\n1) Attack enemy\n";
    cout << "2) Drink potion (+20 HP)\n";
    cout << "3) Defend (take half damage)\n";
    cout << "4) Run (10% chance to escape)\n";
    cout << "\nChoose: ";
}

/**
 * @brief Get valid integer input from user
 * Handles invalid input gracefully
 * @return Valid integer between 1-4
 */
int getValidInput() {
    int choice;
    
    // TODO: Add input validation
    // HINTS:
    // - Use cin >> choice
    // - Check if cin failed: if (cin.fail())
    // - Clear error state: cin.clear()
    // - Ignore bad input: cin.ignore(numeric_limits<streamsize>::max(), '\n')
    // - Keep asking until you get a valid number between 1-4
    
    cin >> choice;
    
    // FIXME: Add proper validation here
    
    return choice;
}

/**
 * @brief Generate random attack power for player (5-15)
 * @return Random attack power
 */
int generatePlayerAttackPower() {
    // TODO: Implement this
    // HINT: rand() % 11 + 5 gives range 5-15
    return rand() % 11 + 5;
}

// ============================================
// MAIN GAME LOOP
// ============================================

int main() {
    // Seed random number generator (CRITICAL - do this once at start!)
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Print title screen
    printTitleScreen();
    
    // Create game objects
    Player player;
    Enemy enemy;
    
    // Game state variables
    int currentTurn = 1;
    const int MAX_TURNS = 10;
    bool gameOver = false;
    bool playerWon = false;
    
    // ============================================
    // MAIN GAME LOOP
    // TODO: Implement the main game loop
    // ============================================
    
    /*
     * GAME LOOP STRUCTURE:
     * 
     * while (player is alive AND turn <= 10 AND not escaped) {
     *     1. Set random attack power for this turn
     *     2. Reset player defense flag
     *     3. Print status
     *     4. Print menu
     *     5. Get player choice
     *     6. Handle player action:
     *        - Attack: player attacks, then enemy counter-attacks
     *        - Potion: drink potion (no enemy attack)
     *        - Defend: enemy attacks (but damage is halved)
     *        - Run: attempt escape, if fail enemy attacks HARD
     *     7. Check win/lose conditions
     *     8. Increment turn
     * }
     * 
     * Print win/lose message
     */
    
    // TODO: Your game loop implementation here
    while (player.getHealth() > 0 && currentTurn <= MAX_TURNS && !gameOver) {
        // Set random attack power for this turn (5-15)
        player.setAttackPower(generatePlayerAttackPower());
        
        // Reset defense from previous turn
        player.resetDefense();
        
        // Display current status
        printStatus(currentTurn, player);
        
        // Show menu and get choice
        printMenu();
        int choice = getValidInput();
        
        // TODO: Handle each choice with switch or if-else
        // HINT: Use a switch statement
        switch (choice) {
            case 1: // Attack
                // TODO: Implement attack logic
                cout << "\n[TODO: Implement attack]\n";
                break;
                
            case 2: // Drink potion
                // TODO: Implement potion logic
                cout << "\n[TODO: Implement drink potion]\n";
                break;
                
            case 3: // Defend
                // TODO: Implement defend logic
                cout << "\n[TODO: Implement defend]\n";
                break;
                
            case 4: // Run
                // TODO: Implement run logic
                cout << "\n[TODO: Implement run attempt]\n";
                break;
                
            default:
                cout << "\nInvalid choice! Turn wasted.\n";
                break;
        }
        
        // TODO: Check if game is over (player dead or escaped)
        
        // Move to next turn
        currentTurn++;
        
        // Small pause for readability
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
    
    // ============================================
    // GAME OVER - Print results
    // ============================================
    
    cout << "\n";
    cout << "╔═══════════════════════════════════╗\n";
    
    if (playerWon) {
        cout << "║         YOU ESCAPED!              ║\n";
        cout << "║      Victory is yours!            ║\n";
    } else if (player.getHealth() > 0 && currentTurn > MAX_TURNS) {
        cout << "║       YOU SURVIVED!               ║\n";
        cout << "║    10 turns completed!            ║\n";
        playerWon = true;
    } else {
        cout << "║        YOU DIED...                ║\n";
        cout << "║      Better luck next time!       ║\n";
    }
    
    cout << "╚═══════════════════════════════════╝\n";
    cout << "\nFinal Health: " << player.getHealth() << "\n";
    cout << "Turns Survived: " << (currentTurn - 1) << " / " << MAX_TURNS << "\n\n";
    
    return 0;
}
