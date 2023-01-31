class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& cr, vector<string>& ids, vector<int>& v) {
        vector<vector<string>> ans;
        unordered_map<string,long long> mp;
        long long maxi = 0;
        for(int i=0;i<ids.size();i++){
            mp[cr[i]]+=v[i];
            maxi = max(maxi , mp[cr[i]]);
        }
        vector<string> names;
        for(auto it: mp){
            if(it.second == maxi){
                names.push_back(it.first);
            }
        }
        
        map<string  , vector<pair<int , string>>> total;
        
        for(int i=0;i<cr.size();i++){
            total[cr[i]].push_back({v[i] , ids[i]});
        }
        
        
        for(auto it: names){
            vector<string> temp;
            temp.push_back(it);
            auto t = total[it];
            sort(t.begin(), t.end() , greater<pair<int,string>>() );
            string st = t[0].second;
            int stn = t[0].first;
            for(int i=1;i<t.size();i++){
                if(t[i].first == stn){
                    st = min(st , t[i].second);
                }else{
                    break;
                }
            }
            temp.push_back(st);
            ans.push_back(temp);
        }
        return ans;
    }
};