class Solution {
public:
    int Add(int num1, int num2) {
        __asm__ __volatile__
        (
            "addl %1,%0;\n"
            : "=m"(num1)
            : "r"(num2), "m"(num1)
        );

        return num1;
    }
};