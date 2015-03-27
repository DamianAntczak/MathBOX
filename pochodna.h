#ifndef POCHODNA_H
#define POCHODNA_H

#include <string>
#include <QObject>
#include "muParser/muParser.h"

class Pochodna : QObject
{
    std::string wyrazenie;
    mu::Parser parser;
    double H;
    double x;

    public:
    Pochodna(std::string wyraz);
    double oblicz(double &x);
    void setX(double x);
};


#endif // POCHODNA_H
