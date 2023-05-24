class Solution {
public:
 
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums1[i],nums2[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long sum=0,ans=-1; 
        for(int i=0;i<n;i++)
        {
           pq.push({v[i].second,v[i].first});
           sum+=v[i].first;
           if(pq.size()==k)
           {
                int s=pq.top().second;
                int m=pq.top().first;
                pq.pop();
                if(sum*1LL*m>ans)
                 ans=sum*1LL*m;
                sum-=s;

           }   
        }
        return ans;
    }
};