class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;   // shuru mein khud ka parent

        int maxLen = 1, lastIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        // Traceback
        vector<int> ans;
        ans.push_back(nums[lastIdx]);
        while (parent[lastIdx] != lastIdx) {
            lastIdx = parent[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};