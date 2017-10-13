class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> adj;
        for (auto p: tickets) {
            adj[p.first] = p.second;
        }

        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {
            string s = st.top();
            if (st[s].size() > 0) {
                for ()
            }
        }
    }
};