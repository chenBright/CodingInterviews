#include <vector>
using namespace std;

#define INT_SIZE (sizeof(int) * 8)
#define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        *num1 = *num2 = 0;
        if(data.size() < 2) {
            return ;
        }
        int XOR = data[0];
        for(int i = 1; i < data.size( ); i++) {
            XOR ^= data[i];
        }


        ///  查找到1的位置
        int flag = XOR & (-XOR);
        *num1 = *num2 = XOR;// 也可以等于XOR
        for(int i = 0; i < data.size( ); i++) {
            if((data[i] & flag) == flag) {
                *num1 ^= data[i];
            }
            else {
                *num2 ^= data[i];
            }
        }
    }
};