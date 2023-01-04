class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k,int n,int no,vector<int> temp){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(n<=0){
            return;
        }
        if(k<=0){
            return;
        }
        if(no>9){
            return;
        }
        solve(k,n,no+1,temp);
        temp.push_back(no);
        solve(k-1,n-no,no+1,temp);
        return;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(k,n,1,temp);
        return ans;
    }
};