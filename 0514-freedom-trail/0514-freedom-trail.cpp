class Solution {
public:
    int dp[101][101];

    int rec( int keyIdx , int ringIdx , string &ring , string &key)
    {
        if(keyIdx == key.length())
        {
            return 0;
        }

        if(dp[keyIdx][ringIdx] != -1)
        {
            return dp[keyIdx][ringIdx];
        }
        
        int stepsRequired = 1e9;
        int temp = ringIdx;
        int count = 0;
        
        int size = ring.length();

        while( count < size)
        {
            if(key[keyIdx] == ring[temp])
            {
                stepsRequired = min(stepsRequired , 1 + count + 
                rec( keyIdx + 1 , temp , ring , key));
            }
            count += 1;
            temp  += 1;

            temp = temp % size; 
        }

        count = 0;
        temp = ringIdx;

        while( count < size)
        {
            if(key[keyIdx] == ring[temp])
            {
                stepsRequired = min(stepsRequired , 1 + count + 
                rec( keyIdx + 1 , temp , ring , key));
            }
            count += 1;
            temp  -= 1;

            temp += size;

            temp %= size; 
        }
        
        return dp[keyIdx][ringIdx] = stepsRequired;
    }
    int findRotateSteps(string ring, string key) {
        
        memset(dp , -1 , sizeof(dp));

        return rec( 0 , 0 , ring , key);
    }
};