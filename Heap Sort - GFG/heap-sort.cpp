//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
void heapify(int arr[], int n, int i)
{
    // Firstly initialise the largest to root;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Check if left is larger and update largest accordingly
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right]>arr[largest])
    {
        largest = right;
    }
    // If the current root is not largest
    if(largest!=i)
    {
        // To swap the root with largest element so far
        swap(arr[i],arr[largest]);
        // To heapify the affected subtree (the next levels)
        heapify(arr,n,largest);
    }
}
// Function to build Heap 
void buildHeap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
// Function for Heap Sort
void heapSort(int arr[], int n)
{
    buildHeap(arr,n);
    // We extract max element from heap and put it to end of array and then heapify the remaining array
    for(int i=n-1;i>=0;i--)
    {
        // After heapify larget element will be at the first place in array
        swap(arr[0],arr[i]);
        // To heapify remaining tree
        heapify(arr,i,0);
    }
}
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends