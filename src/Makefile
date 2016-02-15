CC=gcc

all: markov_localization

markov_localization.o: markov_localization.c
	$(CC) -c markov_localization.c

markov_localization: markov_localization.o
	$(CC) -o markov_localization markov_localization.o

clean:
	rm *.o
	rm markov_localization
