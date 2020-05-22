#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "menu.h"

// Inicia a string selecionada
array_char *CriarString(array_char *string){
    string = (array_char*)malloc(sizeof(array_char));
    string->first_char = NULL;
    string->last_char = NULL;

    return string;
}

// Renicia a string, deletando seus blocos de memória, mas sem deletar a string em si.
void ReiniciaAString(array_char *string){
    char_node *auxNode = string->first_char;
    char_node *auxRemove = (char_node*)malloc(sizeof(char_node));

    if(string->first_char == NULL){
        printf("\n>String dinamica esta vazia.\n");
    } else {
        while(auxNode != NULL){
            auxRemove = auxNode->next;
            free(auxNode);
            auxNode = auxRemove;
            string->first_char = auxNode;
        }
        string->last_char = NULL;
    }
}

// Adiciona caracteres para formar uma string.
void InserirNaString(array_char *string, char c){
    char_node *newNode = (char_node*)malloc(sizeof(char_node));

    if(string->first_char == NULL) {
        newNode->caractere = c;
        newNode->next = NULL;


        string->first_char = string->last_char = newNode;
    } else {
        newNode->caractere = c;
        newNode->next = NULL;

        string->last_char->next = newNode;
        string->last_char = newNode;
    }
}

// Copia de uma string para a outra.
void CopiarDeStringParaString(array_char *string1, array_char *string2){
    char_node *auxNode;
    if(string1->first_char == NULL){
        printf("\n>String dinamica nao iniciada.\n");
    } else {
        for(auxNode = string1->first_char; auxNode != NULL; auxNode = auxNode->next)
            InserirNaString(string2,auxNode->caractere);
    }
}

// Concatena 2 strings para uma nova.
void ConcatenarString(array_char *string1, array_char *string2, array_char *destino){
    char_node *auxNode = string1->first_char;

    if(string1->first_char == NULL || string2->first_char == NULL){
        printf("\n>String dinamica nao iniciada.\n");
    } else {

        array_char *localString = NULL;
        localString = CriarString(localString);

        CopiarDeStringParaString(string1,localString);
        CopiarDeStringParaString(string2,localString);
        CopiarDeStringParaString(localString,destino);

        free(localString);
    }

}

// Deleta conteudo da string de uma determinada posicao definida pelo start e uma quantidade.
void DeletarCharNaPosicao(int start, int quantidade, array_char **string){
    char_node *auxNode;
    char_node *nodeDeletado = (char_node *) malloc(sizeof(char_node));
    char_node *temporario = (char_node *) malloc(sizeof(char_node));
    char_node *anterior = (char_node *) malloc(sizeof(char_node));

    int i = 0;
    int j = 0;

    temporario = (*string)->first_char;

    if (temporario == NULL) {
        printf("* Nao foi possivel deletar caracteres, pois a string esta vazia!!! *\n");
    } else {
        if (start == 0) {
            auxNode = (*string)->first_char;

            while (i < quantidade) {
                //printf("j: %d\n", j);
                temporario = temporario->next;
                i++;
            }
            auxNode = temporario;
            (*string)->first_char = auxNode;

        } else {

            while(temporario->next != NULL){
                temporario = temporario->next;
                i++;
                if(i == start){
                    auxNode = temporario;
                    while(j < quantidade){
                        nodeDeletado = auxNode->next;
                        auxNode->next = nodeDeletado->next;
                        free(nodeDeletado);
                        j++;
                        temporario = auxNode;
                    }
                }
            }

            if (temporario == NULL) {
                (*string)->last_char = anterior;
            } else {
                anterior->next = temporario;
            }
        }
    }
}

// Inserir uma substring dentro de uma string.
array_char *InserirSubString(int start, array_char *string, array_char *subString){
    int i = 0;

    char_node *nextChar;
    char_node *temp;
    char_node *lastSubsTringNode;
    char_node *firstSubsTringNode = subString->first_char;

    array_char *localSubstring = NULL;
    localSubstring = CriarString(localSubstring);

    while(firstSubsTringNode != NULL){
        InserirNaString(localSubstring,firstSubsTringNode->caractere);
        firstSubsTringNode = firstSubsTringNode->next;
    }

    firstSubsTringNode = localSubstring->first_char;
    lastSubsTringNode = localSubstring->last_char;

    /*
    char_node *lastSubsTringNode = (char_node*)malloc(sizeof(char_node));
     lastSubstringNode->caractere = subString->last_char->caractere;
     lastSubstringNode->next = NULL;
     */

    if(string->first_char == NULL)
        CopiarDeStringParaString(subString,string);
    else if(start == TamanhoDaString((string))){
        ConcatenarString(string,subString,string);
    } else {
        for(temp = string->first_char; temp != NULL; temp = temp->next) {
            if(i == start) {
                nextChar = temp->next;
                temp->next = firstSubsTringNode;
                lastSubsTringNode->next = nextChar;

                //temporario->next = subString->first_char;
                //subString->last_char->next = anterior;
            }
            i++;
        }
        free(localSubstring);
        return string;
    }
    return NULL;
}

