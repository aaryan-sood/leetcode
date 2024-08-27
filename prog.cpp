#include <cstddef>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode * reverseList(ListNode* head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    else {
        ListNode *curr=head;
        ListNode *prev=NULL;
        while (curr) {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
}

ListNode * reverseListK(ListNode* head,int k)
{
    ListNode *prev=NULL;
    ListNode *curr=head;
    int i=0;
    while (curr && i < k) {
        ListNode *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        i++;
    }
    if(head)
    {
        head->next=curr;
    }
    return prev;
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout<<"Input K : "<<endl;
    int k;
    cin>>k;
    cout << "Original list : ";
    printList(head);
    // ListNode *revese=reverseList(head);
    // cout<<"Reversed List : ";
    // printList(revese);

    ListNode *reverseK=reverseListK(head,k);
    cout<<"Reversed k List : ";
    printList(reverseK);
    return 0;
}
