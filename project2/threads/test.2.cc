//     Test Non-Preemptive Priority scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest2
//      Non-Preemptive Priority scheduling algorithm
//      Process  Burst Time  Priority  Arrival
//        P1         5          3	16
//        P2        20          5	 0
//        P3        13          9 	20
//        P4         7          8	18
//        P5        12          6	10
//----------------------------------------------------------------------

void ThreadTest2()
{
 
    int  numThreads = 5;
    int  startTime[] = {16,  0, 20, 18,10 };
    int  burstTime[] = {  5, 20,  13,   7, 12 };
    int   priority[] = {  3,  5,   9,   8,  6 };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_PRIO_NP);

    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

