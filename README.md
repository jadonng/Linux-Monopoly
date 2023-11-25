# COMP2113_Group30
Meet requirements.

1.	Generation of random game sets or events:
   
   We use random in rolling the dice to determine the step of player to move. In addition, when the player steps on the chance(punishment cell, we use random to choose one “chance” from all “chances”.

2.	Data structures for storing game status:

   For data structures, we have Player to store their name, money, land, some items and so on. Besides, we have Cell to store the price, position, number of properties and so on. We also use array, vector, and other data structures to store diverse data like players, cells(board), lands and so on.

3.	Dynamic memory management:

   We use dynamic memory management to store players for their uncertain number of players.

4.	File input/output:
   
   We use file input to load the board stored in board.txt and upload them to the array of board.

5.	Program codes in multiple files:

   Description of files

1.) Makefile:

    makefile for generating the executable main file, and for cleaning all .o files

2.) action.cpp:

    contain functions for player actions, such as buy land, pay rent, and build property

3.) action.h:

    header file for action.cpp

4.) board.cpp:

    contain the loadBoard function, which loads the intial board setup from board.txt

5.) board.h:

    header file for board.cpp

6.) board.txt:

    text file containing the initial setup of board

7.) checkstatus.cpp:

    cotain the checkstatus function, which allows players to check his/her status

8.) checkstatus.h:

    header file for checkstatus.cpp

9.) main.cpp:

    main programme for the game

10.) printBoard.cpp:

     contain the printBoard function, which displays the current board layout

11.) printBoard.h:

     header file for printBoard.cpp

12.) structures.cpp:

     contain the TriggerEvent function, which triggers events based on the current position of player

13.) structures.h:

     header file for structures.cpp; contain structures Player (structure for each player) and Cell (structure for each cell of board)

14.) wincheck.cpp:

     contain functions that check whether any player wins or is broke

15.) wincheck.h:

     header file for wincheck.cpp
