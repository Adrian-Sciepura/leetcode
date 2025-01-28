class Solution {
private:
    int writeIntToBuffer(uint num, int position, vector<char>& buffer)
    {
        static char digitBuffer[5];
        int size = 0;

        do
        {
            digitBuffer[size++] = (num % 10) + '0';
            num /= 10;
        } while(num != 0);

        for(int i = size - 1; i >= 0; i--)
        {
            buffer[position++] = digitBuffer[i];
        }

        return size;
    }

public:
    int compress(vector<char>& chars) {
        int length = chars.size();
        int newLength = 0;
        int groupLength = 0;
        int index = 0;
        char groupChar = 0;

        if(length == 1)
            return 1;

        while(index < length)
        {
            groupChar = chars[index];
            groupLength = 0;

            while(index < length && chars[index] == groupChar)
            {
                groupLength++;
                index++;
            }

            if(groupLength > 1)
            {
                chars[newLength++] = groupChar;
                newLength += writeIntToBuffer(groupLength, newLength, chars);
            }
            else
            {
                chars[newLength++] = groupChar;
            }
        }

        chars.resize(newLength);
        return newLength;
    }
};