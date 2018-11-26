#include <bitset>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         bitset<32> bit(n);
         return bit.count();
     }
};