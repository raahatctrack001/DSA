class Solution {
public:
    int compress(vector<char>& chars) {
        //count and store the characters with their frequency;
        int count = 1;
        vector<pair<char, int> > charFrequency;
        for(int i = 1; i < chars.size(); i++){
            if(chars[i-1] == chars[i])
                count++;
            else{
                charFrequency.push_back({chars[i-1], count});
                count = 1;
            }
        }
        charFrequency.push_back({chars.back(), count});

        //lambda expression to convert integer frequency into string
        auto integerToString = [&](int a){
            string temp = "";
            while(a){
                temp += (a%10+'0');
                a /= 10;
            }
            //if frequency = 12 then temp will have 21 and hence
            //reversing will give 12 as string
            reverse(temp.begin(), temp.end());
            return temp;
        };
        //modifying the original character array
        int i = 0;
        for(auto &it : charFrequency){
            if(it.second == 1)
                chars[i++] = it.first;
            else{
                chars[i++] = it.first;
                int charCount = it.second;
                string getString = integerToString(charCount);
                for(auto &digit : getString){
                    chars[i++] = digit;
                }
            }
        }

        return i;
        
    }
};