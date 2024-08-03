#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
class ListNode 
{
    public:
        int val;
        ListNode* next;

        ListNode(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};
void input_list(ListNode *&head, ListNode *&tail, int val)
{
    ListNode * newNode = new ListNode(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void print_list(ListNode* head)
{
    ListNode * tmp = head;
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
}
void preOrder(Node * root)
{
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* par = q.front();
        q.pop();

        cout<<par->val<<" ";

        if(par->left) q.push(par->left);
        if(par->right) q.push(par->right);
    }
}
Node* convert_tree(ListNode* head)
{
    //base case
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        Node* root = new Node(head->val);
        return root;
    }
    ListNode * slow = head;
    ListNode * fast = head;
    ListNode * slowPrev;

    while(fast != NULL and fast->next != NULL)
    {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* root = new Node(slow->val);
    slowPrev->next = NULL;

    Node* rootLeft = convert_tree(head);
    Node* rootRight = convert_tree(slow->next);

    root->left = rootLeft;
    root->right = rootRight;
    return root;

}
int main()
{
    ListNode * head = NULL;
    ListNode * tail = NULL;
    int n;
    cin>>n;
    while (n--)
    {
        int val;
        cin>>val;
        input_list(head,tail,val);
    }
    // print_list(head);
    Node* root = convert_tree(head);
    levelOrder(root);
    cout<<endl;
    preOrder(root);
    return 0;
}