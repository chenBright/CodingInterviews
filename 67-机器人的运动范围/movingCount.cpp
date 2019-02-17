class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        bool *flag = new bool[rows * cols];
        for(int i = 0; i < rows * cols; ++i) {
            flag[i] = false;
        }
        int count = moving(threshold, rows, cols, 0, 0, flag);

        return count; 
    }

private:
     int moving(int threshold, int rows, int cols, int i, int j, bool* flag) {
        int count = 0;
        if(i >= 0 && i < rows && j >= 0 && j < cols && getsum(i) + getsum(j) <= threshold && flag[i * cols + j] == false) {
            flag[i * cols + j] = true;
            count = 1 + moving(threshold, rows, cols, i + 1, j, flag)
                + moving(threshold, rows, cols, i - 1, j, flag)
                + moving(threshold, rows, cols, i , j - 1, flag)
                + moving(threshold, rows, cols, i, j + 1, flag);
        }

        return count;
    }
    
    int getsum(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
              
        }

        return sum;
    }
};