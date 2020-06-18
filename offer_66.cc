class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> b(a.size(), 1);
        for (int i = 1; i < a.size(); ++i) {
            b[i] = b[i-1] * a[i-1];
        }
        int tmp = 1;
        for (int i = a.size() - 2; i >= 0; --i) {
            tmp *= a[i+1];
            b[i] *= tmp;
        }
        return b;
    }
};