#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex_lock;

// 쓰레드 함수 
// 1초를 기다린후 아규먼트^2 을 리턴한다. 
void *t_function(void *data)
{
	pthread_mutex_lock(&mutex_lock);
	int i = 10;
	while (i--)
	{
	    printf("i %d, num %d\n", i, *((int *)data));
		usleep(500);
		(*((int *)data))++;
	}
	pthread_mutex_unlock(&mutex_lock);
    return (void*)(long)(*((int *)data)*(*((int *)data)));
}

int main()
{
    pthread_t p_thread[2];
    int thr_id;
    int status;
    int a = 100;
//	int b = 200;

	pthread_mutex_init(&mutex_lock, NULL);
    thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)&a);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)&a);
    if (thr_id < 0)
    {
        perror("thread create error : ");
        exit(0);
    }
    // 쓰레드 식별자 p_thread 가 종료되길 기다렸다가
    // 종료리턴값을 가져온다.
    pthread_join(p_thread[0], (void *)&status);
    printf("thread[0] join : %d\n", status);
    pthread_join(p_thread[1], (void *)&status);
    printf("thread[1] join : %d\n", status);

    return 0;
}
