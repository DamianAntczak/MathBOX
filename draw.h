#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>
#include <QPainterPath>
#include <QPoint>
#include "wyrazenie.h"
#include "muParser/muParser.h"
#include "pochodna.h"
#include <string>

class Draw
{
    Wyrazenie w;
    //QGraphicsScene* scena;
    //mu::Parser* parser;
    int szerokosc;
    int wysokosc;
    int skala;
    double powiekszenie;
    void rysujPodzialke(QGraphicsScene* scena, double szerokosc, double wysokosc);

public:
    mu::Parser* parser;
    Draw();
    void setWyrazenie( std::string wyrazenie );
    void setScene(QGraphicsScene* scena);
    void setParser(mu::Parser* parser);
    void rysujFunkcje(QGraphicsScene* scena,Wyrazenie* w) throw(mu::Parser::exception_type);
    void rysujPochodna(QGraphicsScene* scena, Wyrazenie* w) throw(mu::Parser::exception_type);
    void setSkala(int skala);
    void setPowikszenie(double powiekszenie);

};

#endif // DRAW_H
