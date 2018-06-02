#pragma once

#include <iostream>
#include <string>

#define MAX_SITUATION 100

class Game {
public:
    Game() = default
    void initial();
    void simulation();
private:
    unsigned int number_of_situation;
    int profit[MAX_SITUATION];  //f(x)
    int cost[MAX_SITUATION];    //g(x)
    double except_profit();
};
