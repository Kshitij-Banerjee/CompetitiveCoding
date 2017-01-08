//
//  main.cpp
//  IB-remDupLL
//
//  Created by Kshitij Banerjee on 24/10/16.
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

ListNode* deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* prev = A;
    ListNode* curr = A->next;
    ListNode* next = A->next->next;
    
    while( next ){
        //   cout << prev->val << curr->val << next->val << flush;
        // 1 2 2 3 4 5 5 5 1p (n)c
        if( curr->val == next->val ){
            while( next && next->val == curr->val ) next = next->next;
            
            prev->next = next;
            while( curr && curr != next){
                ListNode* save = curr->next;
                delete curr;
                curr = save;
            }
            if( next ) next = next->next;
        }
        else{
            next = next->next;
            curr = curr->next;
            prev = prev->next;
        }
    }
    
    return A;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* one = new ListNode(1);
    one->next = new ListNode(2);
    one->next->next = new ListNode(2);
    
    ListNode* ret = deleteDuplicates(one);
    return 0;
}
