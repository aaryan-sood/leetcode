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
    int lengthOfLinkedList(ListNode *head){
        if(head == NULL){
            return 0;
        }
        int ans = 0;
        ListNode *temp = head;
        while(temp != NULL){
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = lengthOfLinkedList(head);
        int start = length - n;
        ListNode *temp = head;
        while(start > 1){
            start--;
            temp = temp->next;
        }
        if(start == 0){
            return head->next;
        }
        if(length == 1 && n == 1){
            return NULL;
        }
        if(temp && temp->next){
            temp->next = temp->next->next;
        }
        return head;
    }
};