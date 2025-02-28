#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "NumberGenerator.h"

class Game {
private:
    Player* player;
    NumberGenerator* generator;
    int min;
    int max;
    std::vector<std::pair<std::string, std::pair<int, double> > > leaderboard;
public:
    Game();
    ~Game();
    void start();
};

#endif