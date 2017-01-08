//
//  main.cpp
//  IB-validNumber
//
//  Created by Kshitij Banerjee on 29/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int isNumber(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i = 0;
    while( A[i] == ' ' ){
        if( i >= A.length() ) {
            return 0;
        }
        i++;
    }
    if( A[i] == '-') i++;
    
    bool dotSeen = false;
    
    for( ; i < A.length(); i ++ ) {
        if( A[i] == 'e') break;
        if( A[i] == '.'){
            if( dotSeen ) return 0;
            else {
                dotSeen = true;
                continue;
            }
        }
        
        if( '0' <= A[i] && A[i] <= '9' )
            continue;
        else
            return false;
    }
    
    dotSeen = false;
    
    if( i < A.length() && A[i] == 'e' ) i++;
    
    if( i < A.length() && A[i] == '.') return 0;
    
    for( ; i < A.length(); i ++ ) {
        if( A[i] == '.'){
            if( dotSeen ) return 0;
            else {
                dotSeen = true;
                continue;
            }
            
        }
        if( '0' <= A[i] && A[i] <= '9' )  continue;
        else
            return 0;
    }
    
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isNumber("  ");
    return 0;
}
