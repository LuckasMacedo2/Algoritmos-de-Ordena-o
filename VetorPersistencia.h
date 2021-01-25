#ifndef VETORPERSISTENCIA_H
#define VETORPERSISTENCIA_H

#include<fstream>
#include<string>

class VetorPersistencia
{
private:
    std::string nomeArq;
public:
    VetorPersistencia();
    VetorPersistencia(std::string nomeArq);
    std::string desmontarVetor(long double A[], int tam, std::string caso, double tempo);
    void arquivar(std::string, std::string, std::string, std::string);
    std::string getNomeArq() const;
    void setNomeArq(const std::string &value);
};

#endif // VETORPERSISTENCIA_H
