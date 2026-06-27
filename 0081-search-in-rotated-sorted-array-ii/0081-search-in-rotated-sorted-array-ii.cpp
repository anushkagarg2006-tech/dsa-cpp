class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), ll = 0, ul = n - 1, mid = 0;
        while(ll <= ul){
            mid = (ll + ul) >> 1;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[ll] && nums[mid] == nums[ul]){//only this if changes
                ll++;
                ul--;
            }
            else if(nums[ll] <= nums[mid]){
                if(target >= nums[ll] && target < nums[mid])
                    ul = mid - 1;
                else
                    ll = mid + 1;
            }
            else{
                if(target <= nums[ul] && target > nums[mid])
                    ll = mid + 1;
                else
                    ul = mid - 1;
            }
        }
        return false;
    }
};