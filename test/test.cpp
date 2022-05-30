#include "hist.h"
#include "svg.h"
#include <cassert>


void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative() {
    double min = -1000;
    double max = -1000;
    find_minmax({ -1, -2, -3 }, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_equal() {
    double min = -3000;
    double max = -1000;
    find_minmax({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_solo() {
    double min = -3000;
    double max = -1000;
    find_minmax({ 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_zero() {
    double min = -3000;
    double max = -1000;
    find_minmax({}, min, max);
    assert(min == -3000);
    assert(max == -1000);
}

void test_low()
{
    double bw = 31;
    bool pv = true;
    svg_blockwidth(bw, pv);
    assert(pv == true);
}

void test_correct()
{
    double bw = 15;
    bool pv = true;
    svg_blockwidth(bw, pv);
    assert(pv == false)
}

int main()
{
    test_positive();
    test_negative();
    test_equal();
    test_solo();
    test_zero();

}
