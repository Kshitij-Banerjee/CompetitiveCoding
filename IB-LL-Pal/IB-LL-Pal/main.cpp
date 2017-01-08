//
//  main.cpp
//  IB-LL-Pal
//
//  Created by Kshitij Banerjee on 30/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseLL( ListNode* A){
    
    if( A == NULL ) return A;
    
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* next = A->next;
    
    while( curr ){
        curr ->next = prev;
        prev = curr;
        curr = next;
        if( next )next = next->next;
    }
    
    return curr;
}


int lPalin(ListNode* A) {
    
    ListNode* slow = A;
    ListNode* fast = A;
    
    while( fast->next && fast->next->next ){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* mid = slow->next;
    
    ListNode* reverse = reverseLL(mid);
    
    while( A && reverse ){
        if( A->val != reverse->val ) return false;
        A = A->next;
        reverse = reverse->next;
    }
    
    return true;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode* node = new ListNode(1);
    node ->next = new ListNode(2);
    node->next->next = new ListNode(3);
//    node->next->next->next = new ListNode(4);
//    node->next->next->next->next = new ListNode(1);
    std::cout << lPalin(node);
    return 0;
}
