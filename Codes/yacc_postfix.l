%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 %}

 %token NUM

 %left '+' '-'
 %left '*' '/'
 %right NEGATIVE


 %%

 S: E { printf("\n"); }
  ;

 E: E '+' E { printf("+"); }
 | E '' E { printf(""); }
 | E '-' E { printf("-"); }
 | E '/' E { printf("/"); }
 | '(' E ')' { printf("("); printf(")"); }
 | '-' E %prec NEGATIVE { printf("-"); }
 | NUM { printf("%d", $1); };

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