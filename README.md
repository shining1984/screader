screader
========

The screader is a soure code reading tool based the libclang. It is implemented by the C.

How to use the scread:
1. You must install the clang on your computer.
   You can follow the doc: http://clang.llvm.org/get_started.html.
   But after you "make", you must "make install".
2. After you install the clang, you can use "clang -v" to check your clang version.
3. Use git clone the source code of scread to you computer.
4. Make directory build under the scread directory.
5. Under the build directory, use the cmd:
   cmake ..
   make
6. Then you can get the scread under the build directory.
7. You can use the testcase under the scread/test directory to test scread like this:
   ./scread ../test/Node.h
