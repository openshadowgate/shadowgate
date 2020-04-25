#include <std.h>
#include <clock.h>

inherit DISEASE;

int next_step = 0;
int saved = 0;

void create()
{
    ::create();
    set_name("wererat infection");
    set_incubation("1 day");
    set_damage_desc("1 con once");
    set_infection("contact");
    set_description("\n\nThis rapidly progressing disease will turn you into a wererat in the last, third, stage, but only if you're partially human.");

    set_property("inanimate bonus", 1);
    set_heart_beat(32);
}

int init_disease(int dc)
{
    ::init_disease(dc);
    next_step = ETO->query_age() + DAY;
}

advance_disease()
{
    int dmg = -1;

    next_step += DAY;

    if (do_save())
    {
        saved++;
        if (saved > 4) {
            tell_object(ETO,"%^BOLD%^%^GREEN%^You feel relieved as skin ache fades.");
            TO->remove();
            return;
        }
        return;
    }
    saved = 0;

    set_item_bonus("con",dmg);

    tell_object(ETO,"\n%^GREEN%^You feel weaker as your skin aches.%^RESET%^");

    if (stage > 3) {
        string race = ETO->qeury_race();

        if (ETO->query_acquired_template()) {
            tell_object(ETO,"%^BOLD%^%^GREEN%^You feel relieved as skin ache fades.");
            TO->remove();
            return;
        }

        if (member_array(race, ({"human", "half-elf", "half-drow", "half-orc",})) == -1) {
            tell_object(ETO,"%^BOLD%^%^GREEN%^You feel relieved as skin ache fades.");
            TO->remove();
            return;
        }

        "/std/acquired_template/wererat"->apply_template(ETO);

        tell_object(ETO,"\n%^BOLD%^%^GREEN%^You twitch and snicker, ready to obey the warren.%^RESET%^");
        tell_object(ETO,"\n%^BOLD%^%^GREEN%^Ignoring the disease inside, you are now a wererat.%^RESET%^");
    }

    stage++;

}

void heart_beat()
{
    if (!objectp(TO)) {
        return;
    }

    if (!next_step) {
        return;
    }

    if (!ETO->is_living()) {
        TO->remove();
    }
    if (ETO->query_age() > next_step) {
        advance_disease();
    }

    return;
}
