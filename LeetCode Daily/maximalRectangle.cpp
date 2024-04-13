class Solution {
    private:
    vector<int> nextSmallerIndex(vector<int> &arr, int n){
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i = n-1; i > -1; i--){

            int curr = arr[i];
            while(st.top()!=-1 and arr[st.top()] >= curr)
                st.pop();

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

     vector<int> prevSmallerIndex(vector<int> &arr, int n){
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i = 0; i < n; i++){

            int curr = arr
            [i];
            while(st.top()!=-1 and arr[st.top()] >= curr)
                st.pop();

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
     }
    

    int areaOfHistogram(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n), prev(n);
        next = nextSmallerIndex(heights, n);
        prev = prevSmallerIndex(heights, n);
        int area = INT_MIN;
        for(int i = 0; i < n; i++){
            int len = heights[i];
            if(next[i] == -1)
                next[i] = n; 
            int breadth = next[i] - prev[i] - 1;
            int newArea = len*breadth;
            area = max(area, newArea);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
            vector<int> histogram(matrix[0].size(), 0);

            int area = INT_MIN;
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < histogram.size(); j++){
                    if(matrix[i][j] == '1')
                        histogram[j]++;
                    else 
                        histogram[j] = 0;
                }
                area = max(area, areaOfHistogram(histogram));
            }
            return area;
    }
};