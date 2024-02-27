class Solution {
public:
    string reorganizeString(string s) {
        //first take the frequency of each element
        unordered_map<char, int> frequencyTable;
        for(auto &ch : s){
            frequencyTable[ch]++;
            //if frequency of any element is greater than size/2 then characters can't be reorganized
            //size+1 is takend to include case having even size
            if(frequencyTable[ch] > (s.size() + 1)/2)
                return "";
        }
        
        //using max-heap so that we can have access to element with max frequency at the top
        priority_queue<pair<int, char> >pq;
        for(auto &it : frequencyTable)
            pq.push({it.second, it.first});

        string result = "";
        
        //taking size >= 2 so that we can re arrange elements alternatively
        while(pq.size() >= 2){
            //first max frequency element
            pair<int, char> first = pq.top();
            char firstChar = first.second;
            pq.pop();

            //second max frequency element;
            pair<int, char> second = pq.top();
            char secondChar = second.second;
            pq.pop();

            result += firstChar;
            result += secondChar;

            //if elements is still left then push it back to pq 
            if(first.first-1 > 0)
                pq.push({first.first-1, firstChar});
            if(second.first-1 > 0)
                pq.push({second.first-1, secondChar});
        }
        
        if(!pq.empty())
            result += pq.top().second;
        return result;
    }
};