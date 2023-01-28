class Solution {
public:
    int ans = 0;
    int count = INT_MAX;
    
    int dij(vector<pair<int,int>> g[],int source,int n,int maxi){
        vector<int> dis(n,INT_MAX);
        vector<bool> vis(n,0);
        set<pair<int,int>> st;
        st.insert({0,source});
        dis[source] = 0;
        while(st.size() > 0){
            auto node = *st.begin();
            int v = node.second;
            int v_dis = node.first;
            st.erase(st.begin());
            if(vis[v]){
                continue;
            }
            vis[v]=1;
            for(auto child: g[v]){
                int child_v = child.first;
                int child_dis = child.second;
                if((dis[v]+child_dis) < dis[child_v]){
                    dis[child_v] = dis[v]+child_dis;
                    st.insert({dis[child_v] , child_v});
                }
            }
        }
        int temp = 0;
        for(auto it: dis){
            if(it <= maxi){
                temp++;
            }
        }
        return temp;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distance) {
        vector<pair<int,int>> g[n];
        for(auto it: edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        for(int i=0;i<n;i++){
            int t = dij(g,i , n , distance);
            if(t<=count){
                ans = i;
                count = t;
            }
        }
        return ans;
    }
};