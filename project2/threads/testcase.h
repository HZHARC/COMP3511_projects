// testcase.h 

#ifndef TESTCASE_H
#define TESTCASE_H

typedef struct { int burst; int prior;} schedpair ;

void ThreadTest0();
void ThreadTest1();
void ThreadTest2();

void TestScheduler( int );
#endif // TESTCASE_H
