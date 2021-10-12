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
vector<int>v;
int b[maxn];
void update(int x, int d) {
    while(x < maxn) {
        b[x] += d;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    f1(n) {
        int x;
        cin >> x;
        v.pb(x);
        sum += x;
    }
    if (sum % 2) {
        cout << "No\n";
        exit(0);
    }
    v.pb(0);
    sort(all(v));
    f1(n) {
        update(i, v[i] - v[i - 1]);
    }
    for (int i = n ; i >= 1 ; i--) {
        int x = query(i);
        if (x < 0) {
            cout << "No\n";
            exit(0);
        }
        if (x == 0) {
            continue;
        }
        if (i - x <= 0) {
            cout << "No\n";
            exit(0);
        } 
        if (query(i - x) <= 0) {
            cout << "No\n";
            exit(0);
        }
        int a = query(i - x);
        update(i, -x);
        update(i + 1, x);
        if (query(i - x - 1) == query(i - x)) {
            int l = 0, r = i;
            int l2 = 0, r2 = i;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                if (query(mid) < a) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            while (r2 - l2 > 1) {
                int mid = (l2 + r2) >> 1;
                if (query(mid) <= a) {
                    l2 = mid;
                }
                else {
                    r2 = mid;
                }
            }
            int rem = max(0, (i - 1 - l2));
            if (rem) {
                update(r2, -1);
                update(i, 1);
            }
            int left = x - rem;
            update(r, -1);
            update(r + left, 1);
        }
        else {
            update(i - x, -1);
            update(i, 1);
        }
    }
    cout << "Yes\n";
}