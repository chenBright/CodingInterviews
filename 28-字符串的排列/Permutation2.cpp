#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty()) {
            return res;
        }
        Permutation(str, 0);

        sort(res.begin(), res.end());
        return res;
    }

private:
    vector<string> res;
    void Permutation(string str, int begin) {
        if (str[begin] == '\0') {
            res.push_back(str);
        } else {
            for (int i = begin; i < str.length(); ++i) {
                if (!hasDuplicate(str, begin, i)) {
                    swap(str[begin], str[i]);
                    Permutation(str, begin + 1);
                    swap(str[begin], str[i]);                    
                }
            }
        }
    }

    bool hasDuplicate(string str, int begin, int end) const {
        for (int i = begin; i < end; ++i) {
            if (str[i] == str[end]) {
                return true;
            }
        }

        return false;
    }
};