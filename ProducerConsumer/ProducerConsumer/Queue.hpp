//
//  Queue.hpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <vector>
#include <mutex>

using namespace std;


class MQueue {

private:
    mutex _mx;
    vector<int> _Q;
    condition_variable cv;
    
public:
    
    void push( int i );
    int pop();
};

#endif /* Queue_hpp */
