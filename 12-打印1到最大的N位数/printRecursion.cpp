#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    void PrintToMaxOfNDigits(int n) {
        if (n < 0) {
            return;
        }

        char *number = new char[n + 1];
        number[n] = '\0';

        for (int i = 0; i < 10; ++i) {
            number[0] = i + '0';
            PrintToMaxOfNDigitsRecursively(number, n, 0);
        }

        delete []number;
    }

private:
    void PrintToMaxOfNDigitsRecursively(char *number, int length, int index) {
        if (index == length) {
            PrintNumber(number);
            return;
        }

        for (int i = 0; i < 10; ++i) {
            number[index] = i + '0';
            PrintToMaxOfNDigitsRecursively(number, length, index + 1);
        }
    }

    void PrintNumber(char *number) {
        int nLength = strlen(number);
        int i;
        for (i = 0; number[i] == '0' && i < nLength; ++i); // 从左到右遍历，找到第一个不为0的数字
        // 全为0
        if (i == nLength) {
            return;
        }

        while (i++ < nLength) {
            cout << number[i];
        }
        cout << '\t';
    }
};