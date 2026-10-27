#include <iostream>
#include <cstdlib>
#include <limits>
#include "Prototypes.h"
using std::cout;
using std::endl;
using std::getline;


void greeting(){

    cout << "\nDice Game" << "\n---------" << endl;
    cout << "\nPress ENTER to continue..";
    getchar();
}


void defaultmenu(){


    cout << "\n\nMain Menu:\n";

    const char *decisions[10] = {"\n\t1. Start", "\t2. How to play", "\t3. Quit"};

    for(int i = 0; i < 3; i++){
        cout << decisions[i] << endl;
    }

    cout << ("\n\nChoose between 1 & 3 for decision: ");

    while(!(cin >> answer) || answer > 3 || answer < 1){
        cout << "\nEnter valid input between 1 & 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


    switch(answer){

        case 1:
            setup();
            roll();
            break;

        case 2:
            how_to();
            break;
        
        case 3:
            cout << "\nSee you later!" << endl;
            exit(1);
    };

}


void setup(){


    cout << "\n\nEnter a username: ";
    std::getline(std::cin >> std::ws, username);

    cout << "\n\nHow much would you like to gamble " << username << "? ";

    while(!(cin >> jackpot) || jackpot == 0 || jackpot < 0){
        cout << "\n\n\tJackpot rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. An initial balance of 0 is not allowed." << endl
            << "3. No character input." << endl
            << "\n\nHow much would you like to gamble " << username << "? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void how_to(){

    cout << "\n\tThe dice is six sided. Provide one number and the dice will roll " << endl
    << "\tautomatically until you decide to quit playing. Jackpot adjusts with winning or lossing bets." << endl;

    cout << "\n\tAt anytime during gameplay type '0' to exit the game." << endl;

    defaultmenu();

}


void roll(){

    cout << "\n\n\t\t\t* At any point during gameplay press '0' to quit *";

    cout << "\nStarting jackpot: $" << jackpot << endl;

    while(true){
    
        cout << "\n\nProvide a number from 1 - 6 for roll: ";

        while(!(cin >> a) || a > 6 || a < 0){
        cout << "\nNumbers between 1 & 6 only. Re-enter roll number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(a == 0){
            cout << "\nThank you for playing " << username << "!" << endl;
            exit(1);
        }

        dice = (rand() % 6) + 1;

        if(a == dice){
            jackpot += 50;
        }else{
            jackpot -= 25;
        }

        cout << "\n\nDice Roll: " << dice << endl;
        
        cout << "Balance: $" << jackpot;

        if(jackpot == 0 || jackpot < 0){
            cout << "\n\nYou ran out of money! Would you like to play again " << username << "? " << endl
            << "(press 1 to restart OR press 0 to quit): ";
            cin >> restart;

            switch(restart){

                case 0:
                    cout << "\nThank you for playing " << username << "!" << endl;
                    exit(1);
            
                case 1:
                    setup();
                    roll();
            }
        
        }
    };
}


