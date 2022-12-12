#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
//#include <F:\analisis\titulos.h>

using namespace std;
long double xf = 0, xi = 0, xr = 0, func, func1, Es;
int cs;

int main()
{
    cout << "La función propuesta es: x^3+2x^2+7x-20=0" << endl << endl;
    cout << "Ingrese el numero de cifras significaticas a usar: ";
    cin >> cs;
    cout << endl;

    Es = 0.5 * pow(10, (2 - cs));

    cout << "El Error de Tolerancia es: " << setprecision((cs - 1) * 2) << Es << " %" << endl << endl;
    cout << "Ingrese el valor de xi (l\241mite inferior): ";
    cin >> xi;
    cout << "Ingrese el valor de xf (l\241mite superior): ";
    cin >> xf;
    cout << endl;
    cout << "Verificando existencia de ra\241z..." << endl << endl;
    func = (powl(xi, 3) + (2 * (powl(xi, 2))) + (7 * xi) - 20);
    func1 = (powl(xf, 3) + (2 * (powl(xf, 2))) + (7 * xf) - 20);
    if (func == 0) {
        cout << "La raiz de la ecuacion es: " << xi << endl << endl;
        system("PAUSE");
    }
    if (func1 == 0) {
        cout << "La raiz de la ecuacion es: " << xf << endl << endl;
        system("PAUSE");
    }
    if (func < 0 && func1>0 || func1 < 0 && func>0) {
        int i = 1;
        long double vprev;
        do {
            cout << "\tIteracion " << i << ":" << endl << endl;
            cout << "xi= " << xi << ", xf= " << xf << endl << endl;
            cout << "f(xi)= " << func << " f(xf)= " << func1 << endl << endl;
            cout << "f(xi)*f(xf)= " << func * func1;

            if (func * func1 > 0) {
                cout << " > 0" << endl << endl << "\t xr=xf";
                //vprev=xf;
                cout << endl << endl;
            }
            else {
                cout << " < 0" << endl << endl << "\t xr=xi";
                //vprev=xi;
                cout << endl << endl;
            }
            vprev = xr;
            xr = (xi + xf) / 2;
            cout << "xr=(xi+xf)/2 = " << xr << endl << endl;

            //Era

            func = (powl(xr, 3) + (2 * (powl(xr, 2))) + (7 * xr) - 20);
            if (func < 0) {
                xi = xr;
                func1 = (func * (-1));
                cout << "Era=|((Vact-Vprev)/Vact)|X100% = " << fabs((xr - vprev) / xr) * 100 << "%" << endl << endl;
            }
            else {
                xf = xr;
                func1 = func;
                cout << "Era=|((Vact-Vprev)/Vact)|X100% = " << fabs((xr - vprev) / xr) * 100 << "%" << endl << endl;
            }
            i++;
        } while ((fabs((xr - vprev) / xr) * 100) > Es);

        cout << "La raiz es x de = " << setprecision(cs) << xr << endl << endl;
        system("PAUSE");
    }
    else {
        cout << "La ecuacion no tiene raices en este intervalo... " << endl << endl;
        system("PAUSE");
    }
    return 0;

}