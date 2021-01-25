#ifndef VETOR_H
#define VETOR_H
#include <iostream>
#include <cmath>
class Vetor
{
private:
    long double * vetor;
    int tam;
    int indice;
public:
    Vetor();
    Vetor(long double *vetor, int tam);
    long double *getVetor() const;
    void setVetor(long double *value);
    void gerarVetor ();
    int getTam() const;
    void setTam(int value);
    std::string getSaida()const;
    long double operator[](int );
    bool operator<(Vetor &obj2){
        if(this->operator [](this->getIndice())<obj2[obj2.getIndice()]){
            return true;
        }
        return false;
    }
    int getIndice() const;
    void setIndice(int value);
};

#endif // VETOR_H
