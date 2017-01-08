//
//  main.cpp
//  IB-MergeArray
//
//  Created by Kshitij Banerjee on 12/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int>::iterator A_it = A.begin();
    vector<int>::iterator B_it = B.begin();
    while( A_it != A.end() ){
        if( *(A_it) < *(B_it) ) {
            A_it++;
        }
        else{
            A_it = A.insert(A_it, *B_it);
            B_it++;
        }
    }
    while( B_it != B.end() ){
        A.push_back( *B_it );
        B_it++;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = { 1, 5,8 };
    int b[] = { 6, 9 };
    vector<int> A(a, a+3);
    vector<int> B(b, b+2);
    merge(A, B);
    
    
    return 0;
}
