#include "obs.hxx"

#include <iostream>

int main (int argc, char** argv)
{
    observer first;
    observer second;

    subject alarm;
    alarm.add_observer (&first);
    alarm.add_observer (&second);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
