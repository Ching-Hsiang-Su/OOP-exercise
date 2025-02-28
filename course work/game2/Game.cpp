#include "Game.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

Game::Game() {
    player = new Player("");
    generator = new NumberGenerator(1, 100);
    min = 1;
    max = 100;
}

Game::~Game() {
    delete player;
    delete generator;
}

void Game::start() {
    std::cout << "Welcome to Guess the Number!" << std::endl;
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    player->setName(name);
    std::cout << "Hello, " << player->getName() << "!" << std::endl;
    std::cout << "Select difficulty level (1-Easy 2-Normal, 3-Hard): ";
    int level;
    std::cin >> level;
    switch (level) {
    case 1:
        min = 1;
        max = 50;
        break;
    case 2:
        min = 1;
        max = 100;
        break;
    case 3:
        min = 1;
        max = 200;
        break;
    default:
        min = 1;
        max = 100;
        break;
    }
    generator = new NumberGenerator(min, max);
    std::cout << "I'm thinking of a number between " << min << " and " << max << ". Can you guess it?" << std::endl;
    if (max == 50){
        std::cout << "Get 3 points if you guessed the number in less than 4 attempts." << std::endl;
        std::cout << "Get 2 points if you guessed the number in 4 to 6 attempts." << std::endl;
        std::cout << "Get 1 points if you guessed the number in more than 6 attempts." << std::endl;
    }
    else if (max == 100){
        std::cout << "Get 3 points if you guessed the number in less than 5 attempts." << std::endl;
        std::cout << "Get 2 points if you guessed the number in 5 to 7 attempts." << std::endl;
        std::cout << "Get 1 points if you guessed the number in more than 7 attempts." << std::endl;
    }
    else {
        std::cout << "Get 3 points if you guessed the number in less than 6 attempts." << std::endl;
    std::cout << "Get 2 points if you guessed the number in 6 to 8 attempts." << std::endl;
    std::cout << "Get 1 points if you guessed the number in more than 8 attempts." << std::endl;
}
std::cout << "------------------------------------------------------------------" << std::endl;
int guess;
int attempts = 0;
time_t start, end;
time(&start);
do {
    std::cout << "Enter your guess: ";
    std::cin >> guess;
    attempts++;
    if (guess < generator->getNumber()) {
        std::cout << "Too low! Try again." << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
    }
    else if (guess > generator->getNumber()) {
        std::cout << "Too high! Try again." << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
    }
    else {
        time(&end);
        double time_taken = double(end - start);
        std::cout << "Congratulations, " << player->getName() << "! You guessed the number in " << attempts << " attempts and " << time_taken << " seconds." << std::endl;
        if (max ==50){
            if(attempts<4){
                player->setScore(player->getScore() + 3);
                std::cout << "You get 3 points !" << std::endl;
            }
            else if(attempts >= 4 && attempts <=6){
                player->setScore(player->getScore() + 2);
                std::cout << "You get 2 points !" << std::endl;
            }
            else {
                player->setScore(player->getScore() + 1);
                std::cout << "You get 1 points !" << std::endl;
            }
        }
        if (max ==100){
            if(attempts<5){
                player->setScore(player->getScore() + 3);
                std::cout << "You get 3 points !" << std::endl;
            }
            else if(attempts >= 5 && attempts <=7){
                player->setScore(player->getScore() + 2);
                std::cout << "You get 2 points !" << std::endl;
            }
            else {
                player->setScore(player->getScore() + 1);
                std::cout << "You get 1 points !" << std::endl;
            }
        }
        if (max ==200){
            if(attempts<6){
                player->setScore(player->getScore() + 3);
                std::cout << "You get 3 points !" << std::endl;
            }
            else if(attempts >= 6 && attempts <=8){
                player->setScore(player->getScore() + 2);
                std::cout << "You get 2 points !" << std::endl;
            }
            else {
                player->setScore(player->getScore() + 1);
                std::cout << "You get 1 points !" << std::endl;
            }
        }
        std::cout << "Your score is now " << player->getScore() << "." << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "Do you want to play again? (y/n) ";
        char choice;
        std::cin >> choice;
        if (choice == 'y') {
            generator = new NumberGenerator(min, max);
            attempts = 0;
            time(&start);
        }
    }
    }while (guess != generator->getNumber());
}