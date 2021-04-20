#include <std.h>
inherit "/d/common/obj/weapon/whip.c";
string owner;
object spellobj;

int FLAG;
void make_me(string str);

void create()
{
    ::create();
    set_name("whip of spiders");
    set_short("%^RESET%^%^WHITE%^a %^BOLD%^%^BLACK%^w%^RESET%^h%^BOLD%^i%^RESET%^p of %^BOLD%^%^BLACK%^c%^RESET%^e%^BOLD%^n%^BLACK%^t%^RESET%^i%^BOLD%^p%^RESET%^edes");
    set_long("You see a strange whip made of numerous centipedes. They look back at you with their tiny black eyes.");
    set_id(({"weapon","whip","whip of centipedes"}));
    set_weight(0);
    set_value(0);
    set("no curse",1);
    set_weapon_prof("simple");
    set_property("able to cast",1);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"extra_unwield":));
    set_hit((:TO,"hit_func":));
    FLAG = 0;
}


void init()
{
    int ench;

    ::init();
    if (stringp(owner)) {
        return;
    }

    if (interactive(TP) && TP == ETO) {
        owner = TPQN;
    }

    set_property("no curse", 1);

}


int extra_wield()
{

    if (interactive(TP) && owner != (string)TPQN) {
        tell_object(TP, "You are not allowed to wield this weapon.");
        return 0;
    }

    set_item_bonus("attack bonus", 2);
    return 1;

}

int extra_unwield()
{
    return 1;
}


int drop()
{
    tell_object(TP,"Centepedes just rearrange around your hand you as you try to drop the whip!");
    return 1;
}

int save_me(string file)
{
    return 1;
}

void make_me(object spell)
{
    int enchant, charlev = (spell->query_caster())->query_level();
    spellobj = spell;
    enchant = spell->query_clevel();
    enchant = enchant < 1 ? 1 : enchant;
    enchant = enchant > charlev ? charlev : enchant;
    if (charlev < 5) {
        return;
    }
    enchant = (enchant - 3) / 5;
    TO->set_property("enchantment", enchant);
}

int hit_func(object targ)
{
    targ = ETO->query_current_attacker();
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }

    if (!random(6)) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^Some centepedes of the whip fall off to bite " + targ->QCN + "!");
        tell_object(targ, "%^BOLD%^%^WHITE%^You feel painful bites of centepedes from " + ETOQCN + "'s as they crawl around you!");
        tell_room(EETO, "%^BOLD%^%^WHITE%^Centepedes on " + ETOQCN + "'s whip bite into " + targ->QCN + "!", ({ ETO, targ }));
        targ->do_damage("torso", random(8) + 8);
        return 1;
    }
}
