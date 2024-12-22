// utils.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
void carregarFuncionarios(const char* nomeFicheiro, Funcionario funcionarios[], int* total) {
    FILE* file = fopen(nomeFicheiro, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    char linha[200];
    *total = 0;
    while (fgets(linha, sizeof(linha), file)) {
        scanf(linha, "%d;%[^;];%[^;];%s", &funcionarios[*total].numero, funcionarios[*total].nome, funcionarios[*total].nif, funcionarios[*total].telefone);
        (*total)++;
    }

    fclose(file);
}

void carregarEmenta(const char* nomeFicheiro, Ementa ementas[], int* total) {
    FILE* file = fopen(nomeFicheiro, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    char linha[300];
    *total = 0;
    while (fgets(linha, sizeof(linha), file)) {
        scanf(linha, "%[^;];%[^;];%[^;];%d;%[^;];%d;%[^;];%d;%[^;];%d",
            ementas[*total].dia, ementas[*total].data,
            ementas[*total].pratoPeixe, &ementas[*total].calPeixe,
            ementas[*total].pratoCarne, &ementas[*total].calCarne,
            ementas[*total].pratoDieta, &ementas[*total].calDieta,
            ementas[*total].pratoVegetariano, &ementas[*total].calVegetariano);
        (*total)++;
    }

    fclose(file);
}

void carregarEscolhas(const char* nomeFicheiro, Escolha escolhas[], int* total) {
    FILE* file = fopen(nomeFicheiro, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    char linha[100];
    *total = 0;
    while (fgets(linha, sizeof(linha), file)) {
        scanf(linha, "%[^;];%d;%c", escolhas[*total].dia, &escolhas[*total].numeroFuncionario, &escolhas[*total].tipoPrato);
        (*total)++;
    }

    fclose(file);
}
