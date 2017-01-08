//
//  main.cpp
//  IB-evaluateToTrue
//
//  Created by Kshitij Banerjee on 05/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#include <string>


int ways(string A, int start, int end, vector<vector<int> >& dp ){
    if( start > end ) return 0;
    if( dp[start][end] != -1 ) return dp[start][end];
    
    long long result = 0;
    
    for( int i = start; i <= end; i++ ){
        if( (A[i] != 'T') && (A[i] != 'F') ){
            int way1 = ways(A, start, i-1, dp);
            int way2 = ways(A, i+1, end, dp);
            if( A[i] == '|') result += (way1 + way2);
            else if( A[i] == '&' ) result += min(way1, way2);
            else if( A[i] == '^' ) result += (way1 + way2);
            result %= 1003;
        }
    }
    
    return dp[start][end] = result;
}

int ccnttrue(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > dp(A.length()+1, vector<int>(A.length()+1, -1));
    
    for(int i = 0; i < A.length(); i ++ ) {
        if( A[i] == 'T' ) dp[i][i] = 1;
        else if( A[i] == 'F' ) dp[i][i] = 0;
    }
    
    return ways(A, 0, A.length()-1, dp);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << ccnttrue("T|F&T^T");
    return 0;
}
