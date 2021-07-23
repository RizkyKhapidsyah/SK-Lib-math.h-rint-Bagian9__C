#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <limits.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    fesetround(FE_TONEAREST);
    printf("rounding to nearest (halfway cases to even):\n" "rint(+2.3) = %+.1f  ", rint(2.3));
    printf("rint(+2.5) = %+.1f  ", rint(2.5));
    printf("rint(+3.5) = %+.1f\n", rint(3.5));
    printf("rint(-2.3) = %+.1f  ", rint(-2.3));
    printf("rint(-2.5) = %+.1f  ", rint(-2.5));
    printf("rint(-3.5) = %+.1f\n", rint(-3.5));

    fesetround(FE_DOWNWARD);
    printf("rounding down: \nrint(+2.3) = %+.1f  ", rint(2.3));
    printf("rint(+2.5) = %+.1f  ", rint(2.5));
    printf("rint(+3.5) = %+.1f\n", rint(3.5));
    printf("rint(-2.3) = %+.1f  ", rint(-2.3));
    printf("rint(-2.5) = %+.1f  ", rint(-2.5));
    printf("rint(-3.5) = %+.1f\n", rint(-3.5));
    printf("rounding down with lrint: \nlrint(+2.3) = %ld  ", lrint(2.3));
    printf("lrint(+2.5) = %ld  ", lrint(2.5));
    printf("lrint(+3.5) = %ld\n", lrint(3.5));
    printf("lrint(-2.3) = %ld  ", lrint(-2.3));
    printf("lrint(-2.5) = %ld  ", lrint(-2.5));
    printf("lrint(-3.5) = %ld\n", lrint(-3.5));

    printf("lrint(-0.0) = %ld\n", lrint(-0.0));
    printf("lrint(-Inf) = %ld\n", lrint(-INFINITY));

    // error handling
    feclearexcept(FE_ALL_EXCEPT);
    printf("rint(1.1) = %.1f\n", rint(1.1));

    if (fetestexcept(FE_INEXACT)) {
        puts("    FE_INEXACT was raised");
    }

    feclearexcept(FE_ALL_EXCEPT);
    printf("lrint(LONG_MIN-2048.0) = %ld\n", lrint(LONG_MIN - 2048.0));
    
    if (fetestexcept(FE_INVALID)) {
        puts("    FE_INVALID was raised");
    }

    _getch();
    return 0;
}