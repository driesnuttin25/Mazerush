#include "TitleScreen.h"
#include <QPainter>
#include <QApplication>  // Include QApplication for exit functionality

// Constructor for the TitleScreen class
TitleScreen::TitleScreen(QWidget *parent) : QWidget(parent), background(":/assets/TitleScreen.png") {
    // Set a fixed size for the title screen window
    setFixedSize(800, 800);

    // Initialize the Start button
    startButton = new QPushButton("Start Game", this);
    connect(startButton, &QPushButton::clicked, this, &TitleScreen::on_startButton_clicked);

    // Initialize the Exit button
    exitButton = new QPushButton("Exit", this);
    connect(exitButton, &QPushButton::clicked, this, &TitleScreen::on_exitButton_clicked);

    // Set up the layout with the buttons
    layout = new QVBoxLayout(this);
    layout->addWidget(startButton);  // Add the Start button to the layout
    layout->addWidget(exitButton);   // Add the Exit button to the layout
    setLayout(layout);               // Apply the layout to this widget
}

// Custom paint event for drawing the title screen background
void TitleScreen::paintEvent(QPaintEvent* /* event */) {
    QPainter painter(this);
    // Calculate position to center the background image
    int x = (width() - background.width()) / 2;
    int y = (height() - background.height()) / 2;
    painter.drawPixmap(x, y, background); // Draw the background image
}

// Slot for handling the Start button click event
void TitleScreen::on_startButton_clicked() {
    emit startGame(); // Emit a signal to start the game
}

// Slot for handling the Exit button click event
void TitleScreen::on_exitButton_clicked() {
    QApplication::quit(); // Quit the application
}
