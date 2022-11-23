#ifndef TFRAC_H
#define TFRAC_H
#include<qmath.h>
#include<QString>
#include<QStringList>
#include<QDebug>
class TFrac
{
public:
    TFrac();
    int u_num;
    int d_num;
    TFrac(int u, int d);
    TFrac(const TFrac & second);
    TFrac(QString frac);
private:
    TFrac reduct(TFrac f);
    void reduct(int* u, int* d);

public:
    void printFrac();
    TFrac pow2();
    TFrac inverse();
    QString cget_up();
    QString cget_frac();
    QString cget_down();
    double get_up();
    double get_down();
    bool operator<(TFrac scnd);
    bool operator>(TFrac scnd);
    bool operator==(TFrac scnd);
    TFrac operator+(TFrac scnd);
    TFrac operator=(TFrac const &scnd);
    TFrac operator-(TFrac scnd);
    TFrac operator*(TFrac scnd);
    TFrac operator/(TFrac scnd);
};
class Exceptionn
{
public:
    Exceptionn(QString msg){
        qDebug() << msg;
    }
};
#endif // TFRAC_H
