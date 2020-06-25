#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>

#define MAX_SIZE 10000

struct proces
{
	int pid, ppid;
    char user[MAX_SIZE], cpu[MAX_SIZE], mem[MAX_SIZE], vsz[MAX_SIZE], rss[MAX_SIZE], tty[MAX_SIZE], stat[MAX_SIZE], start[MAX_SIZE], time[MAX_SIZE], command[MAX_SIZE];
};

struct proces procese[MAX_SIZE];

int nr_procese = 1;
int succesori[MAX_SIZE][MAX_SIZE];
int nr_succesori[MAX_SIZE];
char cale_proiect[MAX_SIZE] = "";

int Proces_fct_pid[MAX_SIZE];


FILE *f1, *f2;
char c;

void citire_user(){
	while(fscanf(f1, "%c", &c))
        {

            if(c == ' ')
                break;
            int l = strlen(procese[nr_procese].user);
            procese[nr_procese].user[l] = c;

        }
}
void citire_pid(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].pid = (c - '0');
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            procese[nr_procese].pid = procese[nr_procese].pid * 10 + (c - '0');
		        }
		        break;
            }
        }
}

void citire_cpu(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].cpu[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].cpu);
		            procese[nr_procese].cpu[l] = c;
		        }
                break;
            }
        }
}

void citire_mem(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].mem[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].mem);
		            procese[nr_procese].mem[l] = c;
		        }
                break;
            }
        }
}

void citire_vsz(){
while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].vsz[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].vsz);
		            procese[nr_procese].vsz[l] = c;
		        }
                break;
            }
        }
}

void citire_rss(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].rss[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].rss);
		            procese[nr_procese].rss[l] = c;
		        }
                break;
            }
        }
}

void citire_tty(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].tty[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].tty);
		            procese[nr_procese].tty[l] = c;
		        }
                break;
            }
        }
}

void citire_stat(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].stat[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].stat);
		            procese[nr_procese].stat[l] = c;
		        }
                break;
            }
        }

}

void citire_start(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].start[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].start);
		            procese[nr_procese].start[l] = c;
		        }
                break;
            }
        }

}

void citire_time(){
	while(fscanf(f1, "%c", &c))
        {
            if(c != ' ')
            {
                procese[nr_procese].time[0] = c;
                while(fscanf(f1, "%c", &c))
		        {
		            if(c == ' ')
		                break;
		            int l = strlen(procese[nr_procese].time);
		            procese[nr_procese].time[l] = c;
		        }
                break;
            }
        }

}

void citire_command(){
	while (fscanf(f1, "%c", &c))
        {
            if (c != ' ')
            {
                procese[nr_procese].command[0] = c;
                while (fscanf(f1, "%c", &c))
		        {
		            if (c == '\n')
		                break;
		            int l = strlen(procese[nr_procese].command);
		            procese[nr_procese].command[l] = c;
		        }
                break;
            }
        }
}



void citire()
{
	f1 = fopen("proces_aux.txt", "r");
	f2 = fopen("proces_pid_ppid.txt", "r");



    char fileText [100];
    fgets (fileText, 100, f1);
    fgets (fileText, 100, f2);



    while(!feof(f2))
    {

    	int a,b;

        fscanf(f2, "%d %d", &a, &b);
        procese[nr_procese].pid = a;
        procese[nr_procese].ppid = b;

        Proces_fct_pid[procese[nr_procese].pid] = nr_procese;

        fscanf(f1, "%c", &c);
        procese[nr_procese].user[0] = c;
        if (c == '\n')
        {
            break;
        }

        citire_user();
        citire_pid();
        citire_cpu();
        citire_mem();
        citire_vsz();
        citire_rss();
        citire_tty();
        citire_stat();
        citire_start();
        citire_time();
        citire_command();


        nr_procese += 1;


    }

    fclose(f1);
    fclose(f2);
}

void matriceSuccesori()
{
    int pid_proces, pid_tata, index_tata;


    for (int i = 0; i < nr_procese; i++)
    {
    	pid_tata = procese[i].ppid;
    	index_tata = Proces_fct_pid[pid_tata];
        pid_proces = procese[i].pid;

        if (pid_tata != pid_proces)
        {
            nr_succesori[index_tata]++;
            int n = nr_succesori[index_tata];
            succesori[n][index_tata] = i;
        }
    }
}


char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;

    if(i<0){
        *p++ = '-';
        i *= -1;
    }

    int shifter = i;
    do{
        ++p;
        shifter = shifter/10;
    }while(shifter);

    *p = '\0';

    do{
        *--p = digit[i%10];
        i = i/10;
    }while(i);

    return b;
}

void verificare(int proces, char* cd)
{
	if (proces > 0)
    {
        FILE *fout;
        char cale_creata[MAX_SIZE] = "";
        strcpy(cale_creata, cd);
        strcat(cale_creata, "stats");
        fout = fopen(cale_creata, "w");

        fprintf(fout, "User: %s\n",procese[proces].user);
        fprintf(fout, "Pid: %d\n",procese[proces].pid);
        fprintf(fout, "Ppid: %d\n",procese[proces].ppid);
        fprintf(fout, "Cpu: %s\n",procese[proces].cpu);
        fprintf(fout, "Mem: %s\n",procese[proces].mem);
        fprintf(fout, "Vsz: %s\n",procese[proces].vsz);
        fprintf(fout, "Rss: %s\n",procese[proces].rss);
        fprintf(fout, "Tty: %s\n",procese[proces].tty);
        fprintf(fout, "Stat: %s\n",procese[proces].stat);
        fprintf(fout, "Start: %s\n",procese[proces].start);
        fprintf(fout, "Time: %s\n",procese[proces].time);
        fprintf(fout, "Command: %s\n",procese[proces].command);

		printf("Am creat fisierul pentru procesul: %d \n",proces);
        fclose(fout);
    }
}



void stats(int proces_curent, char cale_director[MAX_SIZE])
{


    verificare(proces_curent,cale_director);

    int fiu, pid_fiu;

    for (int i = 1; i <= nr_succesori[proces_curent]; i++)
    {
        fiu = succesori[i][proces_curent];
        pid_fiu = procese[fiu].pid;
        char pid_string[MAX_SIZE] = "",cale_fiu[MAX_SIZE] = "";
 		struct stat st = {0};


        itoa(pid_fiu,pid_string);

        strcpy(cale_fiu, cale_director);
        strcat(cale_fiu, "/");
        strcat(cale_fiu, pid_string);


        if (stat(cale_fiu, &st) == -1)
        {
            mkdir(cale_fiu, 0777);
	    	printf("Am creat directorul %s \n",cale_fiu);
		}

        strcat(cale_fiu, "/");
        stats(fiu, cale_fiu);
    }

}

int main(int argc, char* argv[])
{
	system("ps -aux > proces_aux.txt");
    system("ps xao pid,ppid > proces_pid_ppid.txt");

    char buf[1024];
	getcwd(buf,sizeof(buf));
	strcpy(cale_proiect,buf);

	citire();

    matriceSuccesori();

	for (int i = 0; i < nr_procese; i++)
		printf("%d %d \n", procese[i].pid,procese[i].ppid);

	for (int i =0; i< nr_procese;i++)
	{
		for (int j =0; j<nr_procese;j++)
			printf("%d ", succesori[i][j]);
		printf("\n");
	}

    stats(0, cale_proiect);

    return 0;
}
