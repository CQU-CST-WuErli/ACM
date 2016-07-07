#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int count=0;                     //����һ��ȫ�ֱ������������


//*******************************����ṹ��*********************************************

struct question
{
	char id[256];		        //��Ŀ���    /*����Ŀ��Ϣͳһ������ַ�����Ϊ�˶�д��������*/
	char intro[256];			//��Ŀ���
	char level[256];			//��Ŀ�Ѷ� :1     2    3    4    5
								//       ��� �� ��ͨ ���� ����
	char title[256];			//���
	char choice[256];			//ѡ��
	char answer[256];			//��
	int  count;					//���ⱻѡ�д���
	struct question *next;		//ָ����һ����
};


//*****************************��Ҫ��������************************************
void pchapter(struct question * head,int *&a);                             //ͳ��ÿ������
void menu(struct question * head);                                         //�˵���������ʾ�����Ϣ�Ͳ���
void printQuestion(struct question * head);                                //���һ����Ŀ
void inputQuestion(struct question * head);                                //����һ����Ŀ
struct question *  searchQuestion1(struct question * head,char *s );       //����Ų�ѯһ����Ŀ�����ؽڵ�ָ��
void searchQuestion2(struct question * head );                             //��ѯ��Ŀ
void addQuestion(struct question * head) ;			                       //������Ŀ
void modifyQuestion(struct question * head);		                       //�޸���Ŀ
void deleteQuestion(struct question * head);		                       //ɾ����Ŀ
void saveQuestion(struct question * head);			                       //������Ŀ
void createQuestion(struct question * head,int *pcount);		           //�����Ծ�

struct question *  Read();                                                         //������Ŀ
void random(double hard,int * chapter,int*pcount,struct question * p,FILE *fp1,FILE *fp2) ;//��ȡ����



//*****************************main����**************************************
int main()
{
	int c,i;
	struct  question  *head;//����һ��ͷָ��	
	head=Read() ;	       //���ļ���ȡ��Ŀ������
	int pcount[7]={0};     //����һ��������ÿ������
	int *q;
	q=pcount;
	pchapter(head,q);       //���ú���ͳ��ÿ������
	for(i=1;i<8;i++)
		count+=q[i-1];      //������=ÿ���������
	
	printf("                       ��ӭ����C������������ϵͳ��\n\n");
	
	do
	{
		menu(head);
		scanf("%d",&c);
		switch (c) 
		{
		case 1: //��ѯ����
			searchQuestion2(head);
			system("pause");//��ͣ�����Ļ
			break;
		case 2://��������
			addQuestion(head);
			break;
		case 3:  //�޸�����
			modifyQuestion(head);
			break;
		case 4: //ɾ������
			deleteQuestion(head);
			break;
		case 5: //�����Ծ�
			createQuestion(head,pcount);
			system("pause");
			break;
		case 0:
			saveQuestion(head); //��������Ĳ���
			puts("                    ��ӭ�ٴ�ʹ��C������������ϵͳ��\n\n");
			break;
		}	
	}while(c);
	return 0;
}

//************************************��Ҫ��������*******************************


//ͳ��ÿ������
void pchapter(struct question * head,int * &a)
{
	int i;
	for(i=1;i<=8;i++)//i��ʾ�½�
	{
		struct question * q=head;
		for(;q;q=q->next)//������ı���
			if(int(q->id[1])==i+48)//�ַ���ת��Ϊ���ͱȽϣ��ж���Ŀ�½��Ƿ�Ϊ��ǰ�½�
				a[i-1]++;
	}
}

//�˵�����
void menu(struct question * head)										
{
	int pcount[7]={0};
	int *q;
	q=pcount;
	pchapter(head,q);//���ú���ͳ��ÿ������
    int i;
	puts("    - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -  ");
	printf("   |                       ����⹲��7�£�%d����                     |\n",count);
	for(i=1;i<8;i++)
		printf("   |                            ��%d��: %d��                           |\n",i,q[i-1]);
	puts("    - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -  ");
	puts("   |          ******************1.��ѯ����******************          |");
	puts("   |          ******************2.�������******************          |");
	puts("   |          ******************3.�޸�����******************          |");
	puts("   |          ******************4.ɾ������******************          |");
	puts("   |          ******************5.�����Ծ�******************          |");
	puts("   |          ******************0.�����˳�******************          |");
	puts("    - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - ");
	printf("   ��ѡ��Ҫ���еĲ���:  ");
}

//���һ��
void printQuestion(struct question * head)
{
	printf("********************************************************************************\n\n");
	printf("   ��ţ�%s\n",head->id);
	printf("   ��Ŀ��飺%s\n",head->intro);
	printf("   ��Ŀ�Ѷȣ�%s\n",head->level);
	printf("   ��Ŀ: %s\n",head->title);
	printf("   ѡ�%s\n",head->choice);
	printf("   �𰸣�%s\n",head->answer);
	printf("   ��Ŀ��ѡ������%d\n\n",head->count);
	printf("********************************************************************************\n\n");
}

