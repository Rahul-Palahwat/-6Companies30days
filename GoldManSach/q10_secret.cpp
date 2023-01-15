class Solution {
public:
    #define ll long long
    #define MOD 1000000007
 
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(n)
 
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll day = 2, taken = 1;
 
        vector <array <ll, 3>> persons = {{delay + 1, forget + 1, 1}};
 
        while(day<=n){
            // remove all those persons who forgets secrets
            while(!persons.empty() && persons[0][1] == day){
                persons.erase(persons.begin());
            }
 
            // find number of persons that can spread secret
            ll cnt = 0;
            for(auto& x : persons){
                if(x[0] <= day){
                    cnt += x[2];
                }
 
                cnt %= MOD;
            }
 
            persons.push_back({day + delay, day + forget, cnt});
 
            day++;
        }       
 
        ll ans = 0;
        for(auto& x : persons){
            ans += x[2];
            ans %= MOD;
        }
 
        return ans;
    }
};