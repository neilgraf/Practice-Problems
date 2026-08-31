// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// A critical point in a linked list is defined as either a local maxima or a local minima.

// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

// Example 1:


// Input: head = [3,1]
// Output: [-1,-1]
// Explanation: There are no critical points in [3,1].
// Example 2:


// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
// Example 3:


// Input: head = [1,3,2,2,3,2,2,2,7]
// Output: [3,3]
// Explanation: There are two critical points:
// - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
// - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
// Both the minimum and maximum distances are between the second and the fifth node.
// Thus, minDistance and maxDistance is 5 - 2 = 3.
// Note that the last node is not considered a local maxima because it does not have a next node.
 

// Constraints:

// The number of nodes in the list is in the range [2, 105].
// 1 <= Node.val <= 105
 
// Seen this question in a real interview before?
// 1/6
// Yes
// No
// Accepted
// 312,595/428.9K
// Acceptance Rate
// 72.9%

// Completed


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        vector<int> idx;
        vector<int> ans;
        int count = 0;

        while(curr->next != nullptr){
            if(prev->val > curr->val && curr->next->val > curr->val){
                idx.push_back(count);
            }
            if(prev->val < curr->val && curr->next->val < curr->val){
                idx.push_back(count);
            }
            prev = prev->next;
            curr = curr->next;
            count++;
        }

        if(idx.size() < 2){
            return {-1, -1};
        }

        int min = 9999999;

        for(int i = 1; i < idx.size(); ++i){
            if(min > (idx[i] - idx[i-1])){
                min = idx[i] - idx[i-1];
            }
        }
        ans.push_back(min);
        ans.push_back(idx[idx.size()-1] - idx[0]); // max dist
        return ans;

    }
};