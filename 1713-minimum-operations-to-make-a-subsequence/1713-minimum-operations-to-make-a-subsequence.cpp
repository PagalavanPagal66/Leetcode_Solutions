class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> targetTrace;
        int index =0;
        for(int element : target){ targetTrace[element] = index++; }
        vector<int> sequence;
        for(int element : arr){
            if(targetTrace.find(element)==targetTrace.end()){ continue;}
            if(sequence.empty()) {sequence.push_back(element); continue;}
            if(targetTrace[sequence[0]] > targetTrace[element]) 
            {sequence[0] = element; continue;}
            if(targetTrace[sequence.back()]< targetTrace[element]) 
            {sequence.push_back(element); continue;}
            int left = 0, right = sequence.size()-1;
            int mid = left + (right-left)/2;
            while(right>left){ 
                mid = left + (right-left)/2;           
                if(targetTrace[element] > targetTrace[sequence[mid]]) 
                    left = mid+1;
                else right = mid;
                
            }
            sequence[left] = element;
        }
        return target.size()-sequence.size();
    }
};