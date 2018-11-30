#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() <= 1) {
            return;
        }
        vector<int> arrayTemp;
        vector<int>::iterator ib1, ie1;
        ib1 = array.begin();

        while (ib1 != array.end()) {
            if (*ib1 % 2 == 0) {
                arrayTemp.push_back(*ib1);
                ib1 = array.erase(ib1);
            } else {
                ++ib1;
            }
        }

        vector<int>::iterator ib2, ie2;
        ib2 = arrayTemp.begin();
        ie2 = arrayTemp.end();

        while (ib2 != ie2) {
            array.push_back(*ib2);
            ++ib2;
        }
    }
};