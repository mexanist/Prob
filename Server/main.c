#include "main.h"

int main(){
	sfd = socket_init();
	if(sfd == 0){
		perror("Error in func socket_init()");
		exit(EXIT_FAILURE);
	}
/* Тест функции socket_init() */
#if 1
	if(test_of_socket_init(sfd) == -1){
		perror("Error if test func");
		close(sfd);
		exit(EXIT_FAILURE);
	}
#endif
	close(sfd);	
}
