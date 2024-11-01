class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_set<string> vis;
        vis.insert(beginWord);
        q.push(beginWord);
        int level = 0;
        if(beginWord == endWord){
            return level;
        }
        while(!q.empty()){
            int len = q.size();
            level++;
            for(int i = 0; i < len; i++){
                string word = q.front();
                q.pop();
                for(int j = 0; j < word.size(); j++){
                    char org = word[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        word[j] = c;
                        if(s.count(word) && !vis.count(word)){
                            vis.insert(word);
                            if(word == endWord){
                                return level + 1;
                            }else{
                                q.push(word);
                            }
                        }
                    }
                    word[j] = org;
                }
            }
        }
        return 0;
    }
};