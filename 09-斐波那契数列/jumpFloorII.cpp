// f(n) = 2 * f(n - 1), f(1) = 1
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 1) {
            return 1;
        }

        return 2 * jumpFloorII(number - 1);
    }
};