class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //need to create result vector 
        vector<int> res;
        //creating hash table to hold values
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++){
        	umap[nums[i]] = i; //mapping value to index

        	if(umap.find(target-nums[i])){ //a match has been found
        		res.push_back(i);
        		res.push_back(umap[nums[target-nums[i]]);
        		break;
        	}
        }



        return res;
    }
};