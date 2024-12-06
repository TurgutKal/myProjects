#include "gamelogic.h"
#include <iostream>

using namespace std;

int main()
{
    GameLogic game;
    char answer;
    while (true) {
        game.userInteraction();
        cout << "Continue? (y/n): ";
        cin >> answer;
        if (answer == 'n') {
            break;
        }
    }

    return 0;
}
