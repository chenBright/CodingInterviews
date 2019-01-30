#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        unordered_map<char, int> cmap;

        for (int i = 0; i < str.length(); ++i) {
            if (cmap.count(str[i])) {
                ++cmap[str[i]];
            } else {
                cmap[str[i]] = 1;
            }
        }

        for (int i = 0; i < str.length(); ++i) {
            if (cmap[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};