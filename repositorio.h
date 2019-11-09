#ifndef PROYECTO_REPOSITORIO_H
#define PROYECTO_REPOSITORIO_H


/* Se creo la clase repositorio que tiene como atributos una matriz de 20 muestras
 * una para cada semestra de los 10 anos. Y dos matrices de 6 x 6 que representan
 * la matriz de transicion y la matriz final*/
#include <bits/stdc++.h>
#include "muestra.h"

class repositorio{
public:
    muestra muestras[20];
    double matriz[6][6];
    double matriz_final[6][6];
    double matriz_autovalor[6][6];

    explicit repositorio(muestra muestras[20]): matriz{0}, matriz_final{0}, matriz_autovalor{0} {
        for(int i = 0; i < 20; ++i){ this->muestras[i] = muestras[i]; }
    }

    /* Se obtiene la matriz de transicion sumando el numero de trasiciones desde todos
     * los estados hasta todos los estados. Luego se divide la cantidad de transiciones
     * de un estado a otro entre la cantidad de transiciones de ese estado a cualquiera.
     * Asi se obtiene la probabilidad de cada transicion. */
    void matriz_transicion() {
        for (int i = 0; i < muestras->size -1 ; i++) {
            for (int j = 0; j < static_cast<int>(muestras[i].rankings.size())-1; j++) {
                if (muestras[i].rankings.at(j) == "Muy bajas") {
                    if (muestras[i + 1].rankings.at(j) == "Muy bajas") {
                        matriz[0][0]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Bajas") {
                        matriz[1][0]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Intermedias") {
                        matriz[2][0]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Buenas") {
                        matriz[3][0]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Muy buenas") {
                        matriz[4][0]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Excelentes") {
                        matriz[5][0]++;
                    }
                } else if (muestras[i].rankings.at(j) == "Bajas") {
                    if (muestras[i + 1].rankings.at(j) == "Muy bajas") {
                        matriz[0][1]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Bajas") {
                        matriz[1][1]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Intermedias") {
                        matriz[2][1]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Buenas") {
                        matriz[3][1]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Muy buenas") {
                        matriz[4][1]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Excelentes") {
                        matriz[5][1]++;
                    }
                } else if (muestras[i].rankings.at(j) == "Intermedias") {
                    if (muestras[i + 1].rankings.at(j) == "Muy bajas") {
                        matriz[0][2]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Bajas") {
                        matriz[1][2]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Intermedias") {
                        matriz[2][2]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Buenas") {
                        matriz[3][2]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Muy buenas") {
                        matriz[4][2]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Excelentes") {
                        matriz[5][2]++;
                    }
                } else if (muestras[i].rankings.at(j) == "Buenas") {
                    if (muestras[i + 1].rankings.at(j) == "Muy bajas") {
                        matriz[0][3]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Bajas") {
                        matriz[1][3]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Intermedias") {
                        matriz[2][3]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Buenas") {
                        matriz[3][3]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Muy buenas") {
                        matriz[4][3]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Excelentes") {
                        matriz[5][3]++;
                    }
                } else if (muestras[i].rankings.at(j) == "Muy buenas") {
                    if (muestras[i + 1].rankings.at(j) == "Muy bajas") {
                        matriz[0][4]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Bajas") {
                        matriz[1][4]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Intermedias") {
                        matriz[2][4]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Buenas") {
                        matriz[3][4]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Muy buenas") {
                        matriz[4][4]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Excelentes") {
                        matriz[5][4]++;
                    }
                } else if (muestras[i].rankings.at(j) == "Excelentes") {
                    if (muestras[i + 1].rankings.at(j) == "Muy bajas") {
                        matriz[0][5]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Bajas") {
                        matriz[1][5]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Intermedias") {
                        matriz[2][5]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Buenas") {
                        matriz[3][5]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Muy buenas") {
                        matriz[4][5]++;
                    } else if (muestras[i + 1].rankings.at(j) == "Excelentes") {
                        matriz[5][5]++;
                    }
                }
            }
        }
        //showMatrix();
        cout << "----------------------------" << endl;
        double suma[6];
        for(int j = 0; j < 6; ++j){
            suma[j] = 0;
            for(auto & i : matriz){ suma[j] += i[j]; }
        }
        for(int j = 0; j < 6; ++j){
            for(auto & i : matriz){ i[j] /= suma[j]; }
        }
    }

    /* Matriz de autovalores */
    void MatrizAutovalor(){
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                matriz_autovalor[i][j]=matriz[i][j];
        for (int i = 0; i < 6; i++) {
            matriz_autovalor[i][i]=matriz_autovalor[i][i]-1;
        }

        for(auto & i : matriz_autovalor){
            for(double j : i) { cout << setw(10) << j << " "; }
            cout << endl;
        }
        cout<<"\n";
    }

    /* Mostrar matriz */
    void showMatrix(){
        for(auto & i : matriz){
            for(double j : i){ cout << setw(10) << j << " "; }
            cout << endl;
        }
        cout<<"\n";
    }
};
#endif //PROYECTO_REPOSITORIO_H



//    /* Multipliacion de matrices */
//    void mult_matriz(int n){
//        for(int t = 0; t < n; t++) {
//            for (int m = 0; m < 6; m++) {
//                for (int i = 0; i < 6; i++) {
//                    double suma = 0;
//                    for (int j = 0; j < 6; j++) {
//                        suma += (matriz[i][j]) * (matriz[j][m]);
//                    }
//                    matriz_final[i][m] = suma;
//                }
//            }
//            for (int i = 0; i < 6; i++)
//                for (int j = 0; j < 6; j++) {
//                    matriz[i][j]=matriz_final[i][j];
//                }
//        }
//    }

///* Mostrar matriz final */
//void showMatrixFinal(){
//    for(auto & i : matriz_final){
//        for(double j : i){ cout << setw(10) << j << " "; }
//        cout << endl;
//    }
//    cout<<"\n";
//}