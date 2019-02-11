#include <unordered_map>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        *duplication = -1;
        if (!CheckValidity(numbers, length)) {
            return false;
        }

        unordered_map<int, int> hashmap;
        for (int i = 0; i < length; ++i) {
            if (hashmap.count(numbers[i])) {
                *duplication = numbers[i];
                return true;
            } else {
                hashmap.insert(make_pair(numbers[i], 1));
            }
        }

        return false;
    }

private:
    // 检查数据的合法性
    bool CheckValidity(int *number, int length) {
        if (number == NULL && length <= 0) {
            return false;
        }

        for (int i = 0; i < length; ++i) {
            if (*number < 0 || *number > length - 1) {
                return false;
            }
        }

        return true;
    }
};