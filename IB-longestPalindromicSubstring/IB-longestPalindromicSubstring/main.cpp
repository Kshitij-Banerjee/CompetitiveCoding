//
//  main.cpp
//  IB-longestPalindromicSubstring
//
//  Created by Kshitij Banerjee on 12/10/16.
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


string longestPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vvi B(A.length(), vi(A.length(),0));
    
    for( int i =0 ; i < A.length(); i++ ) B[i][i] = 1;
    
    int max_so_far = 1;
    for( int i = 0; i < A.length()-1; i++ ){
        if( A[i] == A[i+1] ){
            B[i][i+1] = true;
            max_so_far = 2;
        }
    }
    
    int start = 0;
    for( int k = 3; k <= (A.length()); k++ ){
        for( int i = 0; i < A.length()-k+1; i ++ ){
            int j = i + k -1;
            if( B[i+1][j-1]  && A[i] == A[j] ){
                B[i][j] = true;
                if( max_so_far < k ){
                    max_so_far = k;
                    start = i;
                }
            }
        }
    }
    
    return A.substr(start, max_so_far);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << longestPalindrome("cccb");
    return 0;
}
