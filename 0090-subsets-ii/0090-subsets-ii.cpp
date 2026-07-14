class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        recurse(nums,ans,curr,0);
        return ans;
    }
    void recurse(vector<int>& nums,vector<vector<int>> &ans,vector<int> &curr,int i){
      
        if(i==nums.size()) {ans.push_back(curr);
        return;}
        curr.push_back(nums[i]);
        recurse(nums,ans,curr,i+1);
        curr.pop_back();
        int j=i;
        while(j<nums.size()&&nums[j]==nums[i]){j++;}
        recurse(nums,ans,curr,j);
    }
};