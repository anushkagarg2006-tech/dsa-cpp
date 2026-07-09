class Solution {
public:
    bool isPalindrome(const string& s, int l, int e) {
        while (l < e) {
            if (s[l] != s[e]) return false;
            l++;
            e--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int e = s.length() - 1;
        
        while (l < e) {
            if (s[l] != s[e]) {
                return isPalindrome(s, l + 1, e) || isPalindrome(s, l, e - 1);
            }
            l++;
            e--;
        }
        return true;
    }
};