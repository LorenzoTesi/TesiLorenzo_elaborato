//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_DATA_H
#define ELABORATO12_DATA_H
#include<vector>
#include<stdexcept>
class Data{
private:
    int giorno, mese, anno;
    std::vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    Data(int g, int m, int a){
        if(a>2023){
            if((a % 4 == 0 && a % 100 != 0) or (a % 400 == 0)){
                days[1]=29;
            }
            if(m>12 or m<0 or g>days[m-1] or g<0)
                throw std::invalid_argument("Data non valida");
        }
        giorno=g;
        mese=m;
        anno=a;
    }
    std::string GetData() const{
        return std::to_string(giorno) + "/" + std::to_string(mese) + "/" + std::to_string(anno);
    }
};

#endif //ELABORATO12_DATA_H
