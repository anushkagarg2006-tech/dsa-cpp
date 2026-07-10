class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> as_strings;
        
        // 1. Sabhi numbers ko string mein convert karein
        for (int num : nums) {
            as_strings.push_back(to_string(num));
        }
        
        // 2. Custom comparator ke saath sort karein
        sort(as_strings.begin(), as_strings.end(), [](const string& a, const string& b) {
            return a + b > b + a; // Jo combination bada string banayega, wo pehle aayega
        });
        
        // 3. Edge Case: Agar sabse bada number hi "0" hai, toh sirf "0" return karein
        if (as_strings[0] == "0") {
            return "0";
        }
        
        // 4. Sabhi strings ko aapas mein jodein
        string result = "";
        for (const string& str : as_strings) {
            result += str;
        }
        
        return result;
    }
};