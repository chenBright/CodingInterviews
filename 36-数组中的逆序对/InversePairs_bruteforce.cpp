#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        for (int i = 0; i < data.size() - 1; ++i) {
            for (int j =   i + 1; j < data.size(); ++j) {
                if (data[i] > data[j]) {
                    ++count;
                }
            }
        }

        return count;
    }
};