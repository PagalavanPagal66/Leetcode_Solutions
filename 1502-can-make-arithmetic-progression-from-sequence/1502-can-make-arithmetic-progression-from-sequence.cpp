class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dif=arr[0]-arr[1];
        for(int i=0;i<arr.size()-1;i++){
            if(dif!=(arr[i]-arr[i+1]))return false;
        }
               return true;
    }
};