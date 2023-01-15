class Solution {
public:
    string fractionToDecimal(int nume, int deno) {
        string ans="";
        string f="";
        if(nume == 0){
            return "0";
        }
        int neg=0;
        long long num=nume*1LL;
        long long den = deno*1LL;
        if(num <0 && den < 0){
            num = abs(num);
            den = abs(den);
        }else if(num < 0 || den < 0){
            num = abs(num);
            den = abs(den);
            neg=1;
            // cout<<neg<<"hello"<<num<<endl;
        }
        if(num%den == 0){
            if(neg == 1){
                string tt = to_string(num/den);
                tt.insert(0,"-");
                return tt;
            }
            return to_string(num/den);
        }
        if(num >= den){
            f+=to_string(num/den);
            num = num%den;
            f+='.';
        }else{
            f+="0.";
        }
        
        unordered_map<int,int> mp;
        mp[num]=1;
        string l="";
        int flag=0;
        int i=0;
        int index = 0;
        while(num % den != 0){
            mp[num]=i;
            num*=10;
            while(num < den){
                l+='0';
                i++;
                mp[num]=i;
                num*=10;
            }
            i++;
            l+=to_string(num/den);
            num = num%den; 
            if(mp.find(num) != mp.end()){
                index = mp[num];
                flag=1;
                break;
            }
        }
        if(flag==1){
            l+=')';
            l.insert(index,"(");
        }
        if(neg == 1){
            f.insert(0,"-");
        }
        return f+l;
    }
};