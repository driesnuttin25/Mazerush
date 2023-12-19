// TitleScreen.h
#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>  // Include QPixmap for graphical features

// TitleScreen class: Manages the title screen of the game
class TitleScreen : public QWidget {
    Q_OBJECT

public:
    explicit TitleScreen(QWidget *parent = nullptr); // Constructor for TitleScreen

protected:
    void paintEvent(QPaintEvent* event) override;  // Handles custom painting of the widget

signals:
    void startGame(); // Signal emitted to start the game

private slots:
    void on_startButton_clicked(); // Slot for handling start button click
    void on_exitButton_clicked();  // Slot for handling exit button click

private:
    QPushButton* startButton; // Start button
    QPushButton* exitButton;  // Exit button
    QVBoxLayout* layout;      // Layout for arranging widgets
    QPixmap background;       // Background image for the title screen
};

#endif // TITLESCREEN_H
