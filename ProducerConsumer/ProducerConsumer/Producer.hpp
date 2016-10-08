//
//  Producer.hpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#ifndef Producer_hpp
#define Producer_hpp

#include <stdio.h>
#include "Queue.hpp"


class Producer{
    MQueue& _queue;
public:
    void produce( int );
    
    Producer( MQueue& q ) : _queue(q){ };
};
#endif /* Producer_hpp */
