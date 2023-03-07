typedef struct Athlete   /*定义运动员管理信息的结构体。typedef用来指定新的类型名来代替已有的类型名*/
{
	char name[10];//姓名
	char sex[4];//性别
	char school[10];//学院
	int number;//学号
	int age;//年龄
	int score[3];//800m,跳高，跳远三门成绩
	float aver;
}athtype;

typedef struct Athletenode   /*使用链表录入运动员数据athtype data*/
{
	athtype data;
	struct Athletenode* next;
}Listnode;
Listnode* Head = NULL;