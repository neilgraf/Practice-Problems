// # 14. Longest Common Prefix
// # Easy
// # Topics
// # premium lock icon
// # Companies
// # Write a function to find the longest common prefix string amongst an array of strings.

// # If there is no common prefix, return an empty string "".

 

// # Example 1:

// # Input: strs = ["flower","flow","flight"]
// # Output: "fl"
// # Example 2:

// # Input: strs = ["dog","racecar","car"]
// # Output: ""
// # Explanation: There is no common prefix among the input strings.
 

// # Constraints:

// # 1 <= strs.length <= 200
// # 0 <= strs[i].length <= 200
// # strs[i] consists of only lowercase English letters if it is non-empty.

// Completed

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int count = 0;

        for (int l = 0; l < strs[0].size(); l++){
            for (int w = 1; w < strs.size(); w++){
                if (strs[w][l] == strs[0][l]){
                    count++;
                }
            }
            if (count == strs.size()-1){
                ans = ans + strs[0][l];
            }
            else{
                return ans;
            }
            count = 0;
            
        }
        return ans;
    }
};