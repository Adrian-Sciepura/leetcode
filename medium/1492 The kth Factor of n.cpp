class Solution {
public:
    int kthFactor(int n, int k) {
        int step = n % 2 == 0 ? 1 : 2;
        int count = 0;

        for(int i = 1; i <= n/2; i += step)
        {
            if (n % i == 0)
            {
                count++;
                if(count == k)
                    return i;
            }
        }

        if(count == k-1)
            return n;

        return -1;
    }
};