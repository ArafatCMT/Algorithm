#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};
void input_list(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void print(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
void reverse_list(Node* &head)
{
    Node* preNode = NULL;
    Node* curNode = head;
    while(curNode != NULL)
    {
        Node* nextNode = curNode->next;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    head = preNode;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    cin>>n;
    while (n--)
    {
        int val;
        cin>>val;
        input_list(head,tail,val);
    }
    print(head);
    reverse_list(head);
    print(head);

    return 0;
}