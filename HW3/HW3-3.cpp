#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int dfn[maxn];
int low[maxn];
vector<int>g[maxn];
int b[maxn];
int bcc;
stack<int>st;
int stamp;

void dfs(int now, int pre = 0) {
    ++stamp;
    dfn[now] = low[now] = stamp;
    st.push(now);
    for (auto &i : g[now]) {
        if (i == pre) continue;
        if (dfn[i]) {
            low[now] = min(low[now], dfn[i]);
        }
        else {
            dfs(i, now);
            low[now] = min(low[now], low[i]);
        }
    }
    if (dfn[now] == low[now]) {
        bcc++;
        while (1) {
            auto x = st.top();
            st.pop();
            b[x] = bcc;
            if (x == now) {
                break;
            }
        }
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout << bcc - 1 << '\n';
}