#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char a[]);
void roman(int x,char a[],int i);
char values[4][3] = {{'I','V','X'},{'X','L','C'},{'C','D','M'},{'C'}};
int main()
{
	// clrscr();
	char final[20] = {'\0'};
	int num,x,i=0;
	printf("Enter the number, to convert to Roman Numerals:");
	scanf("%d",&num);
	if (num>5399)
		num=0;
	while(num)
	{
		x = num%10;
		num /=10;
		roman(x,final,i);
		i++;
	}
	reverse(final);
	printf("%c", &final);
	//getch();
	return 1;
}

void roman(int x, char final[],int i)
{
	int j=0,k=0,flag=0;
	while (final[j]!='\0')
		j++;
	if(x<4)
	{
		for (k=0; k<4; (x<9) )
		{
			k=x-5;
			final[j++]=values[i][1];
			while (k)
			{
				final[j++]=values[i][0];
				k--;
			}
			flag=1;
		}
          }
	  else if (x==9) {
	     final[j++]=values[i][0];
	     final[j++]=values[i+1][0];
		flag=1;
	}

	if(flag)
	  final[j++]='\0';
	
}

void reverse(char string[])
{
		int j=0,k=0;
		char temp[50];
		while(string[j])
			j++;
		while(j)
			temp[--j]=string[k++];
		temp[k]='\0';
		strcpy(string,temp);
}

