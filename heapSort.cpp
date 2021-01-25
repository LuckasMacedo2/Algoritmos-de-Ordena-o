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
template <typename T>
void criarHeap(T A[], int i, int f){
	T pai = A[i];	//Auxiliar
	int j=2*i+1;
	while(j<=f&&j+1<=f){
		if(A[j]<A[j+1])//Definido se um filho é maior que o pai.
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
	return 0;
}

