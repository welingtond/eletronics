# Comentarios em arquivos Makefile sao possiveis e muito uteis. Iniciam com #
CC=gcc
CFLAGS=-g -std=c11 -Wall -fmax-errors=10 -Wextra
MAIN=eletronics

all:$(MAIN)

$(MAIN): eletronics.o resist.o voltage.o corrent.o
	$(CC) $(CFLAGS) -o $(MAIN) eletronics.o resist.o voltage.o corrent.o

*.o: *.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -v eletronics *.o

launch:
	./eletronics

#anotacao adicional
# para utilizar a mesma instrucao de compilacao de objetos para todos os arquivos *.c, use:
# *.o: *.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

