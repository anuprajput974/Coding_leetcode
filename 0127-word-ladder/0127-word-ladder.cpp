class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in the dictionary, return 0
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start with the beginWord and depth 1

        while (!q.empty()) {
            string word = q.front().first;
            int length = q.front().second;
            q.pop();

            // Try changing every letter of the word
            for (int i = 0; i < word.length(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    // If we find the endWord
                    if (temp == endWord)
                        return length + 1;

                    // If this transformed word is in the word set
                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push({temp, length + 1});
                        wordSet.erase(temp); // Mark word as visited
                    }
                }
            }
        }

        return 0; // No transformation found
    }
};
