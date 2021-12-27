#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int mod = 1e9 + 7;
vector<int>g[maxn];
long long c[maxn];
long long dp[maxn];
long long ans = 0;
void solve(int now, int pre) {
    long long sum = 1;
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        solve(i, now);
        sum *= dp[i] + 1;
        sum %= mod;
    }
    dp[now] = sum;
    ans += sum;
    ans %= mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve(1, 0);
    cout << ans << '\n';
}