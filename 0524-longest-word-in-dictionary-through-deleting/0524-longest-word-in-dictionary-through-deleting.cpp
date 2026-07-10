class Solution {
public:
    // यह फंक्शन चेक करेगा कि क्या curr स्ट्रिंग s में मौजूद है (as a subsequence)
    bool iscontain(string s, string curr) {
        int i = 0, j = 0;
        // दोनों स्ट्रिंग्स को दो पॉइंटर्स से स्कैन करेंगे
        while (i < s.length() && j < curr.length()) {
            if (s[i] == curr[j]) {
                j++; // अगर अक्षर मैच हो गया तो curr में आगे बढ़ो
            }
            i++; // s में हमेशा आगे बढ़ेंगे
        }
        // अगर j, curr की लंबाई के बराबर पहुँच गया, मतलब पूरा वर्ड मैच हो गया
        return j == curr.length();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        
        for (int i = 0; i < dictionary.size(); i++) {
            string curr = dictionary[i];
            
            // अगर curr मैच हो जाता है
            if (iscontain(s, curr)) {
                // शर्त 1: या तो ये वर्ड हमारे पिछले आंसर से लंबा हो
                // शर्त 2: या लंबाई बराबर हो, लेकिन ये डिक्शनरी ऑर्डर में छोटा हो
                if (curr.length() > ans.length() || (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};