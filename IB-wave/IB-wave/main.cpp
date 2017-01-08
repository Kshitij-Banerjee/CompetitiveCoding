//
//  main.cpp
//  IB-wave
//
//  Created by Kshitij Banerjee on 13/10/16.
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

#include <algorithm>
vector<int> wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort( A.begin(), A.end() );
    for( int i = 1;  i < A.size(); i+= 2 ){
        //  cout << i << A[i] << endl;
        
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
    }
    return A;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 6, 12, 9, 1, 2, 7 };
    vi v(arr, arr+ 6 );
    cout << wave(v);
    return 0;
}
