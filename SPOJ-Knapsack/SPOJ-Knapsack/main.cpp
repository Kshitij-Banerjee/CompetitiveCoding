//
//  main.cpp
//  SPOJ-Knapsack
//
//  Created by Kshitij Banerjee on 07/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve( int S, vector<int>& size, vector<int>& val ){
    if( size.empty() ) return 0;
    
    vector<vector<int> > dp(size.size()+1, vector<int>(S+1, 0));
    
    
    for( int i = 0; i < dp.size(); i ++ ){
        for(int j = 0; j <= S; j ++ ){
            if( i == 0 || j == 0 )
                dp[i][j] = 0;
            else{
                dp[i][j] = dp[i-1][j];
                if( j - size[i-1] >= 0 )
                    dp[i][j] = max(dp[i][j], val[i-1] + dp[i-1][j-size[i-1]]);
            }
            
        }
    }
    return dp.back()[S];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int S, N;
    cin >> S >> N;
    
    vector<int> siz(N);
    vector<int> val(N);
    
    while( N-- ) {
        
        cin >> siz[N];
        cin >> val[N];
    }
    
    cout <<  solve(S, siz, val);
}
