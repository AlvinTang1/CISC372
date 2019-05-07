
seq: sort.c
	mpicc -o sort sort.c
run-seq: seq
	srun -n 1 ./sort
parA: sort_partA.c
	mpicc -o sort_partA sort_partA.c
parB: sort_partB.c
	mpicc -o sort_partB sort_partB.c 

baseline: seq
	srun -n 1 ./sort 16777216
	srun -n 1 ./sort 33554432
	srun -n 1 ./sort 67108864
	srun -n 1 ./sort 134217728

partA: parA
	srun -n 1 ./sort_partA 134217728
	srun -n 2 ./sort_partA 134217728
	srun -n 4 ./sort_partA 134217728
	srun -n 8 ./sort_partA 134217728
 
partB: parB
	srun -n 8 ./sort_partB 134217728
	srun -n 2 ./sort_partB  33554432
	srun -n 4 ./sort_partB  67108864
	srun -n 8 ./sort_partB  134217728