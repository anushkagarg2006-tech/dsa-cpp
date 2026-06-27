class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         int s = 0;
        int e = arr.size() - 1;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (arr[m] < arr[m + 1]) {
                s = m + 1;
            } else {
                if (m == 0)
                    break;
                else if (arr[m] < arr[m - 1]) {
                    e = m-1;
                } else {
                    return m;
                }
            }
        }
        return s;
    }
};