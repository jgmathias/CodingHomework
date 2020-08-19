//
//  Board.h
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include "BoardRow.h"

namespace cs31
{
    // CS 31:Students must complete this class
    // the Board class keeps track of which spots have been
    // used by each Player through an array of BoardRow
    class Board
    {
    public:
        Board();
        // CS 31:Students must complete the implementation of this method
        // mark that the human player has used this row
        void markHumanUsed( int row );
        // CS 31:Students must complete the implementation of this method
        // has the human player used this row?
        bool hasHumanUsed( int row ) const;
        // CS 31:Students must complete the implementation of this method
        // mark that the human player has used this row
        void markComputerUsed( int row );
        // CS 31:Students must complete the implementation of this method
        // has the computer player used this row?
        bool hasComputerUsed( int row ) const;
        
        // display the entire Board in a stringified form
        std::string display( ) const;
    private:
        BoardRow mBoardRow[ 10 ];  // elements 1-9 ignoring spot 0
    };
}

#endif /* Board_h */
