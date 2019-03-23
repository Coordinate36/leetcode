#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int x, int y) {
    int absX = abs(x);
    int absY = abs(y);
    int ans = 0;
    if (absX >= absY) {
        ans = (absX * 2 - 1) * (absX * 2 - 1);
        if (x > 0) {
            ans += y > -absX ? y + absX - 1 : (absX << 3) - 1;
        } else {
            ans += (absX << 2) - 1 + absX - y;
        }
    } else {
        ans = (absY * 2 - 1) * (absY * 2 - 1);
        if (y > 0) {
            ans += (absY << 1) - 1 + (absY - x);
        } else {
            ans += (absY * 6) - 1 + (x + absY);
        }
    }
    return ans;
}

int main() {
    int x, y;
    while (cin >> x) {
        cin >> y;
        cout << solution(x, y) << endl;
    }
}