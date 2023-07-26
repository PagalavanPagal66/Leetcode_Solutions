class Solution {
public:
    
    bool isPossible(vector<int>& dist, double hour, int speed){
        int n=dist.size();
        
        double time=0;
        
        for(int i=0;i<n-1;i++){
            time += dist[i]/speed;
            
            if(dist[i]%speed!=0) time++;
        }
        time += double(dist[n-1])/speed; 
        
        return (time<=hour);
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1;
        int right=(int)(1e7+5);
        
        while(left<right){
            int mid=left+(right-left)/2;
            if(isPossible(dist,hour,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        
        return (left < 1e7+1 ? left:-1); 
    }
};