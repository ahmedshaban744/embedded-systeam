#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x=0;
    printf( "enter the alphabet to check");
    scanf( "%c",&x);
    switch(x)
    {
    case 'a':
    case 'A':
        {

         printf( "the alphabet is vowel");
         break;
        }
          case 'e':
    case 'E':
        {

         printf( "the alphabet is vowel");
         break;
        }
         case 'I':
    case 'i':
        {

         printf( "the alphabet is vowel");
         break;
        }
          case 'o':
    case 'O':
        {

         printf( "the alphabet is vowel");
         break;
        }
          case 'u':
    case 'U':
        {

         printf( "the alphabet is vowel");
         break;
        }
         default:
         printf( "the alphabet is consonant");
  break;

    }
    return 0;
}
