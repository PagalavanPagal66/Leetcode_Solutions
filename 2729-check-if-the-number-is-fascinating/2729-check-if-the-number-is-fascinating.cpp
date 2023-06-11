class Solution {
public:
    bool isFascinating(int n) {
        int a=n*2;
        int b=n*3;
        string t1=to_string(a);
        string t2=to_string(b);
        string t3=to_string(n);
        unordered_map<char,int>mp;
        for(auto i:t1){mp[i]++;if(i=='0' || mp[i]==2)return false;}
        for(auto i:t2){mp[i]++;if(i=='0' || mp[i]==2)return false;}
        for(auto i:t3){mp[i]++;if(i=='0' || mp[i]==2)return false;}
        return (mp.size()==9);
    }
};