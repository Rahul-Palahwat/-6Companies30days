// class Solution {
// public:
//     int ans = 0;
//     void solve(string s , set<string> st , string temp , int index){
//         if(index > s.length()){
//             return;
//         }
//         if(index == s.length()){
//             if(temp.length() > 0){
//                 st.insert(temp);
//             }
//             if(st.size() == 10){
//                 for(auto it: st){
//                     cout<<it<<" ";
//                 }
//                 cout<<endl;
//             }
//             int sz = st.size();
//             ans = max(ans , sz);
//             return;
//         }
//         if(temp.length() > 0){
//             st.insert(temp);
//             string tt = "";
//             tt+=s[index];
//             solve(s, st , tt , index+1);
//             st.erase(temp);
//         }
//         for(int i=index;i<s.length();i++){
//             temp+=s[i];
//             solve(s , st , temp , i+1);
//         }
//         return;
//     }
//     int maxUniqueSplit(string s) {
//         set<string> mp;
//         string temp = "";
//         solve(s , mp , temp , 0);
//         return ans;
//     }
// };


class Solution {
public:
    
    int ans=1;
    void helper(string &str,int ind,vector<string> &temp,unordered_set<string> &st)
    {
        if(ind == str.length()){
            
            int l=temp.size();
            ans = max(ans,l);
            return;
        }
        string s="";
        for(int i=ind;i<str.length();i++){
            s.push_back(str[i]);
            if(!st.count(s)){                              // call only when string s is not in our set or s is not repeated.
                temp.push_back(s);
                st.insert(s);
                helper(str,i+1,temp,st);
                st.erase(s);                         // backtrack
                temp.pop_back();                     // backtrack 
            }
        }
    }
    int maxUniqueSplit(string s) {
        
        vector<string> temp;
        unordered_set<string> st;
        helper(s,0,temp,st);
        return ans;
        
    }
};