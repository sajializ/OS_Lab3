#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include <stdio.h>

#define NUMBER_OF_PROCESSES 10
#define ONE 1
#define UPPER_BOUND 1000000

int main(int argc, char const *argv[])
{
	int pid = getpid();
	int i;

	for (i = ONE; i < NUMBER_OF_PROCESSES; ++i)
	{
		if (pid > 0)
		{
			switch(i)
			{
				case 2:
					set_proc_queue(pid, 1);
					set_proc_ticket(pid, 16);
					break;

				case 4:
					set_proc_queue(pid, 2);
					break;

				case 6:
					set_proc_queue(pid, 1);
					set_proc_ticket(pid, 24);
					break;

				case 8:
					set_proc_queue(pid, 1);
					set_proc_ticket(pid, 40);
					break;
				case (NUMBER_OF_PROCESSES-1):
					print_processes();
					break;
				default:
					break;
			}
			pid = fork();
		}
	}

	if(pid < 0)
    {
        printf(2, "Fork failed!\n");
    }
	else if (pid == 0)
	{
        int sum = 1;
        for(int i = 1; i < UPPER_BOUND; i++)
            sum += i;
		printf(2, "Pointless Loop: %d\n", sum);	
	}
	else
	{
		for (i = 0; i < NUMBER_OF_PROCESSES; i++)
			wait();
		printf(1, "The test has completed!\n");
	}

	exit();
	return 0;
}