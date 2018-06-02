#include "Game.hpp"
#include <ctime>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    cout<<"Let's begin."<<endl;
    int run = 0;
    cin>>run;
    while (run){
        Game game{};
        game.initial();

    }
    return 0;
}