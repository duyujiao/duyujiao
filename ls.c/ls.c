//dirent结构体，指向目录和目录中的具体函数
struct dirent
{
     long d_ino;     	/* 索引节点号 */
     off_t d_off; 		/*在目录文件中的偏移 */
     unsigned short d_reclen; 		/*文件名长 */
     unsigned char d_type; 			/*文件类型 */
     char d_name [NAME_MAX+1];	 	/* 文件名，最长255字符 */
 }

