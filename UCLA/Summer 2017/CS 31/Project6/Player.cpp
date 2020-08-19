//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <stdexcept>


namespace cs31
{
    // CS 31:Students have no work to do for this class

    // each die is six-sided
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mScore( 0 )
    {
        
    }
    
    // rolls the dice
    // saves the rolled value of each die for later use
    // when supplied a non-zero amount value, the roll will
    // not be random but instead will return the amount requested
    // this supports cheating which allows for much better testing
    // throws std::logic_error if the force amount cannot be rolled
    // by two six-sided dies
    void Player::roll( int amount )
    {
        mScore = 0;
        // is a random roll is desired?
        if (amount == 0)
        {
            mDie1.roll();
            mScore += mDie1.getValue();
            mDie2.roll();
            mScore += mDie2.getValue();
        }
        // is the forced value illegal?
        else if (amount == 1 || amount < 0 || amount > 12)
        {
            throw std::logic_error( "bad forced roll amount" );
        }
        // cheating for testing purposes
        else
        {
            mScore = amount;
        }
    }
    
    // what is the total value of the two dice that the player just rolled?
    int  Player::getScore( ) const
    {
        return( mScore );
    }
    
    // what was the value of one die that the player just rolled?
    int  Player::getDie1( )  const
    {
        // when an amount is forced to be rolled,
        // the die might not really have been tossed.
        int value1 = mDie1.getValue();
        int value2 = mDie2.getValue();
        if (value1 + value2 != mScore)
        {
            value1 = mScore / 2;
            value2 = mScore - value1;
        }
        return( value1 );
    }
    
    // what was the value of one die that the player just rolled?
    int  Player::getDie2( )  const
    {
        // when an amount is forced to be rolled,
        // the die might not really have been tossed.
        int value1 = mDie1.getValue();
        int value2 = mDie2.getValue();
        if (value1 + value2 != mScore)
        {
            value1 = mScore / 2;
            value2 = mScore - value1;
        }
        return( value2 );
    }
    
}
