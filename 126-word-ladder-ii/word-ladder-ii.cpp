class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {}; // If endWord is not in the wordList
        
        unordered_map<string, vector<string>> parent; // Stores all parents for a word
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);
        bool found = false;
        int wordLen = beginWord.size();
        
        // BFS to build the parent graph
        while (!currentLevel.empty() && !found) {
            for (const string& word : currentLevel) wordSet.erase(word); // Avoid revisiting
            
            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < wordLen; ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (temp == endWord) found = true; // Mark if endWord is reached
                        if (wordSet.count(temp)) {
                            nextLevel.insert(temp);
                            parent[temp].push_back(word); // Add parent to the graph
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            
            currentLevel.swap(nextLevel);
            nextLevel.clear();
        }
        
        // Backtracking to generate all paths
        vector<vector<string>> results;
        if (found) {
            vector<string> path = {endWord};
            backtrack(results, path, parent, beginWord, endWord);
        }
        return results;
    }
    
private:
    void backtrack(vector<vector<string>>& results, vector<string>& path,
                   unordered_map<string, vector<string>>& parent,
                   const string& beginWord, const string& currentWord) {
        if (currentWord == beginWord) {
            vector<string> tempPath = path;
            reverse(tempPath.begin(), tempPath.end()); // Reverse the path to get the correct order
            results.push_back(tempPath);
            return;
        }
        for (const string& par : parent[currentWord]) {
            path.push_back(par);
            backtrack(results, path, parent, beginWord, par);
            path.pop_back();
        }
    }
};
