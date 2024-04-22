class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans=0;
        vector<int>oddnums,evennums,oddtarget,eventarget;
        for(auto i:nums){
            if(i%2==0)evennums.push_back(i);
            else oddnums.push_back(i);
        }
        for(auto i:target){
            if(i%2==0)eventarget.push_back(i);
            else oddtarget.push_back(i);
        }
        sort(oddnums.begin(),oddnums.end());
        sort(oddtarget.begin(),oddtarget.end());
        sort(eventarget.begin(),eventarget.end());
        sort(evennums.begin(),evennums.end());
        int n=target.size();
        int extra = 0;
        for(int i=0;i<oddnums.size();i++){
            int moves = (abs(oddtarget[i] - oddnums[i]))/2;
            // if(moves<=extra){
            //     extra-=moves;
            // }
            // else{
            //     ans+=(moves-extra);
            //     extra=(-extra+moves);
            // }
            ans+=moves;
            cout<<oddtarget[i] <<" "<<oddnums[i]<<endl;
        }
        for(int i=0;i<evennums.size();i++){
            int moves = (abs(eventarget[i] - evennums[i]))/2;
            // if(moves<=extra){
            //     extra-=moves;
            // }
            // else{
            //     ans+=(moves-extra);
            //     extra=(-extra+moves);
            // }
            ans+=moves;
        }
        return ans/2;
    }
};