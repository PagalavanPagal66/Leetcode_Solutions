class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>res;
        for(int i=0;i<n-1;i++){
            int strt=i+1;
            int end=n-1;
            while(strt<=end){
                int mid=strt+(end-strt)/2;
                if(numbers[mid]+numbers[i]==target){
                    res.push_back(i+1);
                    res.push_back(mid+1);
                    return res;
                }
                if(numbers[mid]+numbers[i]<target){
                    strt=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return res;
    }
};