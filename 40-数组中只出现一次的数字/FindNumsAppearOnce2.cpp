#include <vector>
using namespace std;

#define INT_SIZE (sizeof(int) * 8)
#define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        *num1 = *num2 = 0;
        if(data.size( ) < 2) {
            return ;
        }
        int XOR = data[0];
        for(int i = 1; i < data.size( ); i++) {
            XOR ^= data[i];
        }

        ///  查找到1的位置
        int index = 0, temp = 1;
        for(; index < INT_SIZE; index++) {
            if((XOR & temp) == temp)
            {
                break;
            }
            temp <<= 1;
        }
        if(index == INT_SIZE) {
            return;
        }

        //  于是我们知道那两个只出现一次的数字, 第index位必然不相同
        //  因此 我们将数组划分成两部分
        //  一部分index位是0
        //  另外一部分index位是1
        *num1 = *num2 = 0;// 也可以等于XOR
        for(int i = 0; i < data.size( ); i++) {
            if(IS_BIT(data[i], index) == 1) {
                *num1 ^= data[i];
            }
            else {
                *num2 ^= data[i];
            }
        }
    }
};