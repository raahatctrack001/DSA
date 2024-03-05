class Solution {
public:
    int minimumLength(string s) {        
        int i = 0;
        int j = s.size()-1;
        //i and j should not intersect and first and last element must be same
        while(i < j and s[i] == s[j]){
            while(i < j and s[i] == s[i+1])
                i++;
            while(j > i and s[j] == s[j-1])
                j--;
            //if intersection is there that means all the characters is deleted and no further action needed
            if(i >= j)
                return 0;
            i++;
            j--;
        }
        //return the length of string left
        return j-i+1;        
        
    }
};