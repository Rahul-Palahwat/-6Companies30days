// dp solution  
class Solution {
public:
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<int>> dir{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
		vector<vector<double>> dp(N,vector<double>(N,0));
		dp[r][c]=1;
		for(int i=1;i<=K;i++){
			vector<vector<double>> tem(N,vector<double>(N,0));
			for(int j=0;j<N;j++){
				for(int k=0;k<N;k++){
					for(int v=0;v<8;v++){
						int x=j+dir[v][0];
						int y=k+dir[v][1];
						if(x<0 || y<0 || x>=N || y>=N){
							continue;
						}
						tem[j][k]+=dp[x][y];
					}
				}
			}
			dp=tem;
		}
		double rec=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				rec+=dp[i][j];
			}
		double res=rec/pow(8,K);
		return res;
	}
};





// recursive solution
// class Solution {
// public:
//     int ans = 0;
//     void solve(int n, int k, int r, int c){
        
//         if(r>=n || c>=n || r<0 || c<0){
//             return;
//         }
//         if(k<0){
//             return;
//         }
//         if(k==0){
//             ans++;
//         }
//         solve(n,k-1,r+2,c+1);
//         solve(n,k-1,r+2,c-1);
//         solve(n,k-1,r-2 , c+1);
//         solve(n,k-1,r-2,c-1);
//         solve(n,k-1,r-1,c+2);
//         solve(n,k-1,r+1,c+2);
//         solve(n,k-1,r-1,c-2);
//         solve(n,k-1,r+1,c-2);
//         return;
//     }
//     double knightProbability(int n, int k, int r, int c) {
//         solve(n,k,r,c);
//         double finalans=ans;
//         cout<<ans<<endl;
//         while(k--){
//             finalans = (finalans*1.0)/(8*1.0);
//         }
//         return finalans;
//     }
// };