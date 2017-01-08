//
//  main.cpp
//  IB-powerof2integers
//
//  Created by Kshitij Banerjee on 25/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>


bool isPower(int A) {
    
    if( A == 1 ) return true;
    if( A <= 3 ) return false;
    
    if( (A & (A-1))  == 0 ) return true;
    
    for( int i = 3; i < A/2; i ++ ) {
        int B = A;
        
        while( B ){
            B = B / i;
            if( B == i )
                return true;
        }
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isPower(16808);
    return 0;
}
