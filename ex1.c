#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

pid_t fils_1 , fils_2 ;

void nbre_premier()
{
    int n = 10 , y = 2 , i = 2;
    
    do
    {

	while( y%i!=0)
	    i++ ;

	if(i==y)
	{
	    printf("\t %d",y) ;
	    n-- ;
	}
      
	y++ ;
	i=2 ;
    }while(n > 0) ;

}


int main()
{
    printf("\n Bonjour\n") ;
    
    fils_1 = fork() ;

    if(fils_1 == 0)
    {
	nbre_premier() ;
	exit(0) ;
    }

    waitpid(fils_1 , NULL , 0);
    
    sleep(2) ;

    fils_2 = fork() ;

    if(fils_2 == 0)
    {
	printf("\n\n Contenu du réperetoire courant : \n\t") ;
	system("ls");
	exit(0) ;
    }

    waitpid(fils_2 , NULL , 0);

    printf("\n Au revoir\n") ;

    return 0 ;
}
    
	
