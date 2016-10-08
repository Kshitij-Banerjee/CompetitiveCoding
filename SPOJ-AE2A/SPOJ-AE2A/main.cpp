//
//  main.cpp
//  SPOJ-AE2A
//
//  Created by Kshitij Banerjee on 27/09/16.
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


int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K ;
        
        vvi dp(N+1,vi(K+1,0));
        for( int i = 1; i < 7; i++ )
            dp[1][i] = 1;
        
        for( int n = 2; n <= N; n ++ ) {
            for( int k = 1; k <= K; k++ ) {
                for( int i = 1; i < 7 && k > i; i ++ )
                    if( n > 0 && k > 0 )
                        dp[n][k] += dp[n-1][k-i];
            }
        }
       
        double total = 0;
        for(int i = 0; i <= K ; i ++ ) total += dp[N][i];
        
        cout << floor(dp[N][K]*100/total);
    }
    return 0;
}
