#include "summoned_monster.h"

create()
{
    ::create();
	set_name("defender");
    set_id(({"astral defender","monster","defender"}));
    set_race("construct");
	set_gender("neuter");
	set_short("%^RESET%^%^CYAN%^fl%^BOLD%^oa%^RESET%^%^CYAN%^t%^BOLD%^i%^RESET%^%^CYAN%^ng pr%^BOLD%^i%^RESET%^%^CYAN%^sm%^WHITE%^");
    set_long("%^CYAN%^This is a big floating prism made out of black stone. Surges of power zap out of it periodically with flashes of cyan energy.");
	set_body_type("human");
    set("aggressive",18);
    set_hd(6,1);
    set_alignment(5);
    set_size(2);
    set_stats("intelligence",10);
    set_stats("wisdom",12);
    set_stats("strength",16);
    set_stats("charisma",10);
    set_stats("dexterity",16);
    set_stats("constitution",10);
    set_hp(50);
    set_max_hp(query_hp());
    set_exp(500);
}

int die()
{
    TO->remove();
    ::die();
    return 1;
}
