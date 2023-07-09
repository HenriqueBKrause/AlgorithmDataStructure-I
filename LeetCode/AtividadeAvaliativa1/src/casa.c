#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



char* LogestNiceSubString( char* s ) {
    int Len = strlen(s);
    char* LogestSubString = ( char* ) malloc (( Len + 1) * sizeof( char ));
    LogestSubString[ 0 ] = '\0';


    for( int i = 0; i < Len; i++) {
        bool UpperCase[26] = { false };
        bool LowerCase[26] = { false };

        for( int j = i; j < Len; j++) {
            if( s[j] >= 'a' && s[j] <= 'z') {
                LowerCase[ s[j] - 'a' ] = true;
            } else {
                UpperCase[ s[j] - 'A' ] = true;
            }

            bool Nice = true;
            for( int k = 0; k < 26; k++) {
                if( LowerCase[k] != UpperCase[k]) {
                    Nice = false;
                    break;
                }
            }

            if( Nice && j - i + 1 > strlen( LogestSubString )) {
                strncpy( LogestSubString, s + i, j - i + 1);
                LogestSubString[ j - i + 1 ] = '\0';
            }
        }
    }

    return LogestSubString;
}




int main() {
    char s[] = "YazaAay";
    char* result = LogestNiceSubString(s);
    printf("Longest nice substring: %s\n", result);
    free(result);
    return 0;
}