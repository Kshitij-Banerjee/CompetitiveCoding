//
//  main.cpp
//  IB-ReverseLL2
//
//  Created by Kshitij Banerjee on 23/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <numeric>

using namespace std;
typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, int> pii;
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


ListNode* reverse( ListNode* A, int times, ListNode* tailNext ){
    ListNode* prev = A;
    ListNode* curr = A->next;
    
    prev->next = tailNext;
    
    while( times -- ) {
        ListNode* save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }
    
    return prev;
}

ListNode* reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    n = n - m;
    m --;
    
    ListNode* prev = A;
    ListNode* curr = A;
    while( m -- ) {
        prev = curr;
        curr = curr->next;
    }
    ListNode* end = curr;
    
    for( int i = 0; i < n ; i ++ ){
        end = end->next;
    }
    
    
    if( prev != A )
        prev->next = reverse(curr, n, end->next );
    else
        A = reverse( curr, n, end->next);
    
    return A;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* one = new ListNode(1);
    one->next = new ListNode(2);
    one->next->next = new ListNode(3);
    //one->next->next->next = new ListNode(4);
    //one->next->next->next->next = new ListNode(5);
    
    std::cout << reverseBetween(one, 2, 3 );
    
    
    return 0;
}
