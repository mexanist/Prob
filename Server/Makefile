obj = main.o socket_init.o test_of_socket_init.o read_actreq.o
server: $(obj)
	gcc $(obj) -o server
main.o: main.c
	gcc -c main.c 
socket_init.o: socket_init.c
	gcc -c socket_init.c 
read_actreq.o: read_actreq.c
	gcc -c read_actreq.c
test_of_socket_init.o: test_of_socket_init.c
	gcc -c test_of_socket_init.c 
.PHONY: clean
clean:
	rm -rf *.o server 
