//
//  Consumer.hpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#ifndef Consumer_hpp
#define Consumer_hpp

#include <stdio.h>
#include "Queue.hpp"


class Consumer {
private:
    MQueue& _queue;
public:
    Consumer( MQueue& q ) : _queue(q) { };
    void consume (int);
    
};
#endif /* Consumer_hpp */
