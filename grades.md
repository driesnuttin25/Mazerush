# Grading System

### Grades
`[#########-------------------------------] 36%`
_19/50 points gathered_



## Basis
- [x] Useful and correct class - _Explain why_
```cpp
// Example: Chest class
class Chest : public GameItem {
    // ...
};

// The Chest class is a useful representation of a chest in the game, encapsulating its properties and behaviors, like being collected and interacting with the player.
```
- [x] Useful and correct abstraction - _Explain why_
```cpp
class GameItem : public QGraphicsPixmapItem {
    public:
        virtual void interact(Player* player) = 0;
};

// GameItem serves as an abstract base class, defining a common interface (interact) for game items like Chest and Hole. This promotes abstraction by allowing different items to be treated uniformly in the game logic.
```
- [x] Useful and correct encapsulation - _Explain why_
```cpp
class Player : public QObject, public QGraphicsRectItem {
    // ...
private:
    float stepSize;
    QSizeF playerSize;
    QTimer* moveTimer;
    QSet<int> pressedKeys;
    int coins = 0;
};

// The Player class encapsulates player properties and behaviors, such as movement and coin collection, while hiding internal details like stepSize and moveTimer from external access.
```
- [x] Useful and correct inheritance - _Explain why_
```cpp
class Chest : public GameItem {
    // ...
};

// The Chest class inherits from GameItem, demonstrating inheritance by extending the base class's functionality, such as implementing the interact method.
```
- [x] Useful and correct polymorphism - _Explain why_
```cpp
void interact(Player* player) override;

// Polymorphism is evident in the use of interact method. Different game items (Chest, Hole) have their unique implementations of this method, allowing dynamic behavior during gameplay.
```
- [x] Useful and correct object composition - _Explain why_
```cpp
class MazeView : public QGraphicsView {
    // ...
private:
    Player* player;
    const Maze& maze;
    // ...
};

// MazeView is composed of Player and Maze objects, demonstrating object composition by combining multiple objects to create a more complex entity.
```
- [x] Useful and correct base class
```cpp
class GameItem : public QGraphicsPixmapItem {
    public:
        virtual void interact(Player* player) = 0;
};

// The GameItem class is a useful and correct base class as it provides a foundational interface (interact) for derived classes (Chest, Hole) to implement. This base class establishes a common contract for all game items in your maze game, ensuring a consistent interaction mechanism.
```
- [x] Useful and correct abstract base class
```cpp
class GameItem : public QGraphicsPixmapItem {
    // ...
};

// GameItem is an abstract base class, as evidenced by its pure virtual function interact. It cannot be instantiated on its own and requires derived classes to provide concrete implementations of interact, thus enforcing a structure while allowing flexibility in derived classes.
```
- [x] Useful and correct virtual function
```cpp
// In GameItem
virtual void interact(Player* player) = 0;

// In Chest
void interact(Player* player) override; 

// The interact function in GameItem is a virtual function, correctly designed to be overridden by derived classes. This design allows different GameItem derivatives like Chest and Hole to have their own interaction logic with the player, showcasing polymorphism.
```
- [x] No mistake in object-oriented programming

## Additional - General
- [ ] Clean main
- [ ] No globals, but statics if needed
- [ ] Correct protections
- [ ] Maintainability by clean uniform code style and good function naming and/or comments everywhere
- [x] Separate header files
- [ ] One complete project that compiles and does not crash
- [ ] Fully working project
- [ ] Sufficient git commits (± weekly)
- [ ] Correct files on git
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
- [ ] Useful usage of "this"
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
