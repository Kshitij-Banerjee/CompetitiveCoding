//
//  main.cpp
//  IB-COmbSUm
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

void solve( vector<int>& A, int B, int start, int end, vector<bool>& mask, vector<vector<int> >& output){
    
    
    if( start > end ) return;
    
    if( B == 0 ){
        vector<int> temp;
        for( int i = 0; i < mask.size(); i ++ ) {
            if( mask[i] == true ){
                temp.push_back(A[i]);
            }
        }
        output.push_back(temp);
        return;
    }
    
    mask[start] = true;
    solve(A, B-A[start], start+1, end, mask, output);
    
    mask[start] = false;
    solve(A, B, start+1, end, mask, output);
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end());
    vector<vector<int> > output;
    vector<bool> mask(A.size(), false);
    
    solve(A, B, 0, A.size()-1, mask, output);
    
    return output;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 1, 6, 8, 8, 10, 11, 16 };
    vector<int> input(arr, arr+7);
    
    combinationSum(input, 28);
    return 0;
}
