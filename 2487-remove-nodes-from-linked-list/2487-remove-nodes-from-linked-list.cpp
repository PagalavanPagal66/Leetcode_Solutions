/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* t=head;
        stack<int>st;
        while(t){
            if(st.empty()){
                st.push(t->val);
                t=t->next;
            }
            else if(st.top()>=t->val){
                st.push(t->val);
                t=t->next;
            }
            else{
                st.pop();
            }
        }
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        ListNode *first=NULL,*last=NULL;
        for(int i=v.size()-1;i>=0;i--){
            int data=v[i];
            ListNode* newn=(struct ListNode*)malloc(sizeof(struct ListNode));
            newn->val=data;
            newn->next=NULL;
            if(first==NULL){
                first=last=newn;
            }
            else{
                last->next=newn;
                last=newn;
            }
        }
        return first;
    }
};