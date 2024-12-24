class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> parent;
        queue<string> q;
        q.push(beginWord);
        s.erase(beginWord);
        int n = beginWord.size();
        bool found = false;
        while (!q.empty() && !found) {
            unordered_set<string> visitedThisLevel;
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                string top = q.front();
                string temp = top;
                q.pop();
                for (int i = 0; i < n; i++) {
                    char org = top[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == org) continue; // Skip the same character
                        top[i] = c;
                        if (top == endWord) found = true;
                        if (s.count(top)) {
                            parent[top].push_back(temp); // Record parent
                            if (!visitedThisLevel.count(top)) {
                                q.push(top);
                                visitedThisLevel.insert(top);
                            }
                        }
                    }
                    top[i] = org;
                }
            }
            for (auto& word : visitedThisLevel) {
                s.erase(word); // Remove words processed at this level
            }
        }
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
            reverse(tempPath.begin(), tempPath.end());
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