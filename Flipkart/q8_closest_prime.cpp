class Solution {
public:
    
    // seive algo to find prime numbers
    void pri(vector<bool>& prime){
        prime[1] = false;
        prime[0] = false;
        prime[2] = true;
        for(int i=2;i<=1000;i++){
            for(int j=2;i*j<=1e6;j++){
                prime[i*j] = false;
            }
        }
        return;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int mini = INT_MAX;
        vector<bool> prime(1e6+1 , true);
        pri(prime);
        vector<int> p;
        for(int i=left;i<=right;i++){
            if(prime[i]){
                p.push_back(i);
            }
        }
        if(p.size()<=1){
            return ans;
        }
        for(int i=0;i<p.size()-1;i++){
            int t = p[i+1]-p[i];
            if(mini > t){
                mini = t;
                ans[0] = p[i];
                ans[1] = p[i+1];
            }
        }
        return ans;
    }
};