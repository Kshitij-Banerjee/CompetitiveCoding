//
//  main.cpp
//  CF-PersistentBookcase
//
//  Created by Kshitij Banerjee on 20/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

static    int n,m,q;
static    map<int, vector<int> > saved_shelves;
static    vector<string> ops;

vector<int> split(string pos) {
    vector<int> elems;
    stringstream ss(pos);
    string item;
    while(getline(ss, item, ' ')){
        elems.push_back(atoi(item.c_str()));
    }
    return elems;
}

void place( vector<int>& vi, int i, int j){
    vi[i] |= (1<<j);
}

void remove( vector<int>& vi, int i, int j){
    vi[i] &= (~(1<<j));
}

void invert( int& vi){
    vi = (~vi) &  ((1<<(m+1))-1);
}

void goback( vector<int>& shelves, int time){
    int high = (1 << m );
    while( !time & high){
        high = high >> 1;
    }
    shelves = saved_shelves[high];
    
    for(int i = high ; high <= time; i++){
        vector<int> o = split(ops[i]);
        if( o[0] == 1 ){
            place(shelves, o[1], o[2]);
        }
        else if (o[0] == 2){
            remove(shelves, o[1], o[2]);
        }
        else if (o[0] == 3){
            invert(shelves[o[1]]);
        }
        else if (o[0] == 4){
            goback(shelves, o[1]);
        }
    }
}

void print( vector<int>& shelves) {
    
    int set = 0;
    for( auto i : shelves) {
        for( int j = 0 ;j < m ; j++){
            if( (j<<m) & i)
                set++;
        }
    }
    cout << set << endl;
}


int main(int argc, const char * argv[]) {
    
    
    cin >> n;
    cin >> m;
    cin >> q;
    
    vector<int> shelfs(n+1, 0);
    for( int i =0; i < q; i ++ ){
        string op;
        cin >> op;
        ops.push_back(op);
    }
    
    
    for( int i = 0; i < ops.size(); i++){
        vector<int> o = split(ops[i]);
        if( o[0] == 1 ){
            place(shelfs, o[1], o[2]);
        }
        else if (o[0] == 2){
            remove(shelfs, o[1], o[2]);
        }
        else if (o[0] == 3){
            invert(shelfs[o[1]]);
        }
        else if (o[0] == 4){
            goback(shelfs, o[1]);
        }
        
        if( (i&(i-1)) == 0){
            saved_shelves[i] = shelfs;
        }
        
        print(shelfs);
        
    }
    
    return 0;
}


