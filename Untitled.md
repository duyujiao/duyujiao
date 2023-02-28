递归实现遍历目录：ls -R

1.判断命令行参数，获取用户要查询的目录名 。agrv[1]

argc==1-->./

2.判断用户指定的是否是目录，不是目录直接展示文件名。

stat S_ISDIR()  --》封装函数 isFile//用来判断是否是目录

3.读目录：

opendir(dir)

while(readdir())

{

普通文件直接打印

目录：拼接目录访问绝对径.

sprintf(path,"%s %s",dir,d_name)dir/d_name   //拼接函数

递归调自己，opendir(path) readdir()closedir()

}

closedir()



