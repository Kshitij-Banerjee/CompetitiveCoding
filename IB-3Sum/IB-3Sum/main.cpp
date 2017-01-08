//
//  main.cpp
//  IB-3Sum
//
//  Created by Kshitij Banerjee on 23/10/16.
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

int two_sum( vector<int>& A, int start, int end, int B ){
    
    
    int best = INT_MAX;
    
    
    while( start < end ) {
        int sum = A[start] + A[end];
        if( sum == B ) return B;
        if( sum < B ) {
            best = min( best, abs(B-sum) );
            start++;
        }
        if( sum > B ) {
            best = min( best, abs(B-sum) );
            end --;
        }
    }
   //  cout << B << " " << best <<  " " << B - best << endl;
    return B-best;
}

int threeSumClosest(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
     sort(A.begin(), A.end());
    int best = INT_MAX;
    
    for( int i = 0; i < A.size(); i ++ ) {
        int tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        
        int twoSum = two_sum(A, 1, A.size()-1, B-A[0]);
        
        best = min(best, abs(twoSum + A[0] - B ) );
        
        tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        //  cout << twoSum << endl;
      
        
    }
    
    return B-best;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { -4, -8, -10, -9, -1, 1, -2, 0, -8, -2 } ;
    
    vector<int> inp( arr, arr+10);
    
    std::cout << threeSumClosest(inp, 0);
    return 0;
}
