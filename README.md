# Arkanoid
## Tech Stack
* [Chili Framework](https://wiki.planetchili.net/index.php/Chili_Framework)

## Playing the Game
A build of the game can be found at Engine/Engine.exe. Simply run the application on any Windows 10 machine.

## Description
A recreation of Arkanoid, a brick breaker game using a paddle and ball
* The goal for the user is to obtain the highest score possible by colliding the ball with the bricks
* The goal of the user is to prevent the ball from colliding with the bottom of the screen by colliding the ball with the paddle
* The movement mechanics of the paddle are in the X dimension within the minimum and maximum screen width
* The movement mechanics of the ball are in the X and Y dimension within the minimum and maximum screen width and heigth
* The ball colliding with a brick destroys the brick and adds 1 point to the user
* Once all the bricks have been destroyed, the next level is reached where an extra line of bricks are added

## Objective

## Physics
* The Brick collision and graphics are rectangles
* The paddle collision and graphics are a rectangle
* The ball collision shape is a rectangle, while the graphics is a circle

## Custom Classes

# Game


# RectF
A class that represents the idea of a rectangle. Utilises the vector class to obtain 2D vector arrays to define rectangular dimensions. This is done with the ```RectF()``` constructor and its wrappers. The member function ```isOverlappingWith()``` checks if two rectangles are overlapping and the member variable ```bool destroyed``` is toggled when the ball collides with a rectangle (within a given position)

# Ball


# Paddle


# Brick

## Imported Framework Classes

# Game

The Game class is where you put the code to make the game do the things. The predefined member functions ```UpdateModel()``` and ```ComposeFrame()``` are where you put your game logic and your rendering code, respectively. Game is composed of the Graphics object used for drawing and keeps a reference to the MainWindow object to interface with the Windows system (which includes the keyboard and mouse inputs). 

# Graphics

This class takes care of all the Direct3D setup and provides an interface to the graphical output of the application. Use Graphics to draw on the screen. ```PutPixel()``` is generally how this is gone about. You can also use ```Graphics::ScreenWidth``` etc. to make sure you keep your drawings inside the screen boundaries.

# MainWindow

Takes care of creating the window and handling the window messages. The message handling involves piping the mouse and keyboard messages to their respective objects. So you need to go through MainWindow to get your input done, à la ```wnd.mouse.Read()```. You can also use this class to figure out whether the main window is minimized or if it's out of focus, and you can kill the main window with ```wnd.Kill()```.

# Keyboard

With Keyboard, you can get the current state of depressed keys, and you can pop key press and release events out of an Event queue contained in Keyboard. You can also turn autorepeat on/off.

# Mouse

With Mouse, you can get the current state of the mouse keys and the pointer position, and you can pop mouse events out of an Event queue contained in Mouse. You can also check whether the mouse is in the window client region.

# Color

Color represents a 32-bit RGBA color value (or a single pixel if you like), and gives you member functions to access the packed channels. There is also a Colors namespace with predefined colors, like ```Colors::Aqua```. 
