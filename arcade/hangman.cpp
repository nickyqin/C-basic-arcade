//
//  hangman.cpp
//  test
//
//  Created by Nicky Qin on 5/19/22.
//

// HANGMAN
// Create hangman
// Get random word, create string / array of underscores
// Listen for character input from user
// CHECK IF CHAR ALREADY USED BEFORE
// If character is correct, show correct letters and positions in console
// If character is incorrect, remove a body part
// Loop until body parts are out or word is correct

// randomWord()
// hangman() create picture, loop call listenForChar()
// listenForChar()

// tomorrow 5/19/22: make it truly random (done), move to separate file, exit program only on certain char, pass by ref practice for arrays and vector<>


#include "hangman.hpp"

// **** function declarations
void hangman();
int listenForChar();
string randomWord();

// **** global variables
string bodyParts[6] = {"[_]", "|", "/", "\\", "/", "\\"};

int attemptNum = 0;
int correctLetters = 0;
string word = "";
vector<string> wordCharacters;
vector<string> usedChars;
vector<string> wrongChars;




// **** FUNCTIONS ****

// **** START A GAME
void hangmanSession()
{
    hangman();
    // keep looping until lose all lives or finish word
    while (attemptNum < 6 && correctLetters < word.length())
    {
        listenForChar();
        hangman();
    }
    
    // game over print statements
    if (attemptNum == 6)
    {
        cout << "Out of lives! Word was: " << word << "\n";
    }
    else
    {
        cout << "You won!\n";
    }
}


// **** DRAW HANGMAN AND WORD
void hangman()
{
    // draw hangman
    cout << "-------------\n";
    cout << "|           |\n";
    cout << "|          " << bodyParts[0] << "\n";
    cout << "|          " << bodyParts[2] << bodyParts[1] << bodyParts[3] << "\n";
    cout << "|          " << bodyParts[4] << " " << bodyParts[5] << "\n";
    cout << "|\n";
    cout << "----   ";
    
    // if no word yet
    if (word.length() == 0)
    {
        word = randomWord();
        
        // fill wordCharacters array with _'s
        for (int i = 0; i < word.length(); i++)
        {
            wordCharacters.push_back("_");
            cout << wordCharacters[0] << " ";
        }
        cout << "\n";
    }
    else
    {
        // print all characters in wordCharacters array
        for (int i = 0; i < word.length(); i++)
        {
            cout << wordCharacters[i] << " ";
        }
        cout << "\n";
    }
    
    // print characters already tried
    if (wrongChars.size() > 0)
    {
        cout << "Tried: ";
        for (int i = 0; i < wrongChars.size(); i++)
        {
            cout << wrongChars[i] << " ";
        }
        cout << "\n";
    }
}


// **** LISTEN FOR NEXT INPUT LETTER
int listenForChar()
{
    string letter;
    bool exists = false;
    
    cout << "Enter one character: ";
    cin >> letter;
    
    // make sure only 1 letter
    if (letter.length() != 1)
    {
        cout << "Please enter 1 letter!\n";
        return 1;
    }
    
    // make sure new letter
    for (int i = 0; i < usedChars.size(); i++)
    {
        if (letter == usedChars[i])
        {
            cout << "Already tried letter " << letter << "\n";
            return 2;
        }
    }
    
    // compare letter to word
    for (int i = 0; i < word.length(); i++)
    {
        if (word.substr(i, 1) == letter)
        {
            wordCharacters.at(i) = letter;
            correctLetters++;
            exists = true;
        }
    }
    
    // if wrong letter
    if (!exists)
    {
        bodyParts[5 - attemptNum] = ' ';
        attemptNum++;
        wrongChars.push_back(letter);
    }
    
    usedChars.push_back(letter);
    
    return 0;
}

// **** SELECT A RANDOM WORD
string randomWord()
{
    // why is rand() givng same number every time
    string line = "";
    
    while (line.length() < 5)
    {
        int i = 0;
        
        srand(time(0));
        int randomNum = rand() % 10000;
        
        ifstream myfile ("/Users/nickyqin/Desktop/projects/test/test/wordlist10000.txt");
        while ((getline(myfile, line)) && i < randomNum)
        {
            i++;
        }
        myfile.close();
    }
    
    return line;
}
