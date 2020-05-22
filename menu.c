//
// Created by ratob on 13/05/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "menu.h"

int menu(array_char *string, array_char *string2, array_char *string3, array_char *subString){
    char str[20];
    char str1[20];
    char str2[20];
    char subSTR[20];

    string = NULL;
    string2 = NULL;
    string3 = NULL;
    subString = NULL;

    int op;
    int tamanho;

    do {
        system("CLS");
        printf("       * Estrutuda de Dados I *\n");
        printf(">String Dinamica< \n");
        printf("\n1  -> Criar uma string vazia\n");
        printf("2  -> Reiniciar string.\n");
        printf("3  -> Mostrar uma string.\n");
        printf("4  -> Ver o tamanho de uma string.\n");
        printf("5  -> Inserir caracteres na string.\n");
        printf("6  -> Copiar conteudo de uma string para outra\n");
        printf("7  -> Concatenar strings\n");
        printf("8  -> Remover caracteres da string1 a partir de uma posicao X\n");
        printf("9  -> Inserir uma substring na string1, na posicao X\n");
        printf("10 -> Verificar se string1 eh menor q string2\n");
        printf("11 -> Verificar se string1 eh igual string2\n");
        printf("12 -> Verificar se a substring existe na string1, se existir, local sera a posicao de inicio dela. \n");

        printf("0 -> Sair\n");
        printf("\nDigite a sua escolha!\n>: ");
        scanf("%d",&op);
        printf("\n");
        if (op == 1) {
            int opt = 1;
            do{
                system("CLS");
                printf("\n1 -> Criar string1\n");
                printf("2 -> Criar string2\n");
                printf("3 -> Criar string3\n");
                printf("4 -> Criar subString\n");

                printf("0 -> voltar\n");

                printf("\nDigite a sua escolha!\n>: ");
                scanf("%d",&opt);

                if(opt == 1){
                    string = CriarString(string);
                    printf("Lista criada com sucesso!");
                } else if(opt == 2) {
                    string2 = CriarString(string2);
                    printf("Lista criada com sucesso!");
                } else if(opt == 3) {
                    string3 = CriarString(string3);
                    printf("Lista criada com sucesso!");
                } else if(opt == 4) {
                    subString = CriarString(subString);
                    printf("Lista criada com sucesso!");
                } else if (opt == 0){

                } else {
                    printf("Digite uma opcao valida!!\n\n");
                }

            }while(opt != 0);

        } else if (op == 2) {
            int opt = 1;
            do{
                system("CLS");
                printf("\n1 -> Reiniciar string1\n");
                printf("2 -> Reiniciar string2\n");
                printf("3 -> Reiniciar string3\n");
                printf("4 -> Reiniciar subString\n");

                printf("0 -> voltar\n");

                printf("\nDigite a sua escolha!\n>: ");
                scanf("%d",&opt);

                if(opt == 1){
                    ReiniciaAString(string);
                    printf("Lista reniciada com sucesso!\n\nLembrando que eh necessario criar a string reniciada de novo!!\n");
                } else if(opt == 2) {
                    ReiniciaAString(string2);
                    printf("Lista reniciada com sucesso!\n\nLembrando que eh necessario criar a string reniciada de novo!!\n");
                } else if(opt == 3) {
                    ReiniciaAString(string3);
                    printf("Lista reniciada com sucesso!\n\nLembrando que eh necessario criar a string reniciada de novo!!\n");
                } else if(opt == 4) {
                    ReiniciaAString(subString);
                    printf("Lista reniciada com sucesso!\n\nLembrando que eh necessario criar a string reniciada de novo!!\n");
                } else if (opt == 0){

                } else {
                    printf("Digite uma opcao valida!!\n\n");
                }

            }while(opt != 0);
        }else if (op == 3) {
            int opt = 1;
            do{
                system("CLS");
                printf("\n1 -> Mostrar string1\n");
                printf("2 -> Mostrar string2\n");
                printf("3 -> Mostrar string3\n");
                printf("4 -> Mostrar subString\n");

                printf("0 -> voltar\n");

                printf("\nDigite a sua escolha!\n>: ");
                scanf("%d",&opt);

                if(opt == 1){
                    MostrarString(string);
                } else if(opt == 2) {
                    MostrarString(string2);
                } else if(opt == 3) {
                    MostrarString(string3);
                } else if(opt == 4) {
                    MostrarString(subString);
                } else if (opt == 0){

                } else {
                    printf("Digite uma opcao valida!!\n\n");
                }

            }while(opt != 0);
        }else if (op == 4) {
            int opt = 1;
            do{
                system("CLS");
                printf("\n1 -> Mostrar o tamanho string1\n");
                printf("2 -> Mostrar o tamanho string2\n");
                printf("3 -> Mostrar o tamanho string3\n");
                printf("4 -> Mostrar o tamanho subString\n");

                printf("0 -> voltar\n");

                printf("\nDigite a sua escolha!\n>: ");
                scanf("%d",&opt);

                if(opt == 1){
                    tamanho = TamanhoDaString(string);
                    printf("O tamanho da string selecionda eh: %d", tamanho);
                } else if(opt == 2) {
                    tamanho = TamanhoDaString(string2);
                    printf("O tamanho da string selecionda eh: %d", tamanho);
                } else if(opt == 3) {
                    tamanho = TamanhoDaString(string3);
                    printf("O tamanho da string selecionda eh: %d", tamanho);
                } else if(opt == 4) {
                    tamanho = TamanhoDaString(subString);
                    printf("O tamanho da string selecionda eh: %d", tamanho);
                } else if (opt == 0){

                } else {
                    printf("Digite uma opcao valida!!\n\n");
                }

            }while(opt != 0);
        }else if (op == 5) {
            int tamanhoStr = 0;
            int i = 0;
            int opt;

            do{
                system("CLS");
                printf("\n1 -> Escrever string1\n");
                printf("2 -> Escrever string2\n");
                printf("3 -> Escrever string3\n");
                printf("4 -> Escrever subString\n");

                printf("0 -> voltar\n");

                printf("\nDigite a sua escolha!\n>: ");
                scanf("%d",&opt);

                if(opt == 1){
                    printf("Digite a string abaixo:");
                    scanf("%s",str);
                    tamanhoStr = strlen(str);

                    for(i = 0; i < tamanhoStr; i++) {
                        InserirNaString(string,str[i]);
                    }
                } else if(opt == 2) {
                    printf("Digite a string abaixo:");
                    scanf("%s",str);
                    tamanhoStr = strlen(str);

                    for(i = 0; i < tamanhoStr; i++) {
                        InserirNaString(string2,str[i]);
                    }
                } else if(opt == 3) {
                    printf("Digite a string abaixo:");
                    scanf("%s",str);
                    tamanhoStr = strlen(str);

                    for(i = 0; i < tamanhoStr; i++) {
                        InserirNaString(string3,str[i]);
                    }
                } else if(opt == 4) {
                    printf("Digite a string abaixo:");
                    scanf("%s",str);
                    tamanhoStr = strlen(str);

                    for(i = 0; i < tamanhoStr; i++) {
                        InserirNaString(subString,str[i]);
                    }
                } else if (opt == 0){

                } else {
                    printf("Digite uma opcao valida!!\n\n");
                }

            }while(opt);
        }else if (op == 6) {
            printf("Copiando o conteudo de string1 para string2\n");
            CopiarDeStringParaString(string,string2);
            MostrarString(string);


        }else if (op == 7) {
            printf("Concatenando o conteudo de string1 com string2 para string3\n");
            ConcatenarString(string,string2,string3);
            MostrarString(string3);


        }else if (op == 8) {
            int start = 0, quant = 0;

            printf("Digite a quantidade caracteres e a posicao q eles serao deletados: \n");
            scanf("%d %d", &start,&quant);

            DeletarCharNaPosicao(start,quant,&string);

        }else if (op == 9) {
            int start = 0;

            printf("Inserindo substring em string1.\n");
            printf("!! Atencao, se string e substring nao estiver escritas, ocorrera um erro fatal !!");

            printf("Digite a posicao onde sera inserida a substring:\n>: ");
            scanf("%d", &start);

            InserirSubString(start,string,subString);
            MostrarString(string);


        }else if (op == 10) {
            printf("Comparando tamanho de String1 com String2\n");

            if(CompararTamanhoDasStrings(string,string2) == true)
                printf("String1 eh menor que String2\n");
            else
                printf("String1 nao eh menor que String2\n");

        }else if (op == 11) {
            printf("Comparando conteudo de String1 com String2\n");

            if(CompararConteudoStrings(string,string2) == true)
                printf("String1 eh igual a que String2\n");
            else
                printf("String1 nao igual a String2\n");

        }else if (op == 12) {
            int resultado = 0;

            printf("Verificando se local representa a posicao onde a substring comeca dentr da string1\n");
            printf("Se local == 0, substring nao existe dentro da string\n");
            printf("Se o local retornar um numero diferente de 1, esse numero eh a posicao q a substring comeca em string1\n\n");

            resultado = ProcurarPosLocalString(string,subString);
            printf("Local = %d,",resultado);


        } else if (op == 0){
            system("CLS");
            printf("Saindo do programa. . .\n");

        } else {
            printf("Digite uma opcao valica!!!");
        }
        printf("\n");
        system("pause");
    }while(op != 0);

    return 0;
}
