#include <stdio.h>
int main(){
    char *error_comun = "error, problema en el sistema, codigo: 404";

    printf("%d", &error_comun);
    return 0;
}