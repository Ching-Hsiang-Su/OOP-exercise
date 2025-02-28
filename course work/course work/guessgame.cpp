#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
 
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
    int getScore() {
        return score;
    }
    Player operator+(int points) {
        Player newPlayer = *this;
        newPlayer.score += points;
        return newPlayer;
    }
    friend ostream& operator<<(ostream& os, const Player& p) {
        os << "Hello " << p.name << ", your score is now " << p.score << ".";
        return os;
    }
    friend istream& operator>>(istream& is, Player& p) {
        is >> p.name;
        return is;
    }
};

class NumberGenerator {
private:
    int number;
public:
    NumberGenerator(int min, int max) {
        srand(time(NULL));
        number = rand() % (max - min + 1) + min;  //rand() is from 0 to RAND_MAX
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
    int min;
    int max;
    vector<pair<string, pair<int, int> > > leaderboard;

    struct LeaderboardSorter {
        bool operator()(const pair<string, pair<int, int> >& a, const pair<string, pair<int, int> >& b) const {
            if (a.second.first == b.second.first) {
                return a.second.second < b.second.second;   //if score is equal, compare time
            }
            return a.second.first > b.second.first; // compare score
        }
    } leaderboardSorter;

    
public:
    Game() {
        player = new Player("");
        generator = new NumberGenerator(1, 100);
        min = 1;
        max = 100;
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
        cout << "Select difficulty level (1-Easy 2-Normal, 3-Hard): ";
        int level;
        cin >> level;
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
        cout << "I'm thinking of a number between " << min << " and " << max << ". Can you guess it?" << endl;
        if (max == 50){
            cout << "Get 3 points if you guessed the number in less than 4 attempts." << endl;
            cout << "Get 2 points if you guessed the number in 4 to 6 attempts." << endl;
            cout << "Get 1 points if you guessed the number in more than 6 attempts." << endl;
        }
        else if (max == 100){
            cout << "Get 3 points if you guessed the number in less than 5 attempts." << endl;
            cout << "Get 2 points if you guessed the number in 5 to 7 attempts." << endl;
            cout << "Get 1 points if you guessed the number in more than 7 attempts." << endl;
        }
        else {
            cout << "Get 3 points if you guessed the number in less than 6 attempts." << endl;
            cout << "Get 2 points if you guessed the number in 6 to 8 attempts." << endl;
            cout << "Get 1 points if you guessed the number in more than 8 attempts." << endl;
        }
        cout << "------------------------------------------------------------------" << endl;
        int guess;
        int attempts = 0;
        time_t start, end;
        time(&start);
        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            if (guess < generator->getNumber()) {
                cout << "Too low! Try again." << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else if (guess > generator->getNumber()) {
                cout << "Too high! Try again." << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
            else {
                time(&end);
                double time_taken = double(end - start);
                cout << "Congratulations, " << player->getName() << "! You guessed the number in " << attempts << " attempts and " << time_taken << " seconds." << endl;
                if (max ==50){
                    if(attempts<4){
                        *player = *player + 3;
                        cout << "You get 3 points !" << endl;
                    }
                    else if(attempts >= 4 && attempts <=6){
                        *player = *player + 2;
                        cout << "You get 2 points !" << endl;
                    }
                    else {
                        *player = *player + 1;
                        cout << "You get 1 points !" << endl;
                    }
                }
                if (max ==100){
                    if(attempts<5){
                        *player = *player + 3;
                        cout << "You get 3 points !" << endl;
                    }
                    else if(attempts >= 5 && attempts <=7){
                        *player = *player + 2;
                        cout << "You get 2 points !" << endl;
                    }
                    else {
                        *player = *player + 1;
                        cout << "You get 1 points !" << endl;
                    }
                }
                if (max ==200){
                    if(attempts<6){
                        *player = *player + 3;
                        cout << "You get 3 points !" << endl;
                    }
                    else if(attempts >= 6 && attempts <=8){
                        *player = *player + 2;
                        cout << "You get 2 points !" << endl;
                    }
                    else {
                        *player = *player + 1;
                        cout << "You get 1 points !" << endl;
                    }
                }
                cout << *player << endl;
                
                leaderboard.push_back(make_pair(player->getName(), make_pair(player->getScore(), time_taken)));
                sort(leaderboard.begin(), leaderboard.end(), leaderboardSorter);
                cout << "Leaderboard:" << endl;

                for (int i = 0; i < leaderboard.size(); i++) {
                    cout << i + 1 << ". " << leaderboard[i].first << " - Score: " << leaderboard[i].second.first << ", Time: " << leaderboard[i].second.second << " seconds" << endl;
                }
                cout << "Do you want to play again? (y/n) ";
                char choice;
                cin >> choice;
                if (choice == 'y') {
                    delete generator;
                    generator = new NumberGenerator(min, max);
                    attempts = 0;
                    time(&start);
                    cout << "What is your name? ";
                    string name;
                    cin >> name;
                    delete player;
                    player = new Player(name);
                    cout << "Hello, " << player->getName() << "!" << endl;
                    cout << "I'm thinking of a number between " << min << " and " << max << ". Can you guess it?" << endl;
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