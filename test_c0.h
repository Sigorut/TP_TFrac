#ifndef TEST_C0_H
#define TEST_C0_H

#include <QObject>
#include <QTest>
#include "tfrac.h"

class Test_c0 : public QObject
{
    Q_OBJECT
public:
    explicit Test_c0(QObject *parent = 0);
private slots:
    void test_constuctor_slot();
    void test_copy_constuctor_slot();
    void test_sum_fract_slot();
    void test_mult_fract_slot();
    void test_subrtact_fract_slot();
    void test_div_fract_slot();
    void test_pow2_fract_slot();
    void test_reverse_fract_slot();
    void test_minus_fract_slot();
    void test_equal_fract_slot();
    void test_more_fract_slot();
    void test_get_num();
    void test_get_den();
    void test_get_num_string();
    void test_get_den_string();
    void test_get_fract_string();
};

#endif // TEST_C0_H
