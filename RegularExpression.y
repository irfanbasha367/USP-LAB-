%{
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int getREindex(const char*);
signed char production[MAX][MAX];
char temp[MAX+MAX],temp2[MAX+MAX];
int count=0,i,j;
%}

%token ALPHABET
%left '|'
%left '.'
%nonassoc '*''+'
%%
S:re'\n'{printf("This is right-most derivation\n");
	for(i=count-1;i>=0;--i)
	{
		if(i==count-1)
		{
			printf("\nre=>");
			strcpy(temp,production[i]);
			printf("%s\n",production[i]);
		}
		else
		{
			printf("\n=>");
			j=getREindex(temp);
			temp[j]='\0';
			sprintf(temp2,"%s%s%s",temp,production[i],(temp+j+2));
			printf("%s",temp2);
			strcpy(temp,temp2);
		}
	}
	printf("\n");
	exit(0);
	}
re:ALPHABET {temp[0]=yylval;temp[1]='\0';
	strcpy(production[count++],temp);}
  |'('re')' {strcpy(production[count++],"(re)");}
  |re'*' {strcpy(production[count++],"re*");}
  |re'+' {strcpy(production[count++],"re+");}
  |re'|'re {strcpy(production[count++],"re|re");}
  |re'.'re {strcpy(production[count++],"re.re");}
  ;
%%
int main(int argc,char **argv)
{
	printf("Plz enter RE\n");
	yyparse();
	return 0;
}
yylex()
{
	signed char ch=getchar();yylval=ch;
	if(isalpha(ch))return ALPHABET;
	return ch;
}
yyerror()
{
	fprintf(stderr,"Invalid RE");
	return -1;
}
int getREindex(const char *str)
{	
	int i=strlen(str)-1;
	for(;i>=0;--i)
	{
		if(str[i]=='e'&&str[i-1]=='r')
			return i-1;
	}
}
