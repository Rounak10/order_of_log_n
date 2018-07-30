/*Length of the longest substring with equal 1s and 0s*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int>m;
        
        int count = 0, max_len = 0;
        m[0] = -1;
        for(int i = 0; i<nums.size(); i++)
        {

            
            count = count + (nums[i] == 1 ? 1 : -1);
                
            if(m.find(count) != m.end())
            {
                max_len = max(max_len, i - m[count]);
            }
            else{
                
                m[count] = i;
            }
        }
        
        return max_len;
        
    }
};
