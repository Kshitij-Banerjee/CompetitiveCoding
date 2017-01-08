//
//  main.cpp
//  IB-pow
//
//  Created by Kshitij Banerjee on 11/10/16.
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
long long mod( long long a, long long b)
{ return (a%b+b)%b; }

int pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if( x == 0 ) return 0;
    if( n == 0 ) return 1;
    if( x == 1 ) return 1;
    if( n == 1 ) return mod(x,d);
    if( n % 2 == 0) {
        long long n_2 = pow(x, n/2, d);
        return mod(n_2 * n_2,  d);
    }
    else {
        long long n_2 = pow(x, (n-1)/2, d);
        return mod(x * n_2 * n_2,  d);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << pow( 71045970, 41535484, 64735492);
    return 0;
}
