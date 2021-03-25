class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> htable;
        
        for(int i = 0; i < nums.size(); i++){
            if(htable.find(nums[i]) == htable.end()){
                htable[nums[i]] = i;
            }
            else{
                if(abs(i-htable[nums[i]]) <= k)
                    return true;
                else
                    htable[nums[i]] = i;
            }
        }
        
        
        return false;
    }
};
