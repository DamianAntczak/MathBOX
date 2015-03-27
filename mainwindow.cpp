#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    wyrazenie = new Wyrazenie();
    draw = new Draw();


    layout_macierz = new QGridLayout(ui->tab_2);
    layout_macierz->setMargin(600 / 4);



    int wiersze = ui->sIloscWierszy->value();
    int kolumny = ui->sIloscWierszy->value();

    createButtonMatrix(wiersze, kolumny , polaMatrix, layout_macierz);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing); //Ustawienie antialiasingu dla obiektugraphicsView
    ui->graphicsView->setSceneRect(0,0,1000, 600);


}

void MainWindow::createButtonMatrix(int wiersze, int kolumny, std::vector<std::vector<QLineEdit*>> &polaMatrix, QGridLayout* layout){

    polaMatrix.resize(wiersze);

    for(int i = 0 ; i < polaMatrix.size() ; i++)
    {
        polaMatrix[i].resize(kolumny);
    }

    for(int i = 0 ; i < wiersze  ; i++)
    {
        for(int j = 0 ; j < kolumny ; j++)
        {
           polaMatrix[i][j] = new QLineEdit();
           polaMatrix[i][j]->setText("0");
        }
    }

    for(int i = 0 ; i < wiersze ; i++)
    {
        for(int j = 0 ; j < kolumny ; j++)
        {
           layout->addWidget(polaMatrix[i][j],i,j);
        }
    }

}

void MainWindow::deleteButtonMatrix( std::vector<std::vector<QLineEdit*>> &polaMatrix)
{

    for(int i = 0 ; i < polaMatrix.size() ; i++)
    {
        for(int j = 0 ; j < polaMatrix[i].size() ; j++)
        {
           delete polaMatrix[i][j];

        }
    }



}


MainWindow::~MainWindow()
{
    deleteButtonMatrix(polaMatrix);
    delete ui;
    delete wyrazenie;
    delete draw;
    delete layout_macierz;
    delete matrixA;
    delete matrixB;
}

void MainWindow::updateLineEdit()
{
    ui->lineEdit->setText(QString::fromStdString(wyrazenie->getWyrazenie()));
}

void MainWindow::on_b1_clicked()
{
   wyrazenie->addToken("1");
   this->updateLineEdit();

}

void MainWindow::on_b2_clicked()
{
    wyrazenie->addToken("2");
    this->updateLineEdit();
}

void MainWindow::on_p3_clicked()
{
    wyrazenie->addToken("3");
    this->updateLineEdit();
}

void MainWindow::on_p4_clicked()
{
    wyrazenie->addToken("4");
    this->updateLineEdit();
}

void MainWindow::on_p5_clicked()
{
    wyrazenie->addToken("5");
    this->updateLineEdit();
}

void MainWindow::on_p6_clicked()
{
    wyrazenie->addToken("6");
    this->updateLineEdit();
}

void MainWindow::on_p7_clicked()
{
    wyrazenie->addToken("7");
    this->updateLineEdit();
}

void MainWindow::on_p8_clicked()
{
    wyrazenie->addToken("8");
    this->updateLineEdit();
}

void MainWindow::on_p9_clicked()
{
    wyrazenie->addToken("9");
    this->updateLineEdit();
}

