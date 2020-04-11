#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <schoolspells.h>
inherit FEAT;

int FLAG;

string *valid_choices = ({ "egoist", "kineticist", "nomad", "seer", "shaper", "telepath" });

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("discipline");
    feat_prereq("Psion L1");
    feat_syntax("discipline [DISCIPLINE]");
    feat_desc("This feat allows a psion to select or change their psionic discipline.

Psionic Disciplines grant unique spells to the practitioner. The psion will
recieve mastery in one discipline spell per spell level.

You can select from the following disciplines:
  Egoist
  Kineticist
  Nomad
  Seer
  Shaper
  Telepath

A psion that has not made their choice will merely be precluded from access to
the discipline-specific spells.

To start selection process type <discipline>.");
    permanent(1);
    allow_tripped(1);
}

int allow_shifted() { return 1; }

int cmd_animal_companion(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    
    return 1;
}

int execute_feat(string args)
{
    ::execute_feat();
    
    if(!args)
    {
        write("%^BOLD%^You current discipline is: %^RESET%^RED%^" + this_player()->query_discipline());
        return 1;
    }
    
    if(this_player()->query_property("discipline_change") > time() - 259200)
    {
        write("%^BOLD%^You may only change your discipline once every three days.");
        return 1;
    }
    
    if(member(valid_choices, args) < 0)
    {
        write("%^BOLD%^Valid choices are : %^RESET%^RED%^" + implode(valid_choices, ", "));
        return 1;
    }
    
    write("You have selected the %^CYAN%^ " + args + "%^RESET%^ discipline. Type <yes> to confirm. Anything else will abort.");
    input_to("confirm_selection", 0);
    
    return 1;
}

void confirm_selection(string args)
{
    if (args != "yes") {
        tell_object(this_player(), "Aborting...");
        return;
    }

    write("%^BOLD%^You declare your psionic discipline as : %^CYAN%^" + args + ".");
    this_player()->set_discipline(args);
    this_player()->set_property("discipline_change", time());
    dest_effect();
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!(ob->is_class("psion")))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
