class Solution {
public:
    int Sum_Solution(int n) {
        res = 0;
        return (MultiRecursion(n, n + 1) >> 1);
    }

private:
    int res;
    int MultiRecursion(int a, int b) {
        a && MultiRecursion(a >> 1, b << 1);
        (a & 1) && (res += b);

        return res;
    }
};