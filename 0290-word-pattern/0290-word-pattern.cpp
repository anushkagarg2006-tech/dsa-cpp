#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Step 1: string s ko alag-alag words mein todna
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Agar pattern ki length aur words ka count match nahi karta, toh false
        if (pattern.length() != words.size()) {
            return false;
        }

        // Step 2: Bijection check karne ke liye do Hash Maps
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Check character to word mapping
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            
            // Check word to character mapping
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }

            // Mappings ko save karein
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};