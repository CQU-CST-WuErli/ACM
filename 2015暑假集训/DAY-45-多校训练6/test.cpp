#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int count=0;                     //定义一个全局变量存放总题数


//*******************************定义结构体*********************************************

struct question
{
	char id[256];		        //题目编号    /*将题目信息统一定义成字符串是为了读写操作方便*/
	char intro[256];			//题目简介
	char level[256];			//题目难度 :1     2    3    4    5
								//       最简单 简单 普通 困难 超难
	char title[256];			//题干
	char choice[256];			//选项
	char answer[256];			//答案
	int  count;					//该题被选中次数
	struct question *next;		//指向下一道题
};


//*****************************主要函数声明************************************
void pchapter(struct question * head,int *&a);                             //统计每章题数
void menu(struct question * head);                                         //菜单函数，显示题库信息和操作
void printQuestion(struct question * head);                                //输出一道题目
void inputQuestion(struct question * head);                                //输入一道题目
struct question *  searchQuestion1(struct question * head,char *s );       //按编号查询一道题目并返回节点指针
void searchQuestion2(struct question * head );                             //查询题目
void addQuestion(struct question * head) ;			                       //增加题目
void modifyQuestion(struct question * head);		                       //修改题目
void deleteQuestion(struct question * head);		                       //删除题目
void saveQuestion(struct question * head);			                       //保存题目
void createQuestion(struct question * head,int *pcount);		           //生成试卷

struct question *  Read();                                                         //读入题目
void random(double hard,int * chapter,int*pcount,struct question * p,FILE *fp1,FILE *fp2) ;//抽取试题



//*****************************main函数**************************************
int main()
{
	int c,i;
	struct  question  *head;//定义一个头指针	
	head=Read() ;	       //从文件读取题目至链表
	int pcount[7]={0};     //定义一个数组存放每章题数
	int *q;
	q=pcount;
	pchapter(head,q);       //调用函数统计每章题数
	for(i=1;i<8;i++)
		count+=q[i-1];      //总题数=每章题数相加
	
	printf("                       欢迎来到C语言试题库管理系统！\n\n");
	
	do
	{
		menu(head);
		scanf("%d",&c);
		switch (c) 
		{
		case 1: //查询试题
			searchQuestion2(head);
			system("pause");//暂停输出屏幕
			break;
		case 2://增加试题
			addQuestion(head);
			break;
		case 3:  //修改试题
			modifyQuestion(head);
			break;
		case 4: //删除试题
			deleteQuestion(head);
			break;
		case 5: //生成试卷
			createQuestion(head,pcount);
			system("pause");
			break;
		case 0:
			saveQuestion(head); //保存对题库的操作
			puts("                    欢迎再次使用C语言试题库管理系统！\n\n");
			break;
		}	
	}while(c);
	return 0;
}

//************************************主要函数定义*******************************


//统计每章题数
void pchapter(struct question * head,int * &a)
{
	int i;
	for(i=1;i<=8;i++)//i表示章节
	{
		struct question * q=head;
		for(;q;q=q->next)//单链表的遍历
			if(int(q->id[1])==i+48)//字符型转变为整型比较，判断题目章节是否为当前章节
				a[i-1]++;
	}
}

//菜单函数
void menu(struct question * head)										
{
	int pcount[7]={0};
	int *q;
	q=pcount;
	pchapter(head,q);//调用函数统计每章题数
    int i;
	puts("    - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -  ");
	printf("   |                       本题库共有7章，%d道题                     |\n",count);
	for(i=1;i<8;i++)
		printf("   |                            第%d章: %d题                           |\n",i,q[i-1]);
	puts("    - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -  ");
	puts("   |          ******************1.查询试题******************          |");
	puts("   |          ******************2.添加试题******************          |");
	puts("   |          ******************3.修改试题******************          |");
	puts("   |          ******************4.删除试题******************          |");
	puts("   |          ******************5.生成试卷******************          |");
	puts("   |          ******************0.保存退出******************          |");
	puts("    - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - ");
	printf("   请选择要进行的操作:  ");
}

//输出一题
void printQuestion(struct question * head)
{
	printf("********************************************************************************\n\n");
	printf("   题号：%s\n",head->id);
	printf("   题目简介：%s\n",head->intro);
	printf("   题目难度：%s\n",head->level);
	printf("   题目: %s\n",head->title);
	printf("   选项：%s\n",head->choice);
	printf("   答案：%s\n",head->answer);
	printf("   题目被选次数：%d\n\n",head->count);
	printf("********************************************************************************\n\n");
}

