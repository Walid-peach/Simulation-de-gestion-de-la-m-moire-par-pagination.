#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>

//*********************** Declaration des structures ************************//
typedef struct Programme {
    char Name[100];
	int Size;
	struct Programme* suivant;
}Prog;

typedef struct Pages {
	int num;
	struct Pages * suivant;
	Prog * ProgMemoire;
}Page;

#endif // HEADER_H_INCLUDED
