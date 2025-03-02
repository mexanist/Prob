/* Определение функции тестирования функции socket_init(). В качестве аргумента принимается
   дескриптор соккета возвращенного функцией socket_init(). Данная функция ожидает сообщения 
   от клиента, при его получении отправляет ответ клиенту */

#define SIZE_BUF 256
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int test_of_socket_init(int fd){
//	struct sockaddr_in addr_clnt;// Если нужен адрес клиента
	ssize_t num_buf_recev;// Если нужно адрес клиента
	ssize_t num_buf_send;// Если нужно адрес клиента
	char buf[SIZE_BUF];
//	socklen_t size_addr_in;
	int acpt_sock;
//	size_addr_in = sizeof(struct sockaddr_in);//Если нужен адрес клиента
//	acpt_sock = accept(fd, (struct sockaddr *)&addr_clnt, &size_addr_in);// Если нужен адрес клиента
	acpt_sock = accept(fd, NULL, NULL);
/* Прием сообщений */
	num_buf_recev = read(acpt_sock, buf, SIZE_BUF);
	if (num_buf_recev == -1){
		return -1;
	}
	buf[num_buf_recev] = '\0';
	printf("%s\n", buf);
/* Отправка сообщений */
	snprintf(buf, sizeof(buf), "Answer to client");
	num_buf_send = write(acpt_sock, buf, strlen(buf));
	if (num_buf_send == -1 || num_buf_send != strlen(buf)){
		return -1;
	}
	return 0;
}
