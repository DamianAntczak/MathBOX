#include "pochodna.h"

Pochodna::Pochodna(std::string wyrazenie):wyrazenie(wyrazenie)
{
    this->x = 0;

    parser.SetExpr(this->wyrazenie);
    parser.DefineVar("x",&x);


    H = 0.005;
}

void Pochodna::setX(double x)
{
    this->x = x;

}

double Pochodna::oblicz(double &x)
{
    double fx1, fx2, fx3, fx4;

    setX(x - 2 * H);
    fx1 = parser.Eval();

    setX(x - H);
    fx2 = parser.Eval();

    setX(x + H);
    fx3 = parser.Eval();

    setX(x  + 2 * H);
    fx4 = parser.Eval();

    double pochodna  =  fx1 - 8 * fx2 + 8 * fx3 - fx4;
    pochodna /= 12 * H;

    return pochodna;
}
