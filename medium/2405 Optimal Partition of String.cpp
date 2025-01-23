class Solution {
private:
    static constexpr int noOfCharacters = 26;
    int found[noOfCharacters] = { 0 }; 

    inline int substring(const string& s, int length, int startPos)
    {
        int i = startPos;
        for(; i < length; i++)
        {
            int idx = s[i] - 'a';
            
            if(found[idx] != 0)
                break;

            found[idx] += 1;
        }

        memset(&found, 0, noOfCharacters * sizeof(int));

        return i;
    }    

public:
    int partitionString(string s) {
        
        int length = s.length();
        int currPos = 0;
        int substrings = 0;

        while(currPos < length)
        {
            currPos = substring(s, length, currPos);
            substrings += 1;
        }

        return substrings;
    }
};