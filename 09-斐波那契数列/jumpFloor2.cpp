class Solution {
public:
    int jumpFloor(int number) {
        int one = 1, two = 2, result;
        if (number <= 2) {
            return number;
        }
        for (int i = 3; i <= number; ++i) {
            result = one + two;
            one = two;
            two = result;
        }

        return result;
    }
};