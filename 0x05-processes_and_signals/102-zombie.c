#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * infinite_while - Run infinite while loop
 * Return: Always 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Creates five zombie processes
 * Return: Always 0
 */
int main(void)
{
	pid_t pid; /* Variable store process ID */
	char count = 0; /* Counter for loop */

	while (count < 5) /* Create 5 child processes using fork() */
	{
		pid = fork(); /* Fork a new process */
		if (pid > 0)
		{
			/* Parent process enters this block */
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1); /* wait for 1 sec to let child process become a zombie */
			count++; /* counter to create next child process */
		}
		else
			/* Child process enters this block */
			exit(0); /* Child process exits immediately */
	}

	infinite_while();

	return (EXIT_SUCCESS); /* program exits successfully */
}
