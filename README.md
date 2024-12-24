## Concurrent Computing

Code credits are included in the header comments of each file. Additional summary comments have been added above them to provide an overview of the file's functionality.

### Engaging Lecture on Parallel Computing. Don't Forget Your Popcorn, It's A 2-Hour Ride!

Watch the insightful session on Shared Memory Programming with OpenMP & More About OpenMP [here](https://youtu.be/fn2VAUSw6cI)

### Learning Made Fun With This OpenMP Tutorial!

Check out the beginner-friendly guide, "Introduction to OpenMP - Tim Mattson (Intel)" [here](https://www.youtube.com/playlist?list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG)

For more related resources, visit [this link](http://www.openmp.org/resources/tutorials-articles/)

Here is a step-by-step guide to install gcc without multilib and locate the executable:

```sh
brew install gcc --without-multilib
cd /usr/local/Cellar/gcc
ls
cd 6.2.0/bin/
# Locate the executable here: gcc-6
```

To setup the libomp library, use these export commands:

```sh
# Get information about libomp using: brew info libomp (OMP)
export LDFLAGS="-L/usr/local/opt/libomp/lib"
export CPPFLAGS="-I/usr/local/opt/libomp/include"
```

<br>
