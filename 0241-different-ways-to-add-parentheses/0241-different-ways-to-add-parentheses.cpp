class Solution {
public:

    vector<int> diffWaysToCompute(string expression) {
        int ind=0;
        vector<int>res;
        for(auto i:expression){
            if(i=='+' || i=='-' || i=='*'){
                vector<int>l=diffWaysToCompute(expression.substr(0,ind));
                vector<int>r=diffWaysToCompute(expression.substr(ind+1));
                for(auto a:l){
                    for(auto b:r){
                        if(i=='+'){
                            res.push_back(a+b);         
                        }
                        if(i=='-'){
                            res.push_back(a-b);
                        }
                        if(i=='*'){
                            res.push_back(a*b);
                        }
                    }
                }
            }
            ind++;
        }
        if(res.size()==0){
            res.push_back(stoi(expression));
        }
        return res;
    }
};