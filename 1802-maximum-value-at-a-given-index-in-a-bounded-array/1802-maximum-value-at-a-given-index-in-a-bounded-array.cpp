class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long low=1ll,high=1ll*maxSum;
        long long ans;
        while(low<=high) { 
            long long mid=(low+high)/2;
            if(isPossible(mid,n,maxSum*1ll,index)) {
                ans=mid; 
                low=mid+1; 
            }
            else high=mid-1; 
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