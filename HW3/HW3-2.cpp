#include <bits/stdc++.h>
using namespace std;
int d[200005];
int fi(int x) {
    return d[x] == x ? x : d[x] = fi(d[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int,vector<pair<int,int>>>mp;
    for (int i = 1 ; i <= n ; i++) {
        d[i] = i;
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        mp[x].push_back({a, b});
    }
    long long ans = 0;
    int f = 0;
    for (auto &i : mp) {
        int cnt = 0;
        for (auto &j : i.second) {
            if (fi(j.first) != fi (j.second)) {
                cnt++;
            }
        }
        for (auto &j : i.second) {
            if (fi(j.first) != fi (j.second)) {
                cnt--;
                ans += i.first;
                d[fi(j.first)] = fi(j.second);
            }
        }
        if (cnt) {
            f = 1;
        }
    }
    cout << ans << '\n';
    for(int i = 2 ; i <= n ; i++) {
        assert(fi(i) == fi(1));
    }
    if (f) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}