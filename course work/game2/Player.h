#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int score;
public:
    Player(std::string n);
    ~Player();
    void setName(std::string n);
    std::string getName();
    void setScore(int s);
    int getScore();
};

#endif