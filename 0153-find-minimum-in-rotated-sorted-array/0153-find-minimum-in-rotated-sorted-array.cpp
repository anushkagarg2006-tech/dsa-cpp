// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int s=0;
//         int e=nums.size()-1;
//         while(s<=e){
//             int m=s+(e-s)/2;
//             if(m==0) return nums[m];
//             if(nums[m-1]>nums[m]&&m!=0){
//                 return nums[m];
//             }
//             if(nums[m]<nums[e]){
//                 e=m-1;
//             }else if(nums[m]>nums[e]){
//                 s=m+1;
//             }else{return nums[m];}

//             }

//         return -1;
//     }
// };
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        // Change 1: Loop tab tak chalao jab tak s < e hai. 
        // Agar s <= e rakhoge, toh [2, 1] jaise cases mein infinite loop ya galat bounds check honge.
        while (s < e) {
            int m = s + (e - s) / 2;

            // Change 2: Ye donon line hata do kyunki ye `m==0` par galat return kar rahi thi.
            // if(m==0) return nums[m];
            // if(nums[m-1]>nums[m]&&m!=0){ return nums[m]; }

            if (nums[m] < nums[e]) {
                // Change 3: e = m - 1 nahi hoga, e = m hoga.
                // Kyunki ho sakta hai 'm' khud hi sabse chhota element (minimum) ho!
                // Agar m - 1 kar doge toh minimum element skip ho jayega.
                e = m; 
            } else if (nums[m] > nums[e]) {
                s = m + 1; // Ye bilkul sahi hai
            } 
            // 'else' block ki zaroorat nahi hai kyunki elements unique hain.
        }

        // Jab s aur e ek hi jagah milenge (s == e), wahi hamara minimum element hoga.
        return nums[s];
    }
};