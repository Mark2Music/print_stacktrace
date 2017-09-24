http://blog.csdn.net/rheostat/article/details/8523598
这篇博客里有关于调试信息的详细做法

要想获得调用栈，使用以下参数编译程序：
g++ -g -rdynamic -Wl,-Map=test.map  test.cpp -o test
在test.map文件里查找到想要查找的函数名之后，再使用以下方式获得调用此函数的位置：
addr2line -a 0x0000000000000a53 -e test -f -C

因为程序的调用栈是从main函数来进行计算的，因此这样即可以得到此函数调用的详细信息
