
#ifndef PROYECTO_REPOSITORIO_H
#define PROYECTO_REPOSITORIO_H

#include <iomanip>
#include "muestra.h"
class repositorio{
public:
    muestra muestras[20];
    double matriz[6][6];
    double matriz_final[6][6];
    double matriz_autovalor[6][6];

    repositorio(muestra muestras[20]){
        for(int i = 0; i < 20; i++){
            this->muestras[i] = muestras[i];
        }
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                matriz[i][j] = 0;
            }
        }
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                matriz_final[i][j] = 0;
            }
        }
    }

    void matriz_transicion() {
        for (int i = 0; i < muestras->size -1 ; i++) {
            for (int j = 0; j < muestras[i].rankings.size()-1; j++) {
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
        cout << "---------------------------------------------------------------------" << endl;
        double suma[6];
        for(int j = 0; j < 6; j++){
            suma[j] = 0;
            for(int i = 0; i< 6; i++){
                suma[j] += matriz[i][j];
            }
        }
        for(int j = 0; j < 6; j++){
            for(int i = 0; i < 6; i++){
                matriz[i][j] /= suma[j];
            }
        }
    }


    void MatrizAutovalor(){
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                matriz_autovalor[i][j]=matriz[i][j];
        for (int i = 0; i < 6; i++) matriz_autovalor[i][i]=matriz_autovalor[i][i]-1;

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++)
                cout << setw(10) << matriz_autovalor[i][j] << " ";
            cout << endl;
        }
        cout<<"\n";

    }

    void mult_matriz(int n){
        for(int t = 0; t < n; t++) {
            for (int m = 0; m < 6; m++) {
                for (int i = 0; i < 6; i++) {
                    double suma = 0;
                    for (int j = 0; j < 6; j++) {
                        suma += (matriz[i][j]) * (matriz[j][m]);
                    }
                    matriz_final[i][m] = suma;
                }
            }
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++) {
                    matriz[i][j]=matriz_final[i][j];
                }
        }
    }

    void showMatrix(){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                cout << setw(10) << matriz[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"\n";
    }
    void showMatrixFinal(){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                cout << setw(10) << matriz_final[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"\n";
    }



};
#endif //PROYECTO_REPOSITORIO_H