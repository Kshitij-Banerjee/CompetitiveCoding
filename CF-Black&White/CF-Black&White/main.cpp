//
//  main.cpp
//  CF-Black&White
//
//  Created by Kshitij Banerjee on 20/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n,m;
    cin >> n;
    cin >> m;
    
    
    for(int i =0 ; i < n; i ++)
    {
        for( int j = 0; j < m; j ++)
        {
            char c;
            cin >> c;
            if(c == 'C' || c == 'M' || c == 'Y' ){
                cout << "#Color" << endl;
                return 0;
            }
        }
    }
    
    cout << "#Black&White" << endl;
    return 0;
}
