class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurse(0,nums,ans);
        return ans;
    }
    void recurse(int i,vector<int>& nums, vector<vector<int>> &ans){
        if(i>nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            recurse(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
};