//����һ��
void inputQuestion(struct question * q)
{
	   int i;
	   printf("   ��������Ŀ����:");
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
		printf("   ��������Ŀ�Ѷ�:");
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
		printf("   ��������Ŀ:");
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
		printf("   ������ѡ��:");
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
		printf("   �������:");
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

//������ҵ�һ�Ⲣ���ؽ��ָ�룬����ɾ�����޸�ʱ�Ȳ�ѯ�Ƿ����
struct question *  searchQuestion1(struct question * head,char *s)
{
		for(;head;head=head->next)
		    if((head->id[0]==s[0])&&(head->id[1]==s[1])&&(head->id[3]==s[3])&&(head->id[4]==s[4])&&(head->id[2]==s[2])) 
				break;
		return head;//���û�д��⣬ָ���ƶ�������β��head=NULL
}


//��ѯ�������Ŀ��Ϣ
void searchQuestion2(struct question * head )		
{
	char s[256];	
	int ok=0,choice;
	printf("   ��ѡ��: 1.���½ڲ�ѯ\n           2.����Ų�ѯ\n           3.����Ŀ�ѶȲ�ѯ\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:
		printf("   �������½ں�(�磺01):");
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
			puts("   û�д������������");
		break;
	case 2:
		printf("   �������½ںš����(��:01001):");
		scanf("%s",&s);
		if(searchQuestion1( head,s))
	        printQuestion(searchQuestion1(head,s ));
		else		
			puts("   û�д������������");
		break;
	case 3:
		printf("   �������Ѷ�(1~5 , 1��򵥣�5����):  ");
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
			puts("   û�д������������");
		break;
	default:
		puts("   û�д������������");
		break;
	}
}


//������Ŀ
void addQuestion(struct question * head) 
{
	
	char s[2];
	int ok=0;
	printf("   ������������Ŀ���½ں�(�磺01,Ĭ�������ÿ�����):");
	scanf("%s",&s);
	struct question * q=(struct question*)malloc(sizeof(struct question)); //�����µĽ��
	for(;head;head=head->next)
	{
		if((head->id[1]==s[1])&&(head->next->id[1]==s[1]+1)) 
		{ 
			ok=1;
			break;
		}                                  
		else continue;
	}//�ҵ�ÿ�����һ���ָ��
	if(!ok)
		puts("   ��������");
	else
	{
		count++;   //��������1
		puts("   ��������Ŀ��Ϣ���������»��ߴ���ո�!��");
		strcpy(q->id,head->id);
		inputQuestion(q);//����������Ŀ����Ϣ
		q->next=head->next;
		head->next=q;     //�µ�����
		puts("   ����ɹ���");
		q->id[4]++;
		if(q->id[4]>'9')
		{
			q->id[4]='0';
		    q->id[3]++;
		}//�ı����Ӻ���Ŀ�ı��
	}
} 

//�޸���Ŀ
void modifyQuestion(struct question * head) 
{
	char s[256];
	int ok=0;
	printf("   ������Ҫ�޸ĵ�������½ںš����(�磺01001):");
	scanf("%s",&s);
	if(!searchQuestion1( head,s))
		puts("   û�д��⣡");  //�Ȳ�ѯ�Ƿ����
	else
	{
		puts("   Ҫ�޸ĵ���ĿΪ��");
		printQuestion(searchQuestion1(head,s ));
		puts("   ��������Ŀ��Ϣ���������»��ߴ���ո�!��");
		inputQuestion(searchQuestion1(head,s ));
		puts("   �޸ĳɹ���");
	}
}

//ɾ����Ŀ
void deleteQuestion(struct question * head) 
{
	char s[256];
	int ok=0,temp;
	printf("   ������Ҫɾ����������½ںš����(�磺01001):");
	scanf("%s",&s);
	if(!searchQuestion1( head,s))
		puts("   û�д��⣡");  //�Ȳ�ѯ�Ƿ����
	else
	{
		puts("   Ҫɾ������ĿΪ��");
		printQuestion(searchQuestion1( head,s));
		puts("   ȷ��ɾ����(y/n)");
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
			}//�ҵ�ǰһ���ָ��
			struct  question * p=(struct  question *)malloc(sizeof(struct  question *));
	        struct  question * q=(struct  question *)malloc(sizeof(struct  question *));
			temp=head->next->id[1];//temp��ű�ɾ����Ŀ���½�
			p=head->next;
			q=p->next;
			head->next=q;//ɾ������ڵ�
		    for(;q&&q->id[1]==temp;q=q->next)
			{
			    if(q->id[1]==temp)
				    q->id[4]--;
				    if(q->id[4]<'0')
			    	{
				    	q->id[4]='9';
				        q->id[3]--;
					}
			} //�ı�ɾ��������
			puts("   ɾ���ɹ���");
			count--;//��������1
		
		}
	}
}



