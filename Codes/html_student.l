%{
 #include <stdio.h>
 %}
 
 %option noyywrap
 
 %%
 ^Name:(.*) {
   printf("<HTML>\n");
   printf("<BODY>\n");
   printf("<TABLE>\n");
   printf("<TR>\n");
   printf("<TH><TD>%s</TD></TH>\n", yytext + 5);
 }
 
 ^M[0-9]{2}:[0-9]+ {
   printf("<TD>%s</TD>\n", yytext + 4);
 }
 
 ^[\t\n]+ {
   /* Skip empty lines or lines with only tabs/spaces */
 }
 
 ^End+ {
   printf("</TR>\n");
 }
 
 %%
 
 int main() {
   yylex();
   return 0;
 }