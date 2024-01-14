class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        
        map<char,int> n1, n2;
        multiset<int> m1, m2;
        bool ans = true;
        if(word1.length()!=word2.length()) return !ans;
        for(int i= 0; i < word1.length(); i++){
            n1[word1[i]]++;
            //s1.insert(word1[i]);
        }
        for(int i= 0; i < word2.length(); i++){
            n2[word2[i]]++;
            //s2.insert(word2[i]);
        }
        for(auto it1 = n1.begin(), it2= n2.begin(); it1!=n1.end(), it2!=n2.end(); it1++, it2++){
            m1.insert(it1->second);
            m2.insert(it2->second);
            if(it1->first != it2->first) return false;
        }
        for(auto it1 = m1.begin(), it2= m2.begin(); it1!=m1.end(), it2!=m2.end(); it1++, it2++){
                if(*it1!=*it2) return !ans;
        }
        
        
        return ans;
    }
};