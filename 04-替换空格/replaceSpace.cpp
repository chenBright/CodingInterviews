class Solution {
public:
	void replaceSpace(char *str,int length) {
        int indexLen = length - 1;
        // 从后往前遍历
        for (int i = length - 1; i >= 0; --i) {
            if (str[i] == ' ') {
                indexLen += 2; // 从空格变成%20长度增加了2

                int j;
                for (j = indexLen; j > i + 2; --j) {
                    str[j] = str[j - 2];
                }
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
        str[indexLen + 1] = '\0';
	}
};