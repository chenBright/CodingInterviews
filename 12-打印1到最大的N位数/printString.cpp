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
        memset(number, '0', n);
        number[n] = '\0';
        
        while (!Increment(number)) {
            printNumber(number);
        }

        delete []number;
    }

private:
    bool Increment(char *number) {
        bool isOverflow = false; // 是否溢出
        int takeOver = 0; // 进位
        int nLength = strlen(number);

        for (int i = nLength - 1; i >= 0; --i) {
            int nSum = number[i] - '0' + takeOver;
            // 个位加1
            if (i == nLength - 1) {
                ++nSum;
            }

            if (nSum >= 10) {
                if (i == 0) {
                    isOverflow = true;
                    break;
                }

                nSum -= 10;
                number[i] = nSum + '0';
                takeOver = 1;
            } else {
                number[i] = nSum + '0';
                break;
            }
        }

        return isOverflow;
    }

    void printNumber(char *number) {
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