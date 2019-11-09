#ifndef PROYECTO_MUESTRA_H
#define PROYECTO_MUESTRA_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;
class muestra{
public:
    int size;
    int min = 300;
    int max = 850;
    vector<int> data;
    vector<string> rankings;
    double frecuencias[6];
    double percentages[6];

    muestra(){};

    muestra(int size):size(size){
        for(int i = 0; i < 6; i++){
            frecuencias[i] = 0;
            percentages[i] = 0;
        }

    };
    void generateData(){
        for(int i = 0; i < size; i++){
            int n = rand()%551 + 300;
            data.push_back(n);
        }
    }
    void calculateRanks(){
        string s;
        for(int i = 0; i < data.size(); i++){
            if(data.at(i) >= 300 && data.at(i) < 600){
                s = "Muy bajas";
                rankings.push_back(s);
            }
            else if(data.at(i) >= 600 && data.at(i) < 650){
                s = "Bajas";
                rankings.push_back(s);
            }
            else if(data.at(i) >= 650 && data.at(i) < 700){
                s = "Intermedias";
                rankings.push_back(s);
            }
            else if(data.at(i) >= 700 && data.at(i) < 750){
                s = "Buenas";
                rankings.push_back(s);
            }
            else if(data.at(i) >= 750 && data.at(i) < 800){
                s = "Muy buenas";
                rankings.push_back(s);
            }
            else if(data.at(i) >= 800 && data.at(i) < 850){
                s = "Excelentes";
                rankings.push_back(s);
            }
        }
    }
    void calculatePercentage(){

        for(int i = 0; i < rankings.size(); i++){
            if(rankings.at(i) == "Muy bajas"){
                frecuencias[0]++;
            }
            else if(rankings.at(i) == "Bajas"){
                frecuencias[1]++;
            }
            else if(rankings.at(i) == "Intermedias"){
                frecuencias[2]++;
            }
            else if(rankings.at(i) == "Buenas"){
                frecuencias[3]++;
            }
            else if(rankings.at(i) == "Muy buenas"){
                frecuencias[4]++;
            }
            else if(rankings.at(i) == "Excelentes"){
                frecuencias[5]++;
            }
        }
        for(int i = 0; i < 6; i++){
            percentages[i] = frecuencias[i]/size*100;
        }
    }
    muestra changes(){
        muestra nuevaMuestra(size);
        for(int i = 0; i < data.size(); i++){
            int change = (rand()%201)- 100;
            if(data.at(i) + change < 300 || data.at(i) + change > 850) {
                nuevaMuestra.data.push_back(data.at(i));
            }
            else{
                nuevaMuestra.data.push_back(data.at(i) + change);
            }
        }
        nuevaMuestra.calculateRanks();
        nuevaMuestra.calculatePercentage();
        return nuevaMuestra;
    }
    void showPercentages(){
        for(int i = 0; i < 6; i++){
            cout << "Categoria " << i << ": " << percentages[i] << "%" << endl;
        }
    }
    void showData(){
        for(int i = 0; i < data.size(); i++){
            cout << "Persona: " << i +1 << ": " <<  data.at(i) << endl;
        }
    }
    void showRanks(){
        cout << rankings.size() << endl;
        for(int i = 0; i < rankings.size(); i++){
            cout << "Persona: " << i +1  << ": " <<  rankings.at(i) << endl;
        }
    }
};
#endif //PROYECTO_MUESTRA_H




