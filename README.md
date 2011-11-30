__Note: I STRONGLY suggest to review this project that is also availabe on [GitHub](https://github.com/snwfog/comp345-assignment-03). I have made a separated repository named `comp345-project-final`, but most of my commits are stored inside of `comp345-assignment-03`.__

# COMP345 Assignment 3 README
## Map Builder Programming Pattern

### Requirement
- __ncurses 5.9 lib installed__

##### Note: I have completed all the 3 parts that were asked in assignment 3. You can choose to correct all of them, or you should correct the __MapEditor__ sections. The MapEditor section includes Map, MapBuilder, MapEditor, and you should comment out all the irrelevant "test" scenarios that I have included in the main.cpp.

### File Hierarchy
> Files are stored in their appropriate __virtual__ folders in my IDE. However, they are not placed in real folders. Here is the file hierarchy tree.
	
	comp345-assignment-03/
	+-main.cpp
	+-Function.h/.cpp
	  +-d20Game
	  | +-d20Game.h/.cpp
	  | +-d20GameBuilder.h/.cpp
	  +-Observers
	  | +-Observer.h
	  +-Character
	  | +-Character.h/.cpp
	  | +-CharacterBuilder.h/.cpp
	  +-Map
	  | +-Map.h/.cpp
	  | +-MapBuilder.h/.cpp
 	  | +-MapEditor/
	  |   +-MapEditor.h/.cpp
	  +-Item
	  | +-Item.h/.cpp
	  | +-ItemBuilder.h/.cpp
	  +-Chest
	  | +-Chest.h/.cpp
	  | +-ChestBuilder.h/.cpp
	  | +-Merchant.h
	  | +-MerchantBuilder.h/.cpp
	  	

### To Run
> You must compile all the provided .cpp files and additionally, you must link your compiler with the ncurses library using the command `-lnucrses`.
	make -f d20Game.make
> Use this command to run the main.cpp
	./main



### Classes Explanation
#### Character/CharacterBuilder
> Character is the base class for all the characters in the game, ie. Monsters and player. The character class also contains all the actions/movements that the character can do, for example, equipping items, consuming item, battle with others. CharacterBuilder builds character, setting their ability scores, their name, their class, etc.

#### Map/MapBuilder/MapEditor
> The map class is the basic map. The map hosts all the ASCII characters representing the objects in the game. The MapBuilder builds the map by placing these objects, ArenaBuilder is a map builder. These classes implement the MapBuilder class MapBuilder is the interface builder class, ArenaBuilder implements MapBuilder and place the corresponding map elements on the map to make the "arena". MapGenerator contains a MapBuilder and has the ability to generates different kind of map from its MapBuilder.In custom map, the MapEditor is used to place all the objects in the map.

##### ArenaBuilder
> ArenaBuilder, implements MapBuilder. Build a 9x9 arena map, as instructed by assignment 3, with a guardian, and a potentially random generated chest. ArenaBuilder implements the placeMapObject method of MapBuilder.For random generated chest, please see ChestBuilder.h and .cpp.

##### 		Arena Builder GUI

		8	####O####
		9	#		#
		10	#		#
		11	#		#
		12	#		#
		13	#		#
		14	#	x	#	
		15	#	n	#
		16	####@####
			890123456
	  	  	  |30

##### MapGenerator
> MapGenerator is the director of MapBuilders. Can construct different type of map by invoking the constructMap() method, which itself calls the overloaded methods from MapBuilders.

#### Item/ItemBuilder
> Item is the principal class for all the items that exists in the game. For example, the different kind of armors, different kinds of weapon, potions and shields. ItemBuilder builds these item by placing the correct stats on them.

#### Chest/ChestBuilder/Merchant/MerchantBuilder
> Chest and merchant are grouped together because we can imagine a chest been similar to a merchant, i.e. a container that has items inside. The difference nbetween them is that the chest has a limited number of items and cannot be renewed, while the merchant has unlimited number of item, everytime an item is taken, a new one is regenerated to replace it, and a player can sell items when close to a merchant. Chest/MerchantBuilder builds the chest or the merchant by randomly placing objects inside of it.

#### Function
> A few useful helping functions for the d20Game, for example, calculating the ability modifiers, calculating the d20 roll.
__Additional comments inside of class files.__

