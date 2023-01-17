// class Solution {
// public:
//     unordered_map<string , int> mp, check;
//     int ans = -1;
//     bool solve(string s1, string s2,int count){
//         if(s1 == s2){
//             ans = count;
//             return true;
//         }
//         for(int i=0;i<8;i++){
//                 char temp = s1[i];
//                 s1[i] = 'A';
//                 if(mp.find(s1) != mp.end()){
//                     if(s1 == s2){
//                         ans = count;
//                         return true;
//                     }
//                     if(check.find(s1) == check.end()){
//                         cout<<s1<<" A"<<endl;
//                         check[s1]=1;
//                         return solve(s1,s2, count+1);
//                     }
//                 }
//                 s1[i] = 'C';
//                 if(mp.find(s1) != mp.end()){
//                     if(s1 == s2){
//                         ans = count;
//                         return true;
//                     }
//                     if(check.find(s1) == check.end()){
//                         cout<<s1<<" C"<<endl;
//                         check[s1]=1;
//                         return solve(s1,s2, count+1);
//                     }
//                 }
//                 s1[i] = 'G';
//                 if(mp.find(s1) != mp.end()){
//                     if(s1 == s2){
//                         ans = count;
//                         return true;
//                     }
//                     if(check.find(s1) == check.end()){
//                         cout<<s1<<" G"<<endl;
//                         check[s1]=1;
//                         return solve(s1,s2, count+1);
//                     }
//                 }
//                 s1[i] = 'T';
//                 if(mp.find(s1) != mp.end()){
//                     if(s1 == s2){
//                         ans = count;
//                         return true;
//                     }
//                     if(check.find(s1) == check.end()){
//                         cout<<s1<<" T"<<endl;
//                         check[s1]=1;
//                         return solve(s1,s2, count+1);
//                     }
//                 }
//                 s1[i] = temp;
//         }
//         return false;
//     }
//     int minMutation(string st, string en, vector<string>& bank) {
//         for(auto it: bank){
//             mp[it]=1;
//         }
//         for(int i=0;i<8;i++){
//             if(st[i] != en[i]){
//                 ans++;
//             }
//         }
//         if(solve(st,en,0)){
//             return ans;
//         }
//         return -1;
        
//     }
// };


class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int size = bank.size(); // extract size
        
        unordered_set<string> dictionary; // make dictionary set 
        for(int i = 0; i < size; i++) // insert every word of bank into the set
        {
            dictionary.insert(bank[i]);
        }
        
        // if end word is not present into the dictionary,
        // will return false from here
        if(dictionary.find(end) == dictionary.end())
        {
            return -1;
        }
        
        // choices that are availble to us
        vector<char> available = {'A', 'C', 'G', 'T'};
        
        // make vis set, to find out whether for a particular word, 
        // either we previously encountered or not
        unordered_set<string> vis;
        
        int ans = 0; // declare ans variable 
        
        queue<string> q; // define queue to start bfs
        q.push(start); // push starting word into the queue
        vis.insert(start); // insert into vis
        
        // starting bfs
        while(!q.empty())
        {
            int n = q.size(); // extract size of queue
            while(n--)
            {
                string curr = q.front(); // curr word 
                q.pop(); // pop from queue
                
                if(curr == end) // if curr word equals to end, return ans from here
                {
                    return ans;
                }
                
                // now for every index of curr word
                for(int i = 0; i < 8; i++)
                {
                    char orig = curr[i]; 
                    
                    // we will try to replace every available choice
                    for(int j = 0; j < 4; j++) 
                    {   
                        curr[i] = available[j]; // replace character
                        
                        // if it is present into the dictionary
                        if(dictionary.find(curr) != dictionary.end())
                        {
                            // also we haven't seen it previously
                            if(vis.find(curr) == vis.end())
                            {
                                q.push(curr); // then push into queue
                                vis.insert(curr); // and also put into vis
                            }
                        }
                    }
                    // now replace with again original character,
                    // for further check
                    curr[i] = orig;
                }
            }
            ans++; // increment answer
        }
        
        return -1; // still we will not able to find end word, return -1
    }
};