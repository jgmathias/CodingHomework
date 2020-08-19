//
//  main.cpp
//  ShutTheBox
//  http://www.playonlinedicegames.com/shutthebox
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

///*
#include <iostream>
#include <cassert>
#include <stdexcept>
#include "Die.h"
#include "Player.h"
#include "ShutTheBox.h"


void clearScreen( );


int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    ShutTheBox game;
    int humanroll;             // what has the human player rolled
    bool validPlay = false;    // is human move valid?
    std::string action, spots, message = "(r)oll (q)uit: ";

    do
    {
        cout << game.display( message ) << endl;
        cin.clear();
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                exit( 0 );
                break;
            case 'r':
            case 'R':
                humanroll = game.humanPlay();
                cout << "Human rolled: " << game.getHumanDie1();
                cout << " " << game.getHumanDie2() << endl;
                // can the human player make any valid move?
                if (game.humanCanPlay( ))
                {
                    do
                    {
                        // query for the human player's move
                        cout << "(s)elect: ";
                        getline( cin, spots );
                        while (spots.size() == 0)
                        {
                            getline( cin, spots );  // no blank entries
                        }
                        // is the desired human player's move valid?
                        validPlay = game.isValidHumanMove(spots, humanroll);
                        if (validPlay)
                        {
                            // update the board with the human player's move
                            for (size_t i = 0; i < spots.size(); i++)
                            {
                                game.humanSelectSpot( spots[ i ] - '0' );
                            }
                        }
                    } while (!validPlay);
                }
                else
                {
                    cout << "No Human move possible!" << endl;
                    cout << "Human ends with a score = " << game.humanScore() << endl;
                    do
                    {
                        game.computerPlay();
                        cout << "Computer rolled: " << game.getComputerDie1();
                        cout << " " << game.getComputerDie2() << endl;
                        // can the computer player make any valid move?
                        if (game.computerCanPlay())
                        {
                            // update the board with the computer player's move
                            string move = game.makeComputerMove();
                            cout << "Computer selecting spots: " << move << endl;
                            message = "Hit return to continue: ";
                            cout << game.display( message ) << endl;
                            getline( cin, action );
                        }
                        else
                        {
                            // game over
                            break;
                        }

                    } while( true );
                    cout << "no Computer move possible!" << endl;
                    cout << "Computer ends with a score = " << game.computerScore() << endl;
                    cout << "Human ends with a score = " << game.humanScore() << endl;
                    cout << game.stringifyGameOutcome() << endl;
                }
                break;
        }
    } while( !game.gameIsOver() );
    
    return( 0 );
}
//*/

/*
#include <iostream>
#include <string>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "BoardRow.h"
#include "Board.h"
#include "ShutTheBox.h"                   

using namespace std;

int main()
{
	using namespace std;
	using namespace cs31;
	// test code
	Board board;
	assert(board.hasHumanUsed(0) == false);
	assert(board.hasComputerUsed(0) == false);
	assert(board.hasHumanUsed(-1) == false);
	assert(board.hasComputerUsed(-1) == false);
	assert(board.hasHumanUsed(10) == false);
	assert(board.hasComputerUsed(10) == false);
	assert(board.hasHumanUsed(1) == false);
	assert(board.hasComputerUsed(1) == false);
	board.markHumanUsed(1);
	assert(board.hasHumanUsed(1) == true);
	board.markComputerUsed(1);
	assert(board.hasComputerUsed(1) == true);


	ShutTheBox game1;
	game1.humanPlay(6);
	assert(game1.getHumanDie1() + game1.getHumanDie2() == 6);
	assert(game1.determineGameOutcome() == ShutTheBox::GAMENOTOVER);



	// test code
	ShutTheBox game2;
	game2.humanPlay(7);
	game2.humanSelectSpot(1);
	game2.humanSelectSpot(6);
	game2.humanPlay(8);
	game2.humanSelectSpot(8);
	game2.humanPlay(9);
	game2.humanSelectSpot(9);
	game2.humanPlay(6);
	game2.humanSelectSpot(2);
	game2.humanSelectSpot(4);
	game2.humanPlay(7);
	game2.humanSelectSpot(7);
	game2.humanPlay(7); // cannot be played...
	assert(game2.humanHasUsedSpot(1));
	assert(game2.humanHasUsedSpot(2));
	assert(game2.humanHasUsedSpot(3) == false);
	assert(game2.humanHasUsedSpot(4));
	assert(game2.humanHasUsedSpot(5) == false);
	assert(game2.humanHasUsedSpot(6));
	assert(game2.humanHasUsedSpot(7));
	assert(game2.humanHasUsedSpot(8));
	assert(game2.humanHasUsedSpot(9));
	assert(game2.humanCanPlay() == false);
	assert(game2.humanScore() == 3 + 5);
	game2.computerPlay(7);
	game2.computerSelectSpot(1);
	game2.computerSelectSpot(6);
	game2.computerPlay(8);
	game2.computerSelectSpot(8);
	game2.computerPlay(9);
	game2.computerSelectSpot(9);
	game2.computerPlay(6);
	game2.computerSelectSpot(2);
	game2.computerSelectSpot(4);
	game2.computerPlay(7);
	game2.computerSelectSpot(7);
	game2.computerPlay(7); // cannot be played...
	assert(game2.computerHasUsedSpot(1));
	assert(game2.computerHasUsedSpot(2));
	assert(game2.computerHasUsedSpot(3) == false);
	assert(game2.computerHasUsedSpot(4));
	assert(game2.computerHasUsedSpot(5) == false);
	assert(game2.computerHasUsedSpot(6));
	assert(game2.computerHasUsedSpot(7));
	assert(game2.computerHasUsedSpot(8));
	assert(game2.computerHasUsedSpot(9));
	assert(game2.computerCanPlay() == false);
	assert(game2.computerScore() == 3 + 5);
	assert(game2.determineGameOutcome() == ShutTheBox::TIEDGAME);

	cout << "all tests passed!" << endl;
	return 0;
}
*/

void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

