class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        while (s < e) {
            int m = s + (e - s) / 2;
            long long sum=0;
            for (int i : nums) {
                sum += (i + m - 1) / m;
            }
            if (sum <= threshold) {
                e = m;
            } else {
                s = m + 1;
            }
        }return s;
    }
};