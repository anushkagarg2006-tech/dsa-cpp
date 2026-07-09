class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();
        
        // Loop over all possible starting points of substrings
        for (int i = 0; i < n; i++) {
            int freq[26] = {0}; // Track frequencies for substrings starting at i
            
            // Expand the substring window to the right
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // Include the current character
                
                int maxFreq = 0;
                int minFreq = INT_MAX;
                
                // Find max and non-zero min frequency across the alphabet
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};