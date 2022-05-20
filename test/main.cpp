//
//  main.cpp
//  test
//
//  Created by Nicky Qin on 5/15/22.
//


#include "ticTacToe.hpp"
#include "hangman.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int arcadeSession();



int main()
{
    int arcadeStatus = 0;
    while (arcadeStatus == 0)
    {
        arcadeStatus = arcadeSession();
    }
    
    return 0;
    
    // ray dalio
}


int arcadeSession()
{
    string gameNum;
    
    cout << "Choose your game: \n";
    cout << "1: Tic Tac Toe\n";
    cout << "2: Hangman\n\n";
    cout << "O to exit\n";
    cout << "Choice: ";
    cin >> gameNum;
    
    if (gameNum == "0") {
        return 1;
    } else if (gameNum == "1") {
        ticTacToe();
    } else if (gameNum == "2") {
        hangmanSession();
    } else {
        cout << "Invalid input!\n";
    }
    
    return 0;
}
