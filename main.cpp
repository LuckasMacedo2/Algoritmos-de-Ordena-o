/*
Aluno: Lucas Macedo da Silva
Aluno: Felipe Pereira Brandão
Turma: A01
Titulo: Metodos de Ordenação



Máquina utilizada
    Sistema Operacional: Windowns 32 bits
    RAM 4 GB
    Obs: Vetores com tamanho acima de 1000.000 demoram mais de 3 horas para ordenar

Comentários sobre Casos/ Metodos ao final do arquivo main

*/

#include <iostream>
using std::cout;
using std::cin;
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "VetorPersistencia.h"
#include "Sortmethods.h"

#include <cmath>
//Casos aleatorios
void gerarVetor(long double A[], int tam){
    for(int i=0;i<tam;i++){
        A[i]=rand();//Potencias acima de 4932 meu Computador marcava como inf
    }
}

void gerarVetorOrdenado(long double A[], int tam){
    for(int i = 0; i<tam; i++){
        A[i]=i;
    }
}

void gerarVetorInverso(long double A[], int tam){
    for(int i=0; i<tam; i++){
        A[i]=tam-i;
    }
}


void imprimirVetor(long double A[], int tam){
    for(int i=0; i<tam; i++){
        cout<<"\n "<<A[i];
    }
    cout<<"\n\n";
}

