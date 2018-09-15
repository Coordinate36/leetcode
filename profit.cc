#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, double> > rate;

void init() {
    rate.push_back(make_pair(0, 0.1));
    rate.push_back(make_pair(100000, 0.075));
    rate.push_back(make_pair(200000, 0.05));
    rate.push_back(make_pair(400000, 0.03));
    rate.push_back(make_pair(600000, 0.015));
    rate.push_back(make_pair(1000000, 0.01));
}

double solution(double profit) {
    double ans = 0;

    int i;
    for (i = 1; i < rate.size() && profit > rate[i].first; i++) {
        ans += (rate[i].first - rate[i-1].first) * rate[i-1].second;
    }

    ans += (profit - rate[i-1].first) * rate[i-1].second;
    return ans;
}

int main() {
    init();
    double profit;
    cin >> profit;
    double ans = solution(profit);
    printf("%.2f", ans);
    return 0;
}