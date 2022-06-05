//
//  finalGrade.cpp
//  test
//
//  Created by Nicky Qin on 5/16/22.
//

#include "finalGrade.hpp"

char passTest() {
    double grade;
    
    cout << "Enter Final Grade: \n";
    cin >> grade;
    
    if (grade >= 93) {
        cout << "Grade is A\n";
        return 'A';
    }
    else if (grade < 93 && grade >= 80) {
        cout << "Grade is B\n";
        return 'B';
    }
    else if (grade < 80 && grade >= 70) {
        cout << "Grade is C\n";
        return 'C';
    }
    else if (grade < 70 && grade > 0) {
        cout << "Grade is F\n";
        return 'F';
    }
    else {
        cout << "Invalid input. Please enter a number between 0 and 100\n";
    }
    
    return ' ';
}
