class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        int cnt=0;
        int strt=0;
        int end=costs.size()-1;
        c*=2;
        vector<int>v(costs.size(),0);
        while(strt<=end){
            if(v[strt]!=0){
                break;
            }
            pq.push({costs[strt],strt});
            v[strt]++;
            strt++;
            cnt++;
            if(cnt==c){
                break;
            }
            if(v[end]!=0){
                break;
            }
            pq.push({costs[end],end});
            v[end]++;
            end--;
            cnt++;
            if(cnt==c){
                break;
            }
        }
        cout<<strt<<" "<<end<<endl;
        long long sum=0;
        while(k--){
            if(pq.empty()){
                return sum;
            }
            sum+=pq.top().first;
            cout<<"popped: "<<pq.top().first<<endl;
            int removed = pq.top().second;
            pq.pop();
            if(removed<strt && strt<costs.size()){
                if(v[strt]==0){
                    pq.push({costs[strt],strt});
                    v[strt]++;
                }
                strt++;
            }
            else if(removed >end && end>=0){
                if(v[end]==0){
                    pq.push({costs[end],end});
                    v[end]++;
                }
                end--;
            }
        }
        return sum;
    }
};
