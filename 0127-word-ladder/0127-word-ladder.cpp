class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0; // endWord not reachable at all

        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord); // avoid revisiting beginWord

        int steps = 1; // beginWord itself counts as step 1

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front(); q.pop();

                if (word == endWord) return steps;

                for (int pos = 0; pos < word.size(); pos++) {
                    char original = word[pos];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        word[pos] = c;

                        if (words.find(word) != words.end()) {
                            words.erase(word);   // mark visited
                            q.push(word);
                        }
                    }
                    word[pos] = original; // restore before trying next position
                }
            }
            steps++;
        }

        return 0; // endWord never reached
    }
};