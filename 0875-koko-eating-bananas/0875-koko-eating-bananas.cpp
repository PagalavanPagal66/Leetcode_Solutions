class Solution {
public:
    bool canEat(int n, int h, int speed, vector<int>&piles){
        int cnt=0; // cnt tracks the hours needed to eat bananas
        for (int i=0; i<n; i++){ // iterate over the array
            cnt+= (piles[i]/speed);
            if(piles[i]%speed==0){ // it can eat with proper speed and can finish all bananas
                cnt+=0;
            }
            else{ // there must be some banana left at that pile that has range(1 to n-1)
                cnt+=1;
            }
            if (cnt>h)return false;
        }
        if(cnt>h){
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int strt=1;
        int end= *max_element(piles.begin(),piles.end()); 
        int ans;
        while (strt<=end){
            int mid= strt+(end-strt)/2;
            if (canEat(piles.size(),h,mid,piles)==true){
                ans= mid;
                end= mid-1;
            }
            else strt= mid+1;
        }
        return ans;
    }
};