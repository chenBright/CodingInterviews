#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strNum;

        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            string str = to_string(*it);
            strNum.push_back(str);
        }

        sort(strNum.begin(), strNum.end(), compare);

        string res = "";
        for (vector<string>::iterator it = strNum.begin(); it != strNum.end(); ++it) {
            res += *it;
        }

        return res;
    }

private:
    static bool compare(const string &left, const string &right) {
        string leftRight = left + right;
        string rightLeft = right + left;

        return leftRight < rightLeft;
    }
};