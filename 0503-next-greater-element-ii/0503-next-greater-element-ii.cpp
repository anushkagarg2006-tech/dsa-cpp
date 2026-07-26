class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        // Iterate through the array twice using modulo indexing
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            // Only push indices during the first pass
            if (i < n) {
                s.push(i);
            }
        }

        return ans;
    }
};