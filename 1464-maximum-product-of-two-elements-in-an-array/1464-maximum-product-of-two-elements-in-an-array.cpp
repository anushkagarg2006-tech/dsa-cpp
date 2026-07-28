class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxi1=0;
        // int maxi2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(maxi1==0){ maxi1=nums[i];}
        //     else if(maxi2==0){
        //         maxi2 =nums[i];
        //     }else{
        //         if(nums[i]>maxi1)
        //     
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);

        }
    
};