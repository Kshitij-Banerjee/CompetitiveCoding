//
//  main.cpp
//  SPOJ-ExpreTORPN
//
//  Created by Kshitij Banerjee on 08/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool is_op(char c){
    return (c == '*') || (c == '/') || (c == '+') || (c == '-') || (c == '^');
}

bool is_constant(char c ){
    return (c >= 'a') && (c <= 'z');
}

void solve( string s ) {
    stack<string> constants;
    stack<string> operators;
    
    for( auto i : s ) {
        if( is_op(i) ){
            operators.push(string(1,i));
        }
        else if( is_constant(i) ){
            constants.push(string(1,i));
        }
        else if( i == ')' ){
            string r = constants.top();
            constants.pop();
            string l = constants.top();
            constants.pop();
            
            string op = operators.top();
            operators.pop();
            
            constants.push(l + r + op);
        }
    }
    cout << constants.top() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int T;
    cin >> T;
    while( T-- ) {
        string s;
        cin >> s;
        solve( s );
    }
    return 0;
}
