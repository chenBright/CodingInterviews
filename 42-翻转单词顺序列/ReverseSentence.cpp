#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) {
            return str;
        }

        Reverse(str, 0, str.size() - 1);

        int left = 0;
        int right = 0;
        while ((right <= str.size())) {
            //  当遇见空格的时候说明找到了一个单词
            //  当走到字符串的最后一个位置, 那么前面如果不是空格, 那么最后也会有一个单词
            if((str[right] == ' ') || (right == str.size() && str[right - 1] != ' ')) {
                Reverse(str, left, right - 1);
                left = right + 1;
            }
            right++;
        }

        return str;
    }

private:
    void Reverse(string &str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[right--]);
        }
    }
};