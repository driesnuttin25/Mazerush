#include "TitleScreen.h"
#include <QPainter>
#include <QApplication>  // Include QApplication for exit functionality

TitleScreen::TitleScreen(QWidget *parent) : QWidget(parent), background(":/assets/TitleScreen.png") {
    // Set predefined size for the window
    setFixedSize(800, 800);

    // Initialize the Start button
    startButton = new QPushButton("Start Game", this);
    connect(startButton, &QPushButton::clicked, this, &TitleScreen::on_startButton_clicked);

    // Initialize the Exit button
    exitButton = new QPushButton("Exit", this);
    connect(exitButton, &QPushButton::clicked, this, &TitleScreen::on_exitButton_clicked);

    // Layout
    layout = new QVBoxLayout(this);
    layout->addWidget(startButton);
    layout->addWidget(exitButton);  // Add the Exit button to the layout

    setLayout(layout);
}

void TitleScreen::paintEvent(QPaintEvent* /* event */) {
    QPainter painter(this);
    int x = (width() - background.width()) / 2;
    int y = (height() - background.height()) / 2;
    painter.drawPixmap(x, y, background);
}

void TitleScreen::on_startButton_clicked() {
    emit startGame(); // Signal to start the game
}

void TitleScreen::on_exitButton_clicked() {
    QApplication::quit(); // Close the application
}
