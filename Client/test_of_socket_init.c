/* Определение функции тестирования функции socket_init(). В качестве аргумента принимается
   дескриптор соккета возвращенного функцией socket_init(). Данная функция отправляет сообщение 
   серверу, при его отправки ожидает ответа сервера */


#define SIZE_BUF 256
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
 
int test_of_socket_init(int fd){
	ssize_t num_buf_recev;
	ssize_t num_buf_send;
	char buf[SIZE_BUF];
/* Отправка сообщений */
	snprintf(buf, sizeof(buf), "Test of sockets");
	num_buf_send = write(fd, buf, strlen(buf));
	if (num_buf_send == -1 || num_buf_send != strlen(buf)){
		return -1;
	}
/* Прием сообщений */
	num_buf_recev = read(fd, buf, SIZE_BUF);
	if (num_buf_recev == -1){
		return -1;
	}
	buf[num_buf_recev] = '\0';
	printf("%s\n", buf);
	return 0;
}

