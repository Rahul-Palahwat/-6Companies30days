class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        vector<int> v;
        int flag=0;
        int mini = INT_MAX;
        for(auto it: matrix){
            for(auto i: it){
                ans+=abs(i);
                if(abs(i)!=0){
                    mini = min(mini , abs(i));
                }
                if(i == 0){
                    flag=1;
                }
                if(i<0){
                    v.push_back(i);
                }
            }
        }
        if(flag==1){
            return ans;
        }
        if(v.size()%2 ==0){
            return ans;
        }
        if(mini == INT_MAX){
            sort(v.begin(),v.end());
            return ans+2*v[v.size()-1];
        }else{
            return ans-2*mini;
        }
        
    }
};