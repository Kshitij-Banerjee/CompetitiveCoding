//
//  main.cpp
//  HR-SubarrayPartition
//
//  Created by Kshitij Banerjee on 19/09/16.
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
#define ll long long
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, int> pii;

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>

ll partition(vll::iterator begin, vll::iterator end, ll sum){
    if( begin == end ) return   0;
    
    vll::iterator mid = find(begin, end, sum);
    if( *mid == sum ){
        return 1 + max( partition(begin, mid, (*end - *begin)/2), partition(mid+1, end, (*end - *(mid+1))/2));
    }
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n, 0);
        vector<ll> sum(n, 0);
        cin >> arr[0];
        sum[0] = arr[0];
        for( ll i = 1;i < n ; i ++ ){
            cin >> arr[i];
            sum[i] = sum[i-1]+arr[i];
        }
        
        cout << partition(sum.begin(), sum.end(), sum[n-1]/2) << endl;
        
    }
    return 0;
}
