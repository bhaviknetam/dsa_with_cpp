class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();
        while(i < n && j < m){
            long long v1 = 0, v2 = 0;
            while(i < n && version1[i] != '.'){
                v1 = v1 * 10 + version1[i] - '0';
                i++;
            }
            while(j < m && version2[j] != '.'){
                v2 = v2 * 10 + version2[j] - '0';
                j++;
            }
            if(v1 < v2) return -1;
            if(v1 > v2) return 1;
            i++;
            j++;
        }
        while(i < n){
            long long v1 = 0;
            while(i < n && version1[i] != '.'){
                v1 = v1 * 10 + version1[i] - '0';
                i++;
            }
            if(v1 > 0) return 1;
            i++;
        }
        while(j < m){
            long long v2 = 0;
            while(j < m && version2[j] != '.'){
                v2 = v2 * 10 + version2[j] - '0';
                j++;
            }
            if(v2 > 0) return -1;
            j++;
        }
        return 0;
    }
};