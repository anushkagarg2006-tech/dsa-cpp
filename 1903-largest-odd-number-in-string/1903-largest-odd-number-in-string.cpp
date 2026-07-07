class Solution {
public:
    string largestOddNumber(string num) {
        string s;
        int n = -1;
        for (int i = num.length() - 1; i >= 0; i--) {
            int c = num[i];
            if (c % 2 != 0) {
                n = i;
                break;
            }
        }
        for (int i = 0; i <= n; i++) {
            s += num[i];
        }
    
    return s;
}
}
;