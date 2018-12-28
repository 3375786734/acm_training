#include <cstdio>
#include <iostream>
#include <unistd.h>
using namespace std;

int svar = 0;

int main()
{
	int lvar = 0;
	svar +=1;
	lvar +=1;
	sleep(10);
	printf("svar address:%x, val %d\n",&svar,svar);
	printf("lvar address:%x, val %d\n",&lvar,lvar);
}
