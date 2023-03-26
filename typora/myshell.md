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

```c
int main()//参数输入
{
  read_history(NULL);
  signal(SIGINT, SIG_IGN);
  signal(SIGHUP, SIG_IGN);
  // char commod[MAX];
  while (1)
  {
    char *argv[MAX] = {NULL};
    //打印提示符
    printname();
    // commod[0]=0;
    // fgets(commod,MAX,stdin);
    //fflush(stdout);
    char *commod = readline(" ");
    if (commod == NULL) //屏蔽掉ctrl d 出现死循环的情况
    {
      printf("\n");
      continue;
    }
    add_history(commod);
    write_history(NULL);
    // commod[strlen(commod)-1]=0;
    if (strlen(commod) == 0) //屏蔽掉ctrl d 出现死循环的情况
    {
      // printf("\n");
      continue;
    }

    const char *mark = " "; //分割标识符,用strtok函数以空格为分割标识对字符串commod进行分割,将每个指令取出来.
    int i = 1;
    argv[0] = strtok(commod, mark);
    while (argv[i] = strtok(NULL, mark))
    {
      i++;
    }
    // free(commod);
    commodAnalsy(argv, i);//解析参数的函数
     free(commod);
  }
}

```

