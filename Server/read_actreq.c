/* Функция чтения открытых заявок из файла.
   Функция создает массив в динамической памяти и записывает туда данные из файла,
   при отсутствии файла выводит предупреждение. Если файл не пустой, то массив
   содержит cnt_req элементов, в противном случае создает только указатель на участок памяти.
   Функция возвращает указатель на массив, ошибку выделения памяти обрабатывается в main */

#define RECORD 1
#define FILE_OPEN_REQ "actreq.dat"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "struct.h"

extern int cnt_req;
struct request * read_actreq(void){
	struct request * tmp;
	FILE *file;
	file = fopen(FILE_OPEN_REQ, "rb"); // Открыть двоичный файл для чтения
/* Если ошибка открытия файла */
	if(errno == ENOENT){
		printf("ВНИМАНИЕ! Файл открытых заявок отсутствует\n");
		tmp = malloc(sizeof(struct request) - 1);
		return tmp;
	} else if(errno){
		perror("Error open file for read: ");
		exit(EXIT_FAILURE);
	}
	rewind(file);
	fread(&cnt_req, sizeof(int), RECORD, file);// Чтение размера будущего массива
	if(cnt_req){
		tmp = malloc(sizeof(struct request) - 1);
	}
	tmp = malloc(cnt_req * sizeof(struct request) - 1);
	for(int i = 0; i < cnt_req; i++){
		fread(&tmp[i], sizeof(struct request), RECORD, file);
	}
	fclose(file);
	return tmp;
}

