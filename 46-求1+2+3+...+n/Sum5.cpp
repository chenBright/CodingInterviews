typedef int (*func)(int);

// 递归的终止函数
int Temiator(int n) {
    return 0;
}

// 递归函数, 选择函数进行递归
int Recursion(int n) {
    static func pf[2] = {Temiator, Recursion};

    return n + pf[!!n](n - 1);
}

class Solution {
public:
    int Sum_Solution(int n) {
        return Recursion(n);
    }
};