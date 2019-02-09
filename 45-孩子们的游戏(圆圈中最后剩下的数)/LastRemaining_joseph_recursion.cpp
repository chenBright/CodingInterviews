#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n < 1 || m < 1) {
            return -1;
        } else if (n == 1) {
            return 0;
        } else {
            return (LastRemaining_Solution(n - 1, m) + m) % n;
        }
    }
};