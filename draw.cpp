#include "draw.h"

Draw::Draw()
{
    powiekszenie = 0;
    szerokosc = 1000;
    wysokosc = 600;
    skala = 40 * (powiekszenie + 1);

}

void Draw::setScene(QGraphicsScene *scena)
{
    //this->scena = scena;
}

void Draw::setParser(mu::Parser *parser)
{
    this->parser = parser;
}

void Draw::rysujPodzialke(QGraphicsScene* scena, double szerokosc, double wysokosc)
{


    scena->addLine(-szerokosc / 2  ,wysokosc / 2 , szerokosc , wysokosc / 2 ,QPen(Qt::blue));
    for(int i = szerokosc/2; i < szerokosc ; i+= this->skala)
    {
        scena->addLine(i,wysokosc /2 ,i,wysokosc /2 - 10);

    }

    for(int i = szerokosc/2; i > 0 ; i -= skala)
    {
        scena->addLine(i,wysokosc / 2 , i,wysokosc /2 - 10);
    }

    for(int i = wysokosc / 2; i < wysokosc ; i += skala)
    {
        scena->addLine(szerokosc / 2,i , szerokosc / 2 + 10,i);
    }

    for(int i = wysokosc / 2; i > 0 ; i -= skala)
    {
        scena->addLine(szerokosc / 2,i , szerokosc / 2 + 10,i);
    }


    scena->addLine(szerokosc/2,0,szerokosc/2,wysokosc,QPen(Qt::blue));

}

void Draw::rysujFunkcje(QGraphicsScene *scena,Wyrazenie* w) throw(mu::Parser::exception_type)
{


    double x = 0;

    mu::Parser parser;
    parser.SetExpr(w->getWyrazenie());
    parser.DefineVar("x",&x);

    rysujPodzialke(scena,szerokosc,wysokosc);

    QPainterPath funkcja;
    funkcja.moveTo(-szerokosc/2,wysokosc/2);
    for(x = -szerokosc/2 ; x < szerokosc/2; x += 0.1)
    {
        QPoint punkt;
        punkt.setX(x * skala + szerokosc/2);
        punkt.setY(-parser.Eval() * skala + wysokosc/2);
        funkcja.lineTo(punkt);
    }


    scena->addPath(funkcja);
}

void Draw::rysujPochodna(QGraphicsScene *scena,Wyrazenie* w) throw(mu::Parser::exception_type)
{



    double x = 0;


    Pochodna pochodna(w->getWyrazenie());

    rysujPodzialke(scena,szerokosc,wysokosc);


    QPainterPath funkcja;
    funkcja.moveTo(-szerokosc/2,wysokosc/2);
    for(x = -szerokosc/2 ; x < szerokosc/2; x += 0.1)
    {
        QPoint punkt;
        punkt.setX(x * skala + szerokosc/2);
        punkt.setY(-pochodna.oblicz(x) * skala + wysokosc/2);
        funkcja.lineTo(punkt);
    }


    scena->addPath(funkcja);


}

void Draw::setSkala(int skala){
    this->skala = skala;
}

void Draw::setPowikszenie(double powiekszenie){
    this->powiekszenie = powiekszenie;
    skala = 40 * (powiekszenie + 1);
}

void Draw::setWyrazenie( std::string wyrazenie)
{
   // this->wyrazenie = wyrazenie;
    //parser->SetExpr(this->wyrazenie);
}
