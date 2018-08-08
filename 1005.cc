#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> steps, int N) {
    int maxStep = steps[0];     // 当前遍历点所能到达最远的点
    int ans = 1;
    int curPos = 0;             // 当前所在位置
    int lastMaxStep = 0;        // 上一个位置所能到底最远的点
    while (maxStep < N) {
        int i = lastMaxStep + 1;
        lastMaxStep = maxStep;
        for (; i <= lastMaxStep && i < N; i++) {
            if (maxStep < i + steps[i]) {
                curPos = i;
                maxStep = i + steps[i];
            }
        }
        if (maxStep <= lastMaxStep) {
            return -1;
        }
        ans++;
        maxStep = curPos + steps[curPos];
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> steps(N);
    for (int i = 0; i < N; i++) {
        cin >> steps[i];
    }
    cout << solution(steps, N) << endl;
    return 0;
}