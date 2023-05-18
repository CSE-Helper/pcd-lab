%{
 #include <stdio.h>
 %}
 
 %%
 
 [aeiouAEIOU]  printf("%c is a vowel.\n", yytext[0]);
 [a-zA-Z]    printf("%c is a consonant.\n", yytext[0]);
 .        printf("Invalid input.\n");
 
 %%
 
 int yywrap() {
   return 1;
 }
 
 int main() {
   yylex();
   return 0;
 }