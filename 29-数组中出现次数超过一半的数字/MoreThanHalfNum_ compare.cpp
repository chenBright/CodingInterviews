#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        } else if (numbers.size() == 1) {
            return numbers[0];
        }

        int num = compare(numbers);
        return checkMoerThanHalf(numbers, num) ? num : 0;
    }

private:
    // 将数组数字两两分成一组。如果两者相等，则只舍去其中一个数字；如果不等，两者都舍去。
    // 得到新的数组后，循环执行上述步骤，直到数组元素个数不大于3位置
    int compare(vector<int> numbers) {
        int len = numbers.size();
        vector<int> temp;
        while (len > 3) {
            for (int i = 0; i <= len / 2 - 1; ++i) {
                if (numbers[i] == numbers[len / 2]) {
                    temp.push_back(numbers[i]);
                }
            }
            if (len % 2 == 1) {
                temp.push_back(numbers[len - 1]);
            }

            numbers.clear();
            numbers.swap(temp);
            len = numbers.size();
        }
        
        if (len == 1) {
            return numbers[0];
        } else if (len == 2) {
            if (numbers[0] == numbers[1]) {
                return numbers[0];
            } else {
                return 0;
            }
        } else if (len == 3) {
            if (numbers[0] == numbers[1] || numbers[0] == numbers[2]) {
                return numbers[0];
            } else if (numbers[1] == numbers[2]) {
                return numbers[1];
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    // 检查number的个数是否超过数组个数的一半
    bool checkMoerThanHalf(vector<int> numbers, int number) {
        int count = 0;
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > numbers.size() / 2 ? true : false;
    }
};