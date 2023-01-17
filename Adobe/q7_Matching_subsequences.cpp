class Solution {
public:
    bool solve(string s1, string s2){
        int j=0;
        for(int i=0;i<s2.length();i++){
            if(s2[i] == s1[j]){
                j++;
            }
            if(j == s1.length()){
                return true;
            }
        }
        return false;
        
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int matchCount = 0; // variable to keep track of the number of matching subsequences
    
    unordered_map<string, int> cache; // hash map to store previously checked words and their result
    
    // iterate through all words in the given vector
    for(auto &word : words) {
        // if the word has already been checked, add the result to matchCount
        if(cache.count(word)) {
            matchCount += cache[word];
        } else {
            // if the word has not been checked yet, check it and add the result to matchCount
            matchCount += cache[word] = solve(word,s);
        }
    }
    return matchCount;
        // int ans = 0;
        // unordered_map<string,int> mp;
        // for(auto it: words){
        //     if(mp.find(it) != mp.end()){
        //         ans++;
        //     }else if(solve(it,s)){
        //         mp[it]++;
        //         ans++;
        //     }
        // }
        // return ans;
    }
};