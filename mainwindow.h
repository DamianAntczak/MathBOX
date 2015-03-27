#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "wyrazenie.h"
#include "draw.h"
#include <string>
#include <QString>
#include <QLineEdit>
#include <QGridLayout>
#include "matrix.h"
#include <QMessageBox>
#include <QTransform>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateLineEdit();

    void createButtonMatrix(int wiersze, int kolumny, std::vector<std::vector<QLineEdit *> > &polaMatrix, QGridLayout *layout);
    void getMatrix(std::vector<std::vector<QLineEdit *> > &polaMatrix, Matrix *&macierz);
    void displeyMatrix(Matrix* macierz);
    void deleteButtonMatrix(std::vector<std::vector<QLineEdit *> > &polaMatrix);

private slots:
    void on_b1_clicked();

    void on_b2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

    void on_p9_clicked();

    void on_p0_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pPlus_clicked();

    void on_pMinus_clicked();

    void on_pMult_clicked();

    void on_pDiv_clicked();

    void on_pEqual_clicked();

    void on_pX_clicked();

    void on_pRysuj_clicked();

    void on_pSin_clicked();

    void on_pCos_clicked();

    void on_pOpenBracket_clicked();

    void on_pEndBracket_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sIloscWierszy_valueChanged(int arg1);

    void on_sIloscKolumn_valueChanged(int arg1);

    void on_pMatrixA_clicked();

    void on_pMatrixB_clicked();

    void on_pMatrixAdd_clicked();

    void on_pPochodna_clicked();

    void on_pushButton_3_clicked();

    void on_pMatrixSub_clicked();

    void on_pPower_clicked();

    void on_lineEdit_editingFinished();

    void on_pTrans_clicked();


    void on_sPowiekszenie_valueChanged(double arg1);

    void on_pMatrixMul_clicked();

    void on_pTg_clicked();


    void on_pLog_clicked();

    void on_pLn_clicked();

    void on_pAsin_clicked();

    void on_pAcos_clicked();

    void on_pAbs_clicked();

    void on_pTanh_clicked();

    void on_pAsinh_clicked();

    void on_pAcosh_clicked();

    void on_pExp_clicked();

private:
    Ui::MainWindow *ui;
    Wyrazenie* wyrazenie;
    Draw* draw;
    std::vector<std::vector<QLineEdit*>> polaMatrix;
    QGridLayout* layout_macierz;
    Matrix* matrixA;
    Matrix* matrixB;
    bool czyMatrixA;
   // QLineEdit* lineEdit;
};

#endif // MAINWINDOW_H
