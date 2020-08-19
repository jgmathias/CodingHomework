//
//  BoardRow.h
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef BoardRow_h
#define BoardRow_h
#include <string>

namespace cs31
{
    // CS 31:Students must complete this class
    // a BoardRow represents one row on the ShutTheBox table
    // each row has a value (1-9)
    //          tracks an X if the human has used this row's value
    //          tracks an X if the computer has used this row's value
    class BoardRow
    {
    public:
        BoardRow();
        // set this row's value
        void setValue( int value );
        // CS 31:Students must complete the implementation of this method
        // mark that the human player has used this row
        void markHumanUsed( );
        // CS 31:Students must complete the implementation of this method
        // has the human player used this row?
        bool hasBeenHumanUsed( ) const;
        // CS 31:Students must complete the implementation of this method
        // mark that the computer player has used this row
        void markComputerUsed( );
        // CS 31:Students must complete the implementation of this method
        // has the computer player used this row?
        bool hasBeenComputerUsed( ) const;
        
        // show this row in a stringified form
        std::string display() const;
    private:
        int  mValue;         // this row's value
        bool mHumanUsed;     // has the human player used the row?
        bool mComputerUsed;  // has the computer player used the row?
    };
    
}

#endif /* BoardRow_h */
