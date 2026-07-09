class Solution {
public:
    string removeDuplicates(string s) {
        string ans = ""; // Yeh string stack ka kaam karegi
        
        for (int i = 0; i < s.length(); i++) {
            // Agar ans khali nahi hai AUR current character pichle character ke barabar hai
            if (!ans.empty() && ans.back() == s[i]) {
                ans.pop_back(); // Adjacent duplicate mil gaya, hata do!
            } else {
                ans.push_back(s[i]); // Duplicate nahi hai, string mein add karo
            }
        }
        
        return ans;
    }
};