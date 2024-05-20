#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 100;
vector<int> graph[MOD]; // An array of vectors to represent the graph
bool vis[MOD];
int dis[MOD];

void bfs(int source) {
    queue<int> q;
    vis[source] = 1;
    dis[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!vis[next]) {
                vis[next] = 1;
                dis[next] = dis[node] + 1;
                q.push(next);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); // Changed NUint to nullptr
    int nodes, edge;
    cin >> nodes >> edge; // Fixed typo from edeg to edge
    for (int i = 1; i <= edge; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cin >> source;
    fill(vis, vis + MOD, false); // Initialize visited array
    fill(dis, dis + MOD, LLONG_MAX); // Initialize distance array with max value
    bfs(source);
    for (int i = 1; i <= nodes; i++) {
        cout << i << " " << dis[i] << endl;
    }
}
