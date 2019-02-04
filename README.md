Work in Progress...

All rights reserved

This is a simple real time strategy game writed by me in C++ language with help of SFML 2.5.1 library.
![alt text](https://raw.githubusercontent.com/Wyder7PL/Game/master/Pictures/picture1.png "Game overview")

Instruction:

After you run an application, you can choose level to play, simply click on the level button to start the game.

Buildings with blue borders belongs to you.

If you have a unit with hammer "Bulider", you can build buildings, to build one select one of the buttons on the GUI on the left, then press create button. It will allow you to place construction on map, all tiles under construction must be yellow in order to set the construction to build.
A builder will go to take resources from the magazine to to the construction, so if you don't have any magazine, make sure you build it first.

![alt text](https://raw.githubusercontent.com/Wyder7PL/Game/master/Pictures/picture2.png "Buildings")


You can select your units to give them orders. 
To select a unit, press and hold left mouse button, then drag mouse over your unit and beyond, then release mouse button.
![alt text](https://raw.githubusercontent.com/Wyder7PL/Game/master/Pictures/picture3.png "unit selection")
![alt text](https://raw.githubusercontent.com/Wyder7PL/Game/master/Pictures/picture4.png "unit selection")
![alt text](https://raw.githubusercontent.com/Wyder7PL/Game/master/Pictures/picture5.png "unit selection")

After you select some units, you can order them to move to specific direction, just press right mouse button 

Also after you select some units, you will see some control buttons on the lower left corner:

First 3 buttons exists to filter selected units 
* First button select only selected combat units and deselect other units
* Second button will leave melee units selected only
* Third button will leave only distance units selected

Next 4 buttons are for:

* Pause Work - worker will stop work, it can only move where player order him to move, but it will return to the same work on resume, works only on non-combat units

* Abort Work - worker will abort work, it can only move where player order him to move, and it will serach for new task on resume, works only on non-combat units

* Resume work - Resume paused and aborted work 

* Enter fortification - It will order unit to enter free slot in nearest tower

Last 2 buttons stands for move mode:

* Offensive mode - Unit will move to the position ordered by player only when unit don't have any tasks to do
	
* Forced move - Unit will do nothnig but move to ordered position, ignoring tasks and fight, set by default


Available buildings for now:

* Magazine - A pace where unit can take and store resources, build it first

* Tavern - Here you can spent gold to afford workers and units, type and price is random

* House - Increase your limit of max population by 1

* Mine - Can be only placed on ores deposit and requires miner to work, used to generate resources

* Workshop - Can make one resource from another resource, require worker with toolbox to work

* Forester - Places tress randomly around that can be harvested by a gatherer, it will also increase your population number by 1

* Tower - Can contain two units, distance unit can shoot to enemy from towers

