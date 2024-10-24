#include "dominios.hpp"

using namespace std;

bool Horario::validateHora(unsigned short h, unsigned short m){
    if (h > 23 || h < 0){
        return false;
    }
    else if (m > 59 || m < 0){
        return false;
    }

    return true;
}

bool Horario::setHora(string h){
    if (h[2] != ':'){
        return false;
    }
    unsigned short HH = stoi(h.substr(0,2));
    unsigned short MM = stoi(h.substr(3 ,2));
    if (validateHora(HH, MM)){
        this->hora=HH;
        this->minu=MM;
        return true;
    }
    return false;
}
