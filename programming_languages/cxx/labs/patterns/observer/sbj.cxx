#include "sbj.hxx"

#include "obs.hxx"

#include <algorithm>
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

subject::node::node (observer* o)
    : m_observer{ o }
{
}

void subject::node::on_notify (event e)
{
    if (nullptr != m_observer)
    {
        m_observer->on_notify (e);
    }
}

bool subject::node::operator== (const node& rhs) const
{
    return this->m_observer == rhs.m_observer;
}

const int subject::node::get_id () const
{
    if (nullptr != m_observer)
    {
        return m_observer->get_id ();
    }
    return -1;
}

std::ostream& operator<< (std::ostream& out, const subject::node& lhs)
{
    out << lhs.m_observer;
    return out;
}
