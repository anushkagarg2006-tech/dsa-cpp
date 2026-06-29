class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // max dhundo
        sort(piles.begin(), piles.end());
        int right = piles.back();
        int left = 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            // kitne ghante lagenge is speed pe
            long long hours = 0;
            for (int p : piles)
                hours += (p + mid - 1) / mid;
            
            if (hours <= h)
                right = mid;    // aur slow try karo
            else
                left = mid + 1; // aur fast karo
        }
        
        return left;
    }
};