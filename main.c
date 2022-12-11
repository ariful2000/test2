#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


bool Operator(char value) {
   if (
   value == '+'  ||
   value == '-'  ||
   value == '*'  ||
   value == '%'  ||
   value == '/'  ||
   value == '>'  ||
   value == ">=" ||
   value == '<'  ||
   value == "<=" ||
   value == '='  ||
   value == "!=" ||
   value == '['  ||
   value == ']'  ||
   value == '{'  ||
   value == '}'
   )
   return (true);
   return (false);
}

bool Val(char value) {
   if (
   value == '/'  ||
   value == ','  ||
   value == ';'  ||
   value == '>'  ||
   value == ">=" ||
   value == '<'  ||
   value == "<=" ||
   value == '='  ||
   value == "!=" ||
   value == '('  ||
   value == ')'  ||
   value == ' '  ||
   value == '+'  ||
   value == '-'  ||
   value == '*'  ||
   value == '['  ||
   value == ']'  ||
   value == '{'  ||
   value == '}'
   )

   return (true);
   return (false);
}

bool Keyword(char* wd) {
    if (
    !strcmp(wd, "long") ||
    !strcmp(wd, "short") ||
    !strcmp(wd, "if") ||
    !strcmp(wd, "else") ||
    !strcmp(wd, "while") ||
    !strcmp(wd, "do") ||
    !strcmp(wd, "break") ||
    !strcmp(wd, "continue") ||
    !strcmp(wd, "int") ||
    !strcmp(wd, "double") ||
    !strcmp(wd, "float") ||
    !strcmp(wd, "return") ||
    !strcmp(wd, "case") ||
    !strcmp(wd, "char") ||
    !strcmp(wd, "goto"))
   return (true);
   return (false);
}

bool Identifier(char* numberString){
   if (
   numberString[0] == '0' ||
   numberString[0] == '1' ||
   numberString[0] == '2' ||
   numberString[0] == '3' ||
   numberString[0] == '4' ||
   numberString[0] == '5' ||
   numberString[0] == '6' ||
   numberString[0] == '7' ||
   numberString[0] == '8' ||
   numberString[0] == '9' ||
   Val(numberString) == true)
   return (false);
   return (true);
}

bool Number(char* numStr) {
   int i, len = strlen(numStr);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (
      numStr[i] != '0' &&
      numStr[i] != '1' &&
      numStr[i] != '2' &&
      numStr[i] != '3' &&
      numStr[i] != '4' &&
      numStr[i] != '5' &&
      numStr[i] != '6' &&
      numStr[i] != '7' &&
      numStr[i] != '8' &&
      numStr[i] != '9' &&
      numStr[i] != '.' || (numStr[i] == '-' && i > 0))
      return (false);
      if (numStr[i] == '.')
      hasDecimal = true;
   }
   return (hasDecimal);
}

bool Integer(char* numberString) {
   int i, len = strlen(numberString);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (
      numberString[i] != '0' &&
      numberString[i] != '1' &&
      numberString[i] != '2'&&
      numberString[i] != '3' &&
      numberString[i] != '4' &&
      numberString[i] != '5' &&
      numberString[i] != '6' &&
      numberString[i] != '7' &&
      numberString[i] != '8' &&
      numberString[i] != '9' || (numberString[i] == '-' && i > 0))
      return (false);
   }
   return (true);
}

char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
   subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}

void TokenDec(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);

   while (right <= length && left <= right) {
      if (Val(str[right]) == false)
      right++;
      if (Val(str[right]) == true && left == right) {
         if (Operator(str[right]) == true)
         printf("oper valid : '%c'\n", str[right]);
         right++;
         left = right;
      } else if (

          Val(str[right]) == true &&
          left != right ||
          (right == length && left != right)) {

         char* subStr = subString(str, left, right - 1);
         if (Keyword(subStr) == true)
         printf("Keyword (valid) : '%s'\n", subStr);

         else if (Number(subStr) == true)
         printf("Number (r) : '%s'\n", subStr);

         else if (Identifier(subStr) == true
         && Val(str[right - 1]) == false)
         printf("Id (valid) : '%s'\n", subStr);

         else if (Integer(subStr) == true)
         printf("Number (valid) : '%s'\n", subStr);

         printf("Id (not valid) : '%s'\n", subStr);
         left = right;
      }
   }
   return;
}

int main() {
   char str[100] = "int a = 5 + 10; 5asd";

   printf("Start : '%s' \n", str);
   TokenDec(str);
}
