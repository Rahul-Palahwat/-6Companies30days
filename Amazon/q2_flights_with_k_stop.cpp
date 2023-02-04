class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        //it will store [node, cost]
        queue<pair<int, int>> q;
        q.push({src, 0});
        //it will store minimum cost to reach each node
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                auto [currNode, cost] = q.front();
                q.pop();
                for (auto& [neighbour, price] : adj[currNode]) {
                    if (price + cost < minCost[neighbour]){
                        minCost[neighbour] = price + cost;
                        q.push({neighbour, minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        if(minCost[dst] == INT_MAX)
            return -1;
        return minCost[dst];
    }
    // int ans = INT_MAX;
    // void solve(vector<pair<int,int>> g[], vector<bool> vis , int src , int dst , int sum,int k){
    //     if(k<0){
    //         return;
    //     }
    //     if(src == dst){
    //         ans = min(ans , sum);
    //         return;
    //     }
    //     if(vis[src]){
    //         return;
    //     }
    //     vis[src] = true;
    //     for(auto it: g[src]){
    //         // cout<<it<<"first"<<it<<endl;
    //         solve(g,vis,it.first,dst,sum+it.second , k-1);
    //     }
    //     return;
    // }
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<pair<int,int>> g[n];
    //     vector<bool> vis(n,false);
    //     for(auto it: flights){
    //         g[it[0]].push_back({it[1],it[2]});
    //     }
    //     solve(g,vis,src,dst,0,k+1);
    //     return ans == INT_MAX ? -1 : ans;
    // }
};