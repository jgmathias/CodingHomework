//
//  ShutTheBox.h
//  ShutTheBox
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef ShutTheBox_h
#define ShutTheBox_h
#include <string>
#include "Player.h"
#include "Board.h"


namespace cs31
{
    // CS 31:Students must complete this class
    // the ShutTheBox class plays the game
    // has two Players: one for the human player, one for the computer player
    // has a Board which is a collection of BoardRow
    class ShutTheBox
    {
    public:
        ShutTheBox();
        
        // the possible outcomes
        enum GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, TIEDGAME, GAMENOTOVER };

        // CS 31:Students must complete the implementation of this method
        // what is the current result of the game?
        GAMEOUTCOME  determineGameOutcome( ) const;
        // CS 31:Students must complete the implementation of this method
        // has the game ended?
        bool gameIsOver() const;

        // CS 31:Students must complete the implementation of this method
        // allow the human to make a move, returning the total value rolled
        // when supplied a non-zero amount value, the roll will
        // not be random but instead will be the amount requested
        // this supports cheating which allows for much better testing
        int humanPlay( int amount = 0 );
        // CS 31:Students must complete the implementation of this method
        // what did the first human die roll
        int getHumanDie1( ) const;
        // CS 31:Students must complete the implementation of this method
        // what did the second human die roll
        int getHumanDie2( ) const;
        // CS 31:Students must complete the implementation of this method
        // has the human player used this spot on the Board?
        bool humanHasUsedSpot( int spot ) const;
        
        // CS 31:Students must complete the implementation of this method
        // allow the computer to make a move, returning the total value rolled
        // when supplied a non-zero amount value, the roll will
        // not be random but instead will be the amount requested
        // this supports cheating which allows for much better testing
        int computerPlay( int amount = 0 );
        // CS 31:Students must complete the implementation of this method
        // what did the first computer die roll
        int getComputerDie1( ) const;
        // CS 31:Students must complete the implementation of this method
        // what did the second computer die roll
        int getComputerDie2( ) const;
        // CS 31:Students must complete the implementation of this method
        // has the computer player used this spot on the Board?
        bool computerHasUsedSpot( int spot ) const;


        // all the rest of the methods listed here have been implemented
        // completely.  Yay!
        
        // show this game in stringified form
        // winds up calling display() on Board and BoardRow
        std::string display( std::string msg = "" ) const;
        
        // update the Board for the human player's spot
        void humanSelectSpot( int spot );
        // based on the current Board and human players two dies,
        // does the human player have any move it can make?
        bool humanCanPlay( ) const;
        // assuming the human player's turn is over,
        // what is the human player's score in the game?
        int humanScore( ) const;
        // for the string of spots selected and the rolled amount,
        // is this move valid for the human player, given the
        // current state of the board?
        bool isValidHumanMove( std::string selections, int rolledAmount ) const;
        
        // update the Board for the specific spot
        void computerSelectSpot( int spot );
        // based on the current Board and computer players two dies,
        // does the computer player have any move it can make?
        bool computerCanPlay( ) const;
        // assuming the computer player's turn is over,
        // what is the computer player's score in the game?
        int computerScore( ) const;
        // based on the computer player's score,
        // update the Board for a valid computer play
        std::string makeComputerMove( );
        // for the string of spots selected and the rolled amount,
        // is this move valid for the computer player, given the
        // current state of the board?
        bool isValidComputerMove( std::string selections, int rolledAmount ) const;
        
        // stringify the current result of the game so it can be printed
        std::string  stringifyGameOutcome( ) const;
        
    private:
        Player mHuman;
        Player mComputer;
        Board  mBoard;
        
        // an internal helper function that determines whether a legal move exists
        bool hasValidMove( bool available[], const int nTiles, int diceTotal ) const;
        // an internal helper function that returns a valid computer move
        // as a string of selected spots and updates the Board for this move
        std::string computerMove( bool available[], const int nTiles, int diceTotal ) const;
        // an internal helper function that determines whether a legal move exists
        bool canPlay( bool human ) const;
        // an internal helper function that determines that a string of selected spots is a valid play for the particular player
        bool validMove( bool human, std::string selections, int rolledAmount ) const;
    };
    
}

#endif /* ShutTheBox_h */
