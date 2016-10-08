//
//  main.cpp
//  HR-maxSubSquareMatrix
//
//  Created by Kshitij Banerjee on 05/10/16.
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
    
    int N;
    int res = 0;
    cin >> N;
    
    vvi arr(N, vi(N, 0));
    vvi dp(N, vi(N, 0));
    
    for( int i = 0; i < N; i ++ )
        for( int j = 0; j < N; j ++ )
            cin >> arr[i][j];
    
    for( int i =0 ;i < N; i ++ )
        dp[i][0] = arr[i][0] == 1 ? 1 : 0;
    
    for( int i =0 ;i < N; i ++ )
        dp[0][i] = arr[0][i] == 1 ? 1 : 0;
    
    for( int i = 1; i < N; i ++ )
        for( int j = 1; j < N; j ++ ){
            if( arr[i][j] == 0 ) continue;
            
            dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] ) + 1 ;
            res = max(res, dp[i][j]);
        }
    
    for( int i =0 ;i < res; i++ ){
        for( int j = 0; j < res; j++ )
            cout << "1 " ;
        cout << endl;
    }
    return 0;
}
