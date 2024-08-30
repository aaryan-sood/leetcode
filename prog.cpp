#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <queue>
#include <vector>
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

string removeDuplicates(string temp)
{
    stack<char> st;

    for(int i=0;i<temp.size();i++)
    {
        if(!st.empty() && st.top() == temp[i])
        {
            st.pop();
        }
        else
        {
            st.push(temp[i]);
        }
    }

    string ans;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    temp="";
    for(int i=ans.size()-1;i >=0 ;i--)
    {
        temp+=ans[i];
    }
    return temp;
}
int main()
{
    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    // cout<<"Input K : "<<endl;
    // int k;
    // cin>>k;
    // cout << "Original list : ";
    // printList(head);
    // ListNode *revese=reverseList(head);
    // cout<<"Reversed List : ";
    // printList(revese);

    // ListNode *reverseK=reverseListK(head,k);
    // cout<<"Reversed k List : ";
    // printList(reverseK);

    // stack<char> s;
    // s.push('3');
    // s.push('4');
    // int first=s.top() - '0';
    // s.pop();
    // int second=s.top() - '0';
    // s.pop();
    // int ans=first+second;
    // cout<<ans<<endl;
    // return 0;

    // implemented max heap
    // priority_queue<int> pq;

    // for (int i=0; i<6; i++) {
    //     pq.push(arr[i]);
    // }

    // while (!pq.empty()) {
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    // cout<<endl;


    // // implementing min heap now
    // cout<<"Min heap : "<<endl;
    // priority_queue<int,vector<int>,greater<int>> gq;
    // for (int i=0; i<6; i++) {
    //     gq.push(arr[i]);
    // }

    // while (!gq.empty()) {
    //     cout<<gq.top()<<" ";
    //     gq.pop();
    // }
    // cout<<endl;
    // return 0;
    int arr[6]={10,2,4,8,6,9};

    string st;
    getline(cin,st);

    string temp=removeDuplicates(st);
    if(temp == "")
    {
        cout<<"Empty String"<<endl;
    }
    else
    {
        cout<<temp;
    }
    return 0;
    
}
