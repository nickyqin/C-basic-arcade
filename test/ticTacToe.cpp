//
//  ticTacToe.cpp
//  test
//
//  Created by Nicky Qin on 5/16/22.
//

#include "ticTacToe.hpp"

char square[10] = {'p', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void board();
bool checkWin();

int ticTacToe() {
    
    board();
    bool win = false;
    int pos, moveNum = 0;
    
    while (!win && moveNum < 9)
    {
        
        cout << "Player " << moveNum % 2 + 1 << ": \n";
        cin >> pos;
        
        if (pos < 1 || pos > 9) cout << "Invalid input, please enter a number from 1-9\n";
        else if (square[pos] == 'X' || square[pos] == 'O') cout << "Invalid Move on Board, try again\n";
        else
        {
            square[pos] = (moveNum % 2 == 1) ? 'X' : 'O';
            moveNum++;
        }
        
        board();
        
        win = checkWin();
    }
    
    if (win)
    {
        cout << "Player " << (moveNum + 1) % 2 + 1 << " Wins!\n";
    }
    else
    {
        cout << "Draw!\n";
    }
    
    return 0;
}

bool checkWin()
{
    if ((square[1] == square[2] && square[2] == square[3]) ||
        (square[4] == square[5] && square[5] == square[6]) ||
        (square[7] == square[8] && square[8] == square[9]) ||
        (square[1] == square[4] && square[4] == square[7]) ||
        (square[2] == square[5] && square[5] == square[8]) ||
        (square[3] == square[6] && square[6] == square[9]) ||
        (square[1] == square[5] && square[5] == square[9]) ||
        (square[3] == square[5] && square[5] == square[7]))
    {
        return true;
    }
    return false;
}

void board()
{
    cout << "\n " << square[1] << " | " << square[2] << " | " << square[3] << "  \n";
    cout << "-----------\n";
    
    cout << " " << square[4] << " | " << square[5] << " | " << square[6] << "  \n";
    cout << "-----------\n";
    
    cout << " " << square[7] << " | " << square[8] << " | " << square[9] << "  \n\n";
}
