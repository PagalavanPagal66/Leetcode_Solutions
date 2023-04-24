class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto p : piles) pq.push(p);
        while(k--) {
            int n = pq.top();
            pq.pop();
            pq.push(n - n / 2);
        }
        int sum = 0;
        while(pq.size()!=0) {
            sum += pq.top(); 
            pq.pop();
        }
        return sum;
    }
};