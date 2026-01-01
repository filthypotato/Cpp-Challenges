/**
 * @file Player.cpp
 * @brief Player class implementation
 */

#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <algorithm> // For std::min, std::max

// Constructor - Initialize player stats
Player::Player() 
    : health(100)
    , maxHealth(100)
    , attackPower(0)     // Will be set randomly each turn
    , defense(0)
    , potionCount(3)     // Start with 3 potions
    , defending(false)
{
}

// ============================================
// ACTION METHODS - TODO: Implement these
// ============================================

/**
 * TODO: Implement player attack
 * HINTS:
 * - Use attackPower to determine damage
 * - Consider adding critical hit logic (bonus)
 * - Return the damage dealt
 */
int Player::attack(Enemy& enemy) {
    // TODO: Your code here
    // Example structure:
    // int damage = attackPower;
    // enemy.takeDamage(damage);
    // return damage;
    
    return 0; // FIXME: Return actual damage
}

/**
 * TODO: Implement defend
 * HINT: Set the defending flag to true
 */
void Player::defend() {
    // TODO: Your code here
    defending = true;
    std::cout << "You brace yourself for the enemy's attack...\n";
}

/**
 * TODO: Implement potion drinking
 * HINTS:
 * - Check if potionCount > 0
 * - Restore 20 HP
 * - Cap health at maxHealth
 * - Decrement potionCount
 * - Return true if successful, false if no potions
 */
bool Player::drinkPotion() {
    // TODO: Your code here
    // Check potion availability
    if (potionCount <= 0) {
        std::cout << "No potions left!\n";
        return false;
    }
    
    // TODO: Restore health (capped at maxHealth)
    // TODO: Decrement potion count
    // TODO: Print success message
    
    return false; // FIXME: Return true on success
}

/**
 * TODO: Implement run attempt
 * HINTS:
 * - Generate random number 1-100
 * - If <= 10, escape successful (return true)
 * - Otherwise, return false
 */
bool Player::attemptRun() {
    // TODO: Your code here
    // Use: rand() % 100 + 1 to get 1-100
    
    return false; // FIXME: Return based on random chance
}

/**
 * COMPLETED: Take damage implementation
 * This shows you how to handle the defending flag
 */
void Player::takeDamage(int damage) {
    // If defending, take half damage
    if (defending) {
        damage = damage / 2;
        std::cout << "Defended! Damage reduced to " << damage << "!\n";
    }
    
    health -= damage;
    
    // Don't let health go below 0
    if (health < 0) {
        health = 0;
    }
    
    std::cout << "You took " << damage << " damage! HP: " << health << "\n";
}

// ============================================
// GETTERS AND SETTERS - Already implemented
// ============================================

void Player::setHealth(int h) {
    health = h;
}

int Player::getHealth() const {
    return health;
}

void Player::setMaxHealth(int mh) {
    maxHealth = mh;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

void Player::setAttackPower(int ap) {
    attackPower = ap;
}

int Player::getAttackPower() const {
    return attackPower;
}

void Player::setDefense(int def) {
    defense = def;
}

int Player::getDefense() const {
    return defense;
}

int Player::getPotionCount() const {
    return potionCount;
}

void Player::setPotionCount(int count) {
    potionCount = count;
}

bool Player::isDefending() const {
    return defending;
}

void Player::resetDefense() {
    defending = false;
}
