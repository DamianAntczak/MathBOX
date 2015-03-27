#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
private:
    int wiersze, kolumny;
    std::vector<std::vector<double>> tablica;
public:
    Matrix();
    Matrix(int wiersze, int kolumny);
    Matrix(Matrix& other);
    void setKomorka(int wiersz, int kolumna, double wartosc);
    int getWiersz();
    int getKolumna();
    double getKomorka(int wiersz, int kolumna);


    Matrix& operator=(Matrix& other);
    Matrix* &operator+(Matrix* &other);
    Matrix& operator-(Matrix& other);

    Matrix *&transpozycja();
    Matrix *&mul(Matrix& other);

    void add(Matrix& other);
    void sub(Matrix& other);



};

#endif // MATRIX_H
