#include "matrix.h"

//using namespaces::std;

Matrix::Matrix()
{

}

Matrix::Matrix(int wiersze, int kolumny)
{
    this->wiersze = wiersze;
    this->kolumny = kolumny;

   tablica.resize(wiersze);

   for(int i = 0 ; i < tablica.size() ; i++)
   {
       tablica[i].resize(kolumny);
   }


}

Matrix::Matrix(Matrix &other){

    tablica = other.tablica;
    wiersze = other.wiersze;
    kolumny = other.kolumny;
}

void Matrix::setKomorka(int wiersz, int kolumna, double wartosc)
{
    tablica[wiersz][kolumna] = wartosc;

}

int Matrix::getWiersz()
{
    return wiersze;
}

int Matrix::getKolumna()
{
    return kolumny;
}

double Matrix::getKomorka(int wiersz, int kolumna)
{
    return tablica[wiersz][kolumna];
}

Matrix& Matrix::operator =(Matrix& other){
    if(this == &other)
    return *this;
}

Matrix* &Matrix::operator+(Matrix* &other)
{
    Matrix* nowa = new Matrix(this->getWiersz(),this->getKolumna());

    for(int i = 0 ; i < this->getWiersz() ;i++){
        for(int j = 0 ; j < this->getKolumna() ; j++){
            double wartosc = tablica[i][j] + other->tablica[i][j];
            nowa->setKomorka(i, j,wartosc);
        }
    }

    return nowa;

}

void Matrix::add(Matrix &other)
{
    for(int i = 0 ; i < this->getWiersz() ;i++){
        for(int j = 0 ; j < this->getKolumna() ; j++){
            tablica[i][j] += other.tablica[i][j];
        }
    }
}


void Matrix::sub(Matrix &other)
{
    for(int i = 0 ; i < this->getWiersz() ;i++){
        for(int j = 0 ; j < this->getKolumna() ; j++){
            tablica[i][j] -= other.tablica[i][j];
        }
    }
}

Matrix* &Matrix::transpozycja()
{
    Matrix* nowa = new Matrix(kolumny,wiersze);

    for(int i = 0 ; i < wiersze ;i++){
        for(int j = 0 ; j < kolumny ; j++){
            nowa->tablica[i][j] = tablica[j][i];
        }
    }
    return nowa;

    delete nowa;
}

Matrix* &Matrix::mul(Matrix &other)
{
    Matrix* nowa = new Matrix(kolumny, other.wiersze);

    if(wiersze == other.kolumny && kolumny == other.wiersze){

        double suma = 0;

        for(int i = 0 ; i < wiersze ; i++){
            for(int j = 0; j < kolumny; j++){
                suma = 0;
                for(int k = 0 ; k < wiersze; k++){

                    suma += this->tablica[i][k] * other.tablica[k][j];
                    nowa->tablica[i][j] = suma;
                }

            }
        }

        return nowa;

    }

    delete nowa;
}
