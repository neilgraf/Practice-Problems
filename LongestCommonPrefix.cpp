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


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        if(strs.empty()){
            return ans;
        }


        for (int l = 0; l < strs[0].size(); l++){
            for (int w = 1; w < strs.size(); w++){
                if ((strs[w][l] == strs[0][l]) && (w+1 == strs.size())){
                    ans = ans + strs[w][l];
                }
            }
        }
        return ans;
    }
};