//������Ŀ
void saveQuestion(struct question * head) 
{
	{
		struct question *p;
		FILE *fp1;
		/* ����������ļ� */
		if( (fp1=fopen("TIKU.txt","w")) == NULL )
		{
			printf("����ʧ��!");
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

//�����Ծ�
void createQuestion(struct question * head,int *pcount) //��pcount��������ÿ������
{
	srand(time(NULL));
	int number=0,num=0,chapter[7],choice,i;//number��¼��������chapter��¼ÿ������
	double hard;
	char s[100];
	printf("   �������ļ�����λ�ã�");
	gets(s);
	FILE *fp1,*fp2;
	if( (fp1=fopen(s,"w")) == NULL )
	{
		printf("�����Ծ�ʧ��!");
		exit(-1);
	}
	if( (fp2=fopen("��.txt","w")) == NULL )
	{
		printf("   �����Ծ�ʧ��!");
		exit(-1);
	}
	puts("   ��ѡ���Ծ����ɷ�ʽ");
	puts("   1.�˹�ָ���Ծ���Ϣ  2.�����������(����������20��Ĭ���Ѷ�3.5���ң�");
	scanf("%s",&choice);
	switch (choice)
	{
	case 1: 
		printf("   ��������Ŀ������������100���⣬��������룡����");
	    scanf("%d",&number);
		printf("   �������Ծ��Ѷ�(1~5):");
		scanf("%d",&hard);
		puts("   �������Ծ����(��������������������):");
		for(i=1;i<8;i++)
		{
			printf("   ��%d����Ŀ����:",i);
			scanf("%d",&chapter[i-1]);
			num+=chapter[i-1];
		}//����ÿ������
		if(num!=number)
		{
			printf("��Ŀ��������ȷ!\n");
			return ;
		}//�ж�ÿ������֮���Ƿ����������
		random(hard,chapter,pcount,head,fp1,fp2);//����������⺯��
		printf("   �������ɳɹ�!\n   �𰸱����ڵ�ǰ·���£���.txt \n");
		break;
	case 2:
		for(i=1;i<8;i++)
		{
			chapter[i-1]=rand()%10+1;
		    number+=chapter[i-1];
		}
		random(3.5,chapter,pcount,head,fp1,fp2);
		printf("   �������ɳɹ�!\n   �𰸱����ڵ�ǰ·���£���.txt \n");
		break;
	default:puts("   ��������");
	}
	fclose(fp1);
}


//������⺯��
void random(double hard,int * chapter,int*pcount,struct question * p,FILE *fp1,FILE *fp2) 
{
	int ok=0,count=0;
	struct question * head=NULL;
	struct question * headtail=NULL;
	do  //����ԭ����
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
	fprintf(fp2,"�ܹ�%d��\n����:",count);
	for( z=1;z<8;z++)
	{
	
		fprintf(fp2,"��%d��%d�⣬",z,*(chapter+z-1));
	}
	fprintf(fp2,"\n�Ծ�ƽ���Ѷ�:%g\n��:\n",hard);
	for(int j=0;j<7;j++)  //j��ʾ�½�
	{
		count=0;
		struct question * pnew=(struct question*)malloc(sizeof(struct question));
		pnew->next=NULL;
		for(int m=0; ;m++ )  //�ҵ����½�
		{
			int n=(head->id[1]-j-49);  //�ַ�ת��Ϊ���αȽ�
			if(n==0)	
				break;
			head=head->next;	
		}
		for(int y=0; y<pcount[j] && count<*(chapter+j) ;y++)                 //�ж��Ѷ�
		{
			double x = head->level[0]-48;
			if((x<hard+2)&&(x>hard-2))
			{
				struct question * pnew2=(struct question*)malloc(sizeof(struct question));
				head->count++;//��Ŀ���鵽�Ĵ�����1
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


//������Ŀ
struct question *  Read()  //������Ŀ
{
	struct question *head,*tail,*pnew;//����һ��ͷָ�룬βָ�룬���ָ��
	FILE *fp;
	char string[256];
	int size;
	head=NULL;
	tail=NULL;
	pnew=NULL;
    size=sizeof(struct question);
	fp=fopen("���.txt","r");
	if(fp==NULL)
	{
		printf("�����ʧ��!\n");
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
		pnew->count=atoi(string);//���ַ���ת��Ϊ������
		fgets(string,256,fp);
		fgets(string,256,fp);
		if(head==NULL)
			head=pnew;
		else
			tail->next=pnew;
		tail=pnew;	
	}//���ν���Ŀ�����㲢���ӳ�����
	fclose(fp);
	return head;
}


