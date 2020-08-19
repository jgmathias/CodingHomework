//
//  ShutTheBox.cpp
//  ShutTheBox
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "ShutTheBox.h"
#include <iostream>
#include <cmath>

namespace cs31
{
    ShutTheBox::ShutTheBox()
    {
        
    }
    
    // what is the current result of the game?
    ShutTheBox::GAMEOUTCOME  ShutTheBox::determineGameOutcome( ) const
    {
        // TODO:
        // if neither player can play, then consider the score
        // of each player to determine the outcome
		ShutTheBox::GAMEOUTCOME result = GAMENOTOVER;
		
		if (mHuman.getScore() < mComputer.getScore())
		{
			result = HUMANWONGAME;
		}
		else if (mHuman.getScore() > mComputer.getScore())
		{
			result = COMPUTERWONGAME;
		}
		else if (mHuman.getScore() == mComputer.getScore())
		{
			result = TIEDGAME;
		}

        return( result );
    }

    // has the game ended?
    bool ShutTheBox::gameIsOver() const
    {
        // TODO:
        // is the game over?
        return( !humanCanPlay() && !computerCanPlay() );
    }

    // allow the human to make a move, returning the total value rolled
    // when supplied a non-zero amount value, the roll will
    // not be random but instead will be the amount requested
    // this supports cheating which allows for much better testing
    int ShutTheBox::humanPlay( int amount )
    {
        // TODO:
        // if the amount is non-zero, then force the human player to roll
        // the desired amount
        // otherwise, have the human player roll a random value
		// HINT:
		// look at computerPlay( int amount ) 
		if (amount == 0)
		{
			mHuman.roll();
		}
		else
		{
			mHuman.roll(amount);
		}
        // return the total value rolled
        return( mHuman.getScore() );
    }
    
    // return the human player's first die
    int ShutTheBox::getHumanDie1( ) const
    {
        // TODO:
        // TRIVIAL: return the human player's first die
        // just for now...
        return( mHuman.getDie1() );
    }
    
    // return the human player's second die
    int ShutTheBox::getHumanDie2( ) const
    {
        // TODO:
        // TRIVIAL: return the human player's second die
        // just for now...
        return( mHuman.getDie2() );
    }
    
    // return the computer player's first die
    int ShutTheBox::getComputerDie1( ) const
    {
        // TODO:
        // TRIVIAL: return the computer player's first die
        // just for now...
        return( mComputer.getDie1() );
    }
    
    // return the computer player's second die
    int ShutTheBox::getComputerDie2( ) const
    {
        // TODO:
        // TRIVIAL: return the computer player's second die
        // just for now...
        return( mComputer.getDie2() );
    }
    
    // has the human player already use this spot on the Board?
    bool ShutTheBox::humanHasUsedSpot( int spot ) const
    {
        // TODO:
        // determine if the current Board has already marked this
        // spot used by the human player
        // just for now...
        return( mBoard.hasHumanUsed(spot) );
    }
    
    // has the computer player already used this spot on the Board?
    bool ShutTheBox::computerHasUsedSpot( int spot ) const
    {
        // TODO:
        // determine if the current Board has already marked this
        // spot used by the computer player
        // just for now...
        return( mBoard.hasComputerUsed(spot) );
    }
    
    
    // CS 31:All the rest of this class has been fully implemented.  Yay!
    
    
    // update the board, selecting this spot for the computer player
    void ShutTheBox::computerSelectSpot( int spot )
    {
        mBoard.markComputerUsed( spot );
    }

    // update the board, selecting this spot for the human player
    void ShutTheBox::humanSelectSpot( int spot )
    {
        mBoard.markHumanUsed( spot );
    }
    
 
    // allow the computer to make a move, returning the total value rolled
    // when supplied a non-zero amount value, the roll will
    // not be random but instead will be the amount requested
    // this supports cheating which allows for much better testing
    int ShutTheBox::computerPlay( int amount )
    {
        if (amount != 0)
        {
            mComputer.roll( amount );
        }
        else
        {
            mComputer.roll();
        }
        return( mComputer.getScore() );
    }
    
