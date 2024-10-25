#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Horario {
    private:
        unsigned short hora;
        unsigned short minuto;
        bool validateHora(unsigned short h, unsigned short m);
    
    public:
        bool setHora(string h);
        string getHora() const;
        
};

class Dinheiro {
    private:
        float dinheiro;
        string dinheiroView;
        bool validateDinheiro(string dinheiro);

    public:
        bool setDinheiro(string dinheiro);
        float getDinheiro() const;
        string getDinheiroView() const;
};

#endif // DOMINIOS_HPP_INCLUDED
