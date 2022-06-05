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


int main()
{
    
    return 0;
}











int arcadeSession()
{
    // to run in main:
    //    int arcadeStatus = 0;
    //    while (arcadeStatus == 0)
    //    {
    //        arcadeStatus = arcadeSession();
    //    }
    
    
    string gameNum;
    
    cout << "Choose your game: \n"
         << "1: Tic Tac Toe\n"
         << "2: Hangman\n\n"
         << "O to exit\n"
         << "Choice: ";
    cin >> gameNum;
    
    if (gameNum == "0")
    {
        return 1;
    }
    else if (gameNum == "1")
    {
        ticTacToe();
    }
    else if (gameNum == "2")
    {
        hangmanSession();
    }
    else
    {
        cout << "Invalid input!\n";
    }
    
    return 0;
}
