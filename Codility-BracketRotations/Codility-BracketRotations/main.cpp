//
//  main.cpp
//  Codility-BracketRotations
//
//  Created by Kshitij Banerjee on 18/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
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

int solution(string &S, int K) {
    
    stack<PR<char,int> > st;
    for( int i = 0; i < S.length(); i ++ ){
        if( S[i] == '(') st.push(mPR(S[i], i));
        else if( S[i] == ')' ){
            if( st.empty()) st.push(mPR(S[i], i));
            else if( st.top().first ==  '(') {
                S[st.top().second] = '-';
                S[i] = '-';
                st.pop();
            }
        }
    }
    
    stringstream ss;
    int distance = 0;
    ss << '0';
    for( int i = 0 ;i < S.length(); i++ ){
        if( S[i] != '-'){
         ss << S[i];
            distance ++;
        }
        else{
            int count =1 ;
            while( S[++i] == '-' && i < S.length() ) count++;
            ss<< count;
            i--;
        }
    }
    
    cout << S << endl;
    cout << ss.str();
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    cin >> s;
    int k;
    cin >> k;
    solution(s, k);
    return 0;
}
