/*

Problem: Given an array of distinct integers, return all of the possible 
permutations. You can return teh answer in any order


Algorithm:

	permute():
		check if there is nothing or only one element => return that
		for every element in nums:
			call permute helper => go to the helper functioon

	helper(vector<int>& nums, vector<int>& a, target_size):
		if a.size() == target_size : add to res and return 
		else:
			for every element in nums not in already in a:
				add to a 
				call helper again with changed a 


	Important thing to notice is that we are doing permutation which is
	basically O(n!), therefore we can get away with doing a lot of inefficient
	things
*/


class Solution {
public:
    
    vector<vector<int>> res;
    
    
    void helper(vector<int>& nums, vector<int>& a){
        if(nums.size() == a.size()){
            res.push_back(a);
        } else{
            for(int i = 0; i < nums.size(); i++){
                if(find(a.begin(), a.end(), nums[i]) == a.end()){
                    a.push_back(nums[i]);
                    helper(nums, a);
                    a.pop_back();
                }
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                vector<int> a;
                a.push_back(nums[i]);
                helper(nums, a);
            }
        }
        
        return res;
    }
};