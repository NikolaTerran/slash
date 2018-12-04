all: main.o parse_args.o exeorder.o detect_operators.o operation.o slash.h
	gcc -o slash main.o parse_args.o exeorder.o detect_operators.o operation.o
	rm *.o  

main.o: main.c slash.h
	gcc -c main.c
  
parse_args.o: parse_args.c slash.h
	gcc -c parse_args.c
	
exeorder.o: exeorder.c slash.h
	gcc -c exeorder.c
	
detect_operators.o: detect_operators.c slash.h
	gcc -c detect_operators.c
	
operation.o: operation.c slash.h
	gcc -c operation.c
	
run:
	./slash
  
clean:
	rm *.o
