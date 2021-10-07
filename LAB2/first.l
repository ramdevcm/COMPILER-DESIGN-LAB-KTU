letter[a-zA-Z]
digit[0-9]
%%

{digit}+("E"("+"|"-")?{digit}+)? printf("\n\t %s is a real number", yytext);
{digit}+"."{digit}+("E"("+"|"-")?{digit}+)? printf("\n\t %s is a floating point number",yytext);

"if"|"else"|"int"|"char"|"float"|"struct"|"while"|"for"|"do"|"case"|"double"|"scanf"|"printf"|"return"|"include" printf("\n\t %s is a keyword", yytext);
"%s"|"%d"|"%f" printf("\n\t %s is a format specifier", yytext);

"\\t"|"\\n"|"\\p"|"\\s" printf("\n\t %s is a escape sequence", yytext);
"+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"="|"!="|"&"|"&&"|"|"|"||"|"%" printf("\n\t %s is an operator", yytext);

{letter}({letter}|{digit})* printf("\n\t %s is an identifier", yytext);
"("|")"|"{"|"}"|"["|"]"|":"|";"|"#"|","|"\""|"."  printf("\n\t %s is a special character", yytext);
%%
int yywrap()
{
    return 1;
}
int main()
{
    yyin = fopen("input.c","r");
    yylex();
    fclose(yyin);
    return 0;
}