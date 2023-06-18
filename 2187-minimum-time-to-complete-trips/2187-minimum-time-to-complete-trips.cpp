#define ll long long 
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start = 1;
        ll end = 1e14;
        ll ans=0;
        while(start <= end){
            long long mid=start+(end-start)/2;
            long long t=0;
            for(int i=0;i<time.size();i++)
            {
                t+=mid/time[i];
            }
            if(t>=totalTrips)
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return start;
    }
};