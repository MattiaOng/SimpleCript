#include <stdio.h>
#include <string.h>

typedef struct byte{
    char bit1:1;
    char bit2:1;
    char bit3:1;
    char bit4:1;
    char bit5:1;
    char bit6:1;
    char bit7:1;
    char bit8:1;
}_BYTE;

char switch_bits( char );
void shift_cript ( char * );
void shift_decript ( char * );

int main ( int argc, char * * argv ){
    if(argc<2){
        printf("Inserisci una stringa da linea di comando.\n\nEsempio: %s cacca", argv [ 0 ] );
        return -1;
    }

    shift_cript(argv[1]);
    shift_decript(argv[1]);

    return 0;
}

unsigned sieve ( long unsigned d ){
   long unsigned a, b, f,ret, e=0;
   a=0;

   while(a<=d)
   {
       f=(a/2);
       for(b=2;b<=f;b++){
                      if(a%b==0)
                                break;
       }

       if(b>f){
            ret=a;
            e++;
        }
       a++;
   }

   return ret;
}

void shift_cript ( char * string ){
    size_t lenght=strlen(string);
    unsigned sum=sieve(lenght);

    //printf("String lenght: %d\nSum number: %d\n\n",lenght,sum);

    for(unsigned counter=0;counter<lenght;counter++){
        //printf("Current char: %c\n", string[counter]);
        string[counter]= switch_bits(string[counter]+sum+counter);
        //printf("Switched bits char: %c\n\n", string[counter]);
    }

    printf("Cripted string: %s\n", string);
}

void shift_decript ( char * string ) {
    size_t lenght=strlen(string);
    unsigned sum=sieve(lenght);

    //printf("String lenght: %d\nSum number: %d\n\n",lenght,sum);

    for(unsigned counter=0;counter<lenght;counter++){
        //printf("Current char: %c\n", string[counter]);
        string[counter]= switch_bits(string[counter]);
        string[counter]-=(sum+counter);
        //printf("Switched bits char: %c\n\n", string[counter]);
    }

    printf("Decripted string: %s", string);
}

char switch_bits( char byte ){
    _BYTE set;

    memcpy ( &set, &byte, 1);

    _BYTE ret;

    ret.bit1 = set.bit2;
    ret.bit8 = set.bit7;
    ret.bit2 = set.bit1;
    ret.bit7 = set.bit8;


    ret.bit3 = set.bit6;
    ret.bit6 = set.bit3;
    ret.bit4 = set.bit5;
    ret.bit5 = set.bit4;

    char r_char;

    memcpy ( &r_char, &ret, 1);

    return r_char;
}
