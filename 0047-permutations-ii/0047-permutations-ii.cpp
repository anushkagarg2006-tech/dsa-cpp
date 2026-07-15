class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
    
        recurse(0,nums,ans);
        return ans;
    }
    void recurse(int i,vector<int>& nums, vector<vector<int>> &ans){
        if(i>nums.size()-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> lookup;
        for(int j=i;j<nums.size();j++){
           if (lookup.count(nums[j])) {
                continue;
            }
            lookup.insert(nums[j]);
            swap(nums[i],nums[j]);
            recurse(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
};