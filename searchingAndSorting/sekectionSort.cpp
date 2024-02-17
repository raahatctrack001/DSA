//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i, int n = 0)
    { 
        // code here such that selectionSort() sorts arr[]
       int minIndex = i;
       for(int j = i+1; j < n; j++){
           if(arr[minIndex] > arr[j])
            minIndex = j;
       }
       return minIndex;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       int minIndex = 0;
       for(int i = 0; i < n; i++){
           minIndex = select(arr, i, n);
           swap(arr[i], arr[minIndex]);
       }
    }
     void selectionSort(int arr[], int n)
    {
       //code here
       int minIndex = 0;
       for(int i = 0; i < n; i++){
           minIndex = i;
          for(int j = i+1; j < n; j++){
              if(arr[minIndex] > arr[j])
                minIndex = j;
          }
          swap(arr[i], arr[minIndex]);
       }
    }
};
