//
//  main.cpp
//  IB-arrange
//
//  Created by Kshitij Banerjee on 16/11/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int product( string A ){
    int whites = count(A.begin(), A.end(), 'W');
    int blacks = count(A.begin(), A.end(), 'B');
    return whites*blacks;
}

int arrange(string A, int B, int start, vector<vector<int> >& dp) {
    if( A.empty() )
    if( start >= A.length() ) return 0;
    if( dp[start][B] != -1 ) return dp[start][B];
    if( B == 1 ) return product(A.substr(start, A.length()));
    
    
    int minCost = INT_MAX;
    
    for( int i = 1; i < A.length(); i ++ ){
        int cost = product ( A.substr(start, i) );
        int remainingCost = arrange( A, B-1, start+i, dp);
        minCost = min(minCost, remainingCost + cost);
    }
    
    return dp[start][B] = minCost;
}

int arrange(string A, int B) {
    vector<vector<int> > dp(A.length()+1, vector<int>(B+1, -1));
    
    return ::arrange(A, B, 0, dp);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << arrange("", 4);
    return 0;
}
