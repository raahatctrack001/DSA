class Solution {
public:
    string frequencySort(string s) {
        //storing uqique characters to get their frequencies
        set<char> st;
        for(auto &ch : s)
            st.insert(ch);

        vector<pair<int, char> > frequencyTable;
        for(auto &it : st){
            //getting the count of it stored in set
            int charCount = count(s.begin(), s.end(), it);
            frequencyTable.push_back({charCount, it});
        }
        //traditional sorting will sort the vector in ascending order hence we applied custom sorting to sort them in descending order.
        sort(frequencyTable.begin(), frequencyTable.end(), [](const auto &a, const auto &b)->bool{
            return a.first > b.first;
        });
        string ans = "";

        for(auto &frequencyPair : frequencyTable){
            int frequency = frequencyPair.first;
            char ch = frequencyPair.second;
            while(frequency--)
                ans += ch;
        }
        return ans;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> frequencyTable;
        for(auto &ch : s){
            frequencyTable[ch]++;
        }
        //to get auto sorted frequency table we use priority queue or max heap
        priority_queue<pair<int, char> > sortedFrequencyTable;

        for(auto &frequencyPair : frequencyTable){
            char ch = frequencyPair.first;
            int frequency = frequencyPair.second;
            cout<<frequency<<" "<<ch<<endl;
            sortedFrequencyTable.push({frequency, ch});
        }

        string ans = "";
        while(!sortedFrequencyTable.empty()){
            pair<int, char> temp = sortedFrequencyTable.top();
            sortedFrequencyTable.pop();

            int frequency = temp.first;
            char ch = temp.second;
            // cout<<ch<<" "<<frequency<<endl;
            while(frequency--){
                ans += ch; 
            }
        }
        return ans;
        
    }
};