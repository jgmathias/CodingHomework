//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    // CS 31:Students must complete this class

    Board::Board()
    {
        // setup each of the nine rows in the Board
        for( int i = 1; i <= 9; i++ )
        {
            mBoardRow[ i ].setValue( i );
        }
    }
    
    void Board::markHumanUsed( int row )
    {
        // TODO:
        // update the correct BoardRow to notate that the human
        // player has used this row.
		mBoardRow[row].markHumanUsed();
    }
    
    bool Board::hasHumanUsed( int row ) const
    {
        // TODO:
        // retrieve from the correct BoardRow
        // whether it has been used by the human player
        return( mBoardRow[row].hasBeenHumanUsed() );
    }
    
    void Board::markComputerUsed( int row )
    {
        // TODO:
        // update the correct BoardRow to notate that the computer
        // player has used this row...
		mBoardRow[row].markComputerUsed();
    }
    
    bool Board::hasComputerUsed( int row ) const
    {
        // TODO:
        // retrieve from the correct BoardRow
        // whether it has been used by the computer player
        return( mBoardRow[row].hasBeenComputerUsed() );
    }

    // display the entire board in stringified form
    // by displaying each of the Board's rows
    std::string Board::display( ) const
    {
        std::string s = "\t\t  ShutTheBox Game\n\t\tHuman\t\tComputer\n";
        
        for( int i = 1; i <= 9; i++)
        {
            s += mBoardRow[ i ].display() + "\n";
        }
        
        return( s );
    }
    
}
