CC=mpic++
LNK=mpic++
CFLAGS=-O2
LIBS=-lmpi

exc: 		fw check
	mpiexec -np 4 ./fw ../Data/Graph8.idat
	./compare_bin.sh short.idat ../Data/Short8.idat

fw: 		fw.o io_idat.o
	$(CC) fw.o io_idat.o -o fw $(LIBS)

fw.o:		fw.cpp io_idat.c alg.cpp etime.cpp io_idat.h
	$(CC) fw.cpp io_idat.c alg.cpp -c $(CFLAGS)

check:		check.o io_idat.o
	$(CC) check.o io_idat.o -o check
	
check.o:	check.cpp io_idat.c alg.cpp io_idat.h
	$(CC) check.cpp io_idat.c alg.cpp -c $(CFLAGS)
	
io_idat.o:	io_idat.h
	$(CC) io_idat.c -c
		
clean:
	rm -vf *.o *~ *.gch *.idat
