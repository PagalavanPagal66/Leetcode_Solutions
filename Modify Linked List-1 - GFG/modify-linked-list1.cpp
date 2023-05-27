//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* reverse(Node* head){
        if(!head || !head->next){
            return head;
        }
        Node* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        // Break the linked List from middle in O(n) time Using fast and slow pointers
        if(!head || head->next  == NULL)
            return head;
        Node* fast = head->next->next,*slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != NULL)
            slow = slow->next;
        Node* head2 = reverse(slow->next);
        slow->next =  NULL;
        Node* t1 = head, *t2 = head2;
        while(t1 && t2){
            t1->data = t2->data - t1->data;
            t2->data = t2->data - t1->data;
            t1 = t1->next, t2= t2->next;
        }
        head2 = reverse(head2);
        slow->next = head2;
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends