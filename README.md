screader
========

The screader is a soure code reading tool based the libclang. It is implemented by the C.
The screader can work on the clang-10.0.0 now.


How to build the scread:
---------------------------------------------------------
1. You must install the clang on your computer.
You can follow the doc: http://clang.llvm.org/get_started.html.
But after you "make", you must "make install".

2. After you install the clang, you can use "clang -v" to check your clang version.

3. Find the clanglib-10.so.1 in the usr/lib/x86_64-linux-gnu dir; if you can't find it, you
can use the "sudo apt-get install libclang1" to install the libclang.

4. Use the cmd to create a link to libclang.so:

  sudo ln -s libclang-10.so.1 libclang.so

5. Use git clone the source code of scread to you computer.

6. Create directory build under the scread directory.

7. Under the build directory, use the cmd:

   cmake ..

   make

6. Then you can get the scread under the build directory.


How to use the scread:
------------------------------------------------------------

You must come to the directory of the scread.

1. If you want to use the scread to output all the informations of ast nodes:
   You can use it like that: ./scread xxx.cpp(or xxx.c, xxx.h)

2. If you just want to get the keyword information, you can use it like this:
   ./scread xxx.cpp keyword

3. We store some testcase under the scread/test/. So, you can use the scread like this:
   ./scread ../test/Node.h
   ./scread ../test/HelloWorld.cpp printf

Update:
-----------------------------------------------
1. The files in include/clang-c dir is copy from the clang-10.0.0/include/clang-c.
