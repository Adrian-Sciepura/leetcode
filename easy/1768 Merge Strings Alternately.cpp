class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1_length = word1.length();
        int word2_length = word2.length();
        int difference = word1_length - word2_length;
        int commonLength = difference > 0 ? word2_length : word1_length;
        int currPos = 0;


        string newString;
        newString.resize(word1_length + word2_length);


        for(int i = 0; i < commonLength; i++)
        {
            newString[currPos] = word1[i];
            newString[currPos + 1] = word2[i];
            currPos += 2;
        }

        if(difference == 0)
            return newString;

        string& longerWord = difference > 0 ? word1 : word2;

        char* dst = newString.data() + sizeof(char) * currPos;
        char* src = longerWord.data() + sizeof(char) * commonLength;
        int size = longerWord.length() - commonLength;

        memcpy(dst, src, size);
        return newString;
    }
};