class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        set<int> edges;
        set<int> heightsSet;

        // collect x edges and building heights
        for (auto& v : buildings) {
            edges.insert(v[0]);
            edges.insert(v[1]);
            heightsSet.insert(v[2]);
        }

        // coordinate compression for x
        vector<int> edgeSet(edges.begin(), edges.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < (int)edgeSet.size(); i++) {
            mp[edgeSet[i]] = i;
        }

        // coordinate compression for heights
        vector<int> heightVals(heightsSet.begin(), heightsSet.end());
        unordered_map<int,int> hmap;
        for (int i = 0; i < (int)heightVals.size(); i++) {
            hmap[heightVals[i]] = i;
        }

        int sz = edgeSet.size();
        vector<vector<int>> events(sz);
        for (int i = 0; i < n; i++) {
            int l = mp[buildings[i][0]];
            int r = mp[buildings[i][1]];
            int h = hmap[buildings[i][2]];
            events[l].push_back(h+1);    // enter building (store index+1)
            events[r].push_back(-(h+1)); // leave building
        }

        vector<int> freq(heightVals.size(), 0);
        int currIdx = -1;   // current max index
        int prevH = 0;
        vector<vector<int>> ans;

        for (int i = 0; i < sz; i++) {
            for (int e : events[i]) {
                if (e > 0) {
                    int idx = e-1;
                    freq[idx]++;
                    currIdx = max(currIdx, idx);
                } else {
                    int idx = -(e+1);
                    if (--freq[idx] == 0 && idx == currIdx) {
                        while (currIdx >= 0 && freq[currIdx] == 0) {
                            currIdx--;
                        }
                    }
                }
            }
            int currH = (currIdx == -1 ? 0 : heightVals[currIdx]);
            if (currH != prevH) {
                ans.push_back({edgeSet[i], currH});
                prevH = currH;
            }
        }
        return ans;
    }
};
