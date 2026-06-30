class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            long long sum = 0;
            int dayno = 1;  // FIX: pehla din already shuru hai
            
            for (int i : weights) {
                if (sum + i > mid) {   // FIX: capacity cross ho rahi hai
                    dayno++;
                    sum = 0;
                }
                sum += i;
            }
            
            if (dayno <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};