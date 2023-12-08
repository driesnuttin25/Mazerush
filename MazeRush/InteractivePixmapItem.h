// InteractivePixmapItem.h
#ifndef INTERACTIVEPIXMAPITEM_H
#define INTERACTIVEPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class InteractivePixmapItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    using QGraphicsPixmapItem::QGraphicsPixmapItem; // Inherit constructors

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        emit clicked();
    }

signals:
    void clicked();
};

#endif // INTERACTIVEPIXMAPITEM_H