int main(){
    try {
        VetorPersistencia objDao("InsertionSort.csv");
        double tempo;
        clock_t inicio, fim;
        long double *A;
        short int opc=0;
        do {

            cout<<"\nInforme \n[1] Para Insertion Sort \n[2] Para Bubble Sort\n[3] Para Shaker Sort \n[4] Para Merge Sort \n[5] Para Quick Sort \n[6] Para heapSort \n[7] Para sair\nOpcao[ ]\b\b";
            cin>>opc;
            long int tam = 1;
            system("cls");
            switch (opc) {


            case 1: //Insertion Sort
                try {
                    std::string saida="Insertion Sort;";
                    std::string saidaM="Melhor Caso;";
                    std::string saidaP="Pior Caso;";
                    std::string saidaA="Caso Aleatorio;";

                    while (tam<1000000) {
                        tam=tam*10;
                        try {
                            A = new long double[tam];
                        } catch (std::bad_alloc &) {
                            throw std::string("Erro, falta de memoria para armazenamento");
                        }
                        saida+=std::to_string(tam)+';';
                        //Melhor Caso
                        cout<<"\nMelhor Caso insertion sort";
                        gerarVetorOrdenado(A, tam);
                        inicio  = clock();
                        insertionSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaM+=std::to_string(tempo)+';';

                        //Pior Caso
                        cout<<"\nPior Caso insertion Sort";
                        gerarVetorInverso(A,tam);
                        inicio = clock();
                        insertionSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        if(tempo>10800){
                            saidaP+=">3h;";
                        }else{
                            saidaP+=std::to_string(tempo)+';';
                        }

                        //Caso aleatorio
                        cout<<"\nCaso Aleatorio do insertion Sort";
                        gerarVetor(A,tam);
                        inicio = clock();
                        insertionSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaA+=std::to_string(tempo)+';';


                        delete A;
                    }
                    objDao.arquivar(saida,saidaM,saidaP,saidaA);
                } catch (std::string &erro) {
                    cout<<erro;
                }
                break;


            case 2: //Bubble Sort
                try {
                    std::string saida="Bubble Sort;";
                    std::string saidaM="Melhor Caso;";
                    std::string saidaP="Pior Caso;";
                    std::string saidaA="Caso Aleatorio;";

                    while (tam<1000000) {
                        tam=tam*10;
                        try {
                            A = new long double[tam];
                        } catch (std::bad_alloc &) {
                            throw std::string("Erro, falta de memoria para armazenamento");
                        }
                        objDao.setNomeArq("BubbleSort.csv");
                        saida+=std::to_string(tam)+';';


                        //Melhor Caso
                        cout<<"\nMelhor Caso bubble sort";
                        gerarVetorInverso(A, tam);
                        inicio  = clock();
                        insertionSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaM+=std::to_string(tempo)+';';


                        //Pior Caso
                        cout<<"\nPior Caso bubble sort";
                        gerarVetorOrdenado(A,tam);
                        inicio=clock();
                        bubbleSort(A,tam);
                        fim=clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        if(tempo>10800){
                            saidaP+=">3h";
                        }else{
                            saidaP+=std::to_string(tempo)+';';
                        }

                        //Caso aleatorio
                        cout<<"\nCaso aleatorio bubble sort";
                        gerarVetor(A,tam);
                        inicio=clock();
                        bubbleSort(A,tam);
                        fim=clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaA+=std::to_string(tempo)+';';

                        delete A;
                    }
                    objDao.arquivar(saida,saidaM,saidaP,saidaA);
                } catch (std::string &erro) {
                    cout<<erro;
                }
                break;


            case 3: //Shaker Sort

                try {
                    std::string saida="Shaker Sort;";
                    std::string saidaM="Melhor Caso;";
                    std::string saidaP="Pior Caso;";
                    std::string saidaA="Caso Aleatorio;";
                    while (tam<1000000) {
                        tam=tam*10;
                        try {
                            A = new long double[tam];
                        } catch (std::bad_alloc &) {
                            throw std::string("Erro, falta de memoria para armazenamento");
                        }
                        objDao.setNomeArq("ShakerSort.csv");
                        saida+=std::to_string(tam)+';';

                        //Melhor Caso
                        cout<<"\nMelhor caso Shaker Sort";
                        gerarVetorOrdenado(A,tam);
                        inicio = clock();
                        bubbleSortOscillanting(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo/CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaM+=std::to_string(tempo)+';';


                        //Pior Caso
                        cout<<"\nPior caso shaker sort";
                        gerarVetorInverso(A,tam);
                        inicio = clock();
                        bubbleSortOscillanting(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        if(tempo>10800){
                            saidaP+=">3h";
                        }else{
                            saidaP+=std::to_string(tempo)+';';
                        }

                        //Caso Aleatorio
                        gerarVetor(A,tam);
                        inicio = clock();
                        bubbleSortOscillanting(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaA+=std::to_string(tempo)+';';

                        delete A;
                    }
                    objDao.arquivar(saida,saidaM,saidaP,saidaA);
                } catch (std::string &erro) {
                    cout<<erro;
                }
                break;


            case 4: //Merge Sort
                try {
                    std::string saida="Merge Sort;";
                    std::string saidaM="Melhor Caso;";
                    std::string saidaP="Pior Caso;";
                    std::string saidaA="Caso Aleatorio;";
                    while (tam<100000) {
                        tam=tam*10;
                        objDao.setNomeArq("MergeSort.csv");
                        try {
                            A = new long double[tam];
                        } catch (std::bad_alloc &) {
                            saidaA += ";Falta de memoria";
                            objDao.arquivar(saida,saidaM,saidaP,saidaA);
                            throw std::string("Erro, falta de memoria para armazenamento");   
                        }

                        saida+=std::to_string(tam)+';';
                        //Caso aleatorio
                        cout<<"\nCaso Aleatorio merge sort";
                        gerarVetor(A,tam);
                        inicio = clock(); 
                        try {
                            mergeSort(A,0,tam-1);
                        } catch (std::string &erro) {
                            saidaA += ";Falta de memoria";
                            objDao.arquivar(saida,saidaM,saidaP,saidaA);
                            throw erro;
                        }
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        delete A;
                        saidaA+=std::to_string(tempo)+';';

                    }
                    objDao.arquivar(saida,saidaM,saidaP,saidaA);
                } catch (std::string &erro) {
                    cout<<erro;
                }

                break;


            case 5://Quick Sort

                try {
                    std::string saida="Quick Sort;";
                    std::string saidaM="Melhor Caso;";
                    std::string saidaP="Pior Caso;";
                    std::string saidaA="Caso Aleatorio;";
                   while (tam<10000) {
                        tam=tam*10;
                        try {
                            A = new long double[tam];
                        } catch (std::bad_alloc &) {
                            throw std::string("Erro, falta de memoria para armazenamento");
                        }
                        objDao.setNomeArq("QuickSort.csv");
                        saida+=std::to_string(tam)+';';
                        cout<<"\n\n\n"<<tam<<"\n\n\n";
                        //Pior Caso
                        cout<<"\nPior caso Quick Sort";
                        gerarVetorOrdenado(A,tam);
                        inicio = clock();
                        QuickSort(A,0,tam-1);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        if(tempo>10800){
                            saidaP+=">3h";
                        }else{
                            saidaP+=std::to_string(tempo)+';';
                        }

                        //Caso Aleatorio
                        cout<<"\nCaso aleatorio Quick Sort";
                        gerarVetor(A,tam);
                        inicio = clock();
                        QuickSort(A,0,tam-1);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaA+=std::to_string(tempo)+';';

                        delete A;
                    }
                    objDao.arquivar(saida,saidaM,saidaP,saidaA);
                    } catch (std::string &erro) {
                        cout<<erro;
                }
                break;

            case 6:  //Heap Sort
                try {
                    std::string saida="Heap Sort;";
                    std::string saidaM="Melhor Caso;";
                    std::string saidaP="Pior Caso;";
                    std::string saidaA="Caso Aleatorio;";
                    while (tam<1000000) {
                        tam=tam*10;
                        try {
                            A = new long double[tam];
                        } catch (std::bad_alloc &) {
                            saidaA += ";Overflow!";
                            objDao.arquivar(saida,saidaM,saidaP,saidaA);
                            throw std::string("Erro, falta de memoria para armazenamento");
                        }
                        objDao.setNomeArq("HeapSort.csv");
                        saida+=std::to_string(tam)+';';

                        //Melhor Caso
                        cout<<"\nMelhor caso Heap Sort";
                        gerarVetorInverso(A,tam);
                        inicio = clock();
                        heapSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaM+=std::to_string(tempo)+';';

                        //Pior Caso
                        cout<<"\nPior caso Heap Sort";
                        gerarVetorOrdenado(A,tam);
                        inicio = clock();
                        heapSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        if(tempo>10800){
                            saidaP+=">3h";
                        }else{
                            saidaP+=std::to_string(tempo)+';';
                        }

                        //Caso Aleatorio
                        cout<<"\nCaso Aleatorio";
                        gerarVetor(A,tam);
                        inicio = clock();
                        heapSort(A,tam);
                        fim = clock();
                        tempo = fim - inicio;
                        tempo = tempo /CLOCKS_PER_SEC;
                        cout<<"\nO tempo gasto foi de "<<tempo<<" s";
                        saidaA+=std::to_string(tempo)+';';
                        delete A;
                    }
                    objDao.arquivar(saida,saidaM,saidaP,saidaA);

                } catch (std::string &erro) {
                    cout<<erro;
                }
                break;
            case 7:
                //delete A;
                exit(1);
                break;
            default:
                cout<<"\nErro, opcao invalida";
                break;
            }
        }while (opc!=7);
    } catch (std::string &erro) {
        cout<<"\n"<<erro;
    }
}
/*
-Insertion Sort
    Melhor Caso o vetor já está devidamente ordenado
    Pior Caso o vetor está ordenado inversamente da condição da função do mesmo
no algoritmo em questão a condição do while
    Caso aleatorio do insertion sort é complexo definir o mesmo, contudo assumindo
que o vetor é composto por numeros aleatorios;

-Bubble Sort
    Melhor caso o vetor encontra-se inversamente ordenado em relação á condição da
função
    Pior caso o vetor encontra-se ordenado
    Caso aleatorio, como já citado anteriormente: é complexo definir o mesmo, contudo assumindo
que o vetor é composto por numeros aleatorios;

-Shaker Sort/ Bubble Sort Oscilante
    Pior Caso o vetor está inversamente ordenado
    Melhor Caso o vetor encontra-se ordenado
    Caso aleatorio, novamente como citado anteriormente:  é complexo definir o mesmo, contudo assumindo
que o vetor é composto por numeros aleatorios;

-Merge Sort
    Caso aleatorio é complexo definir o mesmo, contudo assumindo que o vetor é composto por numeros aleatorios;

-Quick Sort
    Pior caso ocorri quando o vetor já está totalmente ordenado
    Caso aleatorio é complexo definir o mesmo, contudo assumindo que o vetor é composto por numeros aleatorios;
o tempo de ecxecução do caso aleatorio do quick sort está mais proximo do melhor caso do que do pior caso, sendo
portatno um dos melhores metodos de ordenação para conjunto de dados que não se sabe a ordem.

-Heap Sort
    Pior caso ocorri sempre que o pai for menor que seus dois filhos, o vetor também pode estar ordenado
    Melhor caso ocorri sempre que o pai for maior que seus dois filhos, o vetor pode estar inversamente
ordenado
    Caso aleatorio  é complexo definir o mesmo, contudo assumindo que o vetor é composto por numeros aleatorios;

*/
