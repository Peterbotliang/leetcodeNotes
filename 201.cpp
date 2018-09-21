class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        bitset<32> m2(m);
        bitset<32> n2(n);

        int i;
        for (i = 31; i >= 0; i--)
        {
            if (m2[i] != n2[i])
                break;
        }
        
        m2 &= ~(bitset<32>((int)(pow(2, i + 1)) - 1));
        return m2.to_ulong();
    }
};
