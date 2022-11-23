#include "test_c0.h"

Test_c0::Test_c0(QObject *parent) :
    QObject(parent)
{

}

void Test_c0::test_constuctor_slot()
{
    TFrac test(1,2);
    TFrac test1("1/3");
    QVERIFY_EXCEPTION_THROWN(TFrac(1,0), Exceptionn);
    QVERIFY_EXCEPTION_THROWN(TFrac("0/0"), Exceptionn);
    QVERIFY_EXCEPTION_THROWN(TFrac("0/0/1"), Exceptionn);
    QVERIFY(test == TFrac(1,2));
    QVERIFY(test1 == TFrac("1/3"));
}

void Test_c0::test_copy_constuctor_slot()
{
    TFrac first(1,1);
    TFrac scnd(first);
    QVERIFY(scnd == TFrac(1,1));
}

void Test_c0::test_sum_fract_slot()
{
    TFrac first(1,1);
    TFrac scnd(first);
    QVERIFY((first+scnd) == TFrac(2,1));
}

void Test_c0::test_mult_fract_slot()
{
    TFrac first(2,3);
    TFrac scnd(3,2);
    QVERIFY((first * scnd) == TFrac(1,1));
}

void Test_c0::test_subrtact_fract_slot()
{
    TFrac first(2,3);
    TFrac scnd(3,2);
    QVERIFY((first/scnd) == TFrac(2,3));
}

void Test_c0::test_div_fract_slot()
{

}

void Test_c0::test_pow2_fract_slot()
{

}

void Test_c0::test_reverse_fract_slot()
{

}

void Test_c0::test_minus_fract_slot()
{

}

void Test_c0::test_equal_fract_slot()
{

}

void Test_c0::test_more_fract_slot()
{

}

void Test_c0::test_get_num()
{

}

void Test_c0::test_get_den()
{

}

void Test_c0::test_get_num_string()
{

}

void Test_c0::test_get_den_string()
{

}

void Test_c0::test_get_fract_string()
{

}


