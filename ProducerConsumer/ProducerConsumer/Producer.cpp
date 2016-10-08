//
//  Producer.cpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include "Producer.hpp"
#include <math.h>

#include <random>
void Producer::produce(int T){
    
    for( int i = 0; i < T; i ++ )
        _queue.push( rand()%100 );
}