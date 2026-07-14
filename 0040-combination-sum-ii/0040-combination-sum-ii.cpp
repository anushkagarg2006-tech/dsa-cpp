class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        int prev=0;
        recurse(0,prev,target,candidates,ans,curr);
        return ans;
    }
    void recurse(int i,int &prev,int &req,vector<int> &candidates, vector<vector<int>> &ans,vector<int> &curr){
        if(req<0) return ;
        if(req==0){
            ans.push_back(curr);
            return;
        }
        for( int j=i;j<candidates.size();j++){
            if(prev==candidates[j]) continue;
            curr.push_back(candidates[j]);
           req=req-candidates[j];
            recurse(j+1,prev,req,candidates,ans,curr);
            curr.pop_back();
            req=req+candidates[j];
            prev=candidates[j];
            
        }
    }
};