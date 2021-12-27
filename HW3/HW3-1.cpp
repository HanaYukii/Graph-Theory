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
    vector<int>cnt(n, 0), f(n, 0);
    for (int i = 0 ; i < n ; i++) {
        d[i] = i;
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        f[a] = f[b] = 1;
        cnt[a] ^= 1;
        cnt[b] ^= 1;
        a = fi(a);
        b = fi(b);
        d[a] = b;
    }
    int tot = 0;
    for (auto &i : cnt) {
        if (i) {
            tot++;
        }
    }
    if (tot > 2) {
        cout << "NO\n";
        exit(0);
    }
    int last = -1;
    for (int i = 0 ; i < n ; i++) {
        if (f[i]) {
            if (~last && fi(i) != fi(last)) {
                cout << "NO\n";
                exit(0);
            }
            last = i;
        }
    }
    cout << "YES\n";
}