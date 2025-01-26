class Solution {
private:
     static inline bool vowels[26] = {
            true,  //a
            false, //b
            false, //c
            false, //d
            true,  //e
            false, //f
            false, //g
            false, //h
            true,  //i
            false, //j
            false, //k
            false, //l
            false, //m
            false, //n
            true,  //o
            false, //p
            false, //q
            false, //r
            false, //s
            false, //t
            true,  //u
            false, //v
            false, //w
            false, //x
            false, //y
            false, //z
        };

    bool isVowel(char c)
    {
       int idx = c;
       idx -= c >= 'a' ? 'a' : 'A';
       if(idx < 0 || idx > 26)
        return false;

       return vowels[idx];
    }

public:
    string reverseVowels(string s) {
        int length = s.length();
        int left = 0;
        int right = length - 1;
        bool leftFound = false;
        bool rightFound = false;

        string result(s);

    while (left < right)
    {
        if (!leftFound)
            if(isVowel(result[left]))
                leftFound = true;
            else
                left++;
        
        if (!rightFound)
            if(isVowel(result[right]))
                rightFound = true;
            else
                right--;

        if (leftFound && rightFound)
        {
            char tmp = result[left];
            result[left] = result[right];
            result[right] = tmp;
            left++;
            right--;
            leftFound = false;
            rightFound = false;
        }
    }
        
        return result;
    }
};