/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// problem link
// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// takes nore space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node *temp=head;
        while(temp)
        {
            Node *newnode=new Node(temp->val);
            map[temp]=newnode;
            temp=temp->next;
        }

        temp=head;
        Node *newhead=map[temp];
        while(temp)
        {
            Node *curr=map[temp];
            if(temp->next)
            curr->next=map[temp->next];
            else
            curr->next=NULL;

            if(temp->random)
            curr->random=map[temp->random];
            else
            curr->random=NULL;

            temp=temp->next;
        }

        return newhead;
    }
};
// optimised approach
// /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head;

        // inserting the copied nodes in between
        while(temp)
        {
            Node *temp1=temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=temp1;
            temp=temp1;
        }
        temp=head;

        // connecting copied random pointers
        while(temp)
        {
            Node *copynode=temp->next;
            if(temp->random)
            copynode->random=temp->random->next;
            else
            copynode->random=NULL;
            temp=temp->next->next;
        }

        // connecting the next pointers in copied list

        temp=head;
        Node *dummy=new Node(-1);
        Node *res=dummy;
        while(temp)
        {
            res->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            res=res->next;
        }
        return dummy->next;

    }
};
