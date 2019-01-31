#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) {
            return 0;
        }

        vector<int> temp(data.size());
        // 牛客网上的题目要求，结果对1000000007取模
        return mergeSort(data, 0 , data.size() - 1, temp) % 1000000007;
    }

private:
    // 归并排序
    // temp使用引用，因为当测试用例很大的时候，每次递归都创建局部temp，都占用非常多内存
    long long mergeSort(vector<int> &data, int low, int high, vector<int> &temp) {
        long long count = 0; 
        if (low >= high) {
            return count;
        }

        int mid = (low + high) / 2;
        count += mergeSort(data, low, mid, temp);
        count += mergeSort(data, mid + 1, high, temp);

        int left = low;
        int right = mid + 1;
        int tempIndex = low;
        while (left <= mid && right <= high) {
            if (data[left] > data[right]) { // 左半边所有元素都与当前右半边元素构成逆序对
                count += mid - left + 1;
                temp[tempIndex++] = data[right++]; // 将小的那一个放入到临时数组中去
            } else { // 不构成逆序对
                temp[tempIndex++] = data[left++]; // 将小的那一个放入到临时数组中去
            }
        }

        while (left <= mid) {  // 左半边数组中还有元素未放入临时数组
            temp[tempIndex++] = data[left++];
        }
        while (right <= high) { // 右半边数组中还有元素未放入临时数组
            temp[tempIndex++] = data[right++];
        }

        for (int i = low; i <= high; ++i) {
            data[i] = temp[i];
        }

        return count;
    }
};