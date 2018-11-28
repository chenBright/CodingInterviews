#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    void PrintToMaxOfNDigits(int n) {
        int max = pow(10, n);
        for (int i = 0; i < max; ++i) {
            cout << i << endl;
        }
    }
};