PORT=53034
CFLAGS = -DPORT=$(PORT) -g -Wall -std=gnu99
DEPENDENCIES = hash.h ftree.h

all: rcopy_server rcopy_client

rcopy_server: rcopy_server.o ftree.o hash_functions.o newsrc.o handleclient.o
		gcc ${CFLAGS} -o $@ $^

rcopy_client: rcopy_client.o ftree.o hash_functions.o newsrc.o handleclient.o
	gcc ${CFLAGS} -o $@ $^


ftree: ftree.o hash_functions.o newsrc.o handleclient.o
	gcc ${CFLAGS} -o $@ $^

handleclient: handleclient.o
	gcc ${CFLAGS} -o $@ $^
		
hash_functions: hash_functions.o
	gcc ${CFLAGS} -o $@ $^

newsrc : newsrc.o
	gcc ${CFLAGS} -o $@ $^

%.o: %.c ${DEPENDENCIES}
	gcc ${CFLAGS} -c $<

clean:
	rm -f *.o rcopy_server rcopy_client
