#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<limits.h>
#define MAX 200000

int main(int argc, char **argv){
	
	scanf("%s",argv[1]);
	FILE *f1;
	f1=fopen(argv[1],"r");

	FILE *f2;
	f2=fopen("o1.txt","w");
	
	int c[MAX],count=0,char ch;
	for(int i=0;;i++){
	fscanf(f1,"%d",&c[i]);
	while(!feof(f1)){
	fscanf(f1,"%d",&c[i]);
	fgetc(ch);
	count++;
	}
	}
	
	int min=INT_MAX  ;
	for(int i=0;i<count;i++){
		if(c[i]<INT_MAX){
			min=INT_MAX;
		}
	}

	int max=0;
	for(int i=0;i<count;i++){
	if (c[i] > max){
	max=c[i];	
	}
}
	
	int sum=0;
	for(int i=0;i<count;i++){
		sum=sum+c[i];
	}
	
	float avg;
	avg=sum/count;

fprintf(f2, "%d\n", count);
fprintf(f2, "%d\n", min);
fprintf(f2, "%d\n", max);
fprintf(f2, "%d\n", sum);
fprintf(f2, "%0.2f\n", avg); 

//printf("%d\n",count);
return 0;	
}
