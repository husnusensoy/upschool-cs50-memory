# Upschool CS50 Workshop Notes

## Quickstart

Compiling codes

```bash
make all
```

All executables are in `bin/` directory. 

Executing a code 

```bash
bin/multiplication
```

## Content

### Pointers & Pointees

* `bin/multiplication` shows you how every memory piece is managed by address in C. Read `src/multiplication.c` for details.

#### Stack vs Heap

Remeber that stack is great but limited in capacity and capabilities. Remember that maximum stack space is limited with configurations displayed using `ulimit -a` pre process on Linux.

This is obviously not the case for heap but it has other drawbacks as you remember.

* `bin/stack` shows that you are limited in allocating large stack memory segments.
* `bin/heap` shows that this limitation does not exists for heap allocation. 

Access both memory areas are programatically same at C level (memory region is transparent to you as a developer.)


#### Memory Leakage on Heap & `valgrind`

Remember that heap allocation and deallocation is not automatic as opposed to stack allocation/deallocation. 

Memory leakages are usually the nightmare of large scale & long running applications. That's may be the reason why I am using Mac in last 10 years :)

To detect a potential leakage in `src/heap.c`, run

```bash
valgrind --tool=memcheck --leak-check=yes bin/heap
```

then add `free(bigheap);` before `return 0;` into `src/heap.c` and recompile using `make` and run 

```bash
valgrind --tool=memcheck --leak-check=yes bin/heap
```

Compare the difference in output.

### Call by Value & Call by Reference

Remember that our fairly simple swap algorithm doesn't work when we simply offload the operation into a function called `swap`.

1. Run `bin/swapfail` to see swap does not occur as we expect.
2. Run `bin/swap` to see swap does occur when we interact with the function over references (aka addresses, aka pointers)

First way is named as function **call by value** whereas the second one is named as **call by reference**.

### Pointer Aliasing

Call by Reference idea, needless to say, is great. But also catchy sometimes. 

Run `bin/aliasing` first and exemine the output. Later check `src/aliasing.c` to grasp how updating pointee(s) of a pointer cause a change on poinee(s) of another pointer. (Obviously they are pointing to the same pointers.)

Like many things in C this is both good and evil. It is you which one to choose by properly using this feature/behaviour of the language.

### C-Strings & Better String

First start by comparing the performance of `bin/defaultstring` and `bin/betterstring` executables.

```bash
time bin/defaultstring
```

```bash
time bin/betterstring
```

Note that although the results are same performance of two is significantly different (ensure that compiler optization is below `-O2`)

That's because the length of default c strings requires the full scan of `char*` until a `\0` character is encountered, where as in our better string implementation we store string length together with string it self and `strlen` counterpart `bstrlen` does not require this store. Note that this is the string implementation in many modern programming languages.

In application development with C this is also the first behaviour we overwrite by adding our own source into default C library :)

### Functional primitives for C

Before closing the week, we will implement some great things available for `Python`, `Scala`, etc. 

Following Python script simply filters out even numbers in a list (Pythonic way of saying int array. Not exactly indeed but live with that for now :))

```python
a = [1,2,3,4,5,6,7]

def is_even(a):
    return a%2 == 0

even = filter(is_even, a)
```

The great this about `filter` function is that it has no idea about the function it will filter based on (`is_even` in our case). This is a common design pattern call `inversion of control` allowing us just to implement `filter` once and implement many small `is_even` like functions (`is_odd`, `is_prime`, etc.) to filter our our integer arrays.

First run 

```bash
bin/functional 100
```

to see how different filtering functions result on random generated 100 integers. Then go into code to understand

> Functions can also be passed to a function (to `filter` in our case) using **call by reference**.


Here is the challange come:
* Can you implement `map` ?
* Can you implement `reduce` ? 

#### Pythonic `map`

Following example returns a new array consisting of $$\forall i, 2 \cross a_i$$

```python
a = [1,2,3,4,5,6,7]

def double_it(a):
    return a * 2

a2 = map(double_it, a)
```

#### Pythonic `reduce`

Following example might be more catch it `compare`s $$a_0 with a_1$$ and returns $$max(a_0, a_1)$$ then it calls `compare` again with $$max(a_0, a_1)$$ and $$a_2$$. This goes like that until the array is exhausted. At the and there is only one integer returned from `reduce` which is the maximum of all integers. 

```python
a = [1,2,3,4,5,6,7]

def compare(a,b):
    if  a > b:
         return a
    else:
         return b

max_a = reduce(compare, a, -1)
```

Note that `reduce` can do much fancier things :)