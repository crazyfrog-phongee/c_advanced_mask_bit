#include <stdio.h>
#include "main.h"
#include "try_catch.h"

bool_t equal(char* arr1, char* arr2) {
    if((arr1[0] == NULL) || (arr2[0] == NULL)) {
        THROW(404);
    }
    int i = 0;
    while(1) {
        if(arr1[i] != arr2[i]) {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}


int main(int argc, char const *argv[])
{
    char arr1[] = "0";
    char arr2[] = "Phong";
    TRY {
        if(equal(arr1, arr2)) {
            printf("Equal Strings\n");
        } else {
            printf("Unequal Strings\n");
        }
    }
    CATCH(404) {
        printf("NULL String\n");
    }
    FINALLY {
        printf("Default Case\n");
    }
    ENDTRY;
    return 0;
}
