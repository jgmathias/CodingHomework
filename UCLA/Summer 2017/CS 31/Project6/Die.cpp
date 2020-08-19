//
//  Die.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Die.h"
#include <random>

namespace cs31
{
    // CS 31:Students have no work to do for this class

    // how many sides should this die have?
    Die::Die( int sides ) : mSides( sides ), mValue( 1 )
    {

    }
    
    // toss the die
    // save the tossed value for later use
    void Die::roll()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_int_distribution<> dist(1, mSides);
        mValue = dist(e2);
    }
    
    // retrieve the value that was rolled
    int  Die::getValue( ) const
    {
        return( mValue );
    }

}
