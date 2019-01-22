#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) {
            return res;
        }

        sort(str.begin(), str.end());

        do {
            res.push_back(str);
        } while (next_permutation(str.begin(), str.end()));

        return res;
    }
};