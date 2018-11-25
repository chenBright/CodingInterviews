class Solution {
public:
    int rectCover(int number) {
        if (number == 0) {
            return 0;
        }
        if (number == 1) {
            return 1;
        }

        int one = 1;
        int two = 1;
        int result;

        for (int i = 2; i <= number; ++i) {
            result = one + two;
            one = two;
            two = result;
        }

        return result;
    }
};