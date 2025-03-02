/* Функция создает сокет клиента и фомирует сетевой порядок следования байтов и
   его со слушающим сокетом сервера.
   При успешном выполнении возвращает дескриптор сокета, в случае ошибки возвращает 0,
   ошибки обрабатываются в main.
   Для проверки работоспособности используется localhost */
   

#define PORT_SERV 35000 // Порт сервера
#define IP_SERV "127.0.0.1" //IP адрес сервера
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
 
int socket_init(){
	int tmp_sfd;
	struct sockaddr_in addr_serv;
	struct in_addr ip_serv;
	socklen_t size_addr_in;
	size_addr_in = sizeof(struct sockaddr_in);
	tmp_sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(tmp_sfd == -1){
		return 0;
	}
/* Формируем структуру sockaddr in сервера
*  Функция inet_pton возвращает адрес уже в сетевом порядке */
	if((inet_pton(AF_INET, IP_SERV, &ip_serv) == -1)){
		return 0;
	}
	addr_serv.sin_family = AF_INET;
/* Сетевой порядок для порта */
	addr_serv.sin_port = htons(PORT_SERV);
	addr_serv.sin_addr.s_addr = ip_serv.s_addr;
	if(connect(tmp_sfd, (struct sockaddr *)&addr_serv, size_addr_in) == -1){
		return 0;
	}
	return tmp_sfd;
}
