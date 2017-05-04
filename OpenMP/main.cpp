#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel
{
    std::cout << "Thread = " << omp_get_thread_num() << "says hello\n";
}
return 0;
}
