//
//  main.cpp
//  IB-Decodeways
//
//  Created by Kshitij Banerjee on 16/11/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//  2626 = 2 + (626) , 26 + (26)
// 626 = 6 + (26)
// 26 = 2 + (6), 26 + (0) = 2

bool valid(string A, int start, int count){
    if( A[start] == '0' ) return false;
    
    string s = A.substr(start, count);
    if( stoi(s) <= 26 && stoi(s) > 0 ) return true;
    return false;
}

int numDecodings(string A, int start, vector<int>& dp) {
    if( start == A.length()-1 && A[start] == '0') return 0;
    if( start >= A.length()-1 ) return 1;
    if( dp[start] != -1 ) return dp[start];
    
    int total = 0;
    
    if( valid(A, start, 1) ){
        total +=  numDecodings(A, start+1, dp);
    }
    if( valid(A, start, 2 )){
        total += numDecodings(A, start+2, dp);
    }
    
    return dp[start] = total;
}

int numDecodings(string A){
    vector<int> dp(A.length()+1 ,-1);
    return numDecodings(A,0, dp);
}
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
// ABCD = (1 + 3) + (2 + 2) + (3 + 1) + (4+0);


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << numDecodings("2611055971756562");
    return 0;
}
