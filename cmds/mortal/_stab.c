#include <std.h>

inherit "/cmd/mortal/_kill";

int cmd_stab(string args)
{
    tell_object(TP,"%^BOLD%^%^WHITE%^You jump from shadows to deliver a deadly strike!");
    return cmd_kill(string args);
}
