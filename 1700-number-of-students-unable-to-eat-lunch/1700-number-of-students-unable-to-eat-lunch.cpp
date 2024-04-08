class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0,j=0;
        int count = 0;
        while(i != sandwiches.size()){
            if(sandwiches[i] == students[j]){
                i++;
                j++;
                count = 0;
            }else{
                if(count == sandwiches.size() - i){
                    break;
                }
                students.push_back(students[j]);
                j++;
                count++;
            }
        }
        return count;
    }
};