//输入一题
void inputQuestion(struct question * q)
{
	   int i;
	   printf("   请输入题目描述:");
		gets(q->intro);
		for(i=0;q->intro[i]!='\0';)
		{
			i++;
		}
		for(int a=i;a<255;a++)
		{
			q->intro[a]=' ';
		}
		q->intro[255]='\0';
		printf("   请输入题目难度:");
		gets(q->level);
		for(i=0;q->level[i]!='\0';)
		{
			i++;
		}
		for(int b=i;b<255;b++)
		{
			q->level[b]=' ';
		}
		q->level[255]='\0';
		printf("   请输入题目:");
		gets(q->title);
		for(i=0;q->title[i]!='\0';)
		{
			i++;
		}
		for(int c=i;c<255;c++)
		{
			q->title[c]=' ';
		}
		q->title[255]='\0';
		printf("   请输入选项:");
		gets(q->choice);
		for(i=0;q->choice[i]!='\0';)
		{
			i++;
		}
		for(int d=i;d<255;d++)
		{
			q->choice[d]=' ';
		}
		q->choice[255]='\0';
		printf("   请输入答案:");
		gets(q->answer);
		for(i=0;q->answer[i]!='\0';)
		{
			i++;
		}
		for(int e=i;e<255;e++)
		{
			q->answer[e]=' ';
		}
		q->answer[255]='\0';
		q->count=0;
}

//按编号找到一题并返回结点指针，用于删除，修改时先查询是否存在
struct question *  searchQuestion1(struct question * head,char *s)
{
		for(;head;head=head->next)
		    if((head->id[0]==s[0])&&(head->id[1]==s[1])&&(head->id[3]==s[3])&&(head->id[4]==s[4])&&(head->id[2]==s[2])) 
				break;
		return head;//如果没有此题，指针移动到链表尾，head=NULL
}


//查询并输出题目信息
void searchQuestion2(struct question * head )		
{
	char s[256];	
	int ok=0,choice;
	printf("   请选择: 1.按章节查询\n           2.按题号查询\n           3.按题目难度查询\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:
		printf("   请输入章节号(如：01):");
		scanf("%s",&s);
		for(;head;head=head->next)
		{
			if((head->id[0]==s[0])&&(head->id[1]==s[1]))
			{
			
				printQuestion(head);
				ok=1;	
			}
		}
		if(!ok) 
			puts("   没有此题或输入有误！");
		break;
	case 2:
		printf("   请输入章节号、题号(如:01001):");
		scanf("%s",&s);
		if(searchQuestion1( head,s))
	        printQuestion(searchQuestion1(head,s ));
		else		
			puts("   没有此题或输入有误！");
		break;
	case 3:
		printf("   请输入难度(1~5 , 1最简单，5最难):  ");
		scanf("%s",&s);
		for(;head;head=head->next)
		{
			if((head->level[0]==s[0])) 
			{
				printQuestion(head);
				ok=1;	
			}
		}
		if(!ok) 
			puts("   没有此题或输入有误！");
		break;
	default:
		puts("   没有此题或输入有误！");
		break;
	}
}


//增加题目
void addQuestion(struct question * head) 
{
	
	char s[2];
	int ok=0;
	printf("   请输入增加题目的章节号(如：01,默认添加在每章最后):");
	scanf("%s",&s);
	struct question * q=(struct question*)malloc(sizeof(struct question)); //插入新的结点
	for(;head;head=head->next)
	{
		if((head->id[1]==s[1])&&(head->next->id[1]==s[1]+1)) 
		{ 
			ok=1;
			break;
		}                                  
		else continue;
	}//找到每章最后一题的指针
	if(!ok)
		puts("   输入有误！");
	else
	{
		count++;   //总题数加1
		puts("   请输入题目信息：（请用下划线代替空格!）");
		strcpy(q->id,head->id);
		inputQuestion(q);//输入增加题目的信息
		q->next=head->next;
		head->next=q;     //新的链表
		puts("   输入成功！");
		q->id[4]++;
		if(q->id[4]>'9')
		{
			q->id[4]='0';
		    q->id[3]++;
		}//改变增加后题目的编号
	}
} 

