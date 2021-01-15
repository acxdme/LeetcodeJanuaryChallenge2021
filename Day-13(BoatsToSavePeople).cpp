/*
Time complexity : O(NlogN)
Space complexity : O(1)
My appraoch : A modest variation of the two sum problem.
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        int count =0;
        sort(people.begin(),people.end());
        int low =0, high = people.size()-1;
        while(low <=high)
        {
            if(people[low]+people[high] <= limit) // both heavy and light cant fit in boat
            {
                count++;
                low++;
                high--;
            }
            else //given that a person's weight dosen't exceeds the limit, so we put the heaviest alone in boat
            {
                    high--;
                    count++;
            }
        }
        
        return count;
        
    }
};
