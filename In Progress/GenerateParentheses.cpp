// 22. Generate Parentheses
// Medium
// Topics
// premium lock icon
// Companies
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8


//In Progress

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> ans;

        if(open == n && close == n){
            return;
        }

        if(open >= close){
            
        }

        if(close > open){

        }
    }

    void backtrack(string current, int open, int close, int n, vector<string>& ans){
        
    }
};