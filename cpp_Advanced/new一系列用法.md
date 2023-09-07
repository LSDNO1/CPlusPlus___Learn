# C++new操作符

### new

new操作符用于在堆上分配一个内存，并在分配的内存上创建对象

```C++
int* p=new int(10);
```

### operator new

是一个函数，用于在堆上分配制定大小的内存

```C++
int* p=static_cast<int*>(operator new(sizeof(int)));
```

这段代码会在堆上分配一个int类型的内存，但不睡创建任何对象。需要手动调用构造函数来创造对象

### new operator

是一个重载操作符，用于重载new操作符的行为，它可以自定义内存分配和对象构造行为

```C++
void* operator new(size_t size) {
    void* p = malloc(size);
    // 自定义内存分配行为
    return p;
}
```

这个重载函数会在内存分配时使用`malloc`函数代替默认的内存分配行为