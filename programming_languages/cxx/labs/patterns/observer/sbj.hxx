#pragma once

#include "event.hxx"
// #include "obs.hxx"

#include <iostream>
#include <list>
#include <string_view>

enum class event;
class observer;
class subject
{
    class node
    {
        observer* m_observer{ nullptr };

    public:
        node (observer* o);

        void      on_notify (event e);
        bool      operator== (const node& rhs) const;
        const int get_id () const;

        friend std::ostream& operator<< (std::ostream&        out,
                                         const subject::node& lhs);
    };

    std::list<node> m_followers{};

public:
    void add_observer (observer* const o);
    void rem_observer (observer* const o);
    int  send (event e);

    friend std::ostream& operator<< (std::ostream& out, const subject& lhs);
    friend std::ostream& operator<< (std::ostream&        out,
                                     const subject::node& lhs);
};

namespace mg
{
class NL_sbj
{
    mg::event<int, int>         event_to_call_the_sum_bruhhh;
    mg::event<std::string_view> event_to_call_the_string_bruhhh;

public:
    auto& get_event_bruhhh () { return event_to_call_the_sum_bruhhh; };
    auto& get_event_to_string_bruhh ()
    {
        return event_to_call_the_string_bruhhh;
    }

    void bruhhh (int a, int b)
    {
        std::cout << "bruhhh ...notified\n";
        get_event_bruhhh ().invoke (a, b);
    }

    void str (std::string_view str)
    {
        std::cout << "str ...notified\n";
        get_event_to_string_bruhh ().invoke (str);
    }
};
} // namespace mg