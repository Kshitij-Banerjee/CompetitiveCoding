//
//  main.cpp
//  IB-Decodig
//
//  Created by Kshitij Banerjee on 16/11/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


bool is_valid( string x ){
    if( stoi(x) <= 26 ) return true;
    return false;
}

int ways(string A, int start, vector<int>& dp){
    if( start == A.length()-1) return 1;
    if( start >= A.length() ) return 0;
    
    if( dp[start] != -1 ) return dp[start];
    
    int total = 0;
    
    if( is_valid( A.substr(start, 1) ) ){
        total += ways(A, start+1, dp);
    }
    if( is_valid( A.substr(start, 2 ))){
        total += ways(A, start+2, dp);
    }
    
    return dp[start] = total;
}

int numDecodings(string A) {
    vector<int> dp(A.length() +1, -1);
    return ::ways(A,0, dp);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << numDecodings("626");
    return 0;
}
