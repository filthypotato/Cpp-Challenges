/**
 * @file Player.hpp
 * @brief Player class definition for Dungeon Escape game
 * @author Your Name
 * @date 2025
 * 
 * Represents the player character with health, potions, and combat abilities.
 */

#pragma once

class Enemy; // Forward declaration to avoid circular dependency

class Player {
public:
    // Constructor
    Player();
    
    // ACTION METHODS - TODO: Implement these
    
    /**
     * @brief Attack an enemy (damage will be based on attackPower)
     * @param enemy Reference to the enemy being attacked
     * @return Damage dealt to the enemy
     */
    int attack(Enemy& enemy);
    
    /**
     * @brief Enter defensive stance (reduces incoming damage)
     * Sets defense flag for this turn
     */
    void defend();
    
    /**
     * @brief Drink a potion to restore health
     * Restores +20 HP (capped at maxHealth)
     * Consumes one potion if available
     * @return true if potion was used, false if none available
     */
    bool drinkPotion();
    
    /**
     * @brief Attempt to run away from combat
     * 10% chance of success
     * @return true if escape successful, false otherwise
     */
    bool attemptRun();
    
    /**
     * @brief Take damage from an enemy attack
     * Applies defense modifier if defending
     * @param damage Amount of raw damage to take
     */
    void takeDamage(int damage);
    
    // ============================================
    // GETTERS AND SETTERS
    // ============================================
    
    void setHealth(int h);
    int getHealth() const;
    
    void setMaxHealth(int mh);
    int getMaxHealth() const;
    
    void setAttackPower(int ap);
    int getAttackPower() const;
    
    void setDefense(int def);
    int getDefense() const;
    
    int getPotionCount() const;
    void setPotionCount(int count);
    
    bool isDefending() const;
    void resetDefense(); // Call this at the start of each turn

private:
    int health;          // Current HP
    int maxHealth;       // Maximum HP (for capping heals)
    int attackPower;     // Base attack damage
    int defense;         // Defense value (not used in basic version)
    int potionCount;     // Number of potions remaining
    bool defending;      // Is player defending this turn?
};
