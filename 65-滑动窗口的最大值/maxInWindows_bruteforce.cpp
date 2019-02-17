#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;

        if (num.empty() || size == 0) {
            return res;
        }

        int length = num.size();

        for (int i = 0; i <= (int) (length - size); ++i) {
            int max = num[i]; // i + 0
            for (int j = 1; j < size && i + j < length; ++j) {
                int index = i + j;
                if (num[index] > max) {
                    max = num[index];
                }
            }
            res.push_back(max);
        }

        return res;
    }
};