// 46. Permutations
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
 

//Completed

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);   

        backtrack(nums, current, used, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& ans) {
        if (current.size() == nums.size()) {                        
            ans.push_back(current);          
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {                   
                continue;
            }

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, current, used, ans);

            used[i] = false;
            current.pop_back();                
        }
    }
};