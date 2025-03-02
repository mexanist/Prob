obj = main.o socket_init.o test_of_socket_init.o
client: $(obj)
	gcc $(obj) -o client
main.o: main.c
	gcc -c main.c 
socket_init.o: socket_init.c
	gcc -c socket_init.c 
test_of_socket_init.o: test_of_socket_init.c
	gcc -c test_of_socket_init.c 
.PHONY: clean
clean:
	rm -rf *.o client 
