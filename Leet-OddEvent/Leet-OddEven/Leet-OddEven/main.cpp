#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int length = 0;
        ListNode* node = head;
        ListNode* last = NULL;
        ListNode* last_last = NULL;
        while(node){
            length++;
            last_last = last;
            last = node;
            node = node->next;
        }
        
        last_last = last;
        
        
        node = head->next;
        ListNode* prev = head;
        
        length = length /2;
        while(length--){
            last -> next = node;
            prev-> next = node-> next;
            node -> next = NULL;
            last = node;
            
            prev = prev -> next;
            node = prev->next;
        }
        
        return head;
    }
};


int main() {
    ListNode* node = new ListNode(1);
    node -> next = new ListNode(2);
    node -> next -> next = new ListNode(3);
    node -> next -> next -> next = new ListNode(4);
    node -> next -> next -> next -> next = new ListNode(5);
    //node -> next -> next -> next -> next -> next = new ListNode(6);
    Solution s;
    ListNode* head = s.oddEvenList(node);
    
    while( head){
        cout << head->val << "  " ;
        head = head -> next;
    }
    
}