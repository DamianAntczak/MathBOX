#ifndef WYRAZENIE_H
#define WYRAZENIE_H

#include <string>
#include "muParser/muParser.h"
#include <QGraphicsScene>

class Wyrazenie
{   
protected:
    mu::Parser* parser;
    double wynik;
    bool czyFunkcja();
    double x;
public:
    std::string wyrazenie;
public:
    void setWyrazenie(std::string wyrazenie);
    std::string getWyrazenie();
    mu::Parser* getParser();
    double obliczWyrazenie();
    void addToken(std::string token);
    void setX(double x);

    Wyrazenie();
};

#endif // WYRAZENIE_H
