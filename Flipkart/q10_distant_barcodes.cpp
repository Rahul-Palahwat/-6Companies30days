class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it: bar){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second , it.first});
        }
        if(pq.size() <= 1){
            return bar;
        }
        while(pq.size() > 1){
            auto f = pq.top();
            int f_count = f.first;
            pq.pop();
            auto s = pq.top();
            int s_count = s.first;
            pq.pop();
            ans.push_back(f.second);
            ans.push_back(s.second);
            f_count--;
            s_count--;
            if(f_count > 0){
                pq.push({f_count , f.second});
            }
            if(s_count > 0){
                pq.push({s_count , s.second});
            }
        }
        if(pq.size() >0){
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};