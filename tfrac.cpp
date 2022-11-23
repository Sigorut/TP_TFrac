#include "tfrac.h"

TFrac::TFrac() { }

TFrac::TFrac(int u, int d)
{
    u_num = u;
    d_num = d;
    if(d_num == 0) throw Exceptionn("Null on down");
    reduct(&u_num, &d_num);
}

TFrac::TFrac(const TFrac &second)
{
    u_num = second.u_num;
    d_num = second.d_num;
}

TFrac::TFrac(QString frac)
{
    if(!frac.contains("/")) throw Exceptionn("Not correct frac");
    for(int i = 0, count = 0; i < frac.size(); i++){
        if(frac[i] == '/') count++;
        if(count > 1) throw Exceptionn("Not correct frac");
        if(frac[i] < 47 || frac[i] > 57) throw Exceptionn("Not correct frac");
    }
    QStringList u_d_num = frac.split("/");
    u_num = u_d_num[0].toInt();
    d_num = u_d_num[1].toInt();
    if(d_num == 0) throw Exceptionn("Null on down");
    reduct(&u_num, &d_num);
}

TFrac TFrac::pow2()
{
    TFrac answer(u_num, d_num);
    return answer * answer;
}

void TFrac::reduct(int *u, int *d)
{
    int a, b;
    if (*d < 0 && *u < 0) {
        *d *= -1;
        *u *= -1;
    }
    if (*d < 0) {
        *d *= -1;
        *u *= -1;
    }
    a = qAbs(*u);
    b = qAbs(*d);
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    *u /= (a + b);
    *d /= (a + b);
}

void TFrac::printFrac()
{
    qDebug() << u_num << "/" << d_num;
}
TFrac TFrac::reduct(TFrac f)
{
    int a, b;
    if (f.d_num < 0 && f.u_num < 0) {
        f.d_num *= -1;
        f.u_num *= -1;
    }
    if (f.d_num < 0) {
        f.d_num *= -1;
        f.u_num *= -1;
    }
    a = qAbs(f.u_num);
    b = qAbs(f.d_num);
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    f.u_num /= (a + b);
    f.d_num /= (a + b);
    return f;
}

TFrac TFrac::operator+(TFrac scnd)
{
    TFrac answer;
    answer.u_num = this->u_num * scnd.d_num + scnd.u_num * this->d_num;
    answer.d_num = this->d_num * scnd.d_num;
    return reduct(answer);
}

TFrac TFrac::operator=(const TFrac &scnd)
{
    return TFrac(scnd.u_num, scnd.d_num);
}


TFrac TFrac::operator-(TFrac scnd)
{
    TFrac answer;
    answer.u_num = this->u_num * scnd.d_num - scnd.u_num * this->d_num;
    answer.d_num = this->d_num * scnd.d_num;
    return reduct(answer);
}

TFrac TFrac::operator*(TFrac scnd)
{
    TFrac answer;
    answer.u_num = this->u_num * scnd.u_num;
    answer.d_num = this->d_num * scnd.d_num;
    return reduct(answer);
}

TFrac TFrac::operator/(TFrac scnd)
{
    TFrac answer;
    answer.u_num = this->u_num * scnd.d_num;
    answer.d_num = this->d_num * scnd.u_num;
    return reduct(answer);
}

bool TFrac::operator<(TFrac scnd)
{
    this->u_num = scnd.d_num * this->u_num;
    scnd.u_num = this->d_num * scnd.u_num;
    if (this->u_num < scnd.u_num) {
        return true;
    } else {
        return false;
    }
}

bool TFrac::operator>(TFrac scnd)
{
    this->u_num = scnd.d_num * this->u_num;
    scnd.u_num = this->d_num * scnd.u_num;
    if (this->u_num > scnd.u_num) {
        return true;
    } else {
        return false;
    }
}

TFrac TFrac::inverse()
{
    TFrac answer(u_num, d_num);
    if(u_num != 0) qSwap(answer.u_num, answer.d_num);
    return answer;
}

QString TFrac::cget_up()
{
    return QString::number(u_num);
}

QString TFrac::cget_frac()
{
    return QString::number(u_num) + "/" + QString::number(d_num);
}

QString TFrac::cget_down()
{
    return QString::number(d_num);
}

double TFrac::get_up()
{
    return u_num;
}

double TFrac::get_down()
{
    return d_num;
}

bool TFrac::operator==(TFrac scnd)
{
    this->u_num = scnd.d_num * this->u_num;
    scnd.u_num = this->d_num * scnd.u_num;
    if (this->u_num == scnd.u_num) {
        return true;
    } else {
        return false;
    }
}
