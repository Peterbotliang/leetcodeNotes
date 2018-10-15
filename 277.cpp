// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) 
    {
        int celebrity = 0;
        // Find the possible celebrity
        for (int i = 0; i < n; i++)
        {
            if (knows(celebrity, i))
                celebrity = i;
        }
        
        // Verify celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != celebrity)
            {
                if (!knows(i, celebrity) || knows(celebrity, i))
                    return -1;
            }
        }
        return celebrity;
    }
};
