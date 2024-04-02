class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapping1[128] = {0};
        int mapping2[128] = {0};
        for(int i=0;i<s.size();i++){
            int a1 = s[i]+1;
            int a2 = t[i]+1;
            if(mapping1[a1]==0 && mapping2[a2]==0){
                mapping1[a1]=a2;
                mapping2[a2]=a1;
            }else{
                if(mapping1[a1]!=a2 || mapping2[a2]!=a1) return false;
            }
        }
        return true;
    }
};