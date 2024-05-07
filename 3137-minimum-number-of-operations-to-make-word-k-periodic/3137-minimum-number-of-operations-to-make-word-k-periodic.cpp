class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string,int>mp;
        int n=word.size();
        for(int i=0;i<n;i+=k){
            int t=0;
            string temp = "";
            while(t<k){
                temp+=word[i+t];
                t++;
            }
            mp[temp]++;
            //cout<<temp<<endl;
        }
        int times = n/k;
        int maxi = 0;
        for(auto i:mp){
            maxi = max(maxi,i.second);
        }
        return times-maxi;
    }
};