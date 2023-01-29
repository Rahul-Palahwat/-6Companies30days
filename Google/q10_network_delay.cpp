class Solution {
public:
void dijak(vector<pair<int,int>> g[], vector<bool>& vis , vector<int>& dis,int k){
        set<pair<int,int>> s;
        s.insert({0 , k});
        dis[k] = 0;
        while(!s.empty()){
            auto node = *s.begin();
            int v = node.second;
            int v_d = node.first;
            s.erase(s.begin());
            if(vis[v]){
                continue;
            }
            vis[v] = 1;
            for(auto child : g[v]){
                int child_v = child.first;
                int child_w = child.second;
                if(dis[v] + child_w < dis[child_v]){
                    dis[child_v] = dis[v] + child_w;
                    s.insert({dis[child_v] , child_v});
                }
            }
        }
        return;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[n+1];
        long long INF = 1e9+10;
        vector<bool> vis(n+1,0);
        vector<int> dis(n+1,INF);
        for(int i = 0 ;i< times.size();i++){
            g[times[i][0]].push_back({times[i][1] , times[i][2]});
        }
        dijak(g,vis,dis,k);
        int ans = INT_MIN;
        for(int i = 1; i<=n ;i++){
            ans = max(ans , dis[i]);
        }
        return ans == INF ? -1 : ans;
    }
};