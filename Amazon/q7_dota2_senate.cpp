class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int> r,d;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R'){
                r.push(i);
            }else{
                d.push(i);
            }
        }
        while(!r.empty() && !d.empty()){
            int rindex = r.front();
            int dindex = d.front();
            r.pop();
            d.pop();
            if(rindex <dindex){
                r.push(rindex+ senate.length());
            }else{
                d.push(dindex+ senate.length());
            }
        }
        if(r.size() > d.size()){
            return "Radiant";
        }
        return "Dire";
    }
};