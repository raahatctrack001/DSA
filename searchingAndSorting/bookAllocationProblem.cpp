bool isPossibleSolution(vector<int> &arr, int mid, int m, int n){
    int pageSum = 0;
    int studentCount = 1;
    for(int i = 0; i < n; i++){
        if(pageSum+arr[i] <= mid)
            pageSum += arr[i];
        
        else{
            studentCount++;
            if(studentCount > m or arr[i] > mid)
                return false;
            pageSum = arr[i];
        }
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    // m = total student
    //n = size of array
    if(m > n)
        return -1;
        
    int start = 0;
    int end = 0;
    int ans = -1;

    for(int i = 0; i < n; i++)
        end += arr[i]; 

    while(start <= end){
        int mid = start + (end - start)/2;
        if(isPossibleSolution(arr, mid, m, n)){
            ans = mid;
            end = mid-1;
        }
        else    
            start = mid+1;
    }
    return ans;
}