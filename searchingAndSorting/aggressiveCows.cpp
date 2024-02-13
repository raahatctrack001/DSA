//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPossible(vector<int> &stalls, int mid, int k){
        int placedCows = 1;
        int pos = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i]-pos >= mid){
                placedCows++;
                pos = stalls[i];
                if(placedCows == k)
                    return true;
            }
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        
        int start = 0;
        int end = stalls[stalls.size()-1]-stalls[0];
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isPossible(stalls, mid, k)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};