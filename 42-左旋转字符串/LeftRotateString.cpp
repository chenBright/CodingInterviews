#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) {
            return str;
        }

        string res(str);
        int strLength = str.size();
        if (n > strLength) {
            n %= strLength;
        }

        for (int i = 0; i < strLength; ++i) {
            res[i] = str[(n + i) % strLength];
        }

        return res;
    }
};