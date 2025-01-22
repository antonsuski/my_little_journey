#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

const static std::vector<std::string_view> names{ "reserved", "on_notify",
                                                  "on_dying" };
enum class event
{
    on_notify = 1,
    on_dying  = 2,
};

std::ostream& operator<< (std::ostream& out, const event e)
{
    out << names[static_cast<size_t> (e)];
    return out;
}

class observer
{
    static int s_counter;
    int        m_id;

public:
    virtual void on_notify (event e)
    {
        std::cout << "id:" << m_id << "; is notified: " << e << "\n";
    }
    observer ()
        : m_id{ s_counter++ }
    {
    }
    ~observer () { s_counter--; }
    const int get_id () const { return m_id; }
};

int observer::s_counter{ 0 };

class node
{
    observer* m_observer{ nullptr };

public:
    node (observer* o)
        : m_observer{ o }
    {
    }

    void on_notify (event e)
    {
        if (nullptr != m_observer)
        {
            m_observer->on_notify (e);
        }
    }

    bool operator== (const node& rhs) const
    {
        return this->m_observer == rhs.m_observer;
    }

    const int get_id () const
    {
        if (nullptr != m_observer)
        {
            return m_observer->get_id ();
        }
        return -1;
    }

    friend std::ostream& operator<< (std::ostream& out, const node& lhs);
};

std::ostream& operator<< (std::ostream& out, const node& lhs)
{
    out << lhs.m_observer;
    return out;
}

class subject
{
    std::list<node> m_followers{};

public:
    void add_observer (observer* const o) { m_followers.emplace_back (o); };

    void rem_observer (observer* const o)
    {
        auto it = std::find (m_followers.begin (), m_followers.end (), o);
        if (m_followers.end () != it)
        {
            m_followers.erase (it);
        }
    }

    int send (event e)
    {
        for (auto&& it : m_followers)
        {
            it.on_notify (e);
        }

        return 69;
    }

    friend std::ostream& operator<< (std::ostream& out, const subject& lhs);
};

std::ostream& operator<< (std::ostream& out, const subject& lhs)
{
    out << "total followers: " << lhs.m_followers.size () << '\n';
    for (auto&& it : lhs.m_followers)
    {
        out << "follower [" << it.get_id () << "]: " << it << ';';
    }
    return out;
}
