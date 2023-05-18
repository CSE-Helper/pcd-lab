%{
 #include <stdio.h>
 int printfCount = 0;
 int scanfCount = 0;
 %}
 
 %option noyywrap
 
 %%
 printf  { printfCount++; printf("write"); }
 scanf  { scanfCount++; printf("read"); }
 int    { printf("Keyword: %s\n", yytext); }
 [a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier: %s\n", yytext); }
 .      { printf("Symbol: %s\n", yytext); }
 %%
 
 int main() {
   yyin = fopen("input.txt", "r");
   yylex();
   fclose(yyin);
 
   printf("\nNumber of printf statements: %d\n", printfCount);
   printf("Number of scanf statements: %d\n", scanfCount);
 
   return 0;
 }