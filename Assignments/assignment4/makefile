

#Susmitha Shailesh
#I pledge my honor that I have abided by the Stevens Honor System.

all: cs392_echoserver cs392_echoclient

cs392_echoserver : cs392_echoserver.o cs392_log.o
	gcc -o cs392_echoserver cs392_echoserver.o cs392_log.o

cs392_echoclient : cs392_echoclient.o
	gcc -o cs392_echoclient cs392_echoclient.o

cs392_echoserver.o : cs392_echoserver.c cs392_log.h
	gcc -c cs392_echoserver.c

cs392_echoclient.o : cs392_echoclient.c
	gcc -c cs392_echoclient.c 

cs392_log.o: cs392_log.c cs392_log.h
	gcc -c cs392_log.c

clean:
	rm *.o cs392_echoserver cs392_echoclient 