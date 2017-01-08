//
//  main.cpp
//  IB-BS_rotated_array
//
//  Created by Kshitij Banerjee on 13/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start  = 0 ;
    int end = A.size() -1;
    
    while( start <= end ) {
        int mid = (start + end) / 2;
        if( A[mid] == B ) return mid;
        
        if( A[start] <= A[mid] ){
            if(A[mid] >= B && A[start] <= B ){
                end = mid -1;
            }
            else
                start = mid +1;
            
            continue;
        }
        
        else if( A[mid] <= B && A[end] >= B ) start = mid +1;
        else end = mid -1;
        
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100 };
    vector<int> inp( arr, arr + 19 );
    std::cout << search(inp, 202);
    return 0;
}
