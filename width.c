#include <stdio.h>

#define LIMITL 256
#define TRUE 1
#define START 1
#define GOAL 999

struct node {
	int nodeid;
	int parentid;
};

struct node openlist[LIMITL];
int openlistep = 0;
struct node closedlist[LIMITL];
int closedlistep = 0;

void initlist();
void printlist();
void expand(int id);
void movetofirst();
void removefirst();
int check(int id);
// as name , it show track from startpoint to goal
void printroute(int id);

int main(void) {
	initlist();
	printlist();
	while(TRUE) {
		if(openlistep == 0) {
			printf("Can't find goal node\n");
			break;
		}
		if(openlist[0].nodeid == GOAL) {
			printf("\nI found The node you want\n");
			printf("%d[%d]", openlist[0].nodeid, openlist[0].parentid);
			printroute(openlist[0].parentid);
			break;
		}
		expand(openlist[0].nodeid);
		movetofirst();
		printlist();
	}
	return 0;
}

void printroute(int id) {
	int i;
	for (i=0; i < closedlistep; ++i)
		if(closedlist[i].nodeid == id) {
			printf("<-%d[%d]", closedlist[i].nodeid, closedlist[i].parentid);
			break;
		}
		if(closedlist[i].parentid!=0)
			printroute(closedlist[i].parentid);
		printf("\n");
		
}
int check(int id) {
	int i;
	int res = 0;
	
	for(i=0;i<openlistep;++i) 
		if(openlist[i].nodeid == id)
			res = TRUE;
	for(i=0;i<closedlistep;++i)
		if(closedlist[i].nodeid == id)
			res = TRUE;
	return res;
}
void removefirst() {
	int i;
	for(i=0;i<openlistep;++i)
		openlist[i] = openlist[i+1];
		--openlistep;
}
void movetofirst() {
	closedlist[closedlistep++] = openlist[0];
	removefirst();
}
void expand(int id) {
	int tree[][5] = {
		{1, 2, 3, 5},
		{2, 4},
		{3, 6, 7},
		{5, 4, 7, 8},
		{6, 5,7},
		{8, 7, 999},
		{0}
	};
	int i = 0;
	int j;
	
	while(tree[i][0]!=0) {
		if(tree[i][0] == id) {
			for(j=1; tree[i][j] !=0;++j) {
				if(check(tree[i][j])!=TRUE) {
					openlist[openlistep].nodeid= tree[i][j];
					openlist[openlistep++].parentid = id;
				}
			}
			break;
		}
		++i;
	}
}
void initlist() {
	openlist[0].nodeid = START;
	openlist[0].parentid = 0;
	++openlistep;
}
void printlist() {
	int i;
	printf("\nOpenList ");
	for(i=0;i<openlistep;++i)
		printf("%d[%d],", openlist[i].nodeid, openlist[i].parentid);
	printf("\n");
		printf("\nClosedList ");
	for(i=0;i<closedlistep;++i)
		printf("%d[%d],", closedlist[i].nodeid, closedlist[i].parentid);
	printf("\n");
}
