class Solution {
public:
    int bfs(vector<vector<int>>& grid , int i,int j , int n, int m){
        if(i<0 || j<0){
            return 0;
        }
        if(i>=n || j>= m){
            return 0;
        }
        if(grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        return 1+ bfs(grid,i+1,j,n,m) + bfs(grid,i-1,j,n,m)+ bfs(grid,i,j+1,n,m)+ bfs(grid,i,j-1,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    ans = max(ans , bfs(grid , i , j , n , m));
                }
            }
        }
        return ans;
    }
};