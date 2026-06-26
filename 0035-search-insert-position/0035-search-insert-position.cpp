class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int m=s+(e-s)/2;
        if(nums[s]>=target) return 0;
        while(s<=e){
            int m=s+(e-s)/2;
            if(s==e&&target!=nums[m])
            if(nums[m]<target) return m+1;
            else{return m;}
            
            if(target==nums[m]) return m;
            else if( target<nums[m]){ e=m-1;}
            else{ s=m+1;}
        }
        return s;
    }
};