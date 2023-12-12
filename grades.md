# Grading System

### Grades
`[#######---------------------------------] 28%`
_14/50 points gathered_



## General
- [ ] Clean main
- [ ] No globals, but statics if needed
- [ ] Correct protections
- [ ] Maintainability by clean uniform code style and good function naming and/or comments everywhere
- [x] Separate header files
- [x] One complete project that compiles and does not crash
- [x] Fully working project
- [x] Sufficient git commits (± weekly)
- [x] Correct files on git
- [ ] Working build manual as readme on GitHub

## Object-Oriented Programming (OOP)
- [ ] At least 2 default constructors
- [x] At least 2 parameterized constructors
```cpp
Chest::Chest(Player* player, MazeView* mazeView, int x, int y, int cellSize) {...}
Hole::Hole(int x, int y, int cellSize) {...}

// The Chest and Hole classes both have parameterized constructors, allowing for the initialization of their properties based on provided arguments.
```
- [ ] At least 2 copy constructors
- [ ] At least 2 destructors
- [x] Member initialization in constructors
```cpp
Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent), stepSize(3), playerSize(20, 20) {...}

//The Player constructor uses member initialization to set up step size, player size, and key event handling, ensuring efficient object initialization.
```
- [ ] Constructor forwarding
- [ ] Useful proven (dynamic) polymorphism
- [x] Useful usage of "this"
``` cpp
QGraphicsScene* newScene = new QGraphicsScene(this);
    this->setScene(newScene);
    this->mazeHeight = maze->height;

// this is used as the parent for the new QGraphicsScene object, indicating ownership and ensuring proper object lifetime management. 
```
- [x] Useful member function
```cpp
void Player::move() {...}

//The move function in Player is a key member function controlling player movement based on key presses.
```
- [ ] Default values in function definition
- [x] Useful member variable
```cpp
private:
    int coins = 0;

// The coins member variable in Player is essential for tracking the player's coin collection throughout the game. 
```
- [x] Useful getters and setters for member variables
```cpp
int Player::getCoins() const {...}

void Player::addCoin() {
    coins++;
    qDebug() << "Coins:" << coins;

}

//  The getCoins method in Player is a getter that allows other classes to safely access the player's coin count.
```
- [ ] Correct usage of inline function
- [ ] Useful template function or class
- [ ] Useful friend function or class

## C++
- [ ] Everything in one or more self-made namespace(s)
- [ ] 2 useful unsigned chars or other better usage of memory efficient type
- [ ] At least 4 useful const references for variables
- [ ] At least 4 useful const references for functions
- [ ] At least 4 useful bool
- [x] Dynamic memory allocation (new)
``` cpp
Player* player = new Player();

// Dynamic memory allocation is used for creating Player objects, allowing for flexible memory management and the creation of objects whose lifetime extends beyond the scope in which they are created.
```
- [ ] Dynamic memory removing (delete)
- [ ] 2 useful (modern) call-by-references
- [ ] Useful string class usage
- [x] Useful container class
``` cpp
std::vector<std::vector<int>> maze;

// The std::vector container is used in the Maze class to store the layout of the maze, showcasing effective use of dynamic arrays for flexible and efficient data storage.
```
- [ ] Useful usage of nullptr
- [ ] Useful usage of (modern) file-I/O
- [ ] Useful exception handling
- [x] Useful usage of lambda function
``` cpp
QTimer::singleShot(500, [coin](){...});

// A lambda function is used in Chest::interact for delayed execution, demonstrating an effective use of inline, anonymous function objects for concise and localized functionality.
```
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
