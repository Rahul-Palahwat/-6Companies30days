class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        int m = grid[0].size();
        vector<vector<int>> pre;
        for(int i=0;i<n;i++){
            vector<int> temp;
            int sum = 0;
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                temp.push_back(sum);
            }
            pre.push_back(temp);
        }
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int temp = 0;
                if(j==0){
                    temp+=pre[i][j+2];
                    temp+=pre[i+2][j+2];
                    temp+=grid[i+1][j+1];
                }else{
                    temp+=pre[i][j+2] - pre[i][j-1];
                    temp+=pre[i+2][j+2] - pre[i+2][j-1];
                    temp+=grid[i+1][j+1];
                }
                ans = max(ans , temp);
            }
            
        }
        return ans;
    }
};