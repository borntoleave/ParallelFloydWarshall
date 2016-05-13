exc: 		fw check
	./fw ../Data/Graph8.idat

fw: 		fw.o io_idat.o
	g++ fw.o io_idat.o -o fw

fw.o:		fw.cpp io_idat.c alg.cpp etime.cpp io_idat.h
	g++ fw.cpp io_idat.c alg.cpp -c

check:		check.o io_idat.o
	g++ check.o io_idat.o -o check
	
check.o:	check.cpp io_idat.c alg.cpp io_idat.h
	g++ check.cpp io_idat.c alg.cpp -c
	
io_idat.o:	io_idat.h
	g++ io_idat.c -c
		
clean:
	rm -f *.o *~ *.gch 
