#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//BUBBLE SORT
void BubbleSort(int n, int *vetor){
  int i;
  int p;
  int cont;

  for(cont =1; cont < n; cont ++){
    for(i = 0; i < n ; i++){
      if(vetor[i] > vetor[i+1]){
        p = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = p;
      }
    }
  }
}

//INSERTION SORT
void InsertionSort (int n, int *a){
  int i;
  int x;
  for(int j = 2; j<= n; j++){
    x = a[j];
    i = j - 1;
    while(i>=1 && a[i]>x){
      a[i+1] = a[i];
      i = i - 1;
    }
    a[i + 1] = x;
  }
}

//SELECTION SORT
void SelectionSort(int n, int *vetor){
  int cont;
  int i;
  int aux;
  int menor;
  int posmenor;
  int t;

  for(cont = 0; cont < n; cont++){
    menor = vetor[cont];
    for(i = cont; i < n; i++){
      if(menor > vetor[i]){
        menor = vetor[i]; 
        posmenor = i; 
        t = 1;
      }else{
        vetor[cont] = menor;
      }
      if(t == 1){
        aux = vetor[cont];
        vetor[cont] = menor;
        vetor[posmenor] = aux;
        t = 0;
      }
    }
  }
}

//COMB SORT
void CombSort (int tam, int *vetor){
  int gap;
  int j;
  int aux;

  gap = tam;
  
  while(gap > 1 ){
    if(gap > 1){
      gap = gap /1.3;
    }
    j = 0;
    while(gap+j < tam){
      if(vetor[j] > vetor[j+gap]){
        aux = vetor[j];
        vetor[j]= vetor[j+gap];
        vetor[j+gap]=aux;
      }
      j++;
    }
  }

}

int main(void) {

  //Eu escolhi N = 10000 e K = 70983, e deu de resultado 4.03168s
  //O algoritmo com melhor desempenho foi o Insertion Sort.
  //junto com esse .c tem uma foto com o resultado obtido e eu só mostrei o insertion sort porque, para mostrar todos os algoritmos com essse N e esse K iria demorar muito. 
  int n;
  int k;

  printf("\nDigite o tamanho do vetor: \n");
  scanf("%i",&n);
  int vet[n];

  printf("\n");
  printf("Digite a quantidade de  vezes que o procedimento será realizado: \n");
  scanf("%i",&k);

  //preechendo o vetor
  srand(time(NULL));
  for(int i = 1; i<=n; i++){
    vet[i] = rand()%100*n;
  }
  //declarando variavies de tempo
  time_t 
  tempo_inicio_B, tempo_final_B,
  tempo_inicio_I, tempo_final_I, 
  tempo_inicio_S, tempo_final_S, 
  tempo_inicio_C, tempo_final_C;

    long double tempo_total_B;
    long double tempo_total_I;
    long double tempo_total_S;
    long double tempo_total_C;

  printf("\n");
  //mostrando o vetor antes de ser ordenado
  printf("O vetor: \n");
  for(int i = 1; i<=n; i++){
    printf("%i\n", vet[i]);
  }

  printf("\n");
  printf("Vetor Ordenado com Bubble Sort: \n");
  tempo_inicio_B = clock();  
  //rodando K vezes
  for(int i = 1; i<=k; i++){
      BubbleSort(n, vet);
  }
  tempo_final_B = clock();
  for(int i = 1; i<=n; i++){
    printf("%i\n", vet[i]);
  }

  printf("\n");
  printf("Vetor Ordenado com Insertion Sort: \n");
  tempo_inicio_I = clock(); 
  //rodando K vezes
  for(int i = 1; i<= k; i++){
    InsertionSort(n, vet);
  }
  tempo_final_I = clock();
  for(int i = 1; i<=n; i++){
    printf("%i\n", vet[i]);
  }

  printf("\n");
  printf("Vetor Ordenado com Selection Sort: \n");
  tempo_inicio_S = clock();
  //rodando K vezes
  for(int i = 1; i<= k; i++){
    SelectionSort(n, vet);
  }
  tempo_final_S = clock();
  for(int i = 1; i<= n; i++){
    printf("%i\n", vet[i]);
  }

  printf("\n");
  printf("Vetor Ordenado com Comb Sort: \n");
  tempo_inicio_C = clock();  
  //rodando K vezes
  for(int i = 1; i<= k; i++){
    CombSort(n, vet);
  } 
  tempo_final_C = clock();
  for(int i = 1; i<=n; i++){
    printf("%i\n", vet[i]);
  }  

  tempo_total_B = (long double)(tempo_final_B - tempo_inicio_B) / CLOCKS_PER_SEC;

  tempo_total_I = (long double)(tempo_final_I - tempo_inicio_I) / CLOCKS_PER_SEC;

  tempo_total_S = (long double)(tempo_final_S - tempo_inicio_S) / CLOCKS_PER_SEC;

  tempo_total_C = (long double)(tempo_final_C - tempo_inicio_C) / CLOCKS_PER_SEC;
    
  printf("\nTempo total do Bubble sort: %Lf segundos.\n",tempo_total_B);
  printf("\nTempo total do Insertion sort: %Lf segundos.\n",tempo_total_I);
  printf("\nTempo total do Selection sort: %Lf segundos.\n",tempo_total_S);
  printf("\nTempo total do Comb sort: %Lf segundos.\n",tempo_total_C);
  
}