class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto i:stones)pq.push(i);
        while(true){
            if(pq.size()==1){
                return pq.top();
            }
            if(pq.size()==0){
                return 0;
            }
            int temp=pq.top();
            pq.pop();
            int temp2=pq.top();
            pq.pop();
            if(temp==temp2){
                continue;
            }
            if(temp>temp2){
                pq.push(temp-temp2);
            }
        }
        return 0;
    }
};