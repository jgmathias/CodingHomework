//
//  Player.h
//  ShutTheBox
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Die.h"

namespace cs31
{
    // CS 31:Students have no work to do for this class
    // the Player class rolls two six-sided dies
    class Player
    {
    public:
        Player();
        // rolls the dice
        // saves the rolled value of each die for later use
        // when supplied a non-zero amount value, the roll will
        // not be random but instead will return the amount requested
        // this supports cheating which allows for much better testing
        // throws std::logic_error if the force amount cannot be rolled
        // by two six-sided dies
        void roll( int amount = 0 );
        // what is the total value of the two dice that the player just rolled?
        int  getScore( ) const;
        // what was the value of one die that the player just rolled?
        int  getDie1( )  const;
        // what was the value of the other die that the player just rolled?
        int  getDie2( )  const;
    private:
        Die mDie1, mDie2;
        int mScore;
    };
    
}

#endif /* Player_h */
