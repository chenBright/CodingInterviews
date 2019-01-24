#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return numbers[0];
        }

        int n = findKth(numbers, 0, len - 1, len / 2);
        if (checkMoerThanHalf(numbers, n)) {
            return n;
        }

        return 0;
    }

private:
    // 在数组中找索引为k的元素
    int findKth(vector<int> &numbers, int low, int high, int k) {
        int index = Partition(numbers, low, high);

        if (index == k) {
            return numbers[k];
        } else if (index < k) {
            return findKth(numbers, index + 1, high, k);
        } else {
            return findKth(numbers, low, index - 1, k);
        }
    }
    int Partition(vector<int> &numbers, int low, int high) {
        int i = low, j = high;
        int pivotNum = numbers[low]; // 基准元素

        while (i < j) {
            // 从后面开始找，找到第一个不大于基准元素的元素
            while (i < j && numbers[j] > pivotNum) {
                --j;
            }
            numbers[i] = numbers[j];

            // 从前面开始找，找到第一个大于基准元素的元素
            while (i < j && numbers[i] <= pivotNum) {
                ++i;
            }
            numbers[j] = numbers[i];
        }
        numbers[i] = pivotNum;
        return i; // 最后的位置 i == j 就是基准元素的最终位置
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