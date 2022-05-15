//
//  main.cpp
//  test
//
//  Created by Nicky Qin on 5/15/22.
//

#include <iostream>

using namespace std;

int main() {
    // insert code here...
    int ang1, ang2, ang3;
    
    cout << "Triangle Tester\n\n" << "Triangle angle one: " << endl;
    cin >> ang1;
    
    cout << "Angle two: " << endl;
    cin >> ang2;
    
    cout << "Angle three: " << endl;
    cin >> ang3;
    
    if (ang1 + ang2 + ang3 == 180)
    {
        cout << "Valid Triangle!" << endl;
    }
    else
    {
        cout << "Invalid Triangle!" << endl;
    }
    
    return 0;
}
