#define PROFILEAPP
#include "profiling/Timer.h"
#include "profiling/Profiler.h"


Timer t;
int testProf()
{/*
    ThreadProfiler::Start("ProfileThis");
    int i  = sleep(1);
    ThreadProfiler::Start("ProfileThis2");
    sleep(2);
    ThreadProfiler::Stop("ProfileThis2");
    ThreadProfiler::Stop("ProfileThis");*/
    t.start();
    ThreadProfiler::Start("Bla");
    ThreadProfiler::Stop("Bla");
    t.stop();
    double tElapsed = t.getElapsedTimeInMilliSec() ;
    //std::cout << "Elapsed: " << tElapsed << std::cout;
    printf("Elapsed: %f\n", tElapsed);
    return 0;
}

void testProf2()
{
    boost::thread t1(&testProf);
    t1.join();
    boost::thread t2(&testProf);
    t2.join();
}

int main(int argc, char** argv)
{
    return testProf();
}
