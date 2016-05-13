for((n=8;n>1;n--))
	do
		mpiexec -np $(($n*$n)) ./fw ../Data/Graph8.idat
	done
