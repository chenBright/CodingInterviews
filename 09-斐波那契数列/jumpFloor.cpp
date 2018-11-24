// 效率很低，提交oj，超时
class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) {
            return 0;
        }
        if (number == 1) {
            return 1;
        }

        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};