class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> curr;
        recurse(0, n, candidates, ans, curr, k);
        return ans;
    }
    void recurse(int i, int& req, vector<int>& candidates,
                 vector<vector<int>>& ans, vector<int>& curr, int k) {
        if (req < 0)
            return;
        if (req == 0&&curr.size()==k) {
            ans.push_back(curr);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            curr.push_back(candidates[j]);
            req = req - candidates[j];
            recurse(j+1, req, candidates, ans, curr, k);
            curr.pop_back();
            req = req + candidates[j];
        }}
    };