class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        recurse(0,target,candidates,ans,curr);
        return ans;
    }
    void recurse(int i,int &req,vector<int> &candidates, vector<vector<int>> &ans,vector<int> &curr){
        if(req<0) return ;
        if(req==0){
            ans.push_back(curr);
            return;
        }
        for( int j=i;j<candidates.size();j++){
            curr.push_back(candidates[j]);
           req=req-candidates[j];
            recurse(j,req,candidates,ans,curr);
            curr.pop_back();
            req=req+candidates[j];
            
        }
    }
};