class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_par(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find_par(parent[node]);
    }
    void add(int u,int v){
        int x = find_par(u);
        int y = find_par(v);
        if(size[x]>=size[y]){
            size[x]+=size[y];
            parent[y] = x;
        }
        else{
            size[y]+=size[x];
            parent[x] = y;
        }
    }
    int compsize(){
        int cnt=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);      
        map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                    dsu.add(i,mp[accounts[i][j]]);
                    mp[accounts[i][j]] = dsu.find_par(i);
                }
            }
        }
        vector<string>mail[n];
        for(auto i:mp){
            string mailid = i.first;
            int upar = dsu.find_par(i.second);
            mail[upar].push_back(i.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mail[i].size()==0){
                continue;
            }
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto i:mail[i]){
                temp.push_back(i);
            }
            sort(temp.begin()+1,temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};