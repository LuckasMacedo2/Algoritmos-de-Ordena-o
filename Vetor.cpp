#include "Vetor.h"

int Vetor::getIndice() const
{
    return indice;
}

void Vetor::setIndice(int value)
{
    indice = value;
}

Vetor::Vetor():
    tam(0),
    vetor(0)
{

}

Vetor::Vetor(long double *vetor, int tam):
    tam(tam),
    vetor(vetor)
{

}

long double *Vetor::getVetor() const
{
    return vetor;
}

void Vetor::setVetor(long double *value)
{
    vetor = value;
}

void Vetor::gerarVetor()
{
    for (int i =0;i < this->getTam(); i++){
        this->vetor[i] =pow(10,rand()%4932);
    }
}

int Vetor::getTam() const
{
    return tam;
}

void Vetor::setTam(int value)
{
    try {
        tam = value;
        vetor = new long double[tam];
    } catch (std::bad_alloc &) {
        throw std::string("Erro, memoria para armazenamento insuficiente");
    }
}

std::string Vetor::getSaida() const
{
    try {
        if(this->getTam()==0)
            throw std::string("Erro, impossivel realizar a operação");
        std::string saida = "[ ";
        for(int i = 0; i<this->getTam(); i++){
            saida+=' '+vetor[i];
        }
        saida+=" ]";
        return saida;
    } catch (std::string &erro) {
        throw erro;
    }
}

long double Vetor::operator[](int i)
{
    try {
        if (i>this->getTam())
            throw std::string("Erro de segmentação impossivel acessar a posição informada");
        this->setIndice(i);
        return *(vetor+i);
    } catch (std::string &erro) {
        throw erro;
    }
}


