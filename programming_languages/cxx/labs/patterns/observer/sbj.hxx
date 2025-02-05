#pragma once

#include "event.hxx"
#include "obs.hxx"

#include <iostream>
#include <list>

enum class event;
class observer;
class subject
{
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

        friend std::ostream& operator<< (std::ostream&        out,
                                         const subject::node& lhs)
        {
            out << lhs.m_observer;
            return out;
        }
    };

    std::list<node> m_followers{};

public:
    void add_observer (observer* const o);
    void rem_observer (observer* const o);
    int  send (event e);

    friend std::ostream& operator<< (std::ostream& out, const subject& lhs);
};

namespace mg
{
class NL_sbj
{
    mg::event<int, int> event_to_call_the_sum_bruhhh;

public:
    auto& get_event_bruhhh () { return event_to_call_the_sum_bruhhh; };

    void bruhhh ()
    {
        std::cout << "Bruhhh ...\n";
        get_event_bruhhh ().invoke (69, 77);
    }
};
} // namespace mg