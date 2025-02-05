#include "sbj.hxx"

#include "obs.hxx"

#include <iostream>

std::ostream& operator<< (std::ostream& out, const subject& lhs)
{
    out << "total followers: " << lhs.m_followers.size () << '\n';
    for (auto&& it : lhs.m_followers)
    {
        out << "follower [" << it.get_id () << "]: " << it << ';';
    }
    return out;
}

void subject::add_observer (observer* const o)
{
    m_followers.emplace_back (o);
};

void subject::rem_observer (observer* const o)
{
    auto it = std::find (m_followers.begin (), m_followers.end (), o);
    if (m_followers.end () != it)
    {
        m_followers.erase (it);
    }
}

int subject::send (event e)
{
    for (auto&& it : m_followers)
    {
        it.on_notify (e);
    }

    return 69;
}