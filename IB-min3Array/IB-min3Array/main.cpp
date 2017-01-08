//
//  main.cpp
//  IB-min3Array
//
//  Created by Kshitij Banerjee on 01/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int id0 = 0;
    int id1 = 0;
    int id2 = 0;
    int diff = max( max( abs(A[id0] - B[id1]), abs( B[id1] - C[id2] ) ), abs(C[id2] - A[id0]) ) ;
    
    while( (id0 != A.size()-1) && (id1 != B.size()-1) && (id2 != C.size()-1) ){
        
        diff = min( diff, max( max( abs(A[id0] - B[id1]), abs( B[id1] - C[id2] ) ), abs(C[id2] - A[id0]) ) );
        
        vector<int> ids(3, INT_MAX );
        if( id0 != A.size()-1 ) ids[0] = A[id0];
        if( id1 != B.size()-1 ) ids[1] = B[id1];
        if( id2 != C.size()-1 ) ids[2] = C[id2];
        
        int mn = *(min_element( ids.begin(), ids.end() ));
        
        if( (id0 != A.size()-1) && (A[id0] == mn) ) id0++;
        else if( (id1 != B.size()-1) && (B[id1] == mn) ) id1++;
        else if( (id2 != C.size()-1) && (C[id2] == mn) ) id2 ++;
    }
    
    return diff;}




int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 0, 3, 6, 9, 10 };
    int arr1[] = { 1, 4, 9  };
    int arr2[] = { 2, 5, 8, 9, 12 };
    std::cout << minimize(vector<int>(arr, arr+4), vector<int>(arr1, arr1+3), vector<int>(arr2, arr2+5));
    return 0;
}
