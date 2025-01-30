#include <iostream>
#include <limits>

#include "entidades.hpp"
#include "testes.hpp"

using namespace std;

void limpaBuffer(){
    if(cin.fail()) {
        cout << "Erro de entrada. Tente novamente.\n";
        cin.clear(); // Limpa o estado de erro do cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar a entrada inválida
    }
}

void limpaTela(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
        system("clear");

    #elif defined(_WIN32) || defined(_WIN64)
        system("cls");

    #endif
}

