// problem link: https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        while(head != NULL){
            temp.push_back(head->val);
            head = head->next;
        }

        int start = 0,end = temp.size() - 1;
        while(start <= end){
            if(temp[start] != temp[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;

    }
};