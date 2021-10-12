#include<bits/stdc++.h>
using namespace std;
int mat[2005][2005];
int s[2005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, aa[3];
    cin >> n >> k >> aa[1] >> aa[0] >> aa[2];
    multiset<int>st;
    for (int i = 0 ; i < n ; i++) {
        int sum = 0;
        for (int j = 0 ; j < n ; j++) {
            int x;
            cin >> x;
            assert(0 <= x && x <= 2);
            mat[i][j] = x;
            if (i == j)continue;
            sum += aa[x];
        }
        s[i] = sum;
        st.insert(sum);
    }
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        assert(a != b);
        a--, b--;
        assert(mat[a][b] != c);
        int op = min(c ^ 1, 2);
        st.erase(st.find(s[a]));
        st.erase(st.find(s[b]));
        s[a] -= aa[mat[a][b]];
        mat[a][b] = c;
        s[a] += aa[mat[a][b]];
        st.insert(s[a]);
        s[b] -= aa[mat[b][a]];
        mat[b][a] = op;
        s[b] += aa[mat[b][a]];
        st.insert(s[b]);
        cout << *--st.end() - *st.begin() <<' ';
    }
    cout << '\n';
}