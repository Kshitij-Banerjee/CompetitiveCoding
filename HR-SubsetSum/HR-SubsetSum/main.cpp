//
//  main.cpp
//  HR-SubsetSum
//
//  Created by Kshitij Banerjee on 14/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#define ll long long
using namespace std;

struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

bool subsetSum( vector<ll>& a, ll n, ll start, ll end, ll b, ll mask, unordered_map<pair<ll,ll>,bool, pairhash>& dp ){
    if( dp.find( make_pair(start, n) ) != dp.end() ) return dp[make_pair(start,n)];
    if( b < 0 ) return false;
    if( start > end ) return false;
    if( n < 0 ) return false;
    if( n == 0  && b == 0){
        stringstream ss;
        for( ll i = 0; i < a.size(); i++ ) {
            if( mask & (1 << i) )
                ss << a[i] << " ";
        }
        string str = ss.str();
        string s(str.begin(), str.end()-1);
        cout << s << endl;
        return true;
    }
    
    bool f = subsetSum(a, n - a[start], start +1, end, b-1, mask | (1 << start), dp);
    if( f ) return dp[make_pair(start,n)] = f;
    bool s = subsetSum(a, n, start+1, end, b, mask, dp);
    return  dp[make_pair(start,n)] = s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int t;
    cin >> t;
    while( t-- ){
        ll n, k, b;
        cin >> n >> k >> b ;
        
        vector<ll> arr(k,0);
        for( ll i = 1; i <=k; i ++ ) arr[i-1] = i;
        int mask = 0;
        unordered_map<pair<ll,ll>, bool, pairhash> dp;
        bool there = subsetSum(arr, n, 0, n-1, b, mask, dp) ;
        if(!there) cout << "-1" << endl;
    }
    
    return 0;
}

