class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int start = 0;     // Longest palindrome ka starting index track karne ke liye
        int maxLen = 1;    // Longest palindrome ki length track karne ke liye
        
        for (int i = 0; i < s.length(); i++) {
            
            // 1. Odd length palindrome check karein (jaise "aba" jiska center 'b' hai)
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;   // piche jao
                right++;  // aage jao
            }
            
            // 2. Even length palindrome check karein (jaise "abba" jiska center 'bb' hai)
            left = i; 
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;   // piche jao
                right++;  // aage jao
            }
        }
        
        // Akhiri me sabse bade palindrome ka substring return kar do
        return s.substr(start, maxLen);
    }
};