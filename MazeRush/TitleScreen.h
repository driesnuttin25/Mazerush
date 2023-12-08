#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>  // Include QPixmap

class TitleScreen : public QWidget {
    Q_OBJECT

public:
    explicit TitleScreen(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;  // Declare the paintEvent method

signals:
    void startGame();

private slots:
    void on_startButton_clicked();
    void on_exitButton_clicked();  // Slot for the Exit button

private:
    QPushButton* startButton;
    QPushButton* exitButton;  // Exit button
    QVBoxLayout* layout;
    QPixmap background;  // Declare the QPixmap for the background
};

#endif // TITLESCREEN_H
