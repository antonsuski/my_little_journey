#pragma once

#include <functional>
#include <iostream>
#include <map>

namespace mg
{
template <typename... args>
class event
{
    std::map<std::size_t, std::function<void (args...)>> followers;
    std::size_t                                          counter{ 0 };

public:
    virtual ~event () = default;

    [[nodiscard]] int add (std::function<void (args...)> observer)
    {
        std::cout << "Adding new observer:" << &observer << '\n';
        auto current{ counter++ };
        followers[current] = observer;
        return current;
    }

    event& rem (const size_t event_id)
    {
        std::cout << "Deleting new observer, id:" << event_id
                  << ";&:" << &(followers[event_id]) << '\n';
        followers.erase (event_id);
        return *this;
    }

    void invoke (args... ass)
    {
        for (auto& [event_id, call] : followers)
        {
            call (ass...);
        }
    }
};
} // namespace mg
