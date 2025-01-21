#include <algorithm>
#include <iostream>
#include <list>

class observer
{
    static int s_counter;

public:
    virtual void on_notify () { std::cout << s_counter << "\n"; }
    observer () { s_counter++; }
    ~observer () { s_counter--; }
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

    void on_notify ()
    {
        if (nullptr != m_observer)
        {
            m_observer->on_notify ();
        }
    }

    bool operator== (const node& rhs) const
    {
        return this->m_observer == rhs.m_observer;
    }

    friend std::ostream& operator<< (std::ostream& out, const node& lhs);
    // friend std::ostream& operator<<(std::ostream& out, const node& lhs)
    // {
    //     out << lhs.m_observer;
    //     return out;
    // }
};

std::ostream& operator<< (std::ostream& out, const node& lhs)
{
    out << lhs.m_observer;
    return out;
}

class subject
{
    std::list<node> followers{};

public:
    void add_observer (observer* const o) { followers.emplace_back (o); };
    void rem_observer (observer* const o)
    {
        auto it = std::find (followers.begin (), followers.end (), o);
        if (followers.end () != it)
        {
            followers.erase (it);
        }
    }
    void print_followers ()
    {
        std::cout << "total followers: " << followers.size ();
        for (auto&& it : followers)
        {
            // std::cout << it;
        }
    }
};
