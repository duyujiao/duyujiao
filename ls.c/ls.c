//stat结构体定义
struct stat {
         mode_t     st_mode;       	//文件访问权限
         ino_t      st_ino;   		//索引节点号
         dev_t      st_dev;        	//文件使用的设备号
         dev_t      st_rdev;       	//设备文件的设备号
         nlink_t    st_nlink;      	//文件的硬连接数
         uid_t      st_uid;        	//所有者用户识别号
         gid_t      st_gid;        	//组识别号
         off_t      st_size;      	//以字节为单位的文件容量
         time_t     st_atime;      	//最后一次访问该文件的时间
         time_t     st_mtime;      	//最后一次修改该文件的时间
         time_t     st_ctime;      	//最后一次改变该文件状态的时间
         blksize_t st_blksize;    	//包含该文件的磁盘块的大小
         blkcnt_t   st_blocks;     	//该文件所占的磁盘块
      };
/*st_mode文件类型信息的宏
    S_ISLNK(st_mode)： 判断是否为符号链接
    S_ISREG(st_mode)：判断是否为一般文件
    S_ISDIR(st_mode)：判断是否为目录文件
    S_ISCHR(st_mode)：判断是否为字符设备文件
    S_ISBLK(st_mode)：判断是否为快设备文件
    S_ISFIFO(st_mode)：判断是否为先进先出FIFO
    S_ISSOCK(st_mode)：判断是否为socketP
*/