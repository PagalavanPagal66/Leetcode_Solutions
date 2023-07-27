/*
class Solution {
public:
    int valid(long long mid,long long n, vector<int>&batteries){
        int ans=0;
        long long sum=0;
        for(int i=0;i<batteries.size();i++){
            sum+=batteries[i];
            if(sum>=mid){
                ans++;
                sum-=mid;
            }
            if(ans>=n){
                return 1;
            }
        }
        return 0;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long strt=1;
        long long ini=0;
        long long end=accumulate(batteries.begin(),batteries.end(),ini);
        end/=n;
        sort(batteries.begin(),batteries.end());
        long long ans=0;
        while(strt<=end){
            int mid=strt+(end-strt+1)/2;
            if(valid(mid,n,batteries)){
                ans=mid;
                strt=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};
*/


class Solution {
public:
    
    #define ll long long
    bool possible(int n, vector<int> &bat, ll int hrs){
        ll int s=0;
        for(int i=0;i<bat.size();i++){
            s += bat[i];
            if(s>=hrs){
                s-=hrs; 
                n--;
            }
            if(n==0) return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int> &bat) {
        ll int l=1, r=0;
        
        for(int i=0;i<bat.size();i++) r += bat[i];
        r/=n;
        sort(bat.begin(),bat.end());
        while(l<r){
            ll int m=l+(r-l+1)/2;
            if(possible(n,bat,m)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};