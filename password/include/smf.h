#ifndef __SMF_H__
#define __SMF_H__
/*****************************************************
 * 
 * ***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include <dirent.h>

//#include <conio.h>
/*****************************************************
 * 
 * ***************************************************/
#define NAME_LEN 128
#define PASS_LEN 33

typedef struct Pass Pass;
typedef struct Node Node;

struct Pass
{
    int type;
    char name[NAME_LEN];
    char password[PASS_LEN];
    int len;
    Pass *pnext;
};

struct Node
{
    Pass *pass;
    Node *pleft;
    Node *pright;
};

/*****************************************************
 * str.c
 * ***************************************************/
int inputi(char *infor);
int inputstr(char *infor, char *str, int n);
int inputpass(char *pass, int len, int type);
int rstr(char *buff, FILE *fp);
int delch(char *pstr, char ch);
int delch2(char *pstr);
/*****************************************************
 * lib.c
 * ***************************************************/
FILE *rfile(char *filename);
FILE *wfile(char *filename);
Pass *callpass(int n);
void freepass(Pass *phead);
Node *callnode(int n);
/*****************************************************
 * argv.c
 * ***************************************************/
int argvname(int argc, char *argv[], char *name, int *pi, char *infor);
int argvnames(int argc, char *argv[], char *name, int *pi, char *infor);
int argvpass(int argc, char *argv[], char *pass, int create_len, int pass_type, int *pi);
int argvi(int argc, char *argv[], int *pnum, int *pi, char *infor);
int argvis(int argc, char *argv[], int *pnum, int *pi);
/*****************************************************
 * deal.c
 * ***************************************************/
Pass *initpass();
int display(Pass *phead, int n);
int displaytype(Pass *phead, int n, int type);
int editpass(Pass *phead, char *name);
Pass *findpass(Pass *phead, char *name);
int delpass(Pass *phead, char *name);
int addpass(Pass *phead, Pass *pbody);
Pass *inputpassn(int n);
int wpass(char *filename, Pass *phead);
Pass *rpass(char *filename);
int nexists(Pass *phead, char *name);
int createpass(char *buff, int len, int type);
/*****************************************************
 * pass.c
 * ***************************************************/
int encrypt(char *buff, char *pass, int n);
int dncrypt(char *buff, char *pass, int n);
int chtob(char *buff, char *name, int n);
int btoch(char *buff, char *name, int n);
/*****************************************************
 * sort.c
 * ***************************************************/
void sort(char *filename);
/*****************************************************
 * app.c
 * ***************************************************/
int import(char *filename1, char *filename2);
int add(char *filename, int type, int len, char *name, char *pass);
int del(char *filename, char *name);
int find(char *filename, char *name, int n);
int show(char *filename, int n, int type, int type_mark);
/*****************************************************
 * 
 * ***************************************************/
void backup(char *filename, char *dir);
int initdir(char *dir);

#endif