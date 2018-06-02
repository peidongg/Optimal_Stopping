#include "Game.hpp"

using namespace std;

void Game::initial() {
    cout << "Number of situation: ";
    cin >> number_of_situation;
    cout << "The profit of each situation:" << endl;
    for (int i = 0; i < number_of_situation; i++)
        cin >> profit[i];
    cout << "The cost of each situation:" << endl;
    for (int i = 0; i < number_of_situation; i++)
        cin >> cost[i];
    cout << "Game initials completely." << endl;
}

void Game::simulation() {
    int times = 0;
    cout<<"Times to try (not more than 100000): ";
    cin>>times;
    for (int i=0;i<times;i++){
        double now_profit = 0,  next_except_profit = 0;
        next_except_profit = except_profit();
        while (now_profit < next_except_profit){
            unsigned int this_situation = (rand() % number_of_situation) + 1;

        }
    }
}

double Game::except_profit() {
    double result = 0;
    for (auto i : profit) result += i;
    return result / static_cast<double> (number_of_situation);
}