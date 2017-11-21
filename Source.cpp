/***************************************************
 * 
 * CS301 Project
 * Hanbo Ye
 * 11/21/2017
 * The program locates roots
 *
 ***************************************************/

#include <iostream>
#include <cmath>

using namespace std;

const int N = 100;
const double E = 0.0001;
const double R = 125;

/*
double f(double x) {
    return 2 * x * x * x - 11.7 * x * x + 17.7 * x - 5;
}

double df(double x) {
    return 6 * x * x - 23.4 * x + 17.7;
}
 */

double f(double x) {
    return x + 10 - x * cosh(50 / x);
}

double df(double x) {
    return 1 + ((50 * sinh(50 / x) / x) - cosh(50 / x));
}

void bisection(double a, double b) {

    double c, ea, er, temp;

    cout << "\nbisection running...\n";

    if (f(a) * f(b) > 0) {
        cout << "\nterminated\n";
        return;
    }

    for (int i = 0; i < N; i++) {

        c = (a + b) / 2;
        //cout << "x = " << c << "\t";

        er = fabs((c - temp) / c);
        cout << "n = " << i + 1;
        cout << " Er: " << 100 * er << "% ";
        ea = fabs((R - c) / R);
        cout << " Ea: " << 100 * ea << "% ";

        if (f(c) == 0) {
            cout << "\nterminated\n";
            return;
        }
        if (er < E) {
            cout << "\nterminated\n";
            return;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        temp = c;
    }
}

void falsePosition(double a, double b) {

    double c, ea, er, temp;

    cout << "\nfalse position running...\n";

    if (f(a) * f(b) > 0) {
        cout << "\nterminated\n";
        return;
    }

    for (int i = 0; i < N; i++) {

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        //cout << "x = " << c << "\t";

        er = fabs((c - temp) / c);
        cout << "n = " << i + 1;
        cout << " Er: " << 100 * er << "% ";
        ea = fabs((R - c) / R);
        cout << " Ea: " << 100 * ea << "% ";

        if (f(c) == 0) {
            cout << "\nterminated\n";
            return;
        }
        if (er < E) {
            cout << "\nterminated\n";
            return;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        temp = c;
    }
}

void newton(double x) {

    double d, ea, er, temp;

    cout << "\nnewton running...\n";

    for (int i = 0; i < N; i++) {

        if (df(x) < E) {
            cout << "\nterminated\n";
            return;
        }

        temp = x;
        d = f(x) / df(x);
        x = x - d;
        //cout << "x = " << x << "\t";

        er = fabs((x - temp) / x);
        cout << "n = " << i + 1;
        cout << " Er: " << 100 * er << "% ";
        ea = fabs((R - x) / R);
        cout << " Ea: " << 100 * ea << "% ";

        if (er < E) {
            cout << "\nterminated\n";
            return;
        }
        if (fabs(d) < E) {
            cout << "\nterminated\n";
            return;
        }
    }
}

void secant(double x1, double x2) {

    double d, ea, er, temp;

    cout << "\nsecant running...\n";

    for (int i = 0; i < N; i++) {

        d = (f(x2) - f(x1)) / (x2 - x1);

        if ((x2 - x1) < E) {
            cout << "\nterminated\n";
            return;
        }
        if (fabs(d) < E) {
            cout << "\nterminated\n";
            return;
        }

        temp = x1;
        d = f(x1) / d;
        x1 = x1 - d;
        //cout << "x = " << x1 << "\t";

        er = fabs((x1 - temp) / x1);
        cout << "n = " << i + 1;
        cout << " Er: " << 100 * er << "% ";
        ea = fabs((R - x1) / R);
        cout << " Ea: " << 100 * ea << "% ";

        if (er < E) {
            cout << "\nterminated\n";
            return;
        }
    }
}

void modifiedSecant(double x) {

    double d, ea, er, temp;

    cout << "\nmodified secant running...\n";

    for (int i = 0; i < N; i++) {

        d = (f(x + E * x) - f(x)) / (E * x);

        if (fabs(d) < E) {
            cout << "\nterminated\n";
            return;
        }

        temp = x;
        d = f(x) / d;
        x = x - d;
        //cout << "x = " << x << "\t";

        er = fabs((x - temp) / x);
        cout << "n = " << i + 1;
        cout << " Er: " << 100 * er << "% ";
        ea = fabs((R - x) / R);
        cout << " Ea: " << 100 * ea << "% ";

        if (er < E) {
            cout << "\nterminated\n";
            return;
        }
    }
}

int main() {

    cout << "locating root...\n";

    /*
        bisection(0, 4);
        falsePosition(0, 4);
        newton(0);
        secant(0, 4);
        modifiedSecant(4);
     */

    bisection(120, 130);
    falsePosition(120, 130);
    newton(120);
    secant(120, 130);
    modifiedSecant(120);

    return 0;
}
