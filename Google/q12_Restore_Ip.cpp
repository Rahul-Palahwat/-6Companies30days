class Solution {
public:
    vector<string> ans;
    bool check(string s){
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                if(temp.length() > 3 || temp.length() == 0){
                    return false;
                }
                if(temp.length() > 1 && temp[0] == '0'){
                    return false;
                }
                // cout<<temp<<"last"<<endl;
                if(stoi(temp) > 255){
                    return false;
                }
                temp="";
            }else{
                temp+=s[i];
            }
            // temp+=s[i];
        }
        if(temp.length() >3 || temp.length() == 0){
            return false;
        }
        if(temp.length() > 1 && temp[0] == '0'){
            return false;
        }
        // cout<<temp<<"last";
        if(stoi(temp) > 255){
            return false;
        }
        return true;
    }
    void solve(string s , int index , int count){
        if(count >3 || index >= s.length()){
            return;
        }
        if(count == 3){
            if(check(s)){
                ans.push_back(s);
            }
            return;
        }
        solve(s , index+1 , count);
        s.insert(index+1 , ".");
        solve(s , index+1, count+1);
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12){
            return ans;
        }
        solve(s , 0 , 0);
        return ans;
    }
};