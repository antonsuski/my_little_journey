#pragma once

#include "sbj.hxx"

#include <iostream>
#include <vector>

const static std::vector<std::string_view> names{ "reserved", "on_notify",
                                                  "on_dying" };
enum class event
{
    on_notify = 1,
    on_dying  = 2,
};

std::ostream& operator<< (std::ostream& out, const event e);

class subject;
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
    ~observer ();
    const int get_id () const { return m_id; }
};

namespace mg
{
class obs
{
    void on_bruhh (int a, int b)
    {
        std::cout << "obs::on_bruhh()\n"
                  << "get a:" << a << " get b:" << b << '\n'
                  << "event_id:" << event_id << '\n';
    }

    void on_str (std::string_view str)
    {
        std::cout << "obs::on_str()\n"
                  << "get str:" << str << '\n'
                  << "str_event_id:" << str_event_id << '\n';
    }

    mg::NL_sbj& bro;
    int         event_id{};
    int         str_event_id{};

public:
    virtual ~obs ()
    {
        bro.get_event_bruhhh ().rem (event_id);
        bro.get_event_to_string_bruhh ().rem (str_event_id);
    }
    obs (NL_sbj& nls)
        : bro{ nls }
    {
        event_id = bro.get_event_bruhhh ().add ([this] (int a, int b)
                                                { on_bruhh (a, b); });

        str_event_id = bro.get_event_to_string_bruhh ().add (
            [this] (std::string_view str) { on_str (str); });
    }
};
} // namespace mg

// work aroud to release hybrid observer pattern
//  namespace hb
//  {
//  class obs
//  {
//      std::unordered_map<std::reference_wrapper<mg::NL_sbj>, std::list<int>>
//          subscribtions;

// public:
//     obs ();
//     template <typename... args>
//     void subscribe (std::reference_wrapper<mg::NL_sbj> event_caster, args...)
//     {
//         subscribtions[event_caster] = std::list<int>{};
//     }
// };
// } // namespace hb