#include <stdio.h>

#define LIMITL 256
#define TRUE 1
#define FALSE 0

void eval(double data, double olddata);

int main(void) 
{
	char linebuf[LIMITL];
	double data;
	double olddata=0.0;
	int firstdata=TRUE;

	while(fgets(linebuf, LIMITL, stdin) != NULL) {
		if(sscanf(linebuf, "%lf", &data) <= 0)
			break;
		if(firstdata == TRUE) firstdata = FALSE;
		else eval(data, olddata);
		olddata=data;
	}
	return 0;
}

void eval(double data, double olddata)
{
	if(data<olddata)
		printf("RedVelvet Rank UP !!\n");
	else if(data=olddata)
		printf("The Velvet remaining rank\n");
	else
		printf("We hava to streaming melon\n");
}
