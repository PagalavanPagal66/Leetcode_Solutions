class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,int>mp;
        for(auto i:deadends){
            mp[i]++;
        }
        queue<string>q;
        q.push("0000");
        map<string,int>vis;
        vis["0000"] = 1;
        if(mp.find("0000")!=mp.end()){
            return -1;
        }
        if(target == "0000" ){
            return 0;
        }
        int moves = 1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string curr = q.front();
                //cout<<curr<<endl;
                q.pop();
                if(mp.find(curr)!=mp.end()){
                    continue;
                }
                for(int i=0;i<4;i++){
                    string inc = curr;
                    string dec = curr;
                    if(inc[i]=='9'){
                        inc[i]='0';
                    }
                    else{
                        inc[i]++;
                    }
                    if(dec[i]=='0'){
                        dec[i] = '9';
                    }
                    else{
                        dec[i]--;
                    }
                    if(mp.find(inc)==mp.end()){
                        if(vis.find(inc)==vis.end()){
                            vis[inc] = moves;
                            q.push(inc);
                        }
                        if(inc==target){
                            return moves;
                        }
                    }
                    if(mp.find(dec)==mp.end()){
                        if(vis.find(dec)==vis.end()){
                            vis[dec] = moves;
                            q.push(dec);
                        }
                        if(dec==target){
                            return moves;
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};