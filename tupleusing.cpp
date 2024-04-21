#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    // read the input
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> projects(n);
    for (int i = 0; i < n; i++) {
        ll start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = {end, start, reward};
    }
    sort(projects.begin(), projects.end());
 
    // compute the dp table and totalBestReward
    ll bestTotalReward = 0;
    map<ll, ll> dp; // {end: totalRewardSoFar}
    dp[0] = 0;
    for (auto project: projects) {
        ll start, end, reward;
        tie(end, start, reward) = project;
 
        auto it = dp.lower_bound(start);
        it--;
        ll totalReward = it->second + reward;
        bestTotalReward = max(bestTotalReward, totalReward);
        dp[end] = bestTotalReward;
    }
    cout << bestTotalReward;
 
    return 0;
}