#include "Game.hpp"

using namespace std;

void Game::initial() {
    clear();
    cout << "-----------Create new game------------" << endl;
    cout << "Number of situation: ";
    cin >> number_of_situation;
    cout << "The profit of each situation:" << endl;
    for (int i = 0; i < number_of_situation; i++)
        cin >> profit[i];
    cout << "The cost of continue playing: ";
    cin >> cost;
    cout << "Discount (0~1) :";
    cin >> discount;
    cout << "Game initials completely." << "\n" << endl;
}

void Game::simulation() {
    cout << "     -----Simulation-----" << endl;
    cout<<"This simulate each step with the optimal strategy"<<endl;
    int times = 0;
    double sum = 0;
    int statistic[number_of_situation + 1] = {0};
    double statistic_each_stop[number_of_situation+1] = {0};
    cout << "Times to simulation (not more than 1000000): ";
    cin >> times;
    if (times > 1000000) times = 1000000;
    for (int i = 0; i < times; i++) {
//        cout << "The " << i << " time" << endl;
        int timesToPlay = 0;
        double now_profit = 0, next_except_profit = 0;
        next_except_profit = except_profit(now_profit, timesToPlay);
        while (now_profit < next_except_profit) {
            unsigned int this_situation = (rand() % number_of_situation);
            if (!profit[this_situation]) {
                statistic[this_situation]++;
//                cout << "    YOU LOSS. Totally $0" << endl;
                break;
            } else {
                now_profit += (timesToPlay ? profit[this_situation] - cost : profit[this_situation]);
                now_profit *= discount;
                next_except_profit = except_profit(now_profit, timesToPlay);
                if (now_profit < next_except_profit) {
                    //      cout << "    Continue." << endl;
                } else {
                    statistic[this_situation]++;
                    statistic_each_stop[this_situation]+=now_profit;
                    sum += now_profit;
                }
                timesToPlay++;
            }
        }
    }
    for (int i = 0; i < number_of_situation; i++) {
        if (statistic[i])
            cout << "Stop at " << i << " situation " << statistic[i] << " times "
                 << "with average "<< statistic_each_stop[i]/statistic[i] <<" profit."<<endl;
        else cout << "Stop at " << i << " situation " << statistic[i] << " times."<<endl;
    }
    cout << "Total excepted profit: $" << fixed << setprecision(2)
         << sum / times << "\n" << "\n" << endl;
}

void Game::algorithm() {
    cout << "This is the theoretical tests." << endl;
    double Stop = 0, Except_Profit = 0;
    Stop = calculateStop();

    cout << "With the algorithm, it will theoretically stop at: " << Stop << endl;
    cout << "Then , let's simulate that it will not stop until it greater than or equal to the stop value." << endl;
    double average = 0;
    int times;
    int statistic[number_of_situation + 1] = {0};
    double statistic_each_stop[number_of_situation+1] = {0};
    cout << "Times to run with the stop value (not more than 1000000): ";
    cin >> times;
    for (int i = 0; i < times; i++) {
        double now_profit = 0;
        while (now_profit < Stop) {
            unsigned int this_situation = (rand() % number_of_situation);
            if (!profit[this_situation]) {
                statistic[this_situation]++;
                break;
            } else {
                now_profit += profit[this_situation] - cost;
                now_profit *= discount;
                if (now_profit < Stop) {
                } else {
                    statistic[this_situation]++;
                    statistic_each_stop[this_situation]+=now_profit;
                    average += now_profit;
                }
            }
        }
    }
    for (int i = 0; i < number_of_situation; i++) {
        if (statistic[i])
        cout << "Stop at " << i << " situation " << statistic[i] << " times "
             << "with average "<< statistic_each_stop[i]/statistic[i] <<" profit."<<endl;
        else cout << "Stop at " << i << " situation " << statistic[i] << " times."<<endl;
    }
    cout << "With this stop value, the average profit :$" << average / times << "\n" << "\n" << endl;
}

double Game::except_profit(double now_profit, int time) {
    double result = 0;
    int Cost = time ? cost : 0;
    for (int i = 0; i < number_of_situation; i++)
        if (profit[i] != 0) result = result + now_profit + profit[i] - Cost;
    return result / static_cast<double> (number_of_situation) * discount;
}

double Game::calculateStop() {
    double result = 0, sum = 0;
    int countZero = 0;
    for (int i = 0; i < number_of_situation; i++) {
        countZero += (profit[i] ? 0 : 1);
        sum += (profit[i]?(profit[i] - cost):profit[i]);
    }
    result = (discount * sum) / (number_of_situation - discount * (number_of_situation - countZero));
    return result;
}

void Game::clear() {
    number_of_situation = 0;
    for (int i=0;i<MAX_SITUATION-1;i++) profit[i] = 0;
    cost =0;
    discount = 0;
}

//                cout << "    Now profit: " //<< setw(8) << ios::right
//                     << fixed << setprecision(2)
//                     << now_profit;
//                cout << "    Except profit of continue: " //<< setw(8) << ios::right
//                     << fixed << setprecision(2)
//                     << next_except_profit;

//cout << "Situation: " << this_situation;

//                    cout << "    Stop." << endl;
//                    cout << "--------Totally $" << fixed << setprecision(2)
//                         << now_profit << "\n" << endl;