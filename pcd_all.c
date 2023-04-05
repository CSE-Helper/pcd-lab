[0:38 pm, 05/04/2023] +91 70108 36984: #include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void main()
{
 int i=0,j=0,x=0,n;
 void *p,*add[5];
 char ch,srch,b[15],d[15],c;
 printf("Expression terminated by $:");
 while((c=getchar())!='$')
 {
  b[i]=c;
  i++;
 }
 n=i-1;
 printf("Given Expression:");
 i=0;
 while(i<=n)
 {
  printf("%c",b[i]);
  i++;
 }
 printf("\n Symbol Table\n");
 printf("Symbol \t addr \t type");
 while(j<=n)
 {
  c=b[j];
  if(isalpha(toascii(c)))
  {
   p=malloc(c);
   add[x]=p;
   d[x]=c;
   printf("\n%c \t %d \t identifier\n",c,p);
   x++;
   j++;
  }
  else
  {
   ch=c;
   if(ch=='+'||ch=='-'||ch=='*'||ch=='='||ch==')'||ch=='('||ch==';'||ch=='?')
   {
    p=malloc(ch);
    add[x]=p;
    d[x]=ch;
    printf("\n %c \t %d \t operator\n",ch,p);
    x++;
    j++;
	}
	}
	}
}
[0:38 pm, 05/04/2023] +91 70108 36984: symboltable


4. RECURSIVE  
#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

int E(), EPrime(), T(), TPrime(), F();

const char *cursor;
char string[64];

int main()
{
    puts("Enter the string");
    scanf("%s", string);
    //scanf("id+(id+id)*id", "%s", string);
    cursor = string;
    puts("");
    puts("Input            Action");
    puts("--------------------------------");

    if (E() && *cursor == '\0') {
        puts("--------------------------------");
        puts("String is successfully parsed");
        return 0;
    } else {
        puts("--------------------------------");
        puts("Error in parsing String");
        return 1;
    }
}

int E()
{
    printf("%-16s E  ->  T E'\n", cursor);
    if (T()) {
        if (EPrime())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int EPrime()
{
    if (*cursor == '+') {
        printf("%-16s E' ->  + T E'\n", cursor);
        cursor++;
        if (T()) {
            if (EPrime())
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        printf("%-16s E' ->  $\n", cursor);
        return SUCCESS;
    }
}

int T()
{
    printf("%-16s T  ->  F T'\n", cursor);
    if (F()) {
        if (TPrime())
            return SUCCESS;
        else
            return FAILED;
    } else
        return FAILED;
}

int TPrime()
{
    if (cursor == ' ') {
        printf("%-16s T' ->  * F T'\n", cursor);
        cursor++;
        if (F()) {
            if (TPrime())
                return SUCCESS;
            else
                return FAILED;
        } else
            return FAILED;
    } else {
        printf("%-16s T' ->  $\n", cursor);
        return SUCCESS;
    }
}

int F()
{
    if (*cursor == '(') {
        printf("%-16s F  ->  ( E )\n", cursor);
        cursor++;
        if (E()) {
            if (*cursor == ')') {
                cursor++;
                return SUCCESS;
            } else
                return FAILED;
        } else
            return FAILED;
    } else if (*cursor == 'i') {
        cursor++;
        printf("%-16s F  ->  i\n", cursor);
        return SUCCESS;
    } else
        return FAILED;
}

#include<stdio.h>
#include<string.h>
void main()
{
    char re[20];
    int q[20][3],i,j,len,a,b;
    for(a=0;a<20;a++)
    {
        for(b=0;b<3;b++)
        {
            q[a][b]=0;
        }
    }
    printf("Enter the Regular expression:\n");
    scanf("%s",re);
    len=strlen(re);
    i=0;j=1;
    while(i<len)
    {
        if(re[i]=='a'&&re[i+1]!='/'&&re[i+1]!='*')
        {
            q[j][0]=j+1;j++;
        }
        if(re[i]=='b'&&re[i+1]!='/'&&re[i+1]!='*')
        {
            q[j][1]=j+1;j++;
        }
        if(re[i]=='e'&&re[i+1]!='/'&&re[i+1]!='*')
        {
            q[j][2]=j+1;j++;
        }
        if(re[i]=='a'&& re[i+1]=='/'&&re[i+2]=='b')
        {
            q[j][2]=((j+1)*10)+(j+3);j++;
            q[j][0]=j+1;j++;
            q[j][2]=j+3;j++;
            q[j][2]=j+1;j++;i=i+2;
        }
        if(re[i]=='b'&&re[i+1]=='/'&&re[i+2]=='a')
        {
            q[j][2]=((j+1)*10)+(j+3);j++;
            q[j][1]=j+1;j++;
            q[j][2]=j+3;j++;
            q[j][0]=j+1;j++;
            q[j][2]=j+1;j++;
            i=i+2;
        }
        if(re[i]=='a'&&re[i+1]=='*')
        {
            q[j][2]=((j+1)*10)+(j+3);
            j++;
            q[j][0]=j+1;
            j++;
            q[j][2]=((j+1)*10)+(j-1);
            j++;
        }
        if(re[i]=='b'&&re[i+1]=='*')
        {
            q[j][2]=((j+1)*10)+(j+3);
            j++;
            q[i][j]=j+1;
            j++;
            q[j][2]=((j+1)*10)+(j-1);
            j++;
        }
        if(re[i]==')'&&re[i+1]=='*')
        {
            q[0][2]=((j+1)*10)+1;
            q[j][2]=((j+1)*10)+1;
            j++;
        }
        i++;
    }
    printf("Transition function:\n");
    for(i=0;i<=j;i++)
    {
        if(q[i][0]!=0)
            printf("\n q[%d,a]-->%d",i,q[i][0]);
        if(q[i][1]!=0)
            printf("\n q[%d,b]-->%d",i,q[i][1]);
        if(q[i][2]!=0)
        {
            if(q[i][2]<10)
                printf("\n q[%d,e]-->%d",i,q[i][2]);
            else
                printf("\n q[%d,e]-->%d & %d",i,q[i][2]/10,q[i][2]%10);
        }
    }
}

/*lex program to count number of words*/
%{
#include<stdio.h>
#include<string.h>
int i = 0;
%}
  
/* Rules Section*/
%%
([a-zA-Z0-9])*    {i++;} /* Rule for counting 
                          number of words*/
  
"\n" {printf("%d\n", i); i = 0;}
%%
  
int yywrap(void){}
  
int main()
{   
    // The function that starts the analysis
    yylex();
  
    return 0;




