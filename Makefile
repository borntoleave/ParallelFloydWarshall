#
CC=g++
CFLAGS=-O2 -fopenmp
#
LNK=g++
LNK_FLAGS=-fopenmp
LIBS=-lm
#
qrf: qrf.o etime_omp.o Makefile unstack
	$(LNK) -o qrf qrf.o etime_omp.o $(LNK_FLAGS) $(LIBS)
#
qrf.o: qrf.cpp alg.cpp etime_omp.c Makefile
	$(CC) -c $(CFLAGS) qrf.cpp etime_omp.c 

etime_omp.o: etime_omp.c Makefile
	$(CC) -c $(CFLAGS) etime_omp.c
#
unstack: unstack.o Makefile
	$(LNK) -o unstack unstack.o
	
unstack.o: unstack.cpp write_file.cpp read_file.cpp Makefile
	$(CC) -c unstack.cpp write_file.cpp read_file.cpp
#
16:
	rm -f unstacked* *.ppm
	./qrf g_le.dat h_le.dat f_le.dat 
	./unstack f_le.dat
	dat2ppm -jet unstacked_f_le.dat
	display unstacked_f_le.ppm	
32:
	rm -f unstacked* *.ppm
	./qrf g_32_le.dat h_32_le.dat f_32_le.dat 
	./unstack f_32_le.dat
	dat2ppm -jet unstacked_f_32_le.dat
	display unstacked_f_32_le.ppm
64:
	rm -f unstacked* *.ppm
	./qrf g_64_le.dat h_64_le.dat f_64_le.dat 
	./unstack f_64_le.dat
	dat2ppm -jet unstacked_f_64_le.dat
	display unstacked_f_64_le.ppm
		
fsv64:
	rm -f unstacked* *.ppm
	./qrf gsv_64_le.dat hsv_64_le.dat fsv_64_le.dat 
	./unstack fsv_64_le.dat
	dat2ppm -jet unstacked_fsv_64_le.dat
	display unstacked_fsv_64_le.ppm
#
clean:
	/bin/rm -f *.o *~ *.gch *.ppm unstacked_*

#
cleanall:
	/bin/rm -f qrf unstack *.o *~ *.gch *.ppm unstacked_* *.gch
##

