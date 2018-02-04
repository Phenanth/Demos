# Data Structure Project 7

## 源代码结构说明

根目录：

	`q1.c` : `main`函数，整个程序的入口。

	`head.h` : 头文件，通过修改`FILENAME`文件路径改变输入。

	子目录：

	`inputs` : 输入文件存放目录。

		`input.txt` : 作业中提供的输入文件。

		`demo.txt` : 调试用简易数据。

	`source_files` : 主要功能函数及排序函数实现。

		`function.c` : 读取数据函数`readData()`、打印数组函数`printList()`、交换数组中两个位置的值函数`swap()`。

		`heapSort.c` : 修正数组为大堆函数`adjust()`、堆排序函数`HeapSort()`。

		`insertSort.c` : 比较函数`insert()`、插入排序函数`InsertSort()`。

		`mergeSort.c` : 合并有序表函数`merge()`、合并一趟函数`mergeOnePass()`、合并排序函数`MergeSort()`。

		`quickSort.c` : 快速排序函数`QuickSort()`。


## 调试方式

工程默认使用课上提供的`input.txt`文件作为输入，可通过修改`head.h`头文件中定义的`FILENAME`值为`"inputs/demo.txt"`将输入改为简化的输入数据。

与此同时，工程默认不输出输出每次排序后的数组，而是只输出排序前和完全排序后的数组。如有需求，可取消各`source`文件内的`printList()`函数的注释来观察排序过程中的数组。

工程默认以`InsertSort()`作为排序方式，如需查看其他排序方式，可以通过取消`q1.c`中`main()`函数中的相关语句注释和注释无关语句的方式切换排序方式。
