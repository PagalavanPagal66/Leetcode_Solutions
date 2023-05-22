//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node *result(int pre_SI,int pre_EI,int preM_SI,int preM_EI,int pre[],int preMirror[])
    {
        if(pre_SI>pre_EI)
        {
            return NULL;
        }
        Node *r=new Node(pre[pre_SI]);
        if(pre_SI==pre_EI)
        {
        return r;
        }
        int val=pre[pre_SI+1];
        int pos=0;
        for(int i=preM_SI;i<=preM_EI;i++)
        {
            if(val==preMirror[i])
            {
                pos=i;
            }
        }
        r->left=result(pre_SI+1,pre_SI+preM_EI-pos+1,pos,preM_EI,pre,preMirror);
        r->right=result(pre_SI+preM_EI-pos+2,pre_EI,preM_SI+1,pos-1,pre,preMirror);
        return r;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
       return result(0,size-1,0,size-1,pre,preMirror);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends