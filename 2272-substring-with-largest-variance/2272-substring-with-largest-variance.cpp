class Solution {
    int Kadane(int x, int y, string &s)
    {
        int d = 0, n = s.size();
        int ans = 0, ycnt = 0;
        for(int i = 0; i < n; i++)
        {
            if((s[i]-'a') == x)
            {
                d++;
            }
            else if((s[i]-'a') == y)
            {
                d--;
                ycnt = 1;
            }
            if(ycnt != 0)
            {
                ans = max(ans, d);
            }
            else
            {
                ans = max(ans, d-1);
            }
            if(d < 0)
            {
                ycnt = 0;
                d = 0;
            }
        }
        return ans;
    }
public:
    int largestVariance(string s) {
        vector<int> alphabet(26,0);
        int ans = 0;
        for(char &ch : s)
            alphabet[ch-'a']++;
        for(int i = 0; i < 25; i++)
        {
            if(alphabet[i] == 0) continue;
            for(int j = i+1; j < 26; j++)
            {
                if(alphabet[j] == 0) continue;
                int val = max(Kadane(i,j,s), Kadane(j,i,s));
                ans = max(val, ans);
            }
        }
        return ans;
    }
};
