# FT_RETRO

###  Subject and Goals

	The goal of this project is to implement a simplistic shoot-em-up-style game in your
	terminal. For those of you who don’t know what that kind of game is (shame on you, by
	the way), have a look at Gradius, R-Type, etc...

	You will use a ’screen’ made up of a grid of ’squares’, that you can equate to the
	characters on your terminal, so that the entities of your game are each represented by a
	character on screen.

### Cloning and running project
```
cd ~/Desktop &&
git clone https://github.com/amnotme/42_Retro.git &&
cd 42_Retro && 
make
```

you will notice the executable **ft_retro**
to run simply ```./ft_retro```

### Mechanics
```
use the directional arrows to move around the screen
use spacebar to shoot
use 'q' to quit program.
```


###### Basic Requirements

- [x] Single-player
- [x] Display using the ```ncurses```  library
- [x] Horizontal or vertical scrolling (The screen area moves through the world, very
	much like in R-Type for example)
- [ ] Random enemies
- [x] The player can shoot at enemies
- [ ] Basic collision handling (If an enemy touches you, you die)
- [ ] Game entities occupy one ’square’ of the map only.
- [x] Frame-based timing

###### Game Dynamics

- [x] Acquire input (Player controls, network, etc ...)
- [ ] Update game entities
- [x] Render display
- [ ] Repeat until game ends !


###### Essential Features Before Bonus Implementation

- [x] Displaying score, time, number of lives, etc... on screen
- [x] Clock-based timing (Use whichever system facility or library you like)
- [x] Entities that can occupy multiple squares
- [ ] Enemies can also shoot
- [x] Scenery (Collidable objects or simple background)

###### Bonus Suggestions

- [ ] Large and hard-to-beat boss enemies
- [ ] Enemies have a scripted behaviour
- [ ] Multiplayer, either on the same keyboard or through the network if you’re feeling cocky
- [ ] Scripted game worlds, with pre-determined batches of enemies

