#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x,y,z;
} Vetor;

// Valores da figura (mm).
double a = 200, b = 250, c = 150, d = 400;

// Velocidade angular (rad/s)
double w = 9;

// Resultados esperados
Vetor Velocidade, Aceleracao;

/* Funções */
void entradaValores();
void calculaVelocidadeAceleracao();
void apresentaResultado();

double moduloDoVetor(Vetor A);
Vetor subtraiVetor(Vetor A, Vetor B);
Vetor produtoVetorial(Vetor A, Vetor B);
Vetor multiplicaPorEscalar(Vetor A, double escalar);

int main(){
    entradaValores();
    calculaVelocidadeAceleracao();
    apresentaResultado();
}


double moduloDoVetor(Vetor A){
    return sqrt( pow(A.x,2.0) + pow(A.y,2.0) + pow(A.z,2.0));
}

Vetor produtoVetorial(Vetor A, Vetor B){
    Vetor Resultado;

    Resultado.x = A.y * B.z - A.z * B.y;
    Resultado.y = A.z * B.x - A.x * B.z;
    Resultado.z = A.x * B.y - A.y * B.x;

    return Resultado;
}

Vetor multiplicaPorEscalar(Vetor A, double escalar){
    return (Vetor) {.x = A.x*escalar, .y = A.y*escalar, .z = A.z*escalar };
}

Vetor subtraiVetor(Vetor A, Vetor B){
    Vetor Resultado;

    Resultado.x = A.x - B.x;
    Resultado.y = A.y - B.y;
    Resultado.z = A.z - B.z;

    return Resultado;
}

void entradaValores(){
    printf("Insira os valores do problema: \n\n");
    printf("a (mm) = ");
    scanf("%.2f", &a);
    fflush(stdin);

    printf("b (mm) = ");
    scanf("%.2f", &b);
    fflush(stdin);
    printf("c (mm) = ");
    scanf("%.2f", &c);
    fflush(stdin);
    printf("d (mm) = ");
    scanf("%.2f", &d);
    fflush(stdin);
    printf("w (rad/s) = ");
    scanf("%.2f", &w);
    fflush(stdin);
}

void calculaVelocidadeAceleracao() {
    Vetor PontoA = (Vetor) {.x = 0.0, .y = b + c, .z = a};
    Vetor PontoG = (Vetor) {.x = 0.0, .y = c, .z = 0.0};
    Vetor PontoE = (Vetor) {.x = d, .y = 0.0, .z = 0.0};

    Vetor Rge = subtraiVetor(PontoG, PontoE);
    Vetor Rea = subtraiVetor(PontoE, PontoA);

    double moduloRea = moduloDoVetor(Rea);
    Vetor VersorRea = multiplicaPorEscalar(Rea, 1.0/moduloRea);

    Vetor Omega = multiplicaPorEscalar(VersorRea, w);

    Velocidade = produtoVetorial(Omega, Rge);

    Aceleracao = produtoVetorial(Omega, Velocidade);
}

void apresentaResultado(){
    printf("Resultado Final: \n\n");
    printf("Velocidade: %.2fi + %.2fj + %.2fk [mm/s]\n", Velocidade.x, Velocidade.y, Velocidade.z);        
    printf("Modulo: %.2f [mm/s]\n\n",moduloDoVetor(Velocidade));
    printf("Aceleracao: %.2fi + %.2fj + %.2fk [mm/s²]\n", Aceleracao.x, Aceleracao.y, Aceleracao.z);        
    printf("Modulo: %.2f [mm/s²]\n\n", moduloDoVetor(Aceleracao));
}
