// problem link
// https://leetcode.com/problems/add-two-numbers/description/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry = 0;
        ListNode *head = NULL, *temp = NULL;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0,val2 = 0;
            if(l1){
                val1 = l1->val;
            }
            if(l2){
                val2 = l2->val;
            }
            sum = val2 + val1 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *node = new ListNode(digit);
            if(head == NULL){
                head = node;
                temp = node;            
            }
            else{
                temp->next = node;
                temp = temp->next;
            }
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        return head;
    }
};