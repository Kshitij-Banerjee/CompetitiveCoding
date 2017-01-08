//
//  main.cpp
//  IB-countBST
//
//  Created by Kshitij Banerjee on 18/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <numeric>

using namespace std;
typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, int> pii;
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>

int Trees(int A, vector<int>& dp) {
    
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if( A == 0 ) return 1;
    if( A == 1 ) return 1;
    if( A == 2 ) return 2;
    
    if( dp[A] != 0) return dp[A];
    
    int sum = 0;
    
    for( int i = 1; i <= A; i ++){
        sum += (Trees(A-i, dp) * Trees(i-1, dp));
    }
    return dp[A] = sum;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int A = 6;
    vector<int> dp(A+1,0);
    
    cout << Trees(A,dp);
    return 0;
}