// Retorna o tamanho da string.
int TamanhoDaString(array_char *string){
    int stringSize = 0;

    if(string->first_char == NULL){
        printf("\n>String dinamica nao iniciada ou esta vazia.\n");
    } else {
        char_node *auxNode = string->first_char;

        if(string->first_char != NULL) {
            while(auxNode != NULL){
                stringSize++;
                auxNode = auxNode->next;
            }
        } else {
            printf("** String nao iniciada **\n");
        }

        return stringSize;
    }

    return -1;

}

// Retorna um valor verdade ou falso ao comparar o tamanho das strings.
bool CompararTamanhoDasStrings(array_char *string1, array_char *string2){
    int string1Size = TamanhoDaString(string1);
    int string2Size = TamanhoDaString(string2);

    if(string1Size < string2Size)
        return true;
    else
        return false;
}

// Retorna um valor verdade se o conteudo for igual e falso e nao for.
bool CompararConteudoStrings(array_char *string1,array_char *string2){
    char_node *auxNodeString1 = string1->first_char;
    char_node *auxNodeString2 = string2->first_char;

    int tam;
    int i = 0;
    bool flag = false;

    if(string1->first_char == NULL && string2->first_char == NULL){
        printf("\n>String dinamica nao iniciada ou esta vazia.\n");
    } else {
        if(CompararTamanhoDasStrings(string1,string2)){
            tam =  TamanhoDaString(string2);
        } else
            tam =  TamanhoDaString(string1);

        int value[tam];

        for(i = 0; i < tam; i++){
            value[i] = 0;
        }

        i = 0;

        while((auxNodeString1 != NULL) && (auxNodeString2 != NULL)){
            if(auxNodeString1->caractere == auxNodeString2->caractere){
                value[i] = 1;
            } else {
                value[i] = 0;
            }
            auxNodeString1 = auxNodeString1->next;
            auxNodeString2 = auxNodeString2->next;
            i++;
        }

        for(i = 0; i < tam; i++){
            if(value[i] == 1){
                flag = true;
            } else{
                flag = false;
                break;
            }
        }
    }

    return flag;
}

// Procura a posicao aonde a substring se inicia na string, se ela nao iniciar, eh pq a substring n existe.
int ProcurarPosLocalString(array_char *string1, array_char *stringLocal){
    int local = 0;

    char_node *temporarioString1 = string1->first_char;
    char_node *temporarioString2 = stringLocal->first_char;
    char_node *temporarioStringLocal = stringLocal->first_char;

    if(temporarioString1 == NULL || stringLocal->first_char == NULL){
        printf("** String nao iniciada ou vazia, erro**");
        return -1;
    } else if(CompararTamanhoDasStrings(string1,stringLocal) == true) {
        printf("String pedida é maior que a string local.\n");
        return -1;
    } else if(CompararTamanhoDasStrings(string1,stringLocal) == false){
        for(; temporarioString1 != NULL; temporarioString1 = temporarioString1->next){
            local++;
            temporarioString2 = temporarioString1;

            for(temporarioStringLocal = stringLocal->first_char; temporarioStringLocal != NULL; temporarioStringLocal = temporarioStringLocal->next){
                    if(temporarioString2->caractere  == temporarioStringLocal->caractere){
                        printf("%c == %c\n",temporarioStringLocal->caractere,temporarioString2->caractere);
                        temporarioString2 = temporarioString2->next;
                    } else {
                        break;
                    }
            }

            if(temporarioStringLocal == NULL)
                return local;

        }
    }

    return 0;
}

// Mostra a string.
void MostrarString(array_char *string) {
    char_node *auxNode = string->first_char;
    if(auxNode == NULL){
        printf("* String dinamica nao foi inicializada ou esta vazia! *\n");
    } else {
        while(auxNode != NULL) {
            printf("%c",auxNode->caractere);
            auxNode = auxNode->next;
        }
    }
}

