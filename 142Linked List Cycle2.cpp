/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// problem link: https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head ==NULL || head->next == NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                break;
            }

        }

        while(slow && fast && slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast ? fast : NULL;
    }
};