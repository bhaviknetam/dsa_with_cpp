#include <vector>
#include <stack>

class Solution {
public:
    unsigned int N = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<unsigned int> st;
        vector<unsigned int> left(n), right(n);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        unsigned int result = 0;

        for (int i = 0; i < n; ++i) {
            result = (result + arr[i] * (i - left[i]) * (right[i] - i)) % N;
        }

        return result;
    }
};