//修改题目
void modifyQuestion(struct question * head) 
{
	char s[256];
	int ok=0;
	printf("   请输入要修改的试题的章节号、题号(如：01001):");
	scanf("%s",&s);
	if(!searchQuestion1( head,s))
		puts("   没有此题！");  //先查询是否存在
	else
	{
		puts("   要修改的题目为：");
		printQuestion(searchQuestion1(head,s ));
		puts("   请输入题目信息：（请用下划线代替空格!）");
		inputQuestion(searchQuestion1(head,s ));
		puts("   修改成功！");
	}
}

//删除题目
void deleteQuestion(struct question * head) 
{
	char s[256];
	int ok=0,temp;
	printf("   请输入要删除的试题的章节号、题号(如：01001):");
	scanf("%s",&s);
	if(!searchQuestion1( head,s))
		puts("   没有此题！");  //先查询是否存在
	else
	{
		puts("   要删除的题目为：");
		printQuestion(searchQuestion1( head,s));
		puts("   确认删除？(y/n)");
		char ch;
		scanf("%c",&ch);
		if(ch=='y')
		{
		    if(s[4]=='0')
			{
			   for(;head;head=head->next)
			       if(head->id[1]==s[1]&&head->id[4]=='9'&&head->id[3]==s[3]-1)
				       break;
			}
			if(s[4]=='1'&&s[3]=='0')
			{
			    for(;head;head=head->next)
				    if(head->id[1]==s[1]-1&&head->next->id[1]==s[1])
					    break;
			} 
			for(;head;head=head->next)
			{
			     if(head->id[1]==s[1]&&head->id[3]==s[3]&&head->id[4]==s[4]-1)
				     break;
			}//找到前一题的指针
			struct  question * p=(struct  question *)malloc(sizeof(struct  question *));
	        struct  question * q=(struct  question *)malloc(sizeof(struct  question *));
			temp=head->next->id[1];//temp存放被删除题目的章节
			p=head->next;
			q=p->next;
			head->next=q;//删除此题节点
		    for(;q&&q->id[1]==temp;q=q->next)
			{
			    if(q->id[1]==temp)
				    q->id[4]--;
				    if(q->id[4]<'0')
			    	{
				    	q->id[4]='9';
				        q->id[3]--;
					}
			} //改变删除后的题号
			puts("   删除成功！");
			count--;//总题数减1
		
		}
	}
}



//保存题目
void saveQuestion(struct question * head) 
{
	{
		struct question *p;
		FILE *fp1;
		/* 创建试题库文件 */
		if( (fp1=fopen("TIKU.txt","w")) == NULL )
		{
			printf("保存失败!");
			exit(-1);
		}
		for(p=head;p!=NULL;p=p->next) 
		{
			fprintf(fp1,"%s",p->id);
			fprintf(fp1,"%s",p->intro);
			fprintf(fp1,"%s",p->level);
			fprintf(fp1,"%s",p->title);
			fprintf(fp1,"%s",p->choice);
			fprintf(fp1,"%s",p->answer);
			fprintf(fp1,"%d\n\n",p->count);
		}
		fclose(fp1);
	}
}

//生成试卷
void createQuestion(struct question * head,int *pcount) //用pcount获得题库中每章题数
{
	srand(time(NULL));
	int number=0,num=0,chapter[7],choice,i;//number记录总题数，chapter记录每章题数
	double hard;
	char s[100];
	printf("   请输入文件保存位置：");
	gets(s);
	FILE *fp1,*fp2;
	if( (fp1=fopen(s,"w")) == NULL )
	{
		printf("生成试卷失败!");
		exit(-1);
	}
	if( (fp2=fopen("答案.txt","w")) == NULL )
	{
		printf("   生成试卷失败!");
		exit(-1);
	}
	puts("   请选择试卷生成方式");
	puts("   1.人工指定试卷信息  2.机器随机生成(题量不少于20，默认难度3.5左右）");
	scanf("%s",&choice);
	switch (choice)
	{
	case 1: 
		printf("   请输入题目数量（试题库仅100多题，请合理输入！）：");
	    scanf("%d",&number);
		printf("   请输入试卷难度(1~5):");
		scanf("%d",&hard);
		puts("   请输入试卷组成(请合理输入以免产生错误！):");
		for(i=1;i<8;i++)
		{
			printf("   第%d章题目数量:",i);
			scanf("%d",&chapter[i-1]);
			num+=chapter[i-1];
		}//输入每章题数
		if(num!=number)
		{
			printf("题目数量不正确!\n");
			return ;
		}//判断每章题数之和是否等于总题数
		random(hard,chapter,pcount,head,fp1,fp2);//调用随机抽题函数
		printf("   试题生成成功!\n   答案保存在当前路径下：答案.txt \n");
		break;
	case 2:
		for(i=1;i<8;i++)
		{
			chapter[i-1]=rand()%10+1;
		    number+=chapter[i-1];
		}
		random(3.5,chapter,pcount,head,fp1,fp2);
		printf("   试题生成成功!\n   答案保存在当前路径下：答案.txt \n");
		break;
	default:puts("   输入有误！");
	}
	fclose(fp1);
}


