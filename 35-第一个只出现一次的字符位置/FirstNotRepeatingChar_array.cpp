#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        // 简单的哈希表
        const int tableSize = 256;
        int count[tableSize] = {0};

        for (int i = 0; i < str.length(); ++i) {
            ++count[str[i]];
        }

        for (int i = 0; i < str.length(); ++i) {
            if (count[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};