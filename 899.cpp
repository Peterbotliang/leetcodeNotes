class Solution {
public:
    string orderlyQueue(string S, int K) 
    {
        string result = "";
        if (K > 1)
        {
            vector<int> freq(26, 0);
            for (int i = 0; i < S.size(); i++)
                freq[S[i] - 'a']++;
            
            for (int i = 0; i < 26; i++)
                result += string(freq[i], (char)(i + 'a'));    
            return result;
        }
        
        result = S;
        for (int i = 0; i < S.size(); i++)
        {
            char ch = S.front();
            S.erase(0, 1);
            S += ch;
            result = min(S, result);
        }
        return result;
    }
};
