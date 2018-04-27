#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FIB_CONSTANT 5

void unittests(void);

unsigned fib(unsigned);

/* example: a + b * ROOT(5),
 * rationalPart -> a, irrationalPart -> b
 * We don't evaluate ROOT(5) during fibonacci
 * number calculation using fibonacci formula.
 * Thus we can avoid float/double type calculation*/
typedef struct
{
    int rationalPart;
    int irrationalPart;
} fibPolynomial;

fibPolynomial add(fibPolynomial, fibPolynomial);
fibPolynomial multi(fibPolynomial, fibPolynomial);
void showFibPolynomial(fibPolynomial);

int main(void)
{
    unittests();
    exit(0);
}

fibPolynomial add(fibPolynomial fpa, fibPolynomial fpb)
{
    fibPolynomial ret;
    ret.rationalPart = fpa.rationalPart + fpb.rationalPart;
    ret.irrationalPart = fpa.irrationalPart + fpb.irrationalPart;
    return ret;
}

fibPolynomial multi(fibPolynomial fpa, fibPolynomial fpb)
{
    fibPolynomial ret;
    ret.rationalPart = fpa.rationalPart * fpb.rationalPart + FIB_CONSTANT * fpa.irrationalPart * fpb.irrationalPart;
    ret.irrationalPart = fpa.rationalPart * fpb.irrationalPart + fpb.rationalPart * fpa.irrationalPart;
    return ret;
}

unsigned fib(unsigned n)
{
    fibPolynomial phi, phi_;
    phi.rationalPart = 1, phi.irrationalPart = 1;
    phi_.rationalPart = 1, phi_.irrationalPart = -1;
    fibPolynomial phiS = phi, phi_S = phi_;
    int divider = 2;
    fibPolynomial divisor;
    divisor.rationalPart = 1, divisor.irrationalPart = 0;

    while (n-- > 1)
    {
        divider *= 2;
        phiS = multi(phiS, phi);
        phi_S = multi(phi_S, phi_);
    }

    return (phiS.irrationalPart - phi_S.irrationalPart) / divider;
}

void showFibPolynomial(fibPolynomial fp)
{
    printf("(%d) + (%d)(ROOT5)\n", fp.rationalPart, fp.irrationalPart);
}

void unittests(void)
{
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(7) == 13);
    assert(fib(8) == 21);
    assert(fib(9) == 34);
    assert(fib(10) == 55);

    printf("All unittests passed!\n");
}