    // based on the current Board and human players two dies,
    // does the human player have any move it can make?
    bool ShutTheBox::humanCanPlay( ) const
    {
        return( canPlay( true ) );
    }
    
    // based on the current Board and computer players two dies,
    // does the computer player have any move it can make?
    bool ShutTheBox::computerCanPlay( ) const
    {
        return( canPlay( false ) );
    }

    // an internal helper function that determines whether a legal move exists
    bool ShutTheBox::canPlay( bool human ) const
    {
        bool result = false;
        bool availableTiles[ 9 ];
        for (int i = 1; i <= 9; i++)
        {
            if (human && mBoard.hasHumanUsed( i ))
            {
                availableTiles[ i-1 ] = false;
            }
            else if (!human && mBoard.hasComputerUsed( i ))
            {
                availableTiles[ i-1 ] = false;
            }
            else
            {
                availableTiles[ i-1 ] = true;
            }
        }
        if (human)
        {
            result = true;
            if (mHuman.getScore() != 0)
                result = hasValidMove( availableTiles, 9, mHuman.getScore() );
        }
        else
        {
            result = true;
            if (mComputer.getScore() != 0)
                result = hasValidMove( availableTiles, 9, mComputer.getScore() );

        }
        return( result );
    }

    // assuming the computer player's turn is over,
    // what is the computer player's score in the game?
    int ShutTheBox::computerScore( ) const
    {
        int total = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (!mBoard.hasComputerUsed( i ))
            {
                total = total + i;
            }
        }
        return( total );
    }
    
    // assuming the human player's turn is over,
    // what is the human player's score in the game?
    int ShutTheBox::humanScore( ) const
    {
        int total = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (!mBoard.hasHumanUsed( i ))
            {
                total = total + i;
            }
        }
        return( total );
    }
    
    // an internal helper function that determines whether a legal move exists
    bool ShutTheBox::hasValidMove( bool available[], const int nTiles, int diceTotal ) const
    {
		int * value;
		value = new int[nTiles];
        // int value[nTiles]; 			// numeric values of the remaining tiles
        int nRemaining = 0;			// how many tiles are left
        int nCombinations = 0;		// how many combinations are there?
        int sum = 0;				// the sum of a particular combination
        int binary = 0;				// a temporary variable used for conversion
        int whichTile = 0;			// counter for doing sum
        
        bool validMove = false;		// the result variable
        
        // gather the available tiles
        for (int i = 0; i < nTiles; i++)
        {
            if (available[i])
            {
                value[nRemaining] = i + 1;	// add 1 because tiles are numbered 1-9
                nRemaining++;
            }
        }
        
        // calculate number of combinations
        nCombinations = int( pow( 2.0, nRemaining ) );
        
        for (int counter = 1; counter < nCombinations && !validMove; counter++)
        {
            // new combination; reset the sum
            sum = 0;
            whichTile = 0;
            
            // convert this number to binary
            binary = counter;
            while (binary > 0)
            {
                if (binary % 2 == 1)
                {
                    sum += value[whichTile];
                }
                binary /= 2;
                whichTile++;
            }
            validMove = (sum == diceTotal);
        }
		delete[] value;
        return validMove;
    }
    
    // stringify the current result of the game so it can be printed
    std::string  ShutTheBox::stringifyGameOutcome( ) const
    {
        std::string result = "";
        if (determineGameOutcome() == HUMANWONGAME)
        {
            result = "\n\t\tYou won ShutTheBox!";
        }
        else if (determineGameOutcome() == COMPUTERWONGAME)
        {
            result = "\n\t\tYou lost ShutTheBox!";
        }
        else
        {
            result = "\n\t\tShutTheBox wound up tied!";
        }
        return( result );
    }
    
    // for the string of spots selected and the rolled amount,
    // is this move valid for the human player, given the
    // current state of the board?
    bool ShutTheBox::isValidHumanMove( std::string selections, int rolledAmount ) const
    {
        return( validMove( true, selections, rolledAmount ) );
    }
    
    // for the string of spots selected and the rolled amount,
    // is this move valid for the computer player, given the
    // current state of the board?
    bool ShutTheBox::isValidComputerMove( std::string selections, int rolledAmount ) const
    {
        return( validMove( false, selections, rolledAmount ) );
    }
    
    // an internal helper function that determines that a string of selected spots is a valid play for the particular player
    bool ShutTheBox::validMove( bool human, std::string selections, int rolledAmount ) const
    {
        bool result = true;
        int total = 0;
        for (size_t i = 0; i < selections.size(); i++)
        {
            if (isdigit( selections[i] ))
            {
                total = total + (selections[i] - '0');
            }
            else
            {
                result = false;
                total = -1;
                break;
            }
        }
        if( total == rolledAmount )
        {
            // none of the spots can already be used
            for (size_t i = 0; i < selections.size(); i++)
            {
                if (human && humanHasUsedSpot( selections[ i ] - '0' ))
                {
                    // input is bad...
                    result = false;
                    break;
                }
                else if (!human && computerHasUsedSpot( selections[ i ] - '0' ))
                {
                    // input is bad...
                    result = false;
                    break;
                }
            }
            // none of the spots can be repeated
             for (size_t i = 0; i < selections.size(); i++)
             {
                for (size_t j = 0; j < selections.size(); j++)
                {
                    if (i != j && selections[ i ] == selections[ j ])
                    {
                        // input is bad...
                        result = false;
                        break;
                    }
                }
             }
        }
        else
        {
            result = false;
        }
        return( result );
    }
    
    // an internal helper function that returns a valid computer move
    // as a string of selected spots
    std::string ShutTheBox::computerMove( bool available[], const int nTiles, int diceTotal ) const
    {
        // int value[nTiles]; 			// numeric values of the remaining tiles
		int * value;
		value = new int[nTiles];
		int nRemaining = 0;			// how many tiles are left
        int nCombinations = 0;		// how many combinations are there?
        int sum = 0;				// the sum of a particular combination
        int binary = 0;				// a temporary variable used for conversion
        int whichTile = 0;			// counter for doing sum
        bool validMove = false;
        std::string result = "";	// the result variable
        
        // gather the available tiles
        for (int i = 0; i < nTiles; i++)
        {
            if (available[i])
            {
                value[nRemaining] = i + 1;	// add 1 because tiles are numbered 1-9
                nRemaining++;
            }
        }
        
        // calculate number of combinations
        nCombinations = int( pow( 2.0, nRemaining ) );
        
        for (int counter = 1; counter < nCombinations && !validMove; counter++)
        {
            // new combination; reset the sum
            sum = 0;
            result = "";
            whichTile = 0;
            
            // convert this number to binary
            binary = counter;
            while (binary > 0)
            {
                if (binary % 2 == 1)
                {
                    sum += value[whichTile];
                    char c = value[whichTile] + '0';
                    result = result + c;
                }
                binary /= 2;
                whichTile++;
            }
            validMove = (sum == diceTotal);
        }
		delete[] value;
        return( result );
    }

    // an internal helper function that returns a valid computer move
    // as a string of selected spots and updates the Board for this move
    std::string ShutTheBox::makeComputerMove( )
    {
        bool availableTiles[ 9 ];
        for (int i = 1; i <= 9; i++)
        {
            if (mBoard.hasComputerUsed( i ))
            {
                availableTiles[ i-1 ] = false;
            }
            else
            {
                availableTiles[ i-1 ] = true;
            }
        }
        std::string move = computerMove( availableTiles, 9, mComputer.getScore() );
        for (size_t i = 0; i < move.size(); i++)
        {
            computerSelectSpot( move[ i ] - '0' );
        }
        return( move );
    }
    
    // show this game in stringified form
    // winds up calling display() on Board and BoardRow
    std::string ShutTheBox::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        return( s );
    }

}
