#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 200005;

set<int>st[maxn];
vector<vector<pair<int,int>>>e;
vector<int>vv;
int d[maxn];
int fi(int x) {
    return d[x] < 0 ?  x : d[x] = fi(d[x]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        st[x].insert(y);
        st[y].insert(x);
    }
    memset(d, -1, sizeof(d));
    int cc = n;
    for (int i = 0 ; i < k ; i++) {
        int op;
        cin >> op;
        vector<pair<int,int>>v;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            v.pb({x, y});
            st[x].erase(y);
            st[y].erase(x);
            vv.pb(0);
        }
        else {
            int x;
            cin >> x;
            for (auto &i : st[x]) {
                v.pb({x, i});
                st[i].erase(x);
            }
            st[x].clear();
            vv.pb(x);
            cc--;
            d[x] = 0;
        }
        e.pb(v);
    }
    int mx = 1;
    for (int i = 1 ; i <= n ; i++) {
        for (auto &j : st[i]) {
            int x = fi(i);
            int y = fi(j);
            if (x != y) {
                cc--;
                d[y] += d[x];
                mx = max(mx, -d[y]);
                d[x] = y;
            }
        }
    }
    reverse(all(e));
    reverse(all(vv));
    e.pop_back();
    vv.pop_back();
    vector<pair<int,int>>ans;
    ans.pb({cc, mx});
    for (int i = 0 ; i < e.size() ; i++) {
        if (vv[i]) {
            d[vv[i]] = -1;
            cc++;
        }
        for (auto &j : e[i]) {
            int x = fi(j.F);
            int y = fi(j.S);
            if (x != y) {
                cc--;
                d[y] += d[x];
                mx = max(mx, -d[y]);
                d[x] = y;
            }
        }
        ans.pb({cc, mx});
    }
    reverse(all(ans));
    for (auto &i : ans) {
        cout << i.F <<' '<<i.S << '\n';
    }
}