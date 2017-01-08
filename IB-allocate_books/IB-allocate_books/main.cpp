//
//  main.cpp
//  IB-allocate_books
//
//  Created by Kshitij Banerjee on 13/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;



int solve( vector<int>& A, int pages, int& mx ){
    
    int count = 0;
    int students = 0;
    
    for( int i = 0; i < A.size(); i ++ ){
        
        if( count + A[i] > pages ) {
            mx = max(mx, count);
            count = A[i];
            students ++;
        }
        else{
            count += A[i];
        }
    }
    mx = max(mx, count);
    return students + 1;
    
}

int books(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if( B > A.size() ) return -1;
    if( A.size() == 1 ) return A[0];
    if( A.empty() ) return 0;
    if( B == 1 ) return accumulate(A.begin(), A.end(), 0);
    int low = 0;
    int high = accumulate(A.begin(), A.end(), 0);
    int avg = high / B;
    int mx = 0;
    int ans = 0;
    
    while( low < high ) {
        int pages = (low + high) / 2;
        mx = INT_MIN;
        int students = solve(A, pages, mx);
        
        if( students > B ) {
            low = pages + 1;
        }
        else {
            ans = mx;
            high = pages ;
        }
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int inp[] = { 3, 32, 32, 41, 54, 77, 17};
    vector<int> INP( inp, inp + 7 );
    
    std::cout << books(INP, 4 );
    return 0;
}
