//
//  main.cpp
//  Codility-MaxSumDice6
//
//  Created by Kshitij Banerjee on 21/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static int sol[100001];



int solution( vector<int>& A, int end){
    
    if( end <  0 ) return 0;
    if( end == 0 ) return A[0];
    if( sol[end] != 0) return sol[end];
    
    int m = 0;
    for( int i = end-1; (i >(end-6)) && (i>=0); i--){
        m = max(m, A[end] + solution( A, i ));
        m = max(m, solution( A, i ));
    }
    sol[end] = m;
    return m;
}

int solution(vector<int> &A) {
    if( A.empty() ) return 0;
    if( A.size() == 1 ) return A[0];
    for( int i =0 ; i< 100001; i++) sol[i] = 0;
    
    return solution( A, A.size()-2 ) +  A[A.size()-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 1, -2, 0, 9, -1, -2  };
    vector<int> v(arr, arr+6);
    cout << solution( v );
    return 0;
    
}
