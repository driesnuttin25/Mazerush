# Mazerush
<img width="566" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/562b473b-136b-4ac1-a604-9443abe88ff0">

## Overview
Mazerush is an interactive, graphical maze exploration game where players navigate through a maze to collect chests and coins. The goal is to collect as many coins as possible before time runs out or navigate through the maze's challenges.

## Features
- Navigate through a dynamically generated maze. Maze generation is done by using a recursive backtracking algorithm.
- Collect chests to increase your coin count.
- Visual coin counter to track the number of coins collected.
- Collision detection with walls and chests.

## How to Play
- Use arrow keys to move the player through the maze.
- Collect chests to gain coins. Each chest will increase your coin count.
- Avoid getting trapped in dead ends within the maze.

<img width="566" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/11ca8e88-02e9-4683-a450-c02143ea668e">

## Maze Generation

The maze in the game is dynamically generated using a **Recursive Backtracking Algorithm**. 
This algorithm is a randomized version of the depth-first search algorithm and is frequently used in maze generation due to its simplicity and ability to generate perfect mazes.

### How the Recursive Backtracking Algorithm Works

1. **Initialization**: The maze is initially set up as a grid of cells. All cells start as walls.

2. **Starting Cell**: Choose a random cell as the starting point and mark it as a path.

3. **Recursive Exploration**:
    - From the current cell, choose a random neighboring cell that has not been visited yet.
    - If there is such a cell:
        - Remove the wall between the current cell and the chosen cell.
        - Mark the chosen cell as part of the path and recursively apply the same process to it.
    - If there are no unvisited neighboring cells, backtrack to the previous cell and repeat the process.

4. **Backtracking**: The algorithm backtracks when it hits a dead end (a cell with no unvisited neighbors). Backtracking continues until it finds a cell with unvisited neighbors, exploring a new path from there.

5. **Completion**: This process continues until all cells have been visited. The result is a maze with a single path from the start to every cell in the maze.

### Characteristics of the Generated Maze

- **Uniqueness**: Each time the game starts, the maze is generated anew, leading to a unique gameplay experience.
- **Complexity and Solvability**: The maze is complex enough to provide a challenge but is designed to be solvable without dead ends that cannot be escaped.

### Visual Representation

In the game, the maze is visually represented with distinct graphics for the walls and paths. The player navigates through the paths trying to collect chests and avoid dead ends.

The recursive backtracking algorithm ensures that the maze is intriguing and enjoyable, providing a different challenge each time the game is played.

<img width="300" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/8f554a2f-1610-4d90-9388-9dacfc42ca73">

<img width="300" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/47ba791c-9b0b-4e57-96b1-73f274223d20">

<img width="300" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/829c92cd-c65e-452c-bb55-1c493deb6d5f">

Ofcourse all the conditions can also be altered, including the maze height and width and the amount of chests and the amount of holes a player could fall into.

<img width="300" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/43dab3ad-99bb-4b0f-a94b-9b18a38d06e7">
<img width="300" alt="image" src="https://github.com/driesnuttin25/Mazerush/assets/114076101/b54500ad-832c-4a10-9db8-463854eaaa1c">

## Technologies Used
- C++ for game logic.
- Qt Framework for graphics and UI components.

## Acknowledgments

- I am part of the PXL electronics and ICT group and this project is developed as part of an educational initiative to learn C++ and object-oriented programming.

# Grading System
As this is a school task, there are specific criteria that need to be fulfilled. These are the following criteria:


## Basis
- [ ] Useful and correct class - _Explain why_
- [ ] Useful and correct abstraction - _Explain why_
- [ ] Useful and correct encapsulation - _Explain why_
- [ ] Useful and correct inheritance - _Explain why_
- [ ] Useful and correct polymorphism - _Explain why_
- [ ] Useful and correct object composition - _Explain why_
- [ ] Useful and correct base class
- [ ] Useful and correct abstract base class
- [ ] Useful and correct virtual function
- [ ] No mistake in object-oriented programming

## Additional - General
- [ ] Clean main
- [ ] No globals, but statics if needed
- [ ] Correct protections
- [ ] Maintainability by clean uniform code style and good function naming and/or comments everywhere
- [ ] Separate header files
- [ ] One complete project that compiles and does not crash
- [ ] Fully working project
- [ ] Sufficient git commits (± weekly)
- [ ] Correct files on git
- [ ] Working build manual as readme on GitHub

## Object-Oriented Programming (OOP)
- [ ] At least 2 default constructors
- [ ] At least 2 parameterized constructors
- [ ] At least 2 copy constructors
- [ ] At least 2 destructors
- [ ] Member initialization in constructors
- [ ] Constructor forwarding
- [ ] Useful proven (dynamic) polymorphism
- [ ] Useful usage of "this"
- [ ] Useful member function
- [ ] Default values in function definition
- [ ] Useful member variable
- [ ] Useful getters and setters for member variables
- [ ] Correct usage of inline function
- [ ] Useful template function or class
- [ ] Useful friend function or class

## C++
- [ ] Everything in one or more self-made namespace(s)
- [ ] 2 useful unsigned chars or other better usage of memory efficient type
- [ ] At least 4 useful const references for variables
- [ ] At least 4 useful const references for functions
- [ ] At least 4 useful bool
- [ ] Dynamic memory allocation (new)
- [ ] Dynamic memory removing (delete)
- [ ] 2 useful (modern) call-by-references
- [ ] Useful string class usage
- [ ] Useful container class
- [ ] Useful usage of nullptr
- [ ] Useful usage of (modern) file-I/O
- [ ] Useful exception handling
- [ ] Useful usage of lambda function
- [ ] Useful usage of threads

## Extension
- [ ] Useful Qt class
- [ ] Useful usage of signals/slots
- [ ] Test-driven development (written test plan or unit tests)
- [ ] Solve bug ticket (with pull request or commit message issue link and issue branch)
- [ ] Report a bug ticket on another project
- [ ] Usage of a GUI
- [ ] Usage of OpenGL or other 3D engine
- [ ] Useful usage of an external library (not Qt)
- [ ] Project that communicates (e.g., UART, BT) with hardware
- [ ] A nice extra that deserves grading





