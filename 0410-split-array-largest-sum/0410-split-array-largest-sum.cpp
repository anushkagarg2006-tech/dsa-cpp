class Solution {
public:
    bool isright(int mid, vector<int>& nums, int k, int& answer) {
        int count = 1;
        int summ=0;
        for (int i = 0; i < nums.size(); i++) {
            if(summ+nums[i]<=mid){
                summ+=nums[i];
            }else{
                count++;
                summ=nums[i];
            }
        }if(count<=k){
            answer=mid;
            return true;
        }else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        if(k==1){
            return right;
        }
        int answer = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isright(mid, nums, k, answer)) {
                right = mid;

            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};