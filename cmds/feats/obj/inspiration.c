#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

string *INSPIRATION_TYPES = ({
        "courage",
            "competence",
            "greatness",
            "heroics"
    });

object caster;
object *allies;
int clevel;
string active_inspiration;

void create()
{
    ::create();
    set_name("inspiration_obj");
    set("id", ({"inspiration_obj"}));

    set_property("no animate", 1);
    set_weight(0);
}

object setup_inspiration(object mycaster, int myclevel, string inspiration)
{
    object insprtion;

    insprtion = new(base_name(TO));

    if (!objectp(insprtion)) {
        return;
    }

    insprtion->activate_inspiration(mycaster, myclevel, inspiration);
    return insprtion;
}

void activate_inspiration(object mycaster, int myclevel, string inspiration)
{
    caster = mycaster;
    clevel = myclevel;

    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    if (member_array(inspiration, INSPIRATION_TYPES) == -1) {
        TO->remove();
        return;
    }

    // insert feat checks here

    allies = get_present_allies();

    active_inspiration = inspiration;

    tell_room(ENV(caster), "%^CYAN%^T%^MAGENTA%^h%^BOLD%^%^CYAN%^e %^RESET%^%^CYAN%^r%^MAGENTA%^a%^CYAN%^p%^BOLD%^t%^WHITE%^ur%^RESET%^%^MAGENTA%^e %^CYAN%^of %^MAGENTA%^m%^CYAN%^us%^MAGENTA%^i%^BOLD%^%^BLACK%^c %^RESET%^%^CYAN%^f%^MAGENTA%^i%^BOLD%^l%^WHITE%^l%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^h%^MAGENTA%^e air %^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^ro%^BOLD%^u%^RESET%^%^CYAN%^nd %^WHITE%^%^BOLD%^" + caster->QCN + ".");

    call_out("allies_watch", ROUND_LENGTH);

}

void allies_watch()
{
    object * new_allies;
    object * old_allies;
    object * diffout, diffin;

    if (!objectp(caster)) {
        dest_all_effects();
        return;
    }

    old_allies = allies;

    new_allies = get_present_allies();

    diffout = old_allies - new_allies;

    if (sizeof(diffout)) {
        object ally;

        foreach(ally in diffout) {
            inspire_ally(ally, -1);
        }
    }

    diffin = new_allies - old_allies;

    if (sizeof(diffin)) {
        object ally;

        foreach(ally in diffin) {
            inspire_ally(ally, 1);
        }
    }

    allies = new_allies;

    call_out("allies_watch", ROUND_LENGTH);
}

void inspire_ally(object ally, int direction)
{
    if (!objectp(ally)) {
        return;
    }

    if (direction == 1) {
        object foreign_inspiration;
        foreign_inspiration = ally->query_property("inspiration");
        if (objectp(foreign_inspiration)) {
            if (foreign_inspiration->query_clevel() <= clevel ||
                ally == caster) {
                foreign_inspiration->remove_ally(ally);
            } else {
                return;
            }
        }
    }

    if (direction == 1) {
        tell_object(ally,"%^MAGENTA%^T%^BOLD%^h%^BLACK%^e %^RESET%^%^CYAN%^p%^MAGENTA%^er%^BOLD%^m%^WHITE%^u%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^t%^WHITE%^io%^BOLD%^%^BLACK%^n %^CYAN%^o%^RESET%^%^CYAN%^f %^BOLD%^%^MAGENTA%^m%^BLACK%^u%^MAGENTA%^s%^RESET%^%^MAGENTA%^i%^CYAN%^c %^MAGENTA%^e%^WHITE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^t%^WHITE%^e%^BOLD%^%^BLACK%^s %^MAGENTA%^y%^RESET%^%^MAGENTA%^ou.%^RESET%^");
        ally->add_property("inspiration", TO);
    } else {
        tell_object(ally,"%^MAGENTA%^C%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^l%^CYAN%^o%^MAGENTA%^rs %^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^f %^CYAN%^t%^MAGENTA%^he wo%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ld t%^CYAN%^u%^MAGENTA%^rn %^CYAN%^du%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^l %^BOLD%^%^BLACK%^as %^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^us%^RESET%^%^MAGENTA%^ic l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^a%^MAGENTA%^v%^CYAN%^e%^MAGENTA%^s %^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^ou.%^RESET%^");
        ally->remove_property("inspiration");
    }

    if (function_exists("inspire_" + active_inspiration, TO)) {
        call_other(TO, "inspire_" + active_inspiration, ally, direction);
    }

}

void dest_all_effects()
{
    object ally;

    if (sizeof(allies)) {
        foreach(ally in allies) {
            remove_ally(ally);
        }
    }
    TO->remove();
}

void remove_ally(object ally)
{

    allies -= ({ally});

    if (!objectp(ally)) {
        return;
    }

    if (function_exists("inspire_" + active_inspiration, TO)) {
        call_other(TO, "inspire_" + active_inspiration, ally, -1);
    }

    ally->remove_property("inspiration");
}

void inspire_courage(object ally, int direction)
{
    int power;
    power = clevel / 6 + 1;
    power = power > 6 ? 6 : power;

    ally->add_attack_bonus(power * direction);
    ally->add_damage_bonus(power * direction);
}

object *get_present_allies()
{
    object * pa;

    if (!objectp(caster)) {
        return;
    }

    pa = caster->query_followers();

    {
        string pname;
        object * party;

        pname = caster->query_party();

        if (pname) {
            party = PARTY_D->query_party_members(pname);
            party = filter_array(party, (:objectp($1):));
            party = filter_array(party, (:objectp(ENV($1)):));
            pa += party;
        }
    }

    pa = filter_array(pa, (:ENV($1) == ENV($2):), caster);

    pa += ({caster});

    pa = distinct_array(pa);

    return pa;

}

string *query_inspiration_types()
{
    return INSPIRATION_TYPES;
}

int query_clevel()
{
    return clevel;
}

void save_me()
{
    TO->remove();
}

string query_active_inspiration()
{
    return active_inspiration;
}
