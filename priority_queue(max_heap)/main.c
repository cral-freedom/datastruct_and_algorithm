#include "priqueue.h"
int test();
void main()
{
	test();
}

void dsp()
{
	printf("priority queue test:\n");
	printf("1.create a priority queue\n");
	printf("2.enqueue\n");
	printf("3.dequeue\n");
	printf("4.printf queue\n");
	printf("9.exit\n");
}
int test()
{
	int i,opt,elem;
	pQueue pQ;
	dsp();
	while(1)
	{
		printf("your option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:exam_queue(&pQ);break;
			case 2:
				printf("elem:");
				scanf("%d",&elem);
				EnQueue(&pQ,elem);
				break;
			case 3:
				DeQueue(&pQ,&elem);
				printf("del max_prio:%d\n",elem);
			case 4:
				pQ_print(pQ);break;
			case 9:
				printf("exit\n");
				return 0;
				break;
		}
	}
}