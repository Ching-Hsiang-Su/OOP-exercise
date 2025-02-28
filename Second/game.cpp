#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int score;
public:
    Player(string n) {
        name = n;
        score = 0;
    }
    ~Player() {}
    void setName(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
    void setScore(int s) {
        score = s;
    }
    int getScore() {
        return score;
    }
};

class NumberGenerator {
private:
    int number;
public:
    NumberGenerator() {
        srand(time(NULL));
        number = rand() % 100 + 1;
    }
    ~NumberGenerator() {}
    int getNumber() {
        return number;
    }
};

class Game {
private:
    Player* player;
    NumberGenerator* generator;
public:
    Game() {
        player = new Player("");
        generator = new NumberGenerator();
    }
    ~Game() {
        delete player;
        delete generator;
    }
    void start() {
        cout << "Welcome to Guess the Number!" << endl;
        cout << "What is your name? ";
        string name;
        cin >> name;
        player->setName(name);
        cout << "Hello, " << player->getName() << "!" << endl;
        cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;
        cout << "Get 3 points if you guessed the number in less than 5 attempts." << endl;
        cout << "Get 2 points if you guessed the number in 5 to 7 attempts." << endl;
        cout << "Get 1 points if you guessed the number in more than 7 attempts." << endl;
        int guess;
        int attempts = 0;
        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            if (guess < generator->getNumber()) {
                cout << "Too low! Try again." << endl;
            }
            else if (guess > generator->getNumber()) {
                cout << "Too high! Try again." << endl;
            }
            else {
                cout << "Congratulations, " << player->getName() << "! You guessed the number in " << attempts << " attempts." << endl;
                if(attempts<5){
                    player->setScore(player->getScore() + 3);
                    cout << "You get 3 points !" << endl;
                }
                else if(attempts >= 5 && attempts <=7){
                    player->setScore(player->getScore() + 2);
                    cout << "You get 2 points !" << endl;
                }
                else {
                    player->setScore(player->getScore() + 1);
                    cout << "You get 1 points !" << endl;
                }
                cout << "Your score is now " << player->getScore() << "." << endl;
                cout << "Do you want to play again? (y/n) ";
                char choice;
                cin >> choice;
                if (choice == 'y') {
                    generator = new NumberGenerator();
                    attempts = 0;
                }
            }
        } while (guess != generator->getNumber());
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}