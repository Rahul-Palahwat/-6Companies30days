class Solution {
public:
    bool solve(vector<vector<int>>& grid , int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            // cout<<i<<"----i"<<j<<endl;
            return false;
        }
        if(grid[i][j] == 1){
            return true;
        }
        if(grid[i][j] == 1){
            return true;
        }
        grid[i][j] = 1;
        bool r = solve(grid , i+1,j);
        bool l = solve(grid , i-1,j);
        bool t = solve(grid , i, j-1);
        bool b = solve(grid , i, j+1);
        return r&&l&&t&&b;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    // cout<<i<<"i"<<j<<endl;
                    if(solve(grid , i , j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};