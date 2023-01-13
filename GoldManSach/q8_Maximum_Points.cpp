class Solution {
public:
    void solve(int numArrows ,vector<int> aliceArrows, vector<int> var , vector<vector<int>>& temp , int index){
        if(numArrows < 0){
            return;
        }
        if(index >= 12){
            if(numArrows > 0){
                var[0]+=numArrows;
            }
            temp.push_back(var);
            return;
        }
        if(numArrows == 0){
            temp.push_back(var);
            return;
        }
        solve(numArrows , aliceArrows , var, temp , index+1);
        var[index] = aliceArrows[index]+1;
        numArrows-=(aliceArrows[index]+1);
        solve(numArrows , aliceArrows , var, temp , index+1);
        return;
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans(12,0);
        vector<vector<int>> temp;
        solve(numArrows , aliceArrows , ans , temp , 0);
        int maxi = 0;
        for(auto it: temp){
            int t = 0;
            for(int i=0;i<12;i++){
                if(it[i] > aliceArrows[i]){
                    t+=i;
                }
            }
            if(maxi <= t){
                maxi = t;
                ans = it;
            }
        }
        return ans;
        
    }
};