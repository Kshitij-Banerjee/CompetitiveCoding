//
//  main.cpp
//  IB-RPNEval
//
//  Created by Kshitij Banerjee on 13/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


string op(string l, string r, string i ){
    
    int a = stoi(l);
    int b = stoi(r);
    
    if(i == "+" ) return to_string(a + b );
    if( i == "/") return to_string(a / b ) ;
    if( i ==  "*") return to_string( a + b );
    else return to_string( b - a);
}

int evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<string> constants;
    
    for( auto i : A ) {
        
        if(i == "+" || i == "/" || i == "*" || i == "-"){
            string l = constants.top(); constants.pop();
            string r = constants.top(); constants.pop();
            constants.push( op(l, r, i) );
        }
        else
            constants.push(i);
    }
    
    return  stoi( constants.top() );
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s[] = { "5", "1", "2", "+", "4", "*", "+", "3", "-" };
    vector<string> inp(s, s +9);
    std::cout << evalRPN(inp);
    return 0;
}
