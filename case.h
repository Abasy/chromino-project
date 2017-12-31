#ifndef CASE_H
#define CASE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Case: public QGraphicsPixmapItem
{
public:
    //constructeur
    Case(QPixmap &pix, QGraphicsItem *parent=Q_NULLPTR);

    QPixmap getPixmap() const;
    void setPixmap(const QPixmap &value);

    int getIdCouleur() const;
    void setIdCouleur(int value);

private:
    QPixmap pixmap;
    int idCouleur;
};

/*
class Case: public QGraphicsPolygonItem
{
public:
    //cinstructeur
    Case(QGraphicsItem* parent=NULL);
    //void setPos(int x, int y);

};
*/
#endif // CASE_H
