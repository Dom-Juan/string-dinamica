//
// Created by ratob on 13/05/2020.
//

#ifndef STRING_DINAMICA_MAINHEADER_H
#define STRING_DINAMICA_MAINHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    char caractere;
    struct node *next;
}char_node;

typedef struct arrayOfCharacter{
    struct node *first_char;
    struct node *last_char;
}array_char;

array_char *CriarString(array_char *string);

void ReiniciaAString(array_char *string);
void InserirNaString(array_char *string, char c);
void CopiarDeStringParaString(array_char *string1, array_char *string2);
void ConcatenarString(array_char *string1, array_char *string2, array_char *destino);
void DeletarCharNaPosicao(int start, int quantidade, array_char **string);
array_char *InserirSubString(int start, array_char *string, array_char *subString);
int TamanhoDaString(array_char *string);
bool CompararTamanhoDasStrings(array_char *string1, array_char *string2);
bool CompararConteudoStrings(array_char *string1,array_char *string2);
int ProcurarPosLocalString(array_char *string1, array_char *stringLocal);
void MostrarLista(array_char *string);

#endif //STRING_DINAMICA_MAINHEADER_H
