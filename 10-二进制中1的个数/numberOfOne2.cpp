class Solution {
public:
     int  NumberOf1(int n) {
        int count = 0;

        if (n < 0) {
            n = -n;
            ++count;
        }

        while (n) {
            // 1前面补n个0，与n做位与运算，n最右位不为1，则结果为0
            if (n & 1) {
                ++count;
            }
            n >>= 1;
        }

        return count;
     }
};