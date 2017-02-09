/* resched.c  -  resched */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include<sched.h>


unsigned long currSP;	/* REAL sp of current process */
extern int ctxsw(int, int, int, int);
/*-----------------------------------------------------------------------
 * resched  --  reschedule processor to highest priority ready process
 *
 * Notes:	Upon entry, currpid gives current process id.
 *		Proctab[currpid].pstate gives correct NEXT state for
 *			current process if other than PRREADY.
 *------------------------------------------------------------------------
 */
//Pranjali
//rdy is ready queue.
int resched()
{
	register struct	pentry	*optr;	/* pointer to old process entry */
	register struct	pentry	*nptr;	/* pointer to new process entry */
	double prioVar; //variable to take the exponentially generated priority value
	int	next;		/* runs through ready list		*/
	int	prev;
	struct	qent	*mptr;	
	
	
	
	
	//old process pointer
	(optr= &proctab[currpid]);
	
	//find the process with priority value that satisfies the given conditions.
	if(getschedclass()==EXPDISTSCHED)
	{
		//calculate the random number first
		prioVar=expdev(0.1);

	

        next = q[rdyhead].qnext;
        if(q[next].qkey>prioVar)
        {
                //schedule the first process
                nptr = &proctab[ (currpid = getfirst(rdyhead)) ]; //pointer pointing to last process in ready queue.-Pranjali
                nptr->pstate = PRCURR;
                //adjust the queue.
                q[rdyhead].qnext=q[next].qnext;
                mptr=&next;

                q[mptr->qprev].qprev=rdyhead;
        }
        prev=q[rdytail].qprev;
        if(q[prev].qkey<prioVar)
        {
                //schedule last process
                nptr = &proctab[ (currpid = getlast(rdytail)) ]; //pointer pointing to last process in ready queue.-Pranjali
                
                
                nptr->pstate = PRCURR;
                //adjust  the queue
                q[rdytail].qprev=q[prev].qprev;
                mptr=&prev;
                q[mptr->qprev].qnext=rdytail;
        }

        else
        {
                //check for process to schedule
                next=q[next].qnext;
                if(q[next].qkey>prioVar)
                {
                        //schedule this process

                        nptr = &proctab[ (currpid = next) ]; //pointer pointing to last process in ready queue.-Pranjali
                        nptr->pstate = PRCURR;

                        //as the processes are ordered on priority, this is going to be the process with priority least greatest than the exponentially generated priority.

                        mptr = &next;
                        q[mptr->qprev].qnext=mptr->qnext;
                        q[mptr->qnext].qprev=mptr->qprev;

                }

        }	
		}
		
		if(getschedclass()==LINUXSCHED)
		{
		
		}
			/* mark it currently running	*/
#ifdef	RTCLOCK
	preempt = QUANTUM;		/* reset preemption counter	*/
#endif
	
	ctxsw((int)&optr->pesp, (int)optr->pirmask, (int)&nptr->pesp, (int)nptr->pirmask);//context switch ko old and new process pass kiya. stack pointer and interrupt mask is passed.
	
	/* The OLD process returns here when resumed. */
	return OK;
}
