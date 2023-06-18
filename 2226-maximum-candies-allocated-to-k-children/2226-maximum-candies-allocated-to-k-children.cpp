class Solution {
public:
    int val(vector<int>&pile,long long h,int mid)
    {
        if(mid==0){
            return 1;
        }
        long long cnt=0;
        for(int i=0;i<pile.size();i++)
        {
            cnt += pile[i]/mid ;
            if(cnt>h)
            return 1;
        }
        return cnt>=h;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long  strt=0;
        long long end=*max_element(candies.begin(),candies.end());
        long long ans=0;
        while(strt<=end){
            int mid=strt+(end-strt)/2;
            if(val(candies,k,mid)){
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