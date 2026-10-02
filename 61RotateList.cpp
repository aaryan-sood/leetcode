// problem link
// https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL){
            return head;
        }
        vector<int> nums;
        ListNode *temp = head;
        while(temp !=  NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        ListNode* ans = NULL, *final_head;

        for(int i = 0; i < nums.size();i++){
            cout<<nums[i]<<" ";
            ListNode *temp = new ListNode(nums[i]);
            if(ans == NULL){
                ans = temp;
                final_head = ans;
            }
            else{
                ans->next = temp;
                ans = ans->next;
            }
        }
        return final_head;
    }
};