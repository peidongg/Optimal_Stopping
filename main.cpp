#include "Game.hpp"
#include <ctime>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    cout<<"Let's begin."<<endl;
    int run = 1;
    //cin>>run;
    Game game{};
    game.initial();
    while (run){
        game.algorithm();
        game.simulation();
        cout<<"1: create a new game"<<endl;
        cout<<"0: exit"<<endl;
        cout<<"other: continue"<<"\n"<<endl;
        string R;
        cin>>R;
        if (R == "1") game.initial(); else
            if (R == "0") break;
    }
    return 0;
}