class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int s = 0;
        int e = nums.size() - 1;
        int bound = -1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] == target) {
                bound = m; // Record the potential answer
                if (isFirst) {
                    e = m - 1; // Keep searching left for the starting position
                } else {
                    s = m + 1; // Keep searching right for the ending position
                }
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return bound;
    }
};