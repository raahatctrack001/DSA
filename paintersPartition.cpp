//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
    bool isPossible(int arr[], int n, int k, int mid){
        int wallSum = 0, workersCount = 1;
        for(int i = 0; i < n; i++){
            if((wallSum+arr[i]) <= mid)
                wallSum += arr[i];
            else{
                workersCount++;
                wallSum = arr[i];
                if(workersCount > k)
                    return false;
            }
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int s = 0, e = accumulate(arr, arr+n, 0), ans = -1;
        int mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                e = mid-1;
            }
            else 
                s = mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends