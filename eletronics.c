#include <stdio.h>
#include "resist.h"
#include "corrent.h"
#include "voltage.h"

void exibeMenu(void) ;

int main( void ) {
    double v, cor, res ;
    char c = '0' ;

    while(c!='q' || c!='Q' || c!='s' || c!='S') {
        if(c=='q' || c=='Q' || c=='s' || c=='S')
	    return 0;
	exibeMenu() ;
	fflush(stdout);
	scanf("%c", &c) ;

	switch(c) {
	    case '1' : 	printf("     Tensao: ") ;
			fflush(stdout) ;
			scanf("%lf", &v) ;
			getchar();
			printf("   Corrente: ") ;
			fflush(stdout) ;
			scanf("%lf", &cor) ;
			getchar();
			printf("Resistencia: %.2lf Ohm\n\n", resist(v, cor)) ;
			break ;
	    case '2' : 	printf("     Tensao: ") ;
			fflush(stdout) ;
			scanf("%lf", &v) ;
			getchar();
			printf("Resistencia: ") ;
			fflush(stdout) ;
			scanf("%lf", &res) ;
			getchar();
			fflush(stdout) ;
			double crrnt = corrent(v, res) ;
			printf("   Corrente: %.6lf A (%.4lf mA)\n\n", crrnt, (crrnt*1000)) ;
			break ;
	    case '3' : 	printf("   Corrente: ") ;
			fflush(stdout) ;
			scanf("%lf", &cor) ;
			getchar();
			printf("Resistencia: ") ;
			fflush(stdout) ;
			scanf("%lf", &res) ;
			getchar();
			printf("     Tensao: %.2lf volt\n\n", voltage(cor, res)) ;
			break ;
	    default:	fflush(stdout);
			break ;
	}
    }

    return 0 ;
}

void exibeMenu( void ) {
    printf("### Insira valores em Volt, Ohm ou Ampere! ###\n") ;
    printf("1 - Calculo da Resistencia \n");
    printf("2 - Calculo da Corrente \n");
    printf("3 - Calculo da Tensao \n") ;
    printf("Q/q/S/s - Sair \n");
    printf("> ");
}

