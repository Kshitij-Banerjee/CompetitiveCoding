//
//  main.cpp
//  SPOJ-NextHigherPalindrome
//
//  Created by Kshitij Banerjee on 08/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool is_nines(string s) {
    
    for( auto c : s ) if( c != '9' ) return false;
    return true;
}

void solve( int n ) {
        string s = to_string(n);
    
    if( is_nines(s) ){
        cout << "1" + string(s.length()-1,'0') + "1" << endl;
        return;
    }
    else{
        int c = (int)(s.length())/2;
        string pal = s;
        int i = 0;
        bool has_increased = false;
        for( ; i < c; i ++ ){
            int other = (int)s.length()-i-1;
            if( pal[i] - '0' > pal[other] - '0' ) has_increased = true;
            pal[i] = s[i];
            pal[other] = s[i];
        }
        
        if( !has_increased ){
            int i = (int)(s.length()-1)/2;
            int other = (int)s.length()-i-1;
            int x = pal[i]-'0' + 1;
            pal[i] = x + '0';
            pal[other] = x + '0';
        }
        
        cout << pal << endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin >> T;
    
    while( T-- ) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
