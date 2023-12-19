# Grading System

### Grades
`[############################----------------------] 60%`
_30/50 points gathered_



## General
- [x] Clean main
- [x] No globals, but statics if needed
- [x] Correct protections
- [x] Maintainability by clean uniform code style and good function naming and/or comments everywhere
- [x] Separate header files
- [x] One complete project that compiles and does not crash
- [ ] Fully working project
- [x] Sufficient git commits (± weekly)
- [x] Correct files on git
- [x] Working build manual as readme on GitHub

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
- [x] Useful proven (dynamic) polymorphism
``` cpp
virtual void interact(Player* player) override = 0;

```
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
- [x] 2 useful unsigned chars or other better usage of memory efficient type
``` cpp
unsigned char coins = 0;

enum class Direction : unsigned char {
    None = 0,
    Up,
    Down,
    Left,
    Right
};

// unsigned char coins = 0; efficiently stores coin counts using minimal memory, while the enum class Direction : unsigned char efficiently represents player directions with just one byte, optimizing memory usage.

```
- [ ] At least 4 useful const references for variables
- [ ] At least 4 useful const references for functions
- [ ] At least 4 useful bool
- [x] Dynamic memory allocation (new)
``` cpp
maze = new Maze(mazeWidth, mazeHeight);
player = new Player();
view = new MazeView(maze, player, cellSize);

// Dynamic memory allocation is used for creating Player objects, allowing for flexible memory management and the creation of objects whose lifetime extends beyond the scope in which they are created.
```
- [x] Dynamic memory removing (delete)
``` cpp
    if (view) {
        view->scene()->clear();
        delete view;
        view = nullptr;
    }

    if (maze) {
        delete maze;
        maze = nullptr;
    }

    if (player) {
        delete player;
        player = nullptr;
    }

```
- [x] 2 useful (modern) call-by-references
``` cpp
QObject::connect(&titleScreen, &TitleScreen::startGame, [&]() {
    startGame(mazeWidth, mazeHeight, 50 /* cellSize */, currentLevel, view, maze, player);
});
-------------------------------------------------------------------------------------------
void startGame(int mazeWidth, int mazeHeight, int cellSize, int& currentLevel, MazeView*& view, Maze*& maze, Player*& player) {
    // ...
}

// any changes made to these parameters inside startGame will reflect in the original variables that were passed.
```
- [x] Useful string class usage
``` cpp
        std::string line;
        while (getline(file, line)) {
            if (line.empty() || line[0] == '#' || line[0] == '[') continue; // Skip comments and sections
            std::istringstream iss(line);
            std::string key;
            int value;
            if (getline(iss, key, '=') && iss >> value) {
                config[key] = value;
            }
        }
    }

// String usage for parsing data
``` 
- [x] Useful container class
``` cpp
std::vector<std::vector<int>> maze;

// The std::vector container is used in the Maze class to store the layout of the maze, showcasing effective use of dynamic arrays for flexible and efficient data storage.
```
- [x] Useful usage of nullptr
``` cpp

    if (this->scene() == nullptr) {
        qDebug() << "Error: Scene not initialized!";
        return;
    }

// Clean usage of a nullptr to make it clear that you are checking if the scene is set or not
```
- [x] Useful usage of (modern) file-I/O
``` cpp
        std::string line;
        while (getline(file, line)) {
            if (line.empty() || line[0] == '#' || line[0] == '[') continue; // Skip comments and sections
            std::istringstream iss(line);
            std::string key;
            int value;
            if (getline(iss, key, '=') && iss >> value) {
                config[key] = value;
            }
        }
    }

// config.ini

maze_width=19
maze_height=19
chests=5
holes=3
player_speed=20


// Usage of ini file for the settings of the game.
```
- [x] Useful exception handling
``` cpp
if (width <= 0 || height <= 0) {
        throw std::runtime_error("Invalid maze dimensions");
    }
// This ensures the Maze object isn't constructed with invalid dimensions
```
- [x] Useful usage of lambda function
``` cpp
QTimer::singleShot(500, [coin](){...});

// A lambda function is used in Chest::interact for delayed execution, demonstrating an effective use of inline, anonymous function objects for concise and localized functionality.
```
- [ ] Useful usage of threads

## Extension
- [x] Useful Qt class
``` cpp
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsPixmapItem>
```
- [x] Useful usage of signals/slots
``` cpp
signals:
    void chestCollected(int x, int y);
    void levelCompleted();
```
- [ ] Test-driven development (written test plan or unit tests)
- [ ] Solve bug ticket (with pull request or commit message issue link and issue branch)
- [x] Report a bug ticket on another project
- [x] Usage of a GUI
- [ ] Usage of OpenGL or other 3D engine
- [ ] Useful usage of an external library (not Qt)
- [ ] Project that communicates (e.g., UART, BT) with hardware
- [ ] A nice extra that deserves grading
