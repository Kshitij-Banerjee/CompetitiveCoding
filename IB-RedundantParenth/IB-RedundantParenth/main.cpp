//
//  main.cpp
//  IB-RedundantParenth
//
//  Created by Kshitij Banerjee on 16/10/16.
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
#include <stack>

#include <algorithm>
void modify_string( string& A, int start, int end, const char* ans) {
    A.replace(start,end-start, ans);
}

int evaluate(string& A, int start ){
    stack<char> braces;
    stack<char> op;
    stack<char> vars;
    
    for( int i = start ; i < A.length(); i ++ ){
        if( A[i] == '('){
            int out = evaluate(A, i+1);
            if(out == -1) return 1;
            vars.push(out);
        }
        else if ( A[i] == '*' || A[i] == '/' || A[i] == '+' || A[i] == '-'){
            op.push(A[i]);
        }
        else if( A[i] == ')'){
            if( op.size() > 0 && vars.size() > 1 )
            {
                modify_string(A, start-1, i+1, "a");
                return 'a';
            }
            else return -1;
            
        }
        else{
            vars.push(A[i]);
        }
        
    }
    
    if( op.size() > 0 && vars.size() > 1 )
    {
        modify_string(A, start, A.length(), "a");
        return 'a';
    }
    else return -1;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    string inp = "a+b";
    std::cout << evaluate(inp, 0) << endl;
    cout << (inp == "a" ? 0 : 1 );
    return 0;
}
