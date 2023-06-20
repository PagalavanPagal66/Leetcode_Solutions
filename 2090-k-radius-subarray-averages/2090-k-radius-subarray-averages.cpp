class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> vec;
        vector<long long int> prefSum;
        long long int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            prefSum.push_back(sum);
        }

        int m = 0, p = ((2*k) + 1);
        for(int i=0; i<n; i++)
        {
            if((i-k) < 0 || (i+k) >= n){
                vec.push_back(-1);
            }

            else if((i - k) == 0)
            {
                vec.push_back(prefSum[i+k]/p);
            }

            else{
                vec.push_back((prefSum[i+k] - prefSum[m]) / p);
                //cout << prefSum[i+k] << " " << prefSum[m] << " " << p << endl;
                m++;
            }
        }

        return vec;
    }
};