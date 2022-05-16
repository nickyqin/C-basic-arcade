//
//  totalPurchase.cpp
//  test
//
//  Created by Nicky Qin on 5/16/22.
//

#include "totalPurchase.hpp"

int totalPurchase(int cost) {
    int baseCost = cost, num;
    double totalCost;
    
    cout << "Package Seller!!\n\nDiscounts available.\nPackages desired: \n";
    cin >> num;
    
    if (num <= 0)
    {
        cout << "Invalid input!" << endl;
        return 1;
    }
    
    if (num < 10) totalCost = baseCost * num;
    else if (num >= 10 && num < 50) totalCost = baseCost * num * 0.8;
    else if (num >= 50 && num < 100) totalCost = baseCost * num * 0.7;
    else totalCost = baseCost * num * 0.5;
    
    cout << "Total cost: $" << totalCost << endl;
    
    return 0;
}
