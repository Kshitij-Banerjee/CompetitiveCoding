//
//  main.cpp
//  TC-RedSquare
//
//  Created by Kshitij Banerjee on 19/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

class RedSquare{
public:
    int countTheEmptyReds(int maxRank, int maxFile, vector <int> rank, vector <int> file){
        
        bool row_even = maxRank % 2 == 0;
        bool col_even = maxFile % 2 == 0;
        int start = row_even ^ col_even ?  0 : 1;
        int count = 0;
        map<pair<int,int>,bool> block;
        for( int i = 0; i < rank.size(); i ++ )
            block.insert(make_pair(make_pair(rank[i], file[i]), true));
       
        for( int row = 0; row <maxRank; row++){
            
            for(int col = start; col <maxFile; col+=2){
                if(block.find(make_pair(row, col)) != block.end() ) continue;
                else count ++;
            }
            start = !start;
        }
        
        return count;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