void MainWindow::on_p0_clicked()
{
    wyrazenie->addToken("0");
    this->updateLineEdit();
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_pPlus_clicked()
{
    wyrazenie->addToken(" + ");
    this->updateLineEdit();
}

void MainWindow::on_pMinus_clicked()
{
    wyrazenie->addToken(" - ");
    this->updateLineEdit();
}

void MainWindow::on_pMult_clicked()
{
    wyrazenie->addToken(" * ");
    this->updateLineEdit();
}

void MainWindow::on_pDiv_clicked()
{
    wyrazenie->addToken(" / ");
    this->updateLineEdit();
}

void MainWindow::on_pEqual_clicked()
{
    try{
        QString wynik = QString::number(wyrazenie->obliczWyrazenie()); //wyrazenie->obliczWyrazenie()
        ui->lineEdit_wynik->setText(wynik);
    }catch(mu::Parser::exception_type &e){
        QMessageBox::information(this,tr("Blad!!!"),QString::fromStdString(e.GetMsg()));
    }
}

void MainWindow::on_pX_clicked()
{
    wyrazenie->addToken(" x ");
    this->updateLineEdit();
}

void MainWindow::on_pRysuj_clicked()
{
    try{
        QGraphicsScene* scena = new QGraphicsScene();
        draw->setScene(scena);
        ui->graphicsView->setScene(scena);
        draw->rysujFunkcje(scena,wyrazenie);
        ui->graphicsView->show();
    }catch(mu::Parser::exception_type &e){
        QMessageBox::information(this,tr("Blad!!!"),QString::fromStdString(e.GetMsg()));
    }
}

void MainWindow::on_pPochodna_clicked()
{
    try{
        QGraphicsScene* scena = new QGraphicsScene();
    //ui->graphicsView->setSceneRect(0,0,500,500);
        draw->setScene(scena);
        ui->graphicsView->setScene(scena);
        draw->rysujPochodna(scena,wyrazenie);
        ui->graphicsView->show();
    }catch(mu::Parser::exception_type &e){
        QMessageBox::information(this,tr("Blad!!!"),QString::fromStdString(e.GetMsg()));
    }
}

void MainWindow::on_pSin_clicked()
{
    wyrazenie->addToken("sin(");
    this->updateLineEdit();

}

void MainWindow::on_pCos_clicked()
{

    wyrazenie->addToken("cos(");
    this->updateLineEdit();
}

void MainWindow::on_pOpenBracket_clicked()
{
    wyrazenie->addToken("(");
    this->updateLineEdit();
}

void MainWindow::on_pEndBracket_clicked()
{
    wyrazenie->addToken(")");
    this->updateLineEdit();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
    wyrazenie->setWyrazenie("");
    this->updateLineEdit();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(wyrazenie->getWyrazenie().size() > 0){
        std::string s = wyrazenie->getWyrazenie();
        s.assign(s.begin(),s.end() - 1);
        wyrazenie->setWyrazenie(s);
        this->updateLineEdit();
    }
}



void MainWindow::getMatrix(std::vector<std::vector<QLineEdit*>> &polaMatrix,Matrix* &macierz)
{
    int wiersze = ui->sIloscWierszy->value();
    int kolumny = ui->sIloscKolumn->value();

    macierz = new Matrix(wiersze, kolumny);



    for(int i = 0 ; i < wiersze ; i++)
    {
        for(int j = 0 ; j < kolumny ; j++)
        {
            double wartosc = polaMatrix[i][j]->text().toDouble();
            macierz->setKomorka(i,j,wartosc);
        }
    }



}

void MainWindow::displeyMatrix(Matrix *macierz){

    if(true){

        for(int i = 0 ; i < ui->sIloscWierszy->text().toInt() ; i++)
        {
            for(int j = 0 ; j < ui->sIloscKolumn->text().toInt() ; j++)
            {
               polaMatrix[i][j]->setText(QString::number( macierz->getKomorka(i,j)));    //macierz->getKomorka(i,j)));
            }
        }

    }

}


void MainWindow::on_sIloscWierszy_valueChanged(int arg1)
{
    deleteButtonMatrix(polaMatrix);
    createButtonMatrix(arg1, ui->sIloscKolumn->value(), polaMatrix, layout_macierz);
}

void MainWindow::on_sIloscKolumn_valueChanged(int arg1)
{
    deleteButtonMatrix(polaMatrix);
    createButtonMatrix(ui->sIloscWierszy->value() , arg1, polaMatrix, layout_macierz);
}

void MainWindow::on_pMatrixA_clicked()
{

    getMatrix(this->polaMatrix, matrixA );
    ui->lMatrixA->setText("zapisana");
}

void MainWindow::on_pMatrixB_clicked()
{

    getMatrix(this->polaMatrix, matrixB);
    ui->lMatrixB->setText("zapisana");

}

void MainWindow::on_pMatrixAdd_clicked()
{
   // Matrix nowa(ui->sIloscWierszy->text().toInt(),ui->sIloscKolumn->text().toInt());
    matrixA->add(*matrixB);
    displeyMatrix(matrixA);
    //delete nowaMacierz;
}



void MainWindow::on_pushButton_3_clicked()
{

    for(int i = 0 ; i < ui->sIloscWierszy->text().toInt() ; i++)
    {
        for(int j = 0 ; j < ui->sIloscKolumn->text().toInt() ; j++)
        {
           polaMatrix[i][j]->setText("0");    //macierz->getKomorka(i,j)));
        }
    }

}

void MainWindow::on_pMatrixSub_clicked()
{
    matrixA->sub(*matrixB);
    displeyMatrix(matrixA);
}

void MainWindow::on_pPower_clicked()
{
    wyrazenie->addToken("^");
    this->updateLineEdit();
}

void MainWindow::on_lineEdit_editingFinished()
{
        wyrazenie->setWyrazenie(ui->lineEdit->text().toStdString());
}

void MainWindow::on_pTrans_clicked()
{
    int wiersze = ui->sIloscWierszy->value();
    int kolumny = ui->sIloscKolumn->value();

         Matrix* nowa = new Matrix(wiersze,kolumny);


        getMatrix(polaMatrix,nowa);

        ui->sIloscWierszy->setValue(kolumny);
        ui->sIloscKolumn->setValue(wiersze);

        displeyMatrix(nowa->transpozycja());

        delete nowa;

}




void MainWindow::on_sPowiekszenie_valueChanged(double arg1)
{
    draw->setPowikszenie(arg1);
}

void MainWindow::on_pMatrixMul_clicked()
{

    matrixA->mul(*matrixB);
    displeyMatrix(matrixA->mul(*matrixB));


}

void MainWindow::on_pTg_clicked()
{
    wyrazenie->addToken("tan(");
    this->updateLineEdit();
}


void MainWindow::on_pLog_clicked()
{
    wyrazenie->addToken("log(");
    this->updateLineEdit();

}

void MainWindow::on_pLn_clicked()
{
    wyrazenie->addToken("ln(");
    this->updateLineEdit();
}

void MainWindow::on_pAsin_clicked()
{
    wyrazenie->addToken("asin(");
    this->updateLineEdit();
}

void MainWindow::on_pAcos_clicked()
{
    wyrazenie->addToken("acos(");
    this->updateLineEdit();
}

void MainWindow::on_pAbs_clicked()
{
    wyrazenie->addToken("abs(");
    this->updateLineEdit();
}

void MainWindow::on_pTanh_clicked()
{
    wyrazenie->addToken("tanh(");
    this->updateLineEdit();
}

void MainWindow::on_pAsinh_clicked()
{
    wyrazenie->addToken("asinh(");
    this->updateLineEdit();
}

void MainWindow::on_pAcosh_clicked()
{
    wyrazenie->addToken("acosh(");
    this->updateLineEdit();
}

void MainWindow::on_pExp_clicked()
{
    wyrazenie->addToken("exp(");
    this->updateLineEdit();
}
