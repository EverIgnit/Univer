#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

static volatile sig_atomic_t sflag;

static sigset_t signal_new, signal_old, signal_leer;

static void sigfunc(int sig_nr)
{
  fprintf(stderr, "SIGPIPE �������� ���������� ���������\n");
  exit(0);
}

void signal_pipe(void)
{
  if(signal(SIGPIPE, sigfunc) == SIG_ERR)
  {
    fprintf(stderr, "���������� �������� ������ SIGPIPE\n");
    exit(0);
  }
  /*������� ��� ������� �� ��������� ��������*/

  sigemptyset(&signal_leer);

  sigemptyset(&signal_new);

  sigaddset(&signal_new, SIGPIPE);

  /*������������� signal_new � ��������� ���*/

  /* ������ ������ �������� ����� signal_old*/

  if(sigprocmask(SIG_UNBLOCK, &signal_new, &signal_old) < 0)
    exit(0);
}

int main()
{
  int r_fifo, w_fifo; /*����������� FIFO*/
  int number = 0;
  int numbuf=0;
  char buffer[]="��������� ������ ��� fifo\n";
  char buf[100];
  char simb = '*';
  char symbbuf = '*';
  pid_t pid;

  signal_pipe();
  unlink("/tmp/fifo0001.1");
  /*������� FIFO*/
  if((mkfifo("/tmp/fifo0001.1", O_RDWR)) == -1)
    {
        fprintf(stderr, "���������� ������� fifo\n");
        exit(0);
    }

  pid=fork();
  if(pid == -1)
    {
        perror("fork"); exit(0);
    }
  else if(pid > 0) /*�������� ������ �� FIFO*/
  {
    if (( r_fifo=open("/tmp/fifo0001.1", O_RDONLY))<0)
    {
        perror("r_fifo open"); exit(0);
    }

    /*���� ��������� �������*/
    while(wait(NULL)!=pid);

     /*������ �� FIFO*/
    read(r_fifo, &numbuf, sizeof(numbuf));
    printf("%s\n",numbuf);

    read(r_fifo, &buf, sizeof(buf));
    printf("%s\n",buf);

    read(r_fifo, &symbbuf, sizeof(symbbuf));
    printf("%s\n",symbbuf);

    close(r_fifo);

  }

  else /*������� ���������� � FIFO*/

  {

    if((w_fifo=open("/tmp/fifo0001.1", O_WRONLY))<0)

      { perror("w_fifo open"); exit(0); }

    /*���������� � FIFO*/
    write(w_fifo, number, strlen(number));

    write(w_fifo, buffer, strlen(buffer));

    write(w_fifo, symb, strlen(symb));

    close(w_fifo); /*EOF*/

    exit(0);

  }

  return 0;

}
