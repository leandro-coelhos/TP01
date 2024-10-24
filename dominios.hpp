#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Horario {
    private:
        unsigned short hora;
        unsigned short minu;
        bool validateHora(unsigned short h, unsigned short m);
    
    public:
        bool setHora(string h);
        string getHora() const;
        
};

inline string Horario::getHora() const {
    string horario;
    if (Horario::hora < 10 && Horario::minu < 10){
        horario = "0" + to_string(Horario::hora) + ":0" + to_string(Horario::minu);
    }
    else if (Horario::hora < 10){
        horario = "0" + to_string(Horario::hora) + ":" + to_string(Horario::minu);
    }
    else if (Horario::minu < 10){
        horario = to_string(Horario::hora) + ":0" + to_string(Horario::minu);
    }
    else {
        horario = to_string(Horario::hora) + ":" + to_string(Horario::minu);
    }
    return horario;
}


#endif // DOMINIOS_HPP_INCLUDED
