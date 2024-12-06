# Day 4: Ceres Searcha

## Tested on [C](https://en.wikipedia.org/wiki/C_(Programming_language))

```bash
>>> gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-linux-gnu/14.2.1/lto-wrapper
Target: x86_64-pc-linux-gnu
Configured with: /tmp/pkg/src/gcc/configure --enable-languages=ada,c,c++,d,fortran,go,lto,m2,objc,obj-c++,rust --enable-bootstrap --prefix=/usr --libdir=/usr/lib --libexecdir=/usr/lib --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=https://github.com/CachyOS/CachyOS-PKGBUILDS/issues --with-build-config=bootstrap-lto --with-linker-hash-style=gnu --with-system-zlib --enable-__cxa_atexit --enable-cet=auto --enable-checking=release --enable-clocale=gnu --enable-default-pie --enable-default-ssp --enable-gnu-indirect-function --enable-gnu-unique-object --enable-libstdcxx-backtrace --enable-link-serialization=1 --enable-linker-build-id --enable-lto --enable-multilib --enable-plugin --enable-shared --enable-threads=posix --disable-libssp --disable-libstdcxx-pch --disable-werror
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 14.2.1 20240910 (GCC)
```

## Expected Output:

```bash
>>> make part_one
gcc -Wall -g -c main.c -o main.o
gcc -Wall -g -c read_file.c -o read_file.o
gcc main.o read_file.o -o ceres_part_one 
>>> ./ceres_part_one
Part 1: 2397
>>> make part_two
gcc -Wall -g -c part_two.c -o part_two.o
gcc -Wall -g -c read_file.c -o read_file.o
gcc part_two.o read_file.o -o ceres_part_two 
>>> ./ceres_part_two
Part 2: 1824
```
