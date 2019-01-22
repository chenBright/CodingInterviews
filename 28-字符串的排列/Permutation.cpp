#include <vector>
#include <string>
using namespace std;

// 此方法不能AC，因为存在重复的排列
class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty()) {
            return res;
        }
        Permutation("", str);

        return res;
    }

private:
    vector<string> res;
    void Permutation(string prefix, string str) {
        if (str.empty()) {
            res.push_back(prefix);
        } else {
            // 依次从字符串中取出一个字符作为最终排列的第一个字符，对剩余字符组成的字符串生成全排列
            for (int i = 0; i < str.length(); ++i) {
                Permutation(prefix + str[i], str.substr(0, i) + str.substr(i + 1, str.length()));
            }
        }
    }
};