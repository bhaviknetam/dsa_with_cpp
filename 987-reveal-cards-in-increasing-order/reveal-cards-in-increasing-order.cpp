class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        sort(deck.begin(), deck.end());
        deque<int> d;
        for (int i = 0; i < (int)deck.size(); i++) {
            d.push_back(i);
        }
        int k = 0;
        while (!d.empty()) {
            int idx = d.front();
            d.pop_front();
            if (!d.empty()) {
                int last = d.front();
                d.pop_front();
                d.push_back(last);
            }
            ans[idx] = deck[k++];
        }
        return ans;
    }
};