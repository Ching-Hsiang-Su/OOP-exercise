#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
private:
    string name;
    int score;
public:
    Player(string name) {
        this->name = name;
        score = 0;
    }
    ~Player() {}
    string getName() const {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    int getScore() const {
        return score;
    }
    void addScore(int score) {
        this->score += score;
    }
};

class NumberGenerator {
public:
    virtual int generate() = 0;
    virtual ~NumberGenerator() {}
};

class RandomNumberGenerator : public NumberGenerator {
private:
    int min;
    int max;
public:
    RandomNumberGenerator(int min, int max) {
        this->min = min;
        this->max = max;
        srand(time(NULL));
    }
    int generate() {
        return rand() % (max - min + 1) + min;
    }
};

class SequentialNumberGenerator : public NumberGenerator {
private:
    int current;
    int min;
    int max;
public:
    SequentialNumberGenerator(int min, int max) {
        this->min = min;
        this->max = max;
        current = min;
    }
    int generate() {
        int result = current;
        current++;
        if (current > max) {
            current = min;
        }
        return result;
    }
};

class Game {
private:
    Player* player;
    NumberGenerator* generator;
    int min;
    int max;
    vector<pair<string, int> > leaderboard;
    bool changeName;
public:
    Game() {
        player = new Player("");
        generator = new RandomNumberGenerator(1, 100);
        min = 1;
        max = 100;
        changeName = false;
    }
    ~Game() {
        delete player;
        delete generator;
    }
    void start() {
        while (true) {
            if (changeName) {
                cout << "What is your name? ";
                string name;
                cin >> name;
                player->setName(name);
                cout << "Hello, " << player->getName() << "!" << endl;
                changeName = false;
            }
            int number = generator->generate();
            int guess;
            int attempts = 0;
            time_t start;
            time(&start);
            while (true) {
                cout << "Guess a number between " << min << " and " << max << ": ";
                cin >> guess;
                attempts++;
                if (guess == number) {
                    int score = (max - min + 1) * 10 - attempts * 5;
                    player->addScore(score);
                    cout << "Congratulations, you guessed the number in " << attempts << " attempts!" << endl;
                    cout << "Your score is " << score << "." << endl;
                    break;
                }
                else if (guess < number) {
                    cout << "Too low, try again." << endl;
                }
                else {
                    cout << "Too high, try again." << endl;
                }
            }
            cout << "Do you want to play again? (y/n) ";
            char choice;
            cin >> choice;
            if (choice == 'y') {
                cout << "Do you want to change your name? (y/n) ";
                char nameChoice;
                cin >> nameChoice;
                if (nameChoice == 'y') {
                    changeName = true;
                }
                cout << "Do you want to use a different number generator? (y/n) ";
                char generatorChoice;
                cin >> generatorChoice;
                if (generatorChoice == 'y') {
                    cout << "Which generator do you want to use? (r for random, s for sequential) ";
                    char generatorType;
                    cin >> generatorType;
                    if (generatorType == 'r') {
                        generator = new RandomNumberGenerator(min, max);
                    }
                    else {
                        generator = new SequentialNumberGenerator(min, max);
                    }
                }
            }
            else {
                leaderboard.push_back(make_pair(player->getName(), player->getScore()));
                sort(leaderboard.begin(), leaderboard.end(), leaderboardSorter);
                cout << "Leaderboard:" << endl;
                for (int i= 0; i < leaderboard.size(); i++) {
                cout << i + 1 << ". " << leaderboard[i].first << " - Score: " << leaderboard[i].second << endl;
            }
            cout << "Thanks for playing!" << endl;
            break;
        }
        else {
            leaderboard.push_back(make_pair(player->getName(), player->getScore()));
            sort(leaderboard.begin(), leaderboard.end(), leaderboardSorter);
            cout << "Leaderboard:" << endl;
            for (int i = 0; i < leaderboard.size(); i++) {
                cout << i + 1 << ". " << leaderboard[i].first << " - Score: " << leaderboard[i].second << endl;
            }
            cout << "Next player, please!" << endl;
            break;
        }
    }
}
private:
    struct LeaderboardSorter {
        bool operator()(const pair& a, const pair& b) const {
            return a.second > b.second;
        }
    } leaderboardSorter;
};

int main() {
    Game game;
    game.start();
    return 0;
}