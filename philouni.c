#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  // número de filósofos
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
pthread_mutex_t forks[N];           // mutex para cada tenedor
pthread_t philosopher_thread[N];    // hilo de ejecución de cada filósofo

void *philosopher(void *arg) {
    int i = *(int *) arg;
    while (1) {
        printf("Filósofo %d está pensando...\n", i);
        sleep(rand() % 5 + 1);  //t.pensando
        printf("Filósofo %d tiene hambre y quiere comer...\n", i);
        state[i] = HUNGRY;
        pthread_mutex_lock(&forks[LEFT]);  // pillar tenedor izquierdo
        printf("Filósofo %d tiene el tenedor izquierdo (%d)...\n", i, LEFT);
        pthread_mutex_lock(&forks[RIGHT]);  // pillar tenedor derecho
        printf("Filósofo %d tiene ambos tenedores (%d, %d) y está comiendo...\n", i, LEFT, RIGHT);
        state[i] = EATING;  // comiendo
        sleep(rand() % 5 + 1);  //t.coienddo
        printf("Filósofo %d ha terminado de comer y suelta ambos tenedores (%d, %d)...\n", i, LEFT, RIGHT);
        pthread_mutex_unlock(&forks[LEFT]);  // suelta tenedor izquierdo
        pthread_mutex_unlock(&forks[RIGHT]);  // suelta el tenedor derecho
        state[i] = THINKING;  // vuelve a pensar
    }
    return NULL;
}

int main() {
    int i;
    for (i = 0; i < N; i++) {
        state[i] = THINKING;  // empiezan pensando
        pthread_mutex_init(&forks[i], NULL);  // inicializar mutex de cada tenedor
        pthread_create(&philosopher_thread[i], NULL, philosopher, &i);  // crear hilo de ejecución para cada filósofo
    }
    for (i = 0; i < N; i++) {
        pthread_join(philosopher_thread[i], NULL);  // esperar a que todos los hilos terminen
    }
    return 0;
}
