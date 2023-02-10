## pbs

Portable Batch System (or simply PBS) is the name of computer software that performs job scheduling.

Its primary task is to allocate computational tasks, i.e., batch jobs, among the available computing resources. It is often used in conjunction with UNIX cluster environments.

## qsub

[qsub Basics](https://zhanggroup.org/docs/node26.html)

The `qsub` command is used to **submit jobs** to the queue.

A "job" is a program or task that may be assigned to run on a **cluster system**.

Qsub will only run scripts.

```sh
qsub script.sh 
# 1056.axiom.localdomain

qstat

Job id                    Name             User            Time Use S Queue 
------------------------- ---------------- --------------- -------- - ----- 
1056.axiom                script.sh        jdpoisso        00:00:38 R first

ls
# fib  script.sh  script.sh.o1056
```

The only results copied back is the standard output and standard error (script.sh.o1056)

**script.sh**

```sh
#!/bin/bash 
#PBS -j oe 

echo "Running on: " 
cat ${PBS_NODEFILE} 

echo 
echo "Program Output begins: " 

cd ${PBS_O_WORKDIR} 

./fib 46
```

**script.sh.o1056**

```
Running on: 
compute-0-19 

Program Output begins: 
1,      1,      2,      3,      5, 
8,      13,     21,     34,     55, 
89,     144,    233,    377,    610, 
987,    1597,   2584,   4181,   6765, 
10946,  17711,  28657,  46368,  75025, 
121393, 196418, 317811, 514229, 832040, 
1346269,        2178309,        3524578,        5702887,        9227465, 
14930352,       24157817,       39088169,       63245986,       102334155, 
165580141,      267914296,      433494437,      701408733,      1134903170, 
1836311903,
```
