/**
 * @file Enemy.hpp
 * @brief Enemy class definition for Dungeon Escape game
 * @author Your Name
 * @date 2025
 * 
 * Represents the dungeon enemy that attacks the player.
 */

#pragma once

class Player; // Forward declaration

class Enemy {
public:
    // Constructor
    Enemy();
    
    // ACTION METHODS - TODO: Implement these
    
    /**
     * @brief Enemy attacks the player
     * Damage range: 5-20 (or 10-25 if player failed run attempt)
     * @param player Reference to the player being attacked
     * @param hardAttack If true, deal 10-25 damage instead of 5-20
     */
    void attack(Player& player, bool hardAttack = false);
    
    /**
     * @brief Take damage from player
     * @param damage Amount of damage to take
     */
    void takeDamage(int damage);
    
    // GETTERS AND SETTERS
    
    void setHealth(int h);
    int getHealth() const;
    
    void setAttackPower(int ap);
    int getAttackPower() const;
    
    void setDefense(int def);
    int getDefense() const;

private:
    int health{};          // Enemy HP (not tracked in basic version)
    int defense{};         // Defense value
    int attackPower{};     // Base attack damage
};
