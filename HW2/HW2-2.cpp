#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >g[200005];
long long dis[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        long long c;
        cin >> c;
        g[0].push_back({i,c});
    }
    for (int i = 0 ; i < m ; i++){
        int u, v;
        long long c;
        cin >> u >> v >> c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    for (int i = 1 ; i <= n ; i++){
        dis[i] = 1e18;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>> >pq;
    pq.push({0,0});
    while(pq.size()){
        auto now = pq.top();
        pq.pop();
        if (dis[now.second] != now.first) {
            continue;
        }
        for(auto i:g[now.second]){
            if(now.first + i.second < dis[i.first]){
                dis[i.first] = now.first + i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    for (int i = 1 ; i <= n ; i++){
        cout << dis[i] << ' ';
    }
    cout << '\n';
}