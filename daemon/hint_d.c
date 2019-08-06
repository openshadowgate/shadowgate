#include <std.h>
#include <security.h>

#define HFILE "/d/common/text/tips"
#define FREQ 10

inherit DAEMON;

//If nobody uses this it'll swap.
static string *hints;

void create()
{
    ::create();
    remove_call_out("display_hint");
    if(load_hints(HFILE))
        display_hint();
}

/**
 * This one loads hints from a file into hints variable.  
 *
 * If a file grows too big, this fun should be replaced with line-by
 * line read (like in _grep)
 */
int load_hints(string fname)
{
    if(!file_exists(fname))
    {
        return 0;
    }
    hints = explode(read_file(fname),"\n");
    if(!pointerp(hints))
        return 0;
    return 1;
}

/**
 * Display random hint to everyone
 */
void display_hint()
{
    object *people, peep;
    people = filter_array(users(),(:$1->query("no hints"):));
    if(sizeof(people))
    {
        string hint;
        hint = hints[random(sizeof(hints))];
        foreach(peep in people)
        {
            message("hint","%^BOLD%^%^CYAN%^[%^RESET%^%^CYAN%^HINT%^BOLD%^]%^RESET%^ "+hint, peep);
        }
    }
    call_out("display_hint",FREQ);
}

