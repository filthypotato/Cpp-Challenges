#include "Enemy.hpp"
#include "Player.hpp"
#include <iostream>
#include <cstdlib> // For rand()

// Constructor
Enemy::Enemy() 
    : health(100)
    , defense(0)
    , attackPower(0)
{
}

// ACTION METHODS - TODO: Implement these

/**
 * TODO: Implement enemy attack
 * HINTS:
 * - Normal attack: rand() % 16 + 5 gives range 5-20
 * - Hard attack: rand() % 16 + 10 gives range 10-25
 * - Call player.takeDamage(damage)
 * - Print what happened
 */
void Enemy::attack(Player& player, bool hardAttack) {
    // TODO: Your code here
    // Calculate damage based on hardAttack flag
    int damage = 0;
    
    if (hardAttack) {
        // TODO: Hard attack (10-25 damage)
        std::cout << "Enemy strikes with a BRUTAL attack!\n";
    } else {
        // TODO: Normal attack (5-20 damage)
        std::cout << "Enemy attacks!\n";
    }
    
    // TODO: Apply damage to player
    // player.takeDamage(damage);
}

/**
 * TODO: Implement taking damage
 * NOTE: In the basic version, enemy HP isn't tracked
 * But you can implement this for the bonus features!
 */
void Enemy::takeDamage(int damage) {
    // TODO: Your code here (optional for basic version)
    health -= damage;
    std::cout << "Enemy takes " << damage << " damage!\n";
}

// GETTERS AND SETTERS - Already implemented

void Enemy::setHealth(int h) {
    health = h;
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::setAttackPower(int ap) {
    attackPower = ap;
}

int Enemy::getAttackPower() const {
    return attackPower;
}

void Enemy::setDefense(int def) {
    defense = def;
}

int Enemy::getDefense() const {
    return defense;
}
