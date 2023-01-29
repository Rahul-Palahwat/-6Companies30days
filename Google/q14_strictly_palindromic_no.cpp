class Solution {
public:
    bool isStrictlyPalindromic(int n) 
    {
        int tmp;                      // store n into a temp val so actual n will not affected
        string base;                  // for storing the value of each base (2 to n-2)
        
        for(int i=2;i<=n-2;i++)
        {
            tmp=n;
            
            while(tmp)                                   // calculating the base i for value tmp 
            {
                base = base + to_string(tmp%i);
                tmp = tmp/i;
            }
            
            int st=0;
            int en=base.size()-1;
            while(st<en)                                // check for palindrom
            {
                if(base[st++]!=base[en--]) return false;
            }
            
            base.clear();                               // clear base each time after iteration
        }
        return true;
    }
};