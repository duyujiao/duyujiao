```c
void printname()//打印提示符
{
  char *name1 = "emo@dyj";
  printf("\033[1m\033[32m%s\033[0m", name1);
  printf(":");
  getcwd(arr,sizeof(arr));
  printf("\033[1m\033[34m%s\033[0m", arr);
  printf("$ ");
  fflush(stdout); //清空缓冲区,默认为行缓冲，提示符不是以\n结尾的
}

```

