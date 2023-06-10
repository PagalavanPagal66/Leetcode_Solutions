class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long low=1ll,high=1ll*maxSum;
        long long ans;
        while(low<=high) { // Binary search
            long long mid=(low+high)>>1;
            if(isPossible(mid,n,maxSum*1ll,index)) {
                ans=mid; // store correct answer
                low=mid+1; // move to right to get the optimal answer
            }
            else high=mid-1; /* if mid cannot be maximum 
then all values >mid also cannot be maximum, hence we move to left of the search space */
        }
        return ans;
    }
    bool isPossible(long long mid, int n, long long sum,int index) {
        if(sum<mid) return false; 
        sum-=mid;
        long long left = index; 
        long long right= n-index-1; 
        long long temp=mid-1; 
        long long totSum=0;
        if(left>=temp) { 
            totSum+=(temp*(temp+1))/2; 
            left-=temp;
            if(left>0) totSum+=left; 
        }
        else {
            long long extra = temp-left; 
            long long tempSum=(temp*(temp+1))/2-((extra*(extra+1))/2);
            totSum+=tempSum;
        }
        if(right>=temp) {
            totSum+=(temp*(temp+1))/2;
            right-=temp;
            if(right>0) totSum+=right;
        }
        else {
            long long extra = temp-right;
            long long tempSum=(temp*(temp+1))/2-((extra*(extra+1))/2);
            totSum+=tempSum;
        }
        return totSum<=sum;


    }
};