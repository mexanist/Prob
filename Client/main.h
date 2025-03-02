#define PORT_SERV 35000
#define IP_SERV "127.0.0.1"
#define SIZE_BUF 256
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

static int sfd; //Дескриптор сокета для клиента

int socket_init(void);
int test_of_socket_init(int fd); //Функция для тестирования socket_init
