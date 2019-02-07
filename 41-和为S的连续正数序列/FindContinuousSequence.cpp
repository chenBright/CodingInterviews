#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;

        if (sum < 3) {
            return res;
        }

        int small = 1;
        int big = 2;
        int s = small + big;
        while (small <= sum / 2) {
            if (s == sum) {
                vector<int> sequence;
                for (int i = small; i <= big; ++i) {
                    sequence.push_back(i);
                }
                res.push_back(sequence);
                
                ++big;
                s += big;
            } else if (s < sum) {
                ++big;
                s += big;
            } else {
                s -= small;
                ++small;
            }
        }

        return res;
    }
};