#include <string>
using namespace std;

class Solution {
public:
    Solution() {
        str = "";
        memset(count, 0, sizeof(count));
    }
    //Insert one char from stringstream
    void Insert(char ch) {
         str += ch;
         ++count[(int)ch];
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (int i = 0; i < str.size(); ++i) {
            char ch = str[i];
            if (count[(int)ch] == 1) {
                return ch;
            }
        }

        return '#';
    }

private:
    string str;
    int count[256];
};