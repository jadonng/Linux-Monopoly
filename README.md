# COMP2113_Group30

## Team members

Jadon Ng Tsz Hei (3036076067) @jadonng @crxxom

Tony Song Wenhao (3035974066) @swh2004

## How to Play Text-Based Monopoly (HKU version) in C++

Welcome to the world of HKU! 
This guide will help you understand how to play the text-based Monopoly game we have built in C++.

### Before we start......

By simply typing

      make main

to create an executable .exe file for the game

Then type 

      ./main

in your terminal. The game will start automatically!

### Initiating the Game
1. Enter Player Details: When prompted, first enter the **number of rounds** you wished to play
   
   `Number of rounds for each player (must be an integer):`
   
2. Next, enter the the **Initial Cash** that every player will start with
   
   `Initial Cash (must be positive):`
   
   (We suggest 1500 if you have time and aim for an exciting game)

3. Then, enter the **Number of Players** (2-4) you wished to play with, followed by their **Name** respectively
   
   `Number of Players (2-4):`
   
   `Player 1 name: (between 2-20 characters):`

You are all set! Your journey now begins!

### Commands

The game will prompt all the actions you can possibly make when it is your turn, for example:

```
**Example**
>> Player ABC's turn!
Press the respective hotkey to choose your next action.
1: Roll dice
2: Check game status
```
The output above shows it is now Player ABC's turn, which includes **1. Roll Dice** and **2. Check game status**.

You can safely assume all commands you would have to make will be Numbers.

After you enter the desired command, for example

`
1
`

The game will run the command "Roll dice", which will roll 2 fair die and return the sum.

```
>> Player ABC's turn!
Press the respective hotkey to choose your next action.
1: Roll dice
2: Check game status
1
>> You rolled 5!
>> You have arrived MTR_Exit_A1 which has no owner with the price of 200
```

Similarly, you will then be prompted with another set of commands.

```
Press the respective hotkey to choose your next action.
1: Buy land
2: Check game status
3: End Round
```

This time, you can choose from **1: Buy land** **2: Check game status** and **3: End Round**

Your round will not end before you enter **3**, so you can check your status whenever you want.

Right now, Let's try **1. Buy land**

```
1
>> You have bought MTR_Exit_A1 for 200
```

After you buy the land, other players cannot buy it any more, instead,  when they land on the same cell in the future, they will have to pay you some land rent!

For example:

```
>> MTR_Exit_A1 is owned by DEF
>> You have pay 25 to ABC
>> Your remaining balance is 1475
```

Now, let's keep our attention on actions after buying MTR_Exit_A1.

You will again have to choose from a few commands.

```
Press the respective hotkey to choose your next action.
1: Build property
2: Check game status
3: End Round
```

You can choose to **1: Build property** on the land, which is going to **DOUBLE** the rent other players have to play when they land on it!

```
>> You have build a house on MTR_Exit_A1!
>> MTR_Exit_A1 currently have 1 houses.
```

Done! The rent of MTR_Exit_A1 has doubled!


Or instead, you can always **2: Check game status** in your round, which will show all information about you. 

```
>> Player: ABC
>> Your Position: 5
>> Your Money: 50
>> Jail card: 0
>> Your Land(properties): MTR_Exit_A1(1)

```

Don't forget to `3: End Round` and pass the control to your friend!

All players will take turns accessing the terminal when it is their turn.

That's all for the basic commands! You can travel freely around HKU now.

We’ve incorporated a multitude of unexpected elements into the game to heighten the excitement. These elements, which you may encounter, are left for your discovery. 

The game will end when the desired number of turns have been played, or one player reaches **MONOPOLY** (All other players went bankrupt). Whichever earlier.

If no one reaches MONOPOLY when the game ends, the player with the most assets will win!

Enjoy!

-------------------------------------------------------------------------------------------------------------
## Meeting Project requirements

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

    contain the loadBoard function, which loads the intial game setup from board.txt

5.) board.h:

    header file for board.cpp

6.) board.txt:

    text file containing the initial setup of board, players can customize the board without knowing any programming language

7.) checkstatus.cpp:

    contain the checkstatus function, which allows players to check his/her status

8.) checkstatus.h:

    header file for checkstatus.cpp

9.) main.cpp:

    main programme for the game

10.) printBoard.cpp:

     contain the printBoard function, which visualize the entire board layout with the names and prices of various of lands

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

list of libraries we have used:

cmath

cstdlib

ctime

fstream

iomanip

iostream

sstream

string

vector
