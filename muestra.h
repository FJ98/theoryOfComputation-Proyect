#ifndef PROYECTO_MUESTRA_H
#define PROYECTO_MUESTRA_H

#include <bits/stdc++.h>
using namespace std;

#define FICO 6

class muestra{
public:
    int size; int min; int max;
    std::vector< int > data;
    std::vector< std::string > rankings;
    double frequencies[FICO];
    double percentages[FICO];

public:
    muestra(): min{300}, max{850}, size{0}, frequencies{0}, percentages{0} {};
    explicit muestra(int size) : size{size}, min{300}, max{850}, frequencies{0}, percentages{0}{};

    /* Se genera datos de puntaje aleatoriamente en un
     * rango entre 300 y 850 y se anade al vector data*/
    void generateData(){
        for(int i = 0; i < size; i++){
            int n = rand() % 551 + 300;
            data.push_back(n);
        }
    }

    /* Dependiendo del rango donde se encuentre
     * el rango se asigna una categoria*/
    void calculateRanks(){
        string s;
        for(int i : data){
            if(i >= 300 && i < 600){
                s = "Muy bajas";
                rankings.push_back(s);
            }
            else if(i >= 600 && i < 650){
                s = "Bajas";
                rankings.push_back(s);
            }
            else if(i >= 650 && i < 700){
                s = "Intermedias";
                rankings.push_back(s);
            }
            else if(i >= 700 && i < 750){
                s = "Buenas";
                rankings.push_back(s);
            }
            else if(i >= 750 && i < 800){
                s = "Muy buenas";
                rankings.push_back(s);
            }
            else if(i >= 800 && i < 850){
                s = "Excelentes";
                rankings.push_back(s);
            }
        }
    }

    /* Calcula el porcentaje de acuerdo a la categoria */
    void calculatePercentage(){
        for(const auto & ranking : rankings){
            if(ranking == "Muy bajas"){ ++frequencies[0]; }
            else if(ranking == "Bajas"){ ++frequencies[1]; }
            else if(ranking == "Intermedias"){ ++frequencies[2]; }
            else if(ranking == "Buenas"){ ++frequencies[3]; }
            else if(ranking == "Muy buenas"){ ++frequencies[4]; }
            else if(ranking == "Excelentes"){ ++frequencies[5]; }
        }
        for(int i = 0; i < FICO; i++){
            percentages[i] = frequencies[i] / size * 100;
        }
    }

    /* Se genera una nueva muestra para calcular los
     * cambios la cual contiene los datos de la muestra
     * actual mas un numero al azar entre -100 y 100. Nos
     * seguramos de que esta suma nunca resulte en un
     * puntaje menor a 300 o mayor a 850*/
    muestra changes(){
        muestra newMuestra(size);
        for(int i : data){
            int change = (rand()%201)- 100;
            if(i + change < 300 || i + change > 850) {
                newMuestra.data.push_back(i);
            }
            else{
                newMuestra.data.push_back(i + change);
            }
        }
        newMuestra.calculateRanks();
        newMuestra.calculatePercentage();
        return newMuestra;
    }

    /* Muestra los porcentajes */
    void showPercentages(){
        for(int i = 0; i < FICO; i++){
            cout << "Categoria " << i << ": " << percentages[i] << "%" << endl;
        }
    }

    /* Muestra la data de cada persona */
    void showData(){
        for(int i = 0; i < static_cast<int>(data.size()); i++){
            cout << "Persona: " << i +1 << ": " <<  data.at(i) << endl;
        }
    }

    /* Muestra el ranking de cada persona (excelente, bueno, malo, etc) */
    void showRanks(){
        cout << rankings.size() << endl;
        for(int i = 0; i < static_cast<int>(rankings.size()); i++){
            cout << "Persona: " << i + 1  << ": " <<  rankings.at(i) << endl;
        }
    }
};
#endif //PROYECTO_MUESTRA_H




