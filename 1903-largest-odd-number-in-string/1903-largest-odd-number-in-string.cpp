class Solution {
public:
    string largestOddNumber(string num) {
        // Scan from right to left to find the first odd digit
        for (int i = num.length() - 1; i >= 0; i--) {
            // 'num[i] - '0'' converts the char digit to its actual integer value
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from index 0 with a length of (i + 1)
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};