#include <std.h>

int cmd_walk(string str)
{
    if (!objectp(TP)) {
        return 1;
    }

    if (str == "stop") {
        do_stop();
        return 1;
    }

    if (!is_member(ETP->query_exits(), str)) {
        write("There is no such exit!");
        return 1;
    }

    if (TP->qeury_in_vehicle()) {
        write("You should use <ride DIRECTION>");
        return 1;
    }

    TP->set_property("walking", 1);
    write("%^BOLD%^%^WHITE%^You being walking " + str + ".");
    call_out("do_walk", 1, TP, 0, str);
    return 1;
}

do_walk(object walker, object frome, string toe)
{
    if (!objectp(walker)) {
        return;
    }

    if (!walker->query_property("walking")) {
        return;
    }

    if (is_member(ENV(walker)->query_exits(), toe)) {
        call_out("do_walk", 1, walker, ENV(walker), toe);
        walker->force_me(toe);
        return;
    }

    if (frome == ETP) {
        do_stop();
        return;
    }

    if (sizeof(ENV(walker)->query_exits()) == 2 && frome != ENV(walker)) {
        string choice;
        string * exits;

        exits = filter_array(ENV(walker)->query_exits(), (: find_object_or_load(find_object_or_load($2->query_exit($1))->query_exit($3)) != $2:), ENV(walker), toe);

        if (sizeof(exits) > 1) {
            do_stop();
            return;
        }

        choice = last(exits);

        call_out("do_walk", 1, walker, ENV(walker), choice);
        walker->force_me(choice);
        return;
    }

    do_stop();
}

do_stop()
{
    TP->remove_property("walking");
    write("%^BOLD%^%^WHITE%^Unsure how to continue, you stop here.");
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

walk - do lazy strolling

%^CYAN%^SYNTAX%^RESET%^

walk %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^|stop

%^CYAN%^DESCRIPTION%^RESET%^

Walk will try to automatically move you into given %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^, or into an obvious direction if one is available.

To stop walking use %^ORANGE%^<walk stop>%^RESET%^.

Walk is slower than doing it with commands.

You should use %^ORANGE%^<ride>%^RESET%^ when on horse instead.

%^CYAN%^SEE ALSO%^RESET%^

horses, look, hp
"
        );
}
