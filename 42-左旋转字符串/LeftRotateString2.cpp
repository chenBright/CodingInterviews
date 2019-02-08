#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) {
            return str;
        }
        int strLength = str.size();
        n = n % strLength;
        str += str;

        return str.substr(n, strLength);
    }
};