class Base;
Base *parray[2];

class Base {
public:
    virtual unsigned int sum(unsigned int n) {
        // 递归的终止
        return 0;
    }
};

class Derive : public Base {
public:
    virtual unsigned int sum(unsigned int n) {
        // !!n两次非运算, 从而将n转换为bool类型, 来选择函数
        // sum(n) = sum(n - 1) + n 则是递归公式
        return parray[!!n]->sum(n - 1) + n;
    }
};

class Solution {
public:
    int Sum_Solution(int n) {
        Base a;
        Derive b;

        parray[0] = &a;
        parray[1] = &b;

        return parray[1]->sum(n);
    }
};