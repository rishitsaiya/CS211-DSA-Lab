#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<limits.h>
#define MAX 200000

int main(){
	
	printf("Enter File Name:");
	char s[20];
	scanf("%s",s);
	
	FILE *f1;
	f1=fopen(s,"r");

	FILE *f2;
	f2=fopen("o1.txt","w");
	
	int c,b,min,max; 
	int count=0,i=0,sum=0;
	char ch;
	float avg;
	
	fscanf(f1,"%d",&b);
	//printf("%d",b);
	fgetc(ch);
	min=b;
	max=b;
		
	while(!feof(f1)){
	fscanf(f1,"%d",&c);
	//printf("%d",c);
	fgetc(ch);
	count++;
	
	if(c<min){
		min=c;
	}
	
	if(c>max){
		max=c;
	}
	
	sum=sum+c;
	}
	
	sum=sum+b-c;
	avg=(float)sum/count;
	
fprintf(f2, "%d\n", count);
fprintf(f2, "%d\n", min);
fprintf(f2, "%d\n", max);
fprintf(f2, "%d\n", sum);
fprintf(f2, "%0.2f\n", avg); 

return 0;	
}
