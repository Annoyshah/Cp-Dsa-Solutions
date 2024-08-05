#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    int no_tax_house, double_tax_house, discount_tax_house;
    cin >> no_tax_house >> double_tax_house >> discount_tax_house;
    
    vector<pair<int, double>> houses(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> houses[i].first >> houses[i].second;
    }
    
    double total_tax = 0.0;
    
    for (int i = 0; i < n; ++i) {
        int house_number = houses[i].first;
        double income = houses[i].second;
        double tax = 0.0;
        
        if (income < 50000) {
            tax = income * 0.10;
        } else if (income <= 100000) {
            tax = income * 0.20;
        } else {
            tax = income * 0.30;
        }
        
        if (house_number == no_tax_house) {
            tax = 0.0;
        } else if (house_number == double_tax_house) {
            tax *= 2;
        } else if (house_number == discount_tax_house) {
            tax *= 0.10;
        }
        
        total_tax += tax;
    }
    
    cout << total_tax << endl;
    
    return 0;
}
