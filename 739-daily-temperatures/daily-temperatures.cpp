class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<pair<int, int>> st;
        vector<int> ans(n, 0);

        for(int i=n-1; i>=0; i--){
            int lastIndx = i;
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }
            if(!st.empty()) lastIndx = st.top().second;
            else    lastIndx = i;
            st.push({temperatures[i], i});
            ans[i] = lastIndx-i;
        }

        return ans;
    }
};