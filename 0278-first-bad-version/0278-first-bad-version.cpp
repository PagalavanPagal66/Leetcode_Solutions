// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2; 
            if(isBadVersion(mid)==0){ // it is good . So removing the first half from search space
                low=mid+1;
            }
            else if(isBadVersion(mid)==1 && isBadVersion(mid-1)==0){
                //current element is bad and the previous element is good
                return mid;
                //answer found
            }
            else if(isBadVersion(mid)==1){
                // it is a bad version but the second half will never be a first bad version
                high=mid-1;
                // since we already got a bad version before the second half starts (mid)
            }
        }
        return 0;
    }
};