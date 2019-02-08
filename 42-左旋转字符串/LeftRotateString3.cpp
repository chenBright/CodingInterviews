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
        
        Reverse(str, 0, n - 1);
        Reverse(str, n, strLength - 1);
        Reverse(str, 0, strLength - 1);

        return str;
    }

private:
    void Reverse(string &str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }
};