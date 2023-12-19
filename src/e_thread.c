#include "enigma.h"
#include <stdio.h>

/**
 * e_mutex_lock
 *
 * wrapper function around pthreads and winapithreads
 * that locks a mutex
 */
void e_mutex_lock(EMutex *mutex)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	int result = pthread_mutex_lock(mutex);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not lock mutex. Error code: %i\n", result);
	}
#endif
}

/**
 * e_mutex_unlock
 *
 * wrapper function around pthreads and winapithreads
 * that unlocks a mutex
 */
void e_mutex_unlock(EMutex *mutex)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	int result = pthread_mutex_unlock(mutex);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not unlock mutex. Error code: %i\n", result);
	}
#endif
}

/**
 * e_mutex_init
 *
 * wrapper function around pthreads and winapithreads
 * that initializes a mutex
 */
void e_mutex_init(EMutex *mutex, EMutexAttributes *attr)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	int result = pthread_mutex_init(mutex, attr);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not initiate mutex. Error code: %i\n", result);
	}
#endif
}

/**
 * e_mutex_destroy
 *
 * wrapper function around pthreads and winapithreads
 * that destroys a mutex
 */
void e_mutex_destroy(EMutex *mutex)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	int result = pthread_mutex_destroy(mutex);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not destroy mutex. Error code: %i\n", result);
	}
#endif
}

/**
 * e_thread_create
 *
 * wrapper function around pthreads and winapithreads
 * that creates a new thread
 */
EThread e_thread_create(EThreadFunction func, EThreadArguments args)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	pthread_t thread;
	int result = pthread_create(&thread, NULL, func, args);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not create thread. Error code: %i\n", result);
		exit(1);
	}
	return thread;
#endif
}

/**
 * e_thread_self
 *
 * wrapper function around pthreads and winapithreads
 * that returns the current thread
 */
EThread e_thread_self(void)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	return pthread_self();
#endif
}

/**
 * e_thread_join
 *
 * wrapper function around pthreads and winapithreads
 * that joins a thread
 */
void e_thread_join(EThread thread)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	int result = pthread_join(thread, NULL);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not join thread. Error code: %i\n", result);
		exit(1);
	}
	return;
#endif
}

/**
 * e_thread_detach
 *
 * wrapper function around pthreads and winapithreads
 * that detaches a thread
 */
void e_thread_detach(EThread thread)
{
#ifdef _ENIGMA_WINDOWS
#endif
#ifdef _ENIGMA_LINUX
	int result = pthread_detach(thread);
	if (result != 0)
	{
		fprintf(stderr, "ENIGMA: Could not detach thread. Error code: %i\n", result);
		exit(1);
	}
	return;
#endif
}
