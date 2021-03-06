class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len = length;

        // 先统计空格的总数 => 确定替换后的字符串的长度
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') {
                len += 2; // 从空格变成%20长度增加了2
            }
        }

        // 从后向前遍历替换
        for (int i = length - 1, j = len - 1; i >= 0 && j>= 0; --i) {
            if (str[i] != ' ') { // 不是空格，直接复制
                str[j--] = str[i];
            } else { // 空格，移位
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
        str[len] = '\0';
	}
};