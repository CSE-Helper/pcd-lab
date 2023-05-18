%{
 #include<stdio.h>
 %}
 
 %option noyywrap
 
 %%
 
 [ \t]+ {
  printf(" ");
 }
 
 [ \n]+ {
   printf("\n");
 }
 
 . {
  printf("%s",yytext);
 }
 
 %%
 
 int main(){
  FILE* file = fopen("input.txt","r");
  yyin = file;
  yylex();
  fclose(file);
  return 0;
 }
 