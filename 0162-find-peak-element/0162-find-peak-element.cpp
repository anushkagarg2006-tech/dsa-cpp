class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            int m = s + (e - s) / 2;
            if (nums[m] < nums[m + 1]) {
                s = m + 1;
            } else {
                if (m == 0)
                    break;
                else if (nums[m] < nums[m - 1]) {
                    e = m-1;
                } else {
                    return m;
                }
            }
        }
        return s;
    }
};