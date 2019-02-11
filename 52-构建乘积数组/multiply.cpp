#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> res(len);
        for (int i = 0, temp = 1; i < len; ++i) {
            res[i] = temp;
            temp *= A[i];
        }

        for (int j = len - 1, temp = 1; j >= 0; --j) {
            res[j] *= temp;
            temp *= A[j];
        }

        return res;
    }
};