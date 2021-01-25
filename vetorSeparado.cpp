#include<iostream>
using std::cout;
using std::cin;
template <typename Tipo>
int vetorSeparado(Tipo A[], int tam){
	int i;
	bool ok =true;
	int esq, dir;
	for(i=1;i<tam;i++){
		ok = true;
		esq = i-1;
		dir = i+1;
		while(esq>=0){
			if(A[esq]>A[i]){
				ok=false;
				esq=0;
				dir=tam;
			}
			esq--;
		}
		while(dir<tam){
			if(A[dir]<A[i]){
				ok=false;
				dir=tam;
			}
			dir++;
		}
		if(ok==true){
			return i;
		}
	}
	return -1;
}

int main(){
	int A[7];
	A[0]=3;
	A[1]=1;
	A[2]=2;
	A[3]=4;
	A[4]=7;
	A[5]=9;
	A[6]=8;
	int j = vetorSeparado(A,7);
	if(j>=0){
		cout<<"\nO indice que encontra o número separador do vetor e: "<<j<<" sendo este: "<<A[j];
	}
	else{
		cout<<"\nO vetor não esta separado: "<<j;
	}
	
	

}