//随机抽题函数
void random(double hard,int * chapter,int*pcount,struct question * p,FILE *fp1,FILE *fp2) 
{
	int ok=0,count=0;
	struct question * head=NULL;
	struct question * headtail=NULL;
	do  //复制原链表
	{
		if(!head)
			head=p;
		else
			headtail->next=p;
		headtail=p;
		struct question * headtail=NULL;
		p=p->next;
	}while(p);
	headtail->next=NULL;
	struct question * phead=NULL;
	struct question * ptail=NULL;
	int z;
	for( z=1;z<8;z++)
		count+=*(chapter+z-1);
	fprintf(fp2,"总共%d题\n其中:",count);
	for( z=1;z<8;z++)
	{
	
		fprintf(fp2,"第%d章%d题，",z,*(chapter+z-1));
	}
	fprintf(fp2,"\n试卷平均难度:%g\n答案:\n",hard);
	for(int j=0;j<7;j++)  //j表示章节
	{
		count=0;
		struct question * pnew=(struct question*)malloc(sizeof(struct question));
		pnew->next=NULL;
		for(int m=0; ;m++ )  //找到该章节
		{
			int n=(head->id[1]-j-49);  //字符转换为整形比较
			if(n==0)	
				break;
			head=head->next;	
		}
		for(int y=0; y<pcount[j] && count<*(chapter+j) ;y++)                 //判断难度
		{
			double x = head->level[0]-48;
			if((x<hard+2)&&(x>hard-2))
			{
				struct question * pnew2=(struct question*)malloc(sizeof(struct question));
				head->count++;//题目被抽到的次数加1
				strcpy(pnew2->id,head->id);
				strcpy(pnew2->title,head->title);
				strcpy(pnew2->choice,head->choice);
				strcpy(pnew2->answer,head->answer);
				fprintf(fp1,"%s",pnew2->id);
				fprintf(fp1,"%s",pnew2->title);
				fprintf(fp1,"%s\n",pnew2->choice);
				fprintf(fp2,"%s",pnew2->answer);
				count++;
			}
			
			head=head->next;
			
		}
		
		
		//	}
	}
	
}


//读入题目
struct question *  Read()  //读入题目
{
	struct question *head,*tail,*pnew;//定义一个头指针，尾指针，结点指针
	FILE *fp;
	char string[256];
	int size;
	head=NULL;
	tail=NULL;
	pnew=NULL;
    size=sizeof(struct question);
	fp=fopen("题库.txt","r");
	if(fp==NULL)
	{
		printf("打开题库失败!\n");
		exit(-1);
	}
	fgets(string,256,fp);
	while(!feof(fp))
	{
        pnew=(struct question*)malloc(size);
        pnew->next=NULL;
		strcpy(pnew->id,string);
		fgets(string,256,fp);
        strcpy(pnew->intro,string);
		fgets(string,256,fp);
		strcpy(pnew->level,string);
		fgets(string,256,fp);
		strcpy(pnew->title,string);
        fgets(string,256,fp);
		strcpy(pnew->choice,string);
		fgets(string,256,fp);
		strcpy(pnew->answer,string);
		fgets(string,256,fp);
		pnew->count=atoi(string);//把字符串转换为整型数
		fgets(string,256,fp);
		fgets(string,256,fp);
		if(head==NULL)
			head=pnew;
		else
			tail->next=pnew;
		tail=pnew;	
	}//依次将题目读入结点并连接成链表
	fclose(fp);
	return head;
}


