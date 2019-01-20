#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sum = new ListNode(-1);
        ListNode* temp = nullptr;
        temp = sum;
        ListNode* newNode;
        int a,b,c=0;
        for (;l1!=nullptr || l2!=nullptr || c!=0;)
        {
            a=b=0;
            if(l1!=nullptr){
                a=l1->val;
                l1=l1->next;
            }else {
                a=0;
            }
            if(l2!=nullptr){
                b=l2->val;
                l2=l2->next;
            }else {
                b=0;
            }
            if(a+b+c>9){
                newNode = new ListNode(a+b+c-10);
                c=1;
            }else {
                newNode = new ListNode(a+b+c);
                c=0;
            }
            temp->next = newNode;
            temp = newNode;
        }
        return sum->next;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
