// problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = NULL;
        unordered_map<ListNode *, int> map;
        ListNode *tempA = headA, *tempB = headB;

        while(tempA != NULL){
            map[tempA]+=1;
            tempA = tempA->next;
        }

        while(tempB != NULL){
            if(map.contains(tempB) > 0){
                temp = new ListNode(tempB->val);
                break;
            }
            tempB = tempB->next;
        }
        return temp;
    }
};