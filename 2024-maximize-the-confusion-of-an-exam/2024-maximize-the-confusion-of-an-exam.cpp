class Solution {
public:
    int max_len_sub_array(string& anskey, char tar, char n_tar, int k)
    {
        int max_len=0, len=0;
        int i=0, j=0;

        while(j<anskey.size())
        {
            if(anskey[j]==n_tar && k>0)
            {
                k--;
                j++;
                continue;
            }
            else if(anskey[j]==tar)
            {
                j++;
                continue;
            }

            max_len=max(max_len, (j-1)-i+1);

            while(k==0)
            {
                if(anskey[i]==n_tar)
                {
                    k++;
                    i++;
                    break;
                }

                i++;
            }
        }

        max_len=max(max_len, (j-1)-i+1);
        return max_len;
    }

    int maxConsecutiveAnswers(string anskey, int k) 
    {
        int len_T=max_len_sub_array(anskey, 'T', 'F', k);
        int len_F=max_len_sub_array(anskey, 'F', 'T', k);

        return max(len_T, len_F);
    }
};