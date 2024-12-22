// utils.h
#ifndef UTILS_H
#define UTILS_H
#define MAX_NOME 50
#define MAX_PRATO 100

typedef struct {
    int numero;
    char nome[MAX_NOME];
    char nif[10];
    char telefone[10];
} Funcionario;

typedef struct {
    char dia[10];
    char data[12];
    char pratoPeixe[MAX_PRATO];
    int calPeixe;
    char pratoCarne[MAX_PRATO];
    int calCarne;
    char pratoDieta[MAX_PRATO];
    int calDieta;
    char pratoVegetariano[MAX_PRATO];
    int calVegetariano;
} Ementa;

typedef struct {
    char dia[10];
    int numeroFuncionario;
    char tipoPrato; // C, P, D ou V
} Escolha;

void carregarFuncionarios(const char* nomeFicheiro, Funcionario funcionarios[], int* total);
void carregarEmenta(const char* nomeFicheiro, Ementa ementas[], int* total);
void carregarEscolhas(const char* nomeFicheiro, Escolha escolhas[], int* total);

#endif