//
//  Die.h
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Die_h
#define Die_h

namespace cs31
{
    

class Die
{
public:
    // CS 31:Students have no work to do for this class
    Die( int sides = 6 );    // by default, a six sided die
    void roll();             // toss the die
    int  getValue( ) const;  // retrieve the value that was rolled
private:
    int  mSides;
    int  mValue;
};

    
}
#endif /* Die_h */
