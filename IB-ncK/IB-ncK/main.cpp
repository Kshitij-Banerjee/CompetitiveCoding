//
//  main.cpp
//  IB-ncK
//
//  Created by Kshitij Banerjee on 13/11/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> getRow(int A);
};

int nCk(int N, int C, vector<vector<int> >& dp ){
    if( N <= 1 ) return 1;
    
    if( C > (N+1)/2)
        C = N - C + 1;
    
    if( C <= 1 ) return 1;
    
    if( dp[N][C] != -1 ) return dp[N][C];
    
    return dp[N][C] = nCk(N-1,C, dp) + nCk(N-1,C-1,dp);
}

vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> output;
    vector<vector<int> > dp(A+3,vector<int>(A+3,-1));
    
    for(int i = 1; i <= A+1; i++){
        output.push_back(nCk(A+1,i, dp));
    }
    
    return output;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> out =  sol.getRow(4);
    return 0;
}
