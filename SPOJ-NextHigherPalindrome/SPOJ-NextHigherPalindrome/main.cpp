//
//  main.cpp
//  SPOJ-NextHigherPalindrome
//
//  Created by Kshitij Banerjee on 08/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string increment( string s ){
    int carry = 1;
    for( auto i = s.rbegin(); i != s.rend(); i++ ){
        
        if( ! carry ) break;
        else{
            if( *i == '9' ) *i = '0';
            else { (*i)++; carry = 0; }
        }
    }
    if( carry ) return '1' + s;
    else return s;
}

bool is_nines(string s ){
    for( auto i : s ) if( i != '9') return false;
    return true;
}

string solve( string n ) {
    if( is_nines(n) ){
        for( auto& i : n ) i = '0';
        n[n.length()-1] = '1';
        return '1' + n;
    }
    string first = n.substr(0, n.length()/2);
    string second = n.substr((n.length()+1)/2, n.length()/2 );
    
    // if( first < second )  increment first, append second;
    // if( first > second )  replace second by first.
    reverse(first.begin(), first.end());
    
    if( first <= second ){
        string prefix = increment(n.substr(0, (n.length()+1)/2));
        string suffix = prefix;
        reverse(suffix.begin(), suffix.end());
        if( n.length() % 2 == 1 ){
            suffix = suffix.substr(1,suffix.length()-1);
        }
        return prefix + suffix;
    }
    else{
        string prefix = n.substr(0, (n.length()+1)/2);
        string suffix = prefix;
        reverse(suffix.begin(), suffix.end());
        if( n.length() % 2 == 1 ){
            suffix = suffix.substr(1,suffix.length()-1);
        }
        return prefix + suffix;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin >> T;
    
    while( T-- ) {
        string n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
