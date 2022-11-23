#include <QCoreApplication>
#include <QDebug>
#include "tfrac.h"
#include "test_c0.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TFrac test(4,2);
    TFrac test1("0/1");
    QTest::qExec(new Test_c0, argc, argv);

    test = test1;
    test1.inverse().printFrac();
    qDebug() << test.u_num<< " " << test.d_num;
    qDebug() << test1.get_down();
    return a.exec();
}
