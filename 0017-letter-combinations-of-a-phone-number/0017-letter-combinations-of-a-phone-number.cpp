class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;

        if(digits.length()==0)return res;
        res.push_back("");

        for(int i=0;i<digits.length();i++){
            vector<string>ans;
            string map_str=mapping[digits[i]-'0'];
            for(int j=0;j<map_str.length();j++){
                for(int k=0;k<res.size();k++){
                    string temp=res[k];
                    ans.push_back(temp+map_str[j]);
                }
            }
            res.swap(ans);
        }
        return res;
        
    }
};
