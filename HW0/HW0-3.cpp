#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a[3];
    cin >> n >> a[1] >> a[0] >> a[2];
    for (int i = 0 ; i < n ; i++) {
        int sum = 0;
        for (int j = 0 ; j < n ; j++) {
            int x;
            cin >> x;
            if (i == j)continue;
            sum += a[x];
        }
        cout << sum <<' ';
    }
    cout << '\n';
}