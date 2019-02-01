#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        if (!data.empty()) {
            int first = binarySearch_firstK(data, 0, data.size() - 1, k);
            int last = binarySearch_firstK(data, 0, data.size() - 1, k);

            if (first != -1 && last != -1) {
                count = last - first + 1;
            }
        }

        return count;
    }

private:
    // 二分查找第一个等于k的元素
    int binarySearch_firstK(vector<int> &data, int low, int high, int k) {
        if (low > high) {
            return -1;
        }        

        int mid = (low + high) / 2;
        if (data[mid] == k) {
            if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
                return mid;
            } else {
                high = mid - 1;
            }
        } else if (data[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        return binarySearch_firstK(data, low, high, k);
    }

    // 二分查找最后一个等于k的元素
    int binarySearch_lastK(vector<int> &data, int low, int high, int k) {
        if (low > high) {
            return -1;
        }        

        int mid = (low + high) / 2;
        if (data[mid] == k) {
            if ((mid < data.size() - 1 && data[mid + 1] != k) || mid == data.size() - 1) {
                return mid;
            } else {
                low = mid + 1;
            }
        } else if (data[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        return binarySearch_lastK(data, low, high, k);
    }
};