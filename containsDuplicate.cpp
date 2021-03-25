class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> htable;
        
        for(int i = 0; i < nums.size(); i++){
            if(htable.find(nums[i]) == htable.end())
                htable[nums[i]] = i;
            else
                return true;
        }
        
        
        return false;
    }
};
