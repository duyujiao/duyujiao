 //DIR结构体定义，关于目录信息
 struct __dirstream
    {
     void *__fd;
     char *__data;
     int __entry_data;
     char *__ptr;
     int __entry_ptr;
     size_t __allocation;
     size_t __size;
     __libc_lock_define (, __lock)
    };
 typedef struct __dirstream DIR;
