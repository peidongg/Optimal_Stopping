#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#define MAX_SITUATION 100

class Game {
public:
    Game() = default;
    void initial();     //initial a game
    void simulation();  //simulate procedure with optimal strategy
    void algorithm();   //the optimal stopping strategy
private:
    unsigned int number_of_situation;
    int profit[MAX_SITUATION];  //f(x)
    int cost;    //g(x)
    double discount;            //arpha

    //Auxiliary function
    double except_profit(double,int);
    double calculateStop();
    void clear();
};
