//
//  main.cpp
//  IB-BuySellStocksIII
//
//  Created by Kshitij Banerjee on 11/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
            int maxProfit(const vector<int>&);
};


int maxProf( const vector<int>& A, int start, int end, map<int, map<int,int> >& dp ){
    
    if( start > end ) return 0;
    if( dp[start][end] != 0) return dp[start][end];
    int min_till_now = A[start];
    int max_so_far = 0;
    for( int i = start; i <= end; i ++ ) {
        min_till_now = min( min_till_now, A[i] );
        max_so_far = max( max_so_far, A[i] - min_till_now );
    }
    
    return dp[start][end] = max_so_far;
}

int Solution::maxProfit(const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if( B.empty() ) return 0;
    
    vector<pair<int, vector<int>> > low_to_high_candidates;
    vector<int> A;
    A.push_back(B[0]);
    for( int i = 1; i   < B.size(); i ++ ){
        if( B[i] != B[i-1] ) A.push_back( B[i] );
    }
    
    
    if( A[0] < A[1] ) low_to_high_candidates.push_back(make_pair(0, vector<int>()));
    
    
    for( int i = 1; i < A.size()-1; i ++ ) {
        if( A[i] > A[i-1] && A[i] > A[i+1] ){
            for( pair<int, vector<int> >& p : low_to_high_candidates){
                if( A[p.first] < A[i] )
                    p.second.push_back(i);
            }
        }
        if( A[i] < A[i-1] && A[i] < A[i+1] ){
            low_to_high_candidates.push_back(make_pair(i, vector<int>()));
        }
    }
    
    if( A[A.size()-1] > A[A.size()-2]){
        int i = A.size()-1;
        for( pair<int, vector<int> >& p : low_to_high_candidates){
            if( A[p.first] < A[i] ) {
                p.second.push_back(i);
            }
        }
    }
    
    
    int maxProfit = INT_MIN;
    map<int, map<int,int> > dp;
    
    for( pair<int, vector<int> >& p : low_to_high_candidates){
        for( auto i : p.second ){
            maxProfit = max( maxProfit,
                            (A[i] - A[p.first]) + max( maxProf(A, 0, p.first-1, dp),
                                                maxProf(A, i+1, A.size()-1, dp) ) );
        }
    }
    
    return max( maxProfit, 0 );
}



int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    int a[] = { 4, 0, 0 , 0 , 0};
    vector<int> input( a, a+5);
    std::cout << s.maxProfit(input);
    return 0;
}
