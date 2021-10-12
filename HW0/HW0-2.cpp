#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n;
    map<int, int>mp;
    int mx = 0;
    for (int i = 0 ; i < n ; i++) {
        int a;
        cin >> a;
        mp[a]++;
        mx = max(mx, mp[a]);
    }
    int ans = 0;
    for (auto &i : mp) {
        if (i.second == mx) {
            ans = i.first;
        }
    }
    cout << ans << ' ' << mx << '\n';
}