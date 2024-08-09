/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:59:17 by mrhelmy           #+#    #+#             */
/*   Updated: 2024/08/09 16:31:30 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000LL) + (now.tv_usec / 1000));
}
// int eating(t_philo *philo, double timestamp_in_ms, long long time_bc)
// {
// 	int i = 0;
// 	int death = 0;
// 	// int philo_index = 0;
	
// 	while (1)
// 	{
// 		// if (philo->philo == 1)
// 		// 	philo_index = philo->info->philos - 1;
// 		// else
// 		// 	philo_index = 
// 		if (philo->philo == 1 && (philo->info->forks[0] != 1   // first difference philo->info->forks[philo->info->philos - 1] != 1
// 			&& philo->info->forks[philo->info->philos - 1] != 1)) 
// 		{
// 			{
// 				pthread_mutex_lock(&philo->info->fork_lock[0]); //This will go second after meging both if statements, watch the difference
// 				pthread_mutex_lock(&philo->info->fork_lock[philo->info->philos - 1]);   // second difference 
				
// 				philo->info->forks[0] = 1;  
// 				philo->info->forks[philo->info->philos - 1] = 1; // third differnce philo->info->forks[philo->info->philos - 1] = 1;  but 
// 				timestamp_in_ms = time_now() - time_bc;
// 				printf("%s%d %s%d %shas taken a fork\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
// 				timestamp_in_ms = time_now() - time_bc;
// 				printf("%s%d %s%d %shas taken a fork\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
// 				timestamp_in_ms = time_now() - time_bc;
// 				printf("%s%d %s%d %sis eating\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
// 				philo->last_meal = time_now() - time_bc;
// 			while(i < philo->info->t2eat * 1000)
// 			{
// 				usleep(150);
// 				if ((time_now() - time_bc) - philo->last_meal > philo->info->t2die)
// 					{
// 						death = 1;
// 						 printf("%f %d died\n", timestamp_in_ms, philo->philo);
// 						return (0);
// 					}
// 				i += 150;
// 			}
// 				printf("blsa7a %d\n", philo->philo);
// 				pthread_mutex_unlock(&philo->info->fork_lock[0]);
// 				pthread_mutex_unlock(&philo->info->fork_lock[philo->info->philos - 1]); // forth difference
// 			}
// 			break ;
// 		}
// 		else if ((philo->philo != 1 && philo->info->forks[philo->philo - 1] != philo-> philo
// 			&& philo->info->forks[philo->philo - 2] != philo-> philo))
// 		{
// 			pthread_mutex_lock(&philo->info->fork_lock[philo->philo - 2]);
// 			pthread_mutex_lock(&philo->info->fork_lock[philo->philo - 1]);
// 			philo->info->forks[philo->philo - 1] = philo ->philo;
// 			philo->info->forks[philo->philo - 2] = philo ->philo;
// 			timestamp_in_ms = time_now() - time_bc;
// 			printf("%s%d %s%d %shas taken a fork\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET); // modify the sleep to start from the last meal time (difference) & the begining of the program
// 			timestamp_in_ms = time_now() - time_bc;
// 			printf("%s%d %s%d %shas taken a fork\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
// 			timestamp_in_ms = time_now() - time_bc;
// 			printf("%s%d %s%d %sis eating\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
// 			int i = 0;
// 			while(i < philo->info->t2eat * 1000)
// 			{
// 				usleep(150);
// 				if ((time_now() - time_bc) - philo->last_meal > philo->info->t2die)
// 				{
// 					death = 1;
// 					printf("%f %d died\n", timestamp_in_ms, philo->philo);
// 					return (death);
// 				}
// 				if (death == 1)
// 					return (death);
// 				i += 150;
// 			}
// 			printf("blsa7a %d\n", philo->philo);
// 			pthread_mutex_unlock(&philo->info->fork_lock[philo->philo - 1]);
// 			pthread_mutex_unlock(&philo->info->fork_lock[philo->philo - 2]);
// 			break ;
// 		}
// 	}
//     return (death);
// }
int eating(t_philo *philo, double timestamp_in_ms, long long time_bc)
{
	//int i = 0;
	int death = 0;
	int philo_index = 0;

	while (1)
	{
		if (philo->philo == 1)
			philo_index = philo->info->philos - 1;
		else
			philo_index = philo->philo - 2;
		if ((philo->info->forks[philo->philo - 1] != philo-> philo
			&& philo->info->forks[philo_index] != philo-> philo))
		{
			pthread_mutex_lock(&philo->info->fork_lock[philo_index]);
			pthread_mutex_lock(&philo->info->fork_lock[philo->philo - 1]);
			philo->info->forks[philo->philo - 1] = philo ->philo;
			philo->info->forks[philo_index] = philo ->philo;
			timestamp_in_ms = time_now() - time_bc;
			printf("%s%d %s%d %shas taken a fork\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET); // modify the sleep to start from the last meal time (difference) & the begining of the program
			// timestamp_in_ms = time_now() - time_bc;
			printf("%s%d %s%d %shas taken a fork\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
			// timestamp_in_ms = time_now() - time_bc;
			printf("%s%d %s%d %sis eating\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
			// int i = 0;
			philo->last_meal = time_now() - time_bc;
			// philo->started_meal = time_now() - time_bc;
			// while(i < philo->info->t2eat * 1000)
			// printf(" xxx %d\n", (int)time_now() - (int)philo->started_meal);
			while((time_now() - time_bc) - philo->last_meal < (philo->info->t2eat))
			// while((time_now() - philo->started_meal) < philo->info->t2eat)
			{
				// usleep(150);
				if ((time_now() - time_bc) - philo->last_meal > philo->info->t2die)
				{
					death = 1;
					printf("%f %d died\n", timestamp_in_ms, philo->philo);
					return (death);
				}
				if (death == 1)
					return (death);
				// i += 150;
			}
			timestamp_in_ms = time_now() - time_bc;
			printf("%s%d blsa7a %d\n", CYAN, (int)timestamp_in_ms, philo->philo);
			pthread_mutex_unlock(&philo->info->fork_lock[philo->philo - 1]);
			pthread_mutex_unlock(&philo->info->fork_lock[philo_index]);
			break ;
		}
	}
    return (death);
}

int sleeping(t_philo *philo, double timestamp_in_ms, long long time_bc)
{
	int death = 0;
	// pthread_mutex_lock(&philo->info->sleep_lock);
	timestamp_in_ms = time_now() - time_bc;
    printf("%s%d %s%d %sis sleeping\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
    // usleep(philo->info->t2sleep * 1000);
			// while((time_now() - philo->started_meal) < philo->info->t2eat)
	philo->started_sleep = time_now() - time_bc;
    while((time_now() - time_bc) - philo->started_sleep < (philo->info->t2sleep))
	{
		// usleep(150);
		if ((time_now() - time_bc) - philo->last_meal > philo->info->t2die)
		{
			death = 1;
			printf("%f %d died\n", timestamp_in_ms, philo->philo);
			return (death);
		}
		if (death == 1)
			return (death); // unlock the mutex
		// i += 150;
	}
    // pthread_mutex_unlock(&philo->info->sleep_lock);
    // int i = 0;
	// while(i < philo->info->t2eat * 1000)
	// {
	// 	usleep(150);
	// 	if ((time_now() - time_bc) - philo->last_meal > philo->info->t2die)
	// 	{
	// 		death = 1;
	// 		printf("%f %d died\n", timestamp_in_ms, philo->philo);
	// 		return (death);
	// 	}
	// 	if (death == 1)
	// 		return (death);
	// 	i += 150;
	// }
	return (death);
}

int thinking(t_philo *philo, double timestamp_in_ms, long long time_bc)
{   
	int death = 0;
	pthread_mutex_lock(&philo->info->think_lock);
	timestamp_in_ms = time_now() - time_bc;
    printf("%s%d %s%d %sis thinking\n", CYAN, (int)timestamp_in_ms, RED, philo->philo, RESET);
    pthread_mutex_unlock(&philo->info->think_lock);
    if ((time_now() - time_bc) - philo->last_meal > philo->info->t2die)
	{
		death = 1;
		printf("%f %d died\n", timestamp_in_ms, philo->philo);
		return (death);
	}
	if (death == 1)
		return (death);
	return (death);
}

void *life(void *philo_num)
{
    long long timestamp_in_ms;
	t_philo *philo;
	philo = (t_philo *)philo_num;

	long long time_bc = 0;
	
	timestamp_in_ms = 0;
	time_bc = time_now();
	
	int loop = 0; //make this loop infinite
	while (loop < 5)
	{
		if (eating(philo, timestamp_in_ms, time_bc))
			return (NULL);
		 if (sleeping(philo, timestamp_in_ms, time_bc))
		 	return (NULL);
		 if (thinking(philo, timestamp_in_ms, time_bc))
		 	return (NULL);
		loop++;
	}
	if (philo)
	{
		free(philo);
	}
	return (NULL);	
}

void   initializer(t_philo *philo, t_info *info, int i)
{
    philo->total_meals = 0;
    philo->last_meal = 0;
    philo->philo = i + 1;
    philo->info = info;
}

int    execution(t_info *info)
{
	pthread_t threads[info->philos];
    t_philo *philo;
	int i;

	pthread_mutex_init(&info->think_lock, NULL);
	pthread_mutex_init(&info->sleep_lock, NULL);
	pthread_mutex_init(&info->death_lock, NULL);
	i = 0;
	while (i < 200)
	{
		pthread_mutex_init(&info->fork_lock[i], NULL);
		i++;
	}
	i = 0;
	while (i < info->philos)
	{
        philo = malloc(sizeof(t_philo));
        if (!philo)
            return (0);
        initializer(philo, info, i);
		if (pthread_create(&threads[i], NULL, life, (void *)philo))
			return (0);
		i++;
	}
    i = 0;
	while (i < info->philos)
	{
		if (pthread_join(threads[i], NULL))
			return (0);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		pthread_mutex_destroy(&info->fork_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&info->think_lock);
	pthread_mutex_destroy(&info->sleep_lock);
	pthread_mutex_destroy(&info->death_lock);
	return (1);
}

int main(int ac, char **av)
{
    t_info info;
    
    if (!(parsing(ac, av, &info)))
        return (1);
    if (!(execution(&info))) // return 0 if false
        return (1);
    return (0);
}

// For tmrw

// eating meals death logic
// correct time printing


// fix printing time in the lab. Make sure it prints the correct time based on what the philo is doing. Check if the philo is doing the tasks at the expected/required time





// Steps:
// 2. mutex
// 3. routine

// 1. record the program starting time in a variable.

// 2. specify how would you find the time difference to check for the death of a philo & to specify the sleep time. Usleep is in micro sec and the program is in milli sec ***
// 3. specify the logic to follow e.g. even/odd OR monitor etc.
// 4. based on the logic speicify what variables we need to pass/modify/lock in a mutex. Create mutex accordingly.
// 5. check for leak & common cases
// 6. finalized the code
// 7. you can do the bonus if you finish early
// 8. Submit & Cerebrate 🥳🎉

