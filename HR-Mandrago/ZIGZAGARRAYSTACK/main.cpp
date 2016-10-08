//
//  main.cpp
//  HR-Mandrago
//
//  Created by Kshitij Banerjee on 20/09/16.
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
#include <stack>

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
    int T ;
    cin >> T;
    while(T--){
        int N ;
        cin >> N;
        
        vvi arr(N,vi(N,0));
        for(int i = 0; i < N; i ++ ) {
            for(int j = 0; j < N; j ++ ) {
                cin >> arr[i][j];
            }
        }
        
        stack<pii> S1, S2;
        bool odd = true;
        for( int i = 0; i < N ; i ++ ){
            S1.push(mPR(0,i));
        }
        
        stack<pii>* S = odd ? &S1 : &S2;
        stack<pii>* So = odd ? &S2 : &S1;
        while( !S->empty() ) {
            pii top = S->top();
            S->pop();
            cout << arr[top.first][top.second];
            if( top.first+1 < N ) So->push(mPR(top.first+1, top.second));
            if( S->empty() ){
                stack<pii>* temp = S;
                S = So;
                So = temp;
            }
        }
    }
    return 0;
}
