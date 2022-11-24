#include<stdio.h>
#include<string.h>
#include<conio.h>

void fact( char s[] )
	{
	printf("F ->%s\n",s);
	}

void term( char s[] )
	{
	char temp[100],temp1[100];
	int len,c,i,j,k;
	len = strlen(s);
	c = 0;

	for( i = len-1; i >= 0; i-- )
		{
		if( s[i] == '*'|| s[i] == '/' )
		break;
		}

	if( i >= 0 )
		{
		for( j = 0; j < i; j++ )
			{
			temp[j] = s[j];
			}
		temp[j] = NULL;
		for( j = i +1,k=0; j < len; j++,k++ )
		temp1[k] = s[j];
		temp1[k] = NULL;
		printf("T -> T %c F\n",s[i]);
		term(temp);
		fact(temp1);
		}
	else
		{
		printf("T -> F\n");
		fact(s);
		}
	}

void expr( char s[] )
	{
	char temp[100],temp1[100];
	int len,c,i,j,k;
	len = strlen(s);
	c = 0;
	for( i = len-1; i >= 0; i-- )
		{
		if( s[i] == '+'|| s[i] == '-' )
		break;
		}
	if( i >= 0 )
		{
		for( j = 0; j < i; j++ )
			{
			temp[j] = s[j];
			}
		temp[j] = NULL;
		for( j = i +1,k=0; j < len; j++,k++ )
		temp1[k] = s[j];
		temp1[k] = NULL;
		printf("E -> E %c T\n",s[i]);
		expr(temp);
		term(temp1);
		}
	else
		{
		printf("E -> T\n");
		term(s);
		}
	}

int main( void )
	{
	char s[100];
	int i;
	freopen("in.txt","r",stdin);
	clrscr();
	while(gets(s))
		{
		puts(s);
		expr(s);
		}
	return 0;