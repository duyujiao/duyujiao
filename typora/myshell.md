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

```c
int isdo(char *argv[], int count)//解析参数
{
  int flag = 10, i;
  if (argv[0] == NULL)
    return 0;
  if (strcmp(argv[0], "cd") == 0)
  {
    flag = 1;
  }
  for (i = 0; i < count; i++)
  {
    if (strcmp(argv[i], ">") == 0)
      flag = 2;
    if (strcmp(argv[i], "|") == 0)
      flag = 3;
    if (strcmp(argv[i], ">>") == 0)
      flag = 4;
    if (strcmp(argv[i], "<") == 0)
      flag = 5;
    if (strcmp(argv[i], "<<") == 0)
      flag = 6;
    if (strcmp(argv[i], "&") == 0)
    {
        pass = 1;
        argv[i]=NULL;
    }
  }
  return flag;
}
void commodAnalsy(char *argv[], int number)
{
  int flag = isdo(argv, number);
  if(pass==1)
  {
    number--;
  }
  if (flag == 1)
  {
    mycd(argv);
  }
  else if (strcmp(argv[0], "history") == 0)
  {
    ShowHistory();
  }
  else if (strcmp(argv[0], "exit") == 0)
  {
    printf("exit\n");
    printf("有停止的任务\n");
    exit(0);
  }
  else if (flag == 2) //输出重定向'>'
  {
    mydup(argv);
  }
  else if (flag == 3) //管道'|'
  {
    callCommandWithPipe(argv, number);
  }
  else if (flag == 4) //输出重定向'>>'
  {
    mydup2(argv);
  }
  else if (flag == 5)//输入重定向'<'
  {
    mydup3(argv);
  }
  else if (flag == 10) //需要子进程进行执行的第三方函数
  {
    if (strcmp(argv[0], "ll") == 0)
    {
      strcpy(argv[0], "ls");
      argv[number++] = "-l";
    }
    if (strcmp(argv[0], "ls") == 0)
      argv[number++] = "--color=auto";
    pid_t pid = fork();
    if (pid < 0)
    {
      perror("fork");
      exit(1);
    }
    else if (pid == 0) //子进程
    {
      execvp(argv[0], argv); //执行命令
      perror("commod");
      exit(1);
    }
    else if (pid > 0) //父进程
    {
      if(pass==1)
      {
        pass=0;
        printf("%d\n",pid);
        return;
      }
      waitpid(pid, NULL, 0);
    }
  }
}

```

