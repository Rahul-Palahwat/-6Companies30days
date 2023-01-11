class Solution {
public:
    // int solve(int n){
    //     if(n==1 || n==0){
    //         return 1;
    //     }
    //     return n*solve(n-1);
    // }
    // int numberOfBoomerangs(vector<vector<int>>& p) {
    //     int maxi = 0;
    //     int n = p.size();
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==j){
    //                 continue;
    //             }
    //             int dis = pow((p[j][1]-p[i][1]) , 2) + pow((p[j][0]-p[i][0]),2);
    //             // if(i==j){
    //             //     continue;
    //             // }
    //             // int dis = pow((p[j][1]-p[i][1]) , 2) + pow((p[j][0]-p[i][0]),2);
    //             // for(int k=0;k<n;k++){
    //             //     if(j == k){
    //             //         continue;
    //             //     }
    //             //     int temp = pow((p[k][1]-p[i][1]) , 2) + pow((p[k][0]-p[i][0]),2);
    //             //     if(dis == temp){
    //             //         mp[dis]++;
    //             //     }
    //             // }
    //             mp[dis]++;
    //         }
    //     }
    //     for(auto it: mp){
    //         if(it.second > 1){
    //             maxi = max(maxi , solve(it.second/2));
    //         }
    //     }
    //     return maxi;
    // }
    int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0, n = points.size();
    for(int i=0;i<n;i++) {
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int dis = dx*dx + dy*dy;
            // we can pair jth point with any other point we have found till now
            // as ordering also matter, so multiplied by 2
            ans += mp[dis]*2;
            mp[dis]++;
        }
    }
    return ans;
}
};