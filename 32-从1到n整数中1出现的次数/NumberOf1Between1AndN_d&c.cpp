#include <cmath>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        return CountOne(n);
    }

private:
    int CountOne(int n) {
        long count = 0;

        if (n == 0) {
            return 0;
        } else if (n > 1 && n < 10) {
            count = 1;
        } else {
            // 计算n的位数
            long highest = n; // 表示最高位的数字
            int bit = 0;
            // 循环结束时, bit表示n的位数, 而highest是其最高位的数字
            while (highest >= 10) {
                highest = highest / 10;
                ++bit;
            }

            int weight = pow(10, bit); // 代表最高位的权重，即最高位一个1代表的大小

            if (highest == 1) {
                count = CountOne(weight - 1) + CountOne(n - weight) + (n - weight + 1);
            } else {
                count = highest * CountOne(weight - 1) + CountOne(n - highest * weight) + weight;
            }
        }

        return count;
    }
};