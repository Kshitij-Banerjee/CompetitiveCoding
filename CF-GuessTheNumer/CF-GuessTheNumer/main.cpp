//
//  main.cpp
//  CF-GuessTheNumer
//
//  Created by Kshitij Banerjee on 20/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void guess( int s, int e){
    
    if( s == (e-1)){
        guess(e, e);
        guess(s, s);
        return;
    }
    
    if( s == e )
    {
        
        cout << s << endl;
        fflush(stdout);
        string ans;
        cin >> ans;
        
        if( ans == ">="){
            cout << "! " << s;
            exit(0);
        }
        
        return;
    }
    
    int m = (s+e)/2;
    
    cout << m << endl;
    fflush(stdout);
    
    string ans;
    cin >> ans;
    
    if( ans == "<")
        guess(s, m-1);
    else
        guess(m, e);
    
}
int main(int argc, const char * argv[]) {
    
    guess(1, 1000000);
    return 0;
}


