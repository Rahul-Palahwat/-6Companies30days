// class Solution {
// public:
//     int mod = 1e9+7;
//     int dijsktra(vector<pair<int,int>> g[],int source,int n){
//         vector<bool> vis(n,0);
//         vector<long long> dis(n,1e10);
//         vector<long long> ways(n,0);
//         set<pair<int,int>> st;
//         st.insert({0,source});
//         dis[source] = 0;
//         ways[source] = 1;
//         while(st.size() > 0){
//             auto t = *st.begin();
//             int s = t.second;
//             int dist = t.first;
//             st.erase(st.begin());
//             if(vis[s]){
//                 continue;
//             }
//             vis[s] = true;
//             for(auto child: g[s]){
//                 int child_node = child.first;
//                 int child_w = child.second;
//                 long long dd =dist;
//                 dd+=child_w;
//                 if(dd == dis[child_node]){
//                     ways[child_node] = (ways[s] + ways[child_node])%mod;
//                     // if(ways[child_node] >= mod){
//                     //     cout<<"hello"<<ways[child_node];
//                     // }
//                     // ways[child_node] = ways[child_node]%mod;
//                 }
//                 if(dd < dis[child_node]){
//                     ways[child_node] = ways[s];
//                     dis[child_node]=dd;
//                     st.insert({dis[child_node] , child_node});
//                 }
//             }
//         }
//         return ways[n-1];
//     }
//     int countPaths(int n, vector<vector<int>>& roads) {
        
//         vector<pair<int,int>> g[n];
//         for(auto it: roads){
//             g[it[0]].push_back({it[1],it[2]});
//             g[it[1]].push_back({it[0],it[2]});
            
//         }
//         return dijsktra(g,0,n);
//     }
// };

// only last 2 cases were reamingin 



#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};