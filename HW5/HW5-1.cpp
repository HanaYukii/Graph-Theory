#include<bits/stdc++.h>
using namespace std;

int dp[505][505];
int e[505][505];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (!k) {
        for (int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                dp[i][j] = e[i][j] = 5e8;
            }
        }
        for (int i = 0 ; i < m ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dp[a][b] = dp[b][a] = e[a][b] = e[b][a] = c;
        }
        int mn = 5e8;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < k; i++) {
                for (int j = 1; j < i; j++) {
                    mn = min(mn, dp[i][j] + e[i][k] + e[k][j]);  
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);  
                }
            }
        }
        if (mn == 5e8) {
            cout << -1 << '\n';
        }
        else {
            cout << mn << '\n';
        }
    }
    else {
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0 ; i < m ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dp[a][b] = c;
        }
        for (int k = 1 ; k <= n ; k++) {
            for (int i = 1 ; i <= n ; i++) {
                for (int j = 1 ; j <= n ; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int mn = 1e9;
        for (int i = 1 ; i <= n ; i++) {
            mn = min(mn, dp[i][i]);
        }
        if (mn == 1e9) {
            cout << -1 << '\n';
        }
        else {
            cout << mn << '\n';
        }
    }
}