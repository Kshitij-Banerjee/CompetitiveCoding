//
//  Consumer.cpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include "Consumer.hpp"


void Consumer::consume( int T) {
    for( int i = 0 ;i < T; i ++ )
        _queue.pop();
}
