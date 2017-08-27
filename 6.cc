class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (size == 0) {
            return "";
        }
        if (size <= numRows || numRows == 1) {
            return s;
        }
        char tmp[size];
        string ans;
        int dis = 2 * (numRows - 1);
        int width;
        for (width = 0; dis * width < size; ++width) {
            tmp[width] = s[dis * width];
        }
        tmp[width] = 0;
        // cout << tmp << endl;

        ans += tmp;

        for (int i = 1; i < numRows - 1; ++i) {
            int m, n;
            for (m = 0; m * (numRows - 1) + i < size; m += 2) {
                tmp[m] = s[m * (numRows - 1) + i];
            }
            for (n = 1; (n + 1) * (numRows - 1) - i < size; n += 2) {
                tmp[n] = s[(n + 1) * (numRows - 1) - i];
            }
            tmp[min(m, n)] = 0;
            // cout << tmp << endl;

            ans += tmp;
        }

        for (width = 0; numRows - 1 + dis * width < size; ++width) {
            tmp[width] = s[numRows - 1 + dis * width];
        }
        tmp[width] = 0;

        ans += tmp;
        // cout << tmp << endl;

        return ans;
    }
};