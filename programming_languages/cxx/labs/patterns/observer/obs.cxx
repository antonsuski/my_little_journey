#include "obs.hxx"

#include "sbj.hxx"

int observer::s_counter{ 0 };

observer::~observer ()
{
    s_counter--;
}

std::ostream& operator<< (std::ostream& out, const event e)
{
    out << names[static_cast<size_t> (e)];
    return out;
}
