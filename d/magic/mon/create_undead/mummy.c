#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;

void create()
{
	::create();
	set_name("mummy");
	set_id(({"mummy","undead","monster"}));
	set_short("%^ORANGE%^A %^WHITE%^m%^WHITE%^u%^BOLD%^%^WHITE%^mmy%^RESET%^");
	set_long(
	"%^ORANGE%^This is a very terrifying looking mummy. The %^WHITE%^w%^WHITE%^r%^BOLD%^%^WHITE%^appin%^RESET%^%^WHITE%^g%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^ that cover its flesh are %^WHITE%^o%^WHITE%^l%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^wo%^RESET%^%^WHITE%^r%^WHITE%^n%^BOLD%^%^WHITE%^.%^RESET%^%^ORANGE%^ They are yellowing with age and are quite tattered. Despite the centuries of death and decay, this mummy still appears to be quite string. The eyes glow an %^BOLD%^%^RED%^an%^RESET%^%^RED%^g%^BOLD%^%^RED%^ry %^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d%^RESET%^%^ORANGE%^ and its %^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^h%^RESET%^%^ORANGE%^ have been %^BOLD%^%^WHITE%^sh%^RESET%^%^WHITE%^a%^WHITE%^r%^BOLD%^%^WHITE%^pen%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^d%^RESET%^%^ORANGE%^ horribly. Its fingers are more like claws and standing near it you get a slight chill. The smell it gives off is incredibly disgusting."
	);
    //	Str 24, Dex 10, Con Ø, Int 6, Wis 14, Cha 15
    set_stats("strenght",24);
    set_stats("dexterity",10);
    set_stats("constitution",18);
    set_stats("intelligence",6);
    set_stats("wisdom",14);
    set_stats("charisma",16);

	set_property("undead",1);
	set_level(15);    
	set_hd(24,6);
	set_max_hp(random(25)+325);
	set_hp(query_max_hp());
    
	set_body_type("human");
	set_overall_ac(-20);
	set_alignment(3);
	set_size(2);

	set_race("mummy");
	set_class("fighter");
	set_mlevel("fighter",20);
    
	set_new_exp(20,"normal");
	set_gender("neuter");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(4);
	set_nat_weapon_type("thiefslashing");
	set_damage(1,12);
    set_resistance("negative energy",60);
    set_resistance("positive energy",-60);
}

void despair()
{
    object *foes, foe;
    foes = TO->query_attackers();
    if(sizeof(foes))
    {
        foreach(foe in foes)
        {
            if(!objectp(foe))
                continue;

            if(!SAVING_D->saving_throw(foe,"will"))
            {
                tell_object(foe,"%^ORANGE%^You cover in %^WHITE%^f%^BOLD%^%^WHITE%^ea%^RESET%^%^WHITE%^r%^ORANGE%^ before the mummy!");
                tell_room(ENV(TO),"%^ORANGE%^"+foe->QCN+"%^ORANGE%^ covers in %^BOLD%^%^WHITE%^fear%^RESET%^%^ORANGE%^ before the mummy!");
                foe->set_paralyzed(roll_dice(1,2),"%^ORANGE%^You're still %^BOLD%^%^WHITE%^shakin%^RESET%^%^WHITE%^g%^ORANGE%^ with fear!");
            }
        }
    }
}


void heart_beat()
{
    ::heart_beat();
    despair();
}
