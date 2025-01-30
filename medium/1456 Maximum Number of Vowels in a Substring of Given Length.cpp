class Solution {
private:
    inline bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int length = s.length();
        int maxVowels = 0;
        int vowels = 0;

        for(int i = 0; i < k; i++)
        {
            maxVowels += static_cast<int>(isVowel(s[i]));
        }

        vowels = maxVowels;
        for(int i = k; i < length; i++)
        {
            vowels += static_cast<int>(isVowel(s[i]));
            vowels -= static_cast<int>(isVowel(s[i - k]));

            if(vowels > maxVowels)
                maxVowels = vowels;
        }

        return maxVowels;
    }
};