// Function criada quando o programa precisava ser testado para funcionar antes do menu.
int __InitApp__(){

    printf("       * Estrutuda de Dados I *\n");
    printf(">String Dinamica< \n");

    array_char *string = NULL;
    array_char *string2 = NULL;
    array_char *string3 = NULL;
    array_char *stringsub = NULL;

    string = CriarString(string);
    string2 = CriarString(string2);
    string3 = CriarString(string3);

    InserirNaString(string, 'c');
    InserirNaString(string, 'a');
    InserirNaString(string, 's');
    InserirNaString(string, 'a');
    //InserirNaString(string, '\n');

    InserirNaString(string2, 'a');
    InserirNaString(string2, 'b');
    InserirNaString(string2, 'a');
    InserirNaString(string2, 'c');
    InserirNaString(string2, 'a');
    InserirNaString(string2, 't');
    InserirNaString(string2, 'e');
    //InserirNaString(string2, '\n');

    printf("Antes de copiar:\n");

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("String3: ");
    MostrarString(string3);
    printf("\n");

    CopiarDeStringParaString(string,string2);

    printf("Depois de copiar:\n");

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("String3: ");
    MostrarString(string3);
    printf("\n");

    int tam = TamanhoDaString(string2);
    printf("\nTamanho da string2 eh: %d\n\n",tam);

    printf("Reiniciando string\n");
    ReiniciaAString(string);

    InserirNaString(string, 'a');
    InserirNaString(string, 'n');
    InserirNaString(string, 'a');
    InserirNaString(string, 'l');
    InserirNaString(string, 'u');

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("String3: ");
    MostrarString(string3);
    printf("\n");

    printf("Fim Reiniciando string\n");

    printf("\nConcatenando strings:\n");
    ConcatenarString(string,string2,string3);

    fflush(stdin);
    printf("\n");
    fflush(stdin);

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("String3: ");
    MostrarString(string3);
    printf("\n");

    printf("\nFim Concatenando strings:\n");

    printf("\nDeletando elementos:\n");
    DeletarCharNaPosicao(0,2, &string3);
    DeletarCharNaPosicao(3,1, &string3);

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("String3: ");
    MostrarString(string3);
    printf("\n");

    printf("\n >Deletado elementos da string 3.\n");

    printf("\nFim Deletando elementos:\n");

    printf("\nComparando conteudo das strings!\n");
    ReiniciaAString(string);
    ReiniciaAString(string2);

    InserirNaString(string, 'f');
    InserirNaString(string, 'a');

    InserirNaString(string2, 'f');
    InserirNaString(string2, 'a');

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    if(CompararConteudoStrings(string, string2)){
        printf("Eh igual\n");
    } else {
        printf("Nao eh igual\n");
    }

    printf("\nFim Comparando conteudo das strings!\n");

    printf("\nInserir substring na string!\n");

    InserirNaString(string, 'z');
    InserirNaString(string2, 's');
    InserirNaString(string2, 'e');

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    string = InserirSubString(1,string,string2);

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("\nFim Inserir substring na string!\n");

    ReiniciaAString(string);
    ReiniciaAString(string2);
    ReiniciaAString(string3);


    InserirNaString(string,'a');
    InserirNaString(string,'l');
    InserirNaString(string,'g');
    InserirNaString(string,'o');
    InserirNaString(string,'r');
    InserirNaString(string,'i');
    InserirNaString(string,'t');
    InserirNaString(string,'m');
    InserirNaString(string,'o');

    InserirNaString(string2,'r');
    InserirNaString(string2,'i');
    InserirNaString(string2,'t');
    InserirNaString(string2,'m');
    InserirNaString(string2,'o');

    printf("\n");

    printf("String: ");
    MostrarString(string);
    printf("\n");

    printf("String2: ");
    MostrarString(string2);
    printf("\n");

    printf("String3: ");
    MostrarString(string3);
    printf("\n");

    printf("Local: %d\n",ProcurarPosLocalString(string, string2));

    printf("\n* FIM DO PROGRAMA *\n");
    system("pause");

    return 0;
}

int main() {
    array_char *string = NULL;
    array_char *string2 = NULL;
    array_char *string3 = NULL;
    array_char *stringsub = NULL;

    //__InitApp__();
    menu(string, string2, string3, stringsub);
    return 0;
}