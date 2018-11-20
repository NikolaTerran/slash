all: main.c
  gcc -o slash main.c
  
run:
  ./slash
  
clean:
  rm *.o
