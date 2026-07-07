class Solution {
public:
    string largestGoodInteger(string num) {
        char max_digit = '\0'; // Tracks the largest digit found in a triplet
        
        // Loop from the second character to the second-to-last character
        for (int i = 1; i < num.length() - 1; i++) {
            // Check if the current character matches both its neighbors
            if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
                // If it's a valid triplet, update max_digit if this one is larger
                if (max_digit == '\0' || num[i] > max_digit) {
                    max_digit = num[i];
                }
            }
        }
        
        // If max_digit was updated, return a string of 3 of those digits
        if (max_digit != '\0') {
            return string(3, max_digit);
        }
        
        return "";
    }
};