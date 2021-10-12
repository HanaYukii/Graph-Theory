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
const int maxn = 100005;
vector<int>g[200000];
int c[200000];
int a[2];
void bfs(int now, int cc) {
    a[c[now]]++;
    for (auto &i : g[now]) {
        if (~c[i]) {
            if (c[i] == c[now]) {
                cout << -1 << '\n';
                exit(0);
            }
        }
        else {
            c[i] = cc ^ 1;
            bfs(i, c[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(c, -1, sizeof(c));
    for(int i= 0 ; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    c[0] = 0;
    bfs(0, 0);
    cout << a[0] <<' '<< a[1] << '\n';
}