class Solution {
public:
    /*----------------recursive binary search-------------------------
    bool binarySearch(vector<int>&arr, int left, int right,int target){
        if(left==right && arr[left]==target)
            return true;
        if(left<right){
            int mid=left+(right-left)/2;
            if(arr[mid]==target)
                return 1;
            if(arr[mid]<target)
                return binarySearch(arr,mid+1,right,target);
            if(arr[mid]>target)
                return binarySearch(arr,left,mid,target);
        }
        return 0;
    }
    */
    //----------------looping binary search --------------------------
    
    bool binarySearch(vector<int>&arr,int left,int right,int target){
        while(left<=right){
            int mid=(right+left)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
    //----------------pre defined function----------------------------
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); 
        int m=matrix[0].size(); 
        int wanted=-1;
        for(int i=0; i<n; i++){
            if(matrix[i][0]<target && target<matrix[i][m-1])
                wanted=i;
            if(matrix[i][0]==target || matrix[i][m-1]==target) return 1;
        }
        if(wanted==-1) return 0;
        return binarySearch(matrix[wanted],0,m-1,target);
    }
};