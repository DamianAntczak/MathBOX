#include "wyrazenie.h"

Wyrazenie::Wyrazenie()
{
    parser = new mu::Parser();
    //this->parser.DefineVar("x",&x);
}

void Wyrazenie::setWyrazenie(std::string wyrazenie)
{
    this->wyrazenie = wyrazenie;
}

std::string Wyrazenie::getWyrazenie()
{
    return this->wyrazenie;
}

double Wyrazenie::obliczWyrazenie()
{

    parser->SetExpr(wyrazenie);

    return parser->Eval();

}

void Wyrazenie::addToken(std::string token)
{
    this->wyrazenie += token;
}

void Wyrazenie::setX(double x)
{
    this->x = x;
}

mu::Parser* Wyrazenie::getParser()
{
    return parser;
}
