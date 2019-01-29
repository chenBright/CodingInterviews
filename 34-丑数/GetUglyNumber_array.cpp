#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);

        int indexOf2 = 0;
        int indexOf3 = 0;
        int indexOf5 = 0;

        while (uglyNumbers.size() <= index) {
            int num = min(uglyNumbers[indexOf2] * 2, uglyNumbers[indexOf3] * 3, uglyNumbers[indexOf5] * 5);
            uglyNumbers.push_back(num);

            // 将产生这个丑数的index*向后挪一位
            // 用三个独立的if判断，因为可能有两个最小值，这时都要挪动
            if (num == uglyNumbers[indexOf2] * 2) {
                ++indexOf2;
            } 
            if (num == uglyNumbers[indexOf3] * 3) {
                ++indexOf3;
            } 
            if (num == uglyNumbers[indexOf5] * 5) {
                ++indexOf5;
            }
        }

        return uglyNumbers[index - 1];
    }

private:
    int min(int a, int b, int c) {
        int min = a < b ? a : b;
        if (c < min) {
            min = c;
        }

        return min;
    }
};