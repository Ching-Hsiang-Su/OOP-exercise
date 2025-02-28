#include "Player.h"

Player::Player(std::string n) {
    name = n;
    score = 0;
}

Player::~Player() {}

void Player::setName(std::string n) {
    name = n;
}

std::string Player::getName() {
    return name;
}

void Player::setScore(int s) {
    score = s;
}

int Player::getScore() {
    return score;
}