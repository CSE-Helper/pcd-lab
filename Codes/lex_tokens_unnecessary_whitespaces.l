%{
 #include <stdio.h>
 #include <string.h>
 %}
 
 %option noyywrap
 
 %{
 // Function to print token and its type
 void printToken(const char* token, const char* type) {
   printf("Token: %s, Type: %s\n", token, type);
 }
 
 // Function to print error message for illegal token
 void printError(const char* token) {
   printf("Illegal Token: %s\n", token);
 }
 %}
 
 
 %option yylineno
 
 %%
 "//"(.)*[\n] { /* Match and ignore single-line comments */ }
 "/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/" { /* Match and ignore multi-line comments */ }
 <INITIAL>{
 "#include"  { printToken(yytext, "Preprocessor Directive"); }
 "#define"  { printToken(yytext, "Preprocessor Directive"); }
 "#ifdef"   { printToken(yytext, "Preprocessor Directive"); }
 "#endif"   { printToken(yytext, "Preprocessor Directive"); }
 }
 
 <INITIAL>{
 [a-zA-Z_][a-zA-Z0-9_]*  { printToken(yytext, "Identifier"); }
 [0-9]+         { printToken(yytext, "Number"); }
 "\""([^\\\"]|\\.)*"\"" { printToken(yytext, "String"); }
 [+\-*/=<>!&|%^]     { printToken(yytext, "Operator"); }
 [\{\}\[\]\(\);.,:]   { printToken(yytext, "Delimiter"); }
 .            { printError(yytext); }
 }
 
 %%
 
 int main() {
   FILE* file = fopen("input.txt", "r");
 
   yyin = file;
   yylex();
 
   fclose(file);
 
   return 0;
 }