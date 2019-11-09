#include <bits/stdc++.h>
#include "muestra.h"
#include "repositorio.h"

/* Funcion utilizada para hallar la matriz final*/
void GaussElimination(double a[6][6]) {
    int n,i,j,k; cout.precision(7); cout.setf(ios::fixed);
    n = 6; double x[n];

    for (i=0;i<n-1;i++)
        for (k=i+1;k<n;k++) {
            double t=a[k][i]/a[i][i];
            for (j=0;j<n;j++)
                a[k][j]=a[k][j]-t*a[i][j];
        }

    cout<<"\n\nLa matriz despues de la eliminacion gaussiana es la siguiente:\n\n\n";
    for (i=0;i<n;i++) {
        for (j=0;j<=n;j++)
            cout<<a[i][j]<<setw(16);
        cout<<"\n";
    }
    x[5]=3;
    for (i=n-2;i>=0;i--) {
        x[i]=a[i][n];
        for (j=i+1;j<n;j++)
            if (j!=i)
        x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];
    }
    double suma=0;
    for (i=0; i<n; i++) { suma+=x[i]; }
    for (i=0; i<n; i++) { x[i]=x[i]/suma; }

    cout<<"\nLos elementos del autovector son los siguientes \n";
    for (i=0;i<n;i++)
        cout<<x[i]<<endl;
}



int main() {
    srand(time(nullptr));
    double m[6][6];
    int num_personas = 10;
    const int num_muestras = 20;
    muestra muestra1(num_personas);
    muestra muestras[num_muestras];

    muestra1.generateData();
    muestra1.calculateRanks();
    muestra1.calculatePercentage();
    cout << "\n";
    muestras[0] = muestra1;
    for(int i = 1; i < num_muestras; i++){
        muestras[i] = muestras[i-1].changes();
    }
    repositorio repositorio1(muestras);
    repositorio1.matriz_transicion();

    cout<<"\n\nLa matriz transicion es la siguiente:\n";
    repositorio1.showMatrix();
    cout<<"\n\nLa matriz diferencia entre la matriz transicion y la matriz identidad es la siguiente:\n";
    repositorio1.MatrizAutovalor();
    GaussElimination(repositorio1.matriz_autovalor);

    return 0;
}