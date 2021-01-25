#include <stdlib.h>
#include <algorithm>
/*InsertionSort*/
template<class T>
void insertionSort(T A[], int tam)
{
    T key;
    int i;
    for (int j = 1; j<tam; j++){
        key = A[j];
        i = j - 1;
        while (i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

/*QuickSort*/
template <typename T>
int Partition (T A[], int p, int r){
    T X = A[r];
    int i = p - 1;
    int j;
    T aux;
    for (j = p;j<=r-1; j++){
        if(A[j]<=X){
            i = i+1;
            aux = A[j];
            A[j] = A[i];
            A[i] = aux;
        }
    }
    aux = A[i+1];
    A[i+1] = A[r];
    A[r] = aux;
    return i+1;
}
template <typename T>
void QuickSort(T A[],int p, int r){
    int q;
    if (p<r){
        q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

/*MergeSortComSentinela*/
template <typename T>
void mergeSentinela(T A[], int p, int q, int r){
    int n1 = (q-p+1);
    int n2 = (r-q);
    T L[r];
    T R[r];
    int i, j, k;
    for(i = 1; i<=n1; i++){
        L[i] = A[p+i-1];
    }

    for(j=1; j<=n2;j++){
        R[j] = A[q+j];
    }

    L[n1+1]=RAND_MAX;
    R[n2+1]=RAND_MAX;
    i=1;
    j=1;

    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else {
            A[k]=R[j];
            j++;
        }
    }
}

template <typename T>
void mergeSortSentinela (T A[], int p, int r){
    try {
        int q;
        if(p<r){
            q = (p+r)/2;
            mergeSortSentinela(A,p,q);
            mergeSortSentinela(A,q+1,r);
            mergeSentinela(A,p,q,r);
        }
        return;
    } catch (std::string &erro) {
        throw erro;
    }
}

/*MergeSortSemSentinela*/
template <typename T>
void merge(T v[], int p, int q, int r)
{
    try {
        int i, j, k;
        T w[r-p];
        i = p;
        j = q;
        k = 0;

        while (i < q && j < r) {
            if (v[i] <= v[j])
                w[k++] = v[i++];
            else
                w[k++] = v[j++];
        }
        while (i < q)
            w[k++] = v[i++];
        while (j < r)
            w[k++] = v[j++];
        for (i = p; i < r; ++i)
            v[i] = w[i-p];
    } catch (std::bad_alloc &) {
        throw std::string("\nFalta de memoria");
    }
}

template <typename T>
void mergeSort (T A[], int p, int r){
    try {
        int q;
        if(p<r-1){
            q = (p+r)/2;
            mergeSort(A,p,q);
            mergeSort(A,q,r);
            merge(A,p,q,r);
        }
        return;
    } catch (std::string &erro) {
        throw erro;
    }
}

/*BubbleSort*/
template <typename T>
void bubbleSort(T A[], int tam) {
    T aux;
    int i, j;
    for (i = 0; i<tam-1; i++){
        for (j=tam;j>i;j--){
            if(A[j]<A[j-1]){
                aux = A[j-1];
                A[j-1] = A[j];
                A[j] = aux;
            }
        }
    }
}

/*BubbleSort Oscilante*/
template <typename T>
void bubbleSortOscillanting(T A[], int tam){

    T aux;
    int i, inicio, fim;
    fim=tam-1;
    inicio=0;
    bool houveTroca = true;
    while(houveTroca && inicio<fim){
        houveTroca=false;
        for (i=inicio; i < fim; i++){
            if(A[i+1]<A[i]){
                aux = A[i+1];
                A[i+1] = A[i];
                A[i] = aux;
                houveTroca = true;
            }
        }
        fim--;
        for (i=fim; i>inicio; i--){
            if(A[i-1]>A[i]){
                aux = A[i-1];
                A[i-1] = A[i];
                A[i] = aux;
                houveTroca = true;
            }
        }
        inicio++;
    }
}

///*BubbleSort Oscilante*/
//template <typename T>
//void bubbleSortOscillanting(T A[], int tam){
//    T aux;
//    int i,j;
//    for (i = 0; i < tam-1; i++){
//        for(j = tam-1; j>=i+1; j--){
//            if(A[j]<A[j-1]){
//                aux = A[j-1];
//                A[j-1] = A[j];
//                A[j] = aux;
//            }
//        }
//    }
//}

/*HeapSort*/
template <typename T>
void criarHeap(T A[], int i, int f){
    T pai = A[i];	//Auxiliar
    int j=2*i+1;
    while(j<=f){
        if(j+1<=f&&A[j]<A[j+1])//Definido se um filho é maior que o pai.
        {
            j++;//Apontando para o filho que deveria ser o maior
        }
        if(pai<A[j]){//Definido se o pai é menor que o maior dos filhos
            A[i]=A[j];
            i=j;
            j=2*i+1;
        }
        else{
            j=f+1;
        }
        A[i]=pai;
    }
}

template <typename T>
void heapSort (T A[], int tam){
    //Monta o heap, ou seja monta um estrutura heap a partir do vetor informado
    for (int i = (tam-1)/2; i>=0;i--){
        criarHeap(A,i,tam-1);
    }
    for(int i = tam-1; i>=1;i--){
        T aux;
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        criarHeap(A,0,i-1);
    }
}

