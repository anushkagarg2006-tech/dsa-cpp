class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int m=s+(e-s)/2;
            
            if(m%2==0){
                if(nums[m+1]==nums[m]){
                    s=m+1;
                }else{e=m;}
            }else{
                if(nums[m+1]==nums[m]){
                    e=m-1;
                }else{s=m+1;}
            }
        }return nums[s];

    }
};