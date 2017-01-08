//
//  main.cpp
//  IB-FractionToDecimal
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

string fractionToDecimal(int N, int D, bool fraction, map<pair<int,int>, string>& ans, pair<int,int>*& repeat) {
    // Do not write main() functionN
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if( N <= 0 ) return "";
    
    
    if( ans.find(make_pair(N,D)) != ans.end() ){
        repeat = new pair<int,int>(N,D);
        return ")";
    }
    
    stringstream ss;
    int q = N/D;
    if( q == 0 ){
        if( !fraction) ss << '.' ;
        ans[make_pair(N,D)] = q;
        string s = fractionToDecimal(N*10,D, true, ans, repeat);
        if( fraction && repeat != NULL && repeat->first == N && repeat->second == D){
            ss << "(";
        }
        ss << s;
    }
    else {
        ans[make_pair(N,D)] = q;
        string s = fractionToDecimal(fraction ? N%D *10 : N%D, D, fraction, ans, repeat);
        if( fraction && repeat != NULL && repeat->first == N && repeat->second == D){
            ss << "(";
        }
        ss << q << s;
    }
    
    return ans[make_pair(N,D)] = ss.str();
    
}

string fractionToDecimal(long N, long D) {
    
    bool negate;
    if( N < 0 && D < 0){
        N = N * -1;
        D = D * -1;
    }else if( N <0){
        negate = true;
        N = -N;
    } else if( D < 0 ){
        negate = true;
        D = -D;
    }
    
    
    if( D == 1 ) {
        stringstream ss;
        if( negate ) ss <<  "-";
        ss << N;
        return ss.str();
    }
    
    string s;
    if( N/D == 0) s += '0';
    map<pair<int,int>, string> answers;
    pair<int,int>* repeat = NULL;
    if( negate ) s += "-";
    return s += ::fractionToDecimal(N,D,false, answers, repeat);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << fractionToDecimal(2, 3) << endl;
    std::cout << fractionToDecimal(3, 2) << endl;
    std::cout << fractionToDecimal(1, 2) << endl;
    std::cout << fractionToDecimal(22, 7) << endl;
   std::cout << fractionToDecimal(22, -7) << endl;
   std::cout << fractionToDecimal(-2147483648, -1) << endl;
    return 0;
}
