[Open MPI v1.4.5 documentation](https://www.open-mpi.org/doc/v1.4/)

[videos](https://www.open-mpi.org/video/)

Install: `brew install open-mpi`

<hr>

[High-Performance Computing - Episode 1 - Introducing MPI](https://youtu.be/kHV6wmG35po)

```sh
mpiexec -n 4 hostname

mpiexec -machinefile machines.txt -n 4 hostname
```

machines.txt

```
wolfman
mummy
frankenstein
```

### Easy way to check that it's distributing processes across hosts
`mpiexec -machinefile machines.txt -n 4 hostname1`
