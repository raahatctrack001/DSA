//with map
class Solution {
public:
    vector<int> intersection(vector<int>& first, vector<int>& second) {
        unordered_map<int, int> freq;
        for(auto &num: first)
            freq[num]++;

        vector<int> ans;
        for(auto &num : second){
            if(freq.find(num) != freq.end() and freq[num] > 0){
                ans.push_back(num);
                freq[num] *= -1;
            }
        }
        return ans;
    }
};

//without map
class Solution {
public:
    vector<int> intersection(vector<int>& first, vector<int>& second) {
        int freq[1000];
        for(auto &num: first)
            freq[num]++;
        
        vector<int> ans;
        for(auto &num: second){
            if(freq[num] > 0){
                ans.push_back(num);
                freq[num] *= -1;
            }
        }
        return ans;
    }
};

//set with binary search
class Solution {
    auto binarySearch(vector<int> &nums, int key){
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == key)
                return true;
            else if(nums[mid] < key)
                start = mid+1;
            else
                end = mid-1;
        }
        return false;
    };
public:
    vector<int> intersection(vector<int>& first, vector<int>& second) {
        set<int> st;
        for(auto &num: first)
            st.insert(num);

        vector<int> ans;
        sort(second.begin(), second.end());
        for(auto &it : st){
            if(binarySearch(second, it))
                ans.push_back(it);
        }

        return ans;
    }
};