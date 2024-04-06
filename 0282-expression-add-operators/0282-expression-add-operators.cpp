#define ll long long

class Solution {
public:
    string s;
    ll goal;
    vector<string> ans;

    void recurse (string exp, ll val, ll prev, int i) {
        if (i == s.size()) {
            if (val == goal) ans.push_back(exp);
            return;
        }
        for (int j=i; j<s.size(); j++) { 
            string sub = s.substr(i, j-i+1);
            ll foo = stoll(sub);
            if (j>i && s[i]=='0') return; 
            if (i==0) { 
                recurse(sub, foo, foo, j+1);
            }
            else {
                recurse(exp+"+"+sub, val+foo, foo, j+1);
                recurse(exp+"-"+sub, val-foo, -foo, j+1);
                recurse(exp+"*"+sub, val-prev+prev*foo, prev*foo, j+1); 
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        goal = target;  
        s = num; 
        recurse ("", 0, 0, 0);
        return ans;
    }
};