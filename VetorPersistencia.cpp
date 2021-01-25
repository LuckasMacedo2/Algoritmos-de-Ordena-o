#include "VetorPersistencia.h"
#include<iostream>
std::string VetorPersistencia::getNomeArq() const
{
    return nomeArq;
}

void VetorPersistencia::setNomeArq(const std::string &value)
{
    nomeArq = value;
}

VetorPersistencia::VetorPersistencia():
    nomeArq("")
{

}

VetorPersistencia::VetorPersistencia(std::string nomeArq):
    nomeArq(nomeArq)
{

}

std::string VetorPersistencia::desmontarVetor(long double A[], int tam, std::string caso, double tempo)
{
    std::string saida;
    saida+=caso+";"+std::to_string(tempo)+";";
    for(int i = 0; i < tam; i++){
        saida+=std::to_string(A[i])+";";
    }
    saida+="\n";
    return saida;
}

void VetorPersistencia::arquivar(std::string tam, std::string melhor, std::string pior, std::string ale)
{
    std::string saida = tam + '\n' + melhor + '\n' + pior + '\n' + ale + '\n';
    std::ofstream arquivo;
    arquivo.open(nomeArq.c_str(),std::ios::out|std::ios::app);
    if(!arquivo.is_open()){
        arquivo.close();
        throw std::string("Erro, arquivo não encontrado");
    }
    arquivo<<saida;
    arquivo.close();
}
