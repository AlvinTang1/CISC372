
seq: conway-seq.c
	mpicc -o conway-seq conway-seq.c

run-seq: seq
	srun -n 1 ./conway-seq

par: conway-par.c
	mpicc -o conway-par conway-par.c

run-par: par
	srun -n 1 ./conway-par

baseline: par
	srun -n 1 ./conway-par 0 64 64 1000 0 1
	srun -n 1 ./conway-par 0 128 128 1000 0 1
	srun -n 1 ./conway-par 0 256 256 1000 0 1
	srun -n 1 ./conway-par 0 512 512 1000 0 1
	srun -n 1 ./conway-par 0 1024 1024 1000 0 1

part1: par
	srun -n 1 ./conway-par
	srun -n 2 ./conway-par
	srun -n 4 ./conway-par
	srun -n 8 ./conway-par

part2: par
	srun -n 1 ./conway-par 0 64 64 1000 0 1
	srun -n 2 ./conway-par 0 64 64 1000 0 1
	srun -n 4 ./conway-par 0 64 64 1000 0 1
	srun -n 8 ./conway-par 0 64 64 1000 0 1
	srun -n 16 ./conway-par 0 64 64 1000 0 1

part2-all: part2
	srun -n 1 ./conway-par 0 64 64 1000 0 1
	srun -n 1 ./conway-par 0 128 128 1000 0 1
	srun -n 1 ./conway-par 0 256 256 1000 0 1
	srun -n 1 ./conway-par 0 512 512 1000 0 1
	srun -n 1 ./conway-par 0 1024 1024 1000 0 1

	srun -n 2 ./conway-par 0 64 64 1000 0 1
	srun -n 2 ./conway-par 0 128 128 1000 0 1
	srun -n 2 ./conway-par 0 256 256 1000 0 1
	srun -n 2 ./conway-par 0 512 512 1000 0 1
	srun -n 2 ./conway-par 0 1024 1024 1000 0 1

	srun -n 4 ./conway-par 0 64 64 1000 0 1
	srun -n 4 ./conway-par 0 128 128 1000 0 1
	srun -n 4 ./conway-par 0 256 256 1000 0 1
	srun -n 4 ./conway-par 0 512 512 1000 0 1
	srun -n 4 ./conway-par 0 1024 1024 1000 0 1

	srun -n 8 ./conway-par 0 64 64 1000 0 1
	srun -n 8 ./conway-par 0 128 128 1000 0 1
	srun -n 8 ./conway-par 0 256 256 1000 0 1
	srun -n 8 ./conway-par 0 512 512 1000 0 1
	srun -n 8 ./conway-par 0 1024 1024 1000 0 1

	srun -n 16 ./conway-par 0 64 64 1000 0 1
	srun -n 16 ./conway-par 0 128 128 1000 0 1
	srun -n 16 ./conway-par 0 256 256 1000 0 1
	srun -n 16 ./conway-par 0 512 512 1000 0 1
	srun -n 16 ./conway-par 0 1024 1024 1000 0 1
