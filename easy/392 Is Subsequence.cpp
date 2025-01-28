class Solution {
public:
    bool isSubsequence(string s, string t) {
        int subsequenceLength = s.length();
        int stringLength = t.length();
        int subsequenceIndex = 0;

        if(subsequenceLength == 0)
            return true;

        for(int stringLetter = 0; stringLetter < stringLength; stringLetter++)
        {
            if(t[stringLetter] == s[subsequenceIndex])
            {
                subsequenceIndex++;
                if(subsequenceIndex == subsequenceLength)
                    return true;
            }
        }

        return false;
    }
};