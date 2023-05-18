%{
 #include <stdio.h>
 #include <stdlib.h>
 %}
 
 %token NUM
 
 %%
 
 S: E { printf("Result: %d\n", $1); }
  ;
 
 E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { $$ = $1 / $3; }
 | '(' E ')' { $$ = $2; }
 | NUM { $$ = $1; }
  ;
 
 %%
 
 int yylex() {
   int c = getchar();
   if (isdigit(c)) {
     ungetc(c, stdin);
     scanf("%d", &yylval);
     return NUM;
   }
   return c;
 }
 
 int yyerror(char *msg) {
 
   exit(1);
 }
 
 int main() {
   yyparse();
   return 0;
 }