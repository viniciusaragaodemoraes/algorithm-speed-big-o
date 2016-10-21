#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <locale.h>
#define MAX 10000

/* BubbleSort */

using namespace std::chrono;

void Random();
void Chrono();
void BubbleSort();

int random[MAX]; // Variavel global.

int main(int argc, char** argv) {
	std::setlocale(LC_ALL, "Portuguese"); //Define a linguagem do console de aplicação para portugues.
	Chrono();
	system("PAUSE");
	return 0;
}

void Random(){ // Popula a variavel global "random" com 1000 numeros de 1 ate 1000 randomicamente, dentro do vetor.

	srand((unsigned)time(NULL));

    for (int i = 1; i < MAX; i++){
        random[i] = 1+ rand() % MAX;
        std::cout << random[i] << ",";
    }
    
    std::cout << std::endl;
    	
}

void Chrono(){ // Calcula o tempo de execução do programa

	high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Pega o tempo atual da maquina
	
	Random(); // Chama o metodo para popular a variavel global
	BubbleSort(); // Chama o metodo sorted.

	high_resolution_clock::time_point t2 = high_resolution_clock::now(); // Pega o tempo pós execução

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1); // Subtrai os valores para obter o tempo de execução

	std::cout << std::endl;
	std::cout << "Tempo de execução no BubbleSort: " << time_span.count() << " em segundos.";
	std::cout << std::endl;

}

void BubbleSort(){
	
	int d, swap;
 	
	for (int c = 0 ; c < ( MAX - 1 ); c++){
    	for (d = 0 ; d < MAX - c - 1; d++){
      		if (random[d] > random[d + 1]) {
        	swap = random[d];
        	random[d] = random[d + 1];
       		random[d + 1] = swap;
      		}
    	}
  	}
 
	std::cout<<"Iniciando o metodo BubbleSort e organizado em ordem crescente: "<<std::endl;

	for (int c = 0 ; c < MAX ; c++ ){
    	std::cout << random[c] << ",";
	}
	
}

