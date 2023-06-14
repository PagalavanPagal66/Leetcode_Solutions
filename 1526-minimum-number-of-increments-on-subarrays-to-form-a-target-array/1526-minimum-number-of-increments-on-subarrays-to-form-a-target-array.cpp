class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int count=0;
        for(int i=0;i<target.size();i++)
        {
            if(i==0)count+=target[i];
            else
            {
                int a=target[i]-target[i-1];
                if(a>=0)count+=a;
            }
        }
        return count;
    }
};