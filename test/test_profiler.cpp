#include <tue/profiling/profiler.h>

tue::Profiler profiler;

void a()
{
    profiler.startTimer("a");
    profiler.stopTimer();
}

void b()
{
    profiler.startTimer("b");
    a();
    profiler.stopTimer();
}

void c()
{
    profiler.startTimer("c");
    b();
    a();
    profiler.stopTimer();
}

int main(int argc, char **argv) {

    profiler.setName("test");

    for(unsigned int i = 0; i < 1000; ++i)
    {
        profiler.startTimer("total");
        a();
        b();
        c();
        profiler.stopTimer();
    }

    std::cout << profiler << std::endl;

    return 0;
}
