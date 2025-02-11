#include "obs.hxx"
#include "sbj.hxx"

// #include <iostream>

int main (int argc, char** argv)
{
    // observer first;
    // observer second;

    // subject alarm;
    // alarm.add_observer (&first);
    // alarm.add_observer (&second);

    // std::cout << "Hello, World!" << std::endl;
    // std::cout << alarm << "\nNotifing alaram follrowers ...\n";
    // alarm.send (event::on_notify);

    // std::cout << "Removing followers ...\n";
    // alarm.rem_observer (&first);
    // std::cout << alarm << std::endl;
    // alarm.rem_observer (&second);
    // std::cout << alarm << std::endl;

    // alarm.send (event::on_dying);

    // observer with arguments
    mg::NL_sbj observable_subj;
    mg::obs    L_observer (observable_subj); // 0,1 for void<int,int>
    {
        mg::obs L2_observer (observable_subj); // 0,1 for void<std::string_view>
        observable_subj.bruhhh (77, 69);
    }

    observable_subj.str ("lol");
    return 0;
}
