//
//  BoardRow.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "BoardRow.h"


namespace cs31
{
    // CS 31:Students must complete this class

    // the default board row constructor is needed to be able
    //     to create an array of BoardRow inside the Board class
    // set the row to have been unused by either Player
    BoardRow::BoardRow() : mValue( 0 ), mHumanUsed( false ), mComputerUsed( false )
    {

    }
    
    // mark that the human player has used this row
    void BoardRow::markHumanUsed( )
    {
        // TODO:
        // TRIVIAL: set humanUsed to true
		mHumanUsed = true;
    }
    
    // has the human player used this row?
    bool BoardRow::hasBeenHumanUsed( ) const
    {
        // TODO:
        // TRIVIAL: return humanUsed
        // just for now...
        return( mHumanUsed );
    }
    
    // mark that the computer player has used this row
    void BoardRow::markComputerUsed( )
    {
        // TODO:
        // TRIVIAL: set computerUsed to true
		mComputerUsed = true;
    }
    
    // has the computer player used this row?
    bool BoardRow::hasBeenComputerUsed( ) const
    {
        // TODO:
        // TRIVIAL: return computerUsed
        // just for now...
        return( mComputerUsed );
    }
    
    // set this row's value
    void BoardRow::setValue( int value )
    {
        mValue = value;
    }
    
    // display this row in stringified form
    // called by the Board class to display each of the Board's rows
    std::string BoardRow::display() const
    {
        std::string s = "";
        s = s + "\t";
        char c = mValue + '0';
        s = s + c + ":\t";
        if (hasBeenHumanUsed())
        {
            s = s + "X";
        }
        s = s + "\t\t";
        if (hasBeenComputerUsed())
        {
            s = s + "X";
        }
        return( s );
    }
    
}
