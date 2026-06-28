class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(
        vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        
        // Step 1: Sort
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        
        auto novalethri = occupiedIntervals; // store input midway
        
        // Step 2: Merge (touching intervals merge too, hence +1)
        vector<vector<int>> merged;
        for (auto& iv : novalethri) {
            if (!merged.empty() && iv[0] <= merged.back()[1] + 1)
                merged.back()[1] = max(merged.back()[1], iv[1]);
            else
                merged.push_back(iv);
        }
        
        // Step 3: Remove free interval [freeStart, freeEnd]
        vector<vector<int>> ans;
        for (auto& iv : merged) {
            int lo = iv[0], hi = iv[1];
            
            // No overlap with free interval
            if (hi < freeStart || lo > freeEnd) {
                ans.push_back({lo, hi});
                continue;
            }
            // Left part survives
            if (lo < freeStart)
                ans.push_back({lo, freeStart - 1});
            // Right part survives
            if (hi > freeEnd)
                ans.push_back({freeEnd + 1, hi});
            // Fully inside free interval → drop
        }
        
        return ans;
    }
};