#include <std.h>
inherit "/d/common/obj/weapon/bastard.c";
    set_lore("%^BOLD%^%^WHITE%^This is the sword of Jarmilas Archangel Castiel Lightbringer, who was sent down from the Heavens to watch over Cerviel Kii Ra, Guardian of Antioch, and one of Jarmila's Malakhims. The Goddess had seen the potential of a great hero of the age, and thus Cerviel Kii Ra was given the sword as a proof of her divinity and protect the citizens of Antioch. It is said that the wielder of this weapon can take on the %^YELLOW%^aspect%^RESET%^%^BOLD%^WHITE%^ of a divine being.\n");

    set_weight(5);
    set("value", 100000);
    set_property("no_curse", 1);
    set_property("enchantment", 7);
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_item_bonus("strength", 2);
    set_item_bonus("constitution", 2);
    set_item_bonus("charisma", 2);
    set_item_bonus("wisdom", 2);
    set_item_bonus("negative energy resistance", 100);
    set_item_bonus("attack bonus", 2);
    set_item_bonus("damage bonus", 2);
    set_item_bonus("sight bonus", 2);
    set_wield( (: this_object(), "wield_func" :) );
    set_unwield( (: this_object(), "unwield_func" :) );
    set_hit( (: this_object(), "hit_func" :) );

    set_heart_beat(1);
}

void init()
{
    ::init();

    owner = environment(this_object());

    if(!living(owner))
        return;

    tell_object(owner, "The holy weapon seems to adjust its size to better suit you!\n");
    set_size(owner->query_size() + 1);

    hit_count = 0;

    add_action("angelic_aspect", "aspect");
}

int wield_func()
{

    if(owner->query_level() < 40)
    {
        tell_object(owner, "You feel that the power of the sword is far beyond your ability to wield.\n");
        return 0;
    }

    if(owner->query_true_align() != 1 && owner->query_true_align() != 4 && owner->query_true_align() != 7)
    {
        tell_object(owner, "The blade seems to deem you unworthy of wielding it!\n");
        return 0;
    }

    tell_object(owner, "%^BOLD%^You feel holy power course through you as you grip the mighty sword!%^RESET%^\n");

    return 1;
}

int unwield_func()
{
    owner && tell_object(owner, "You feel the holy power of the blade leave you as you release it.\n");

    return 1;
}

void heart_beat()
{
    object *people;
    object room;
    int alignment;

    if(!living(owner))
        return;

    owner && room = environment(owner);

    if(!room)
        return;

    people = all_living(room);
    people = filter_array(people, "is_non_immortal_player", FILTERS_D);

    if(this_object()->query_wielded() && !random(20))
    {
        foreach(object ob in people)
        {
            ob && alignment = ob->query_alignment();
            if(alignment == 3 || alignment == 6 || alignment == 9)
                owner && tell_object(owner, "%^CYAN%^You sense the presence of evil through the sword!%^RESET%^\n");
            else
                if(ob != owner->query_current_attacker() && ob->query_hp() < ob->query_max_hp())
                {
                    ob->add_hp(ob->query_max_hp() / 20);
                    tell_object(owner, sprintf("%^YELLOW%^Your sword pulses and heals some of %s wounds!%^RESET%^\n", ob == owner ? "your" : ob->query_name() + "'s"));
                }
        }
    }

}

int hit_func(object target)
{
    int damage,
        alignment;

    if(!target || !owner)
        return 0;

    hit_count++;

    if(hit_count < HIT_INTERVAL)
        return 0;

    hit_count = 0;
    alignment = target->query_alignment();

    //Sword doesn't like hitting Good opponents.
    if(alignment == 1 || alignment == 4 || alignment == 7)
        return 0;

    damage = roll_dice(1, PROC_BASE);

    if(alignment == 3 || alignment == 6 || alignment == 9)
        damage += roll_dice(1, 6);

    tell_object(owner, "%^BOLD%^%^WHITE%^A%^CYAN%^n%^WHITE%^g%^CYAN%^e%^WHITE%^li%^CYAN%^c %^RESET%^wings %^BOLD%^sprout from you back, and in one %^CYAN%^motion %^WHITE%^you take to the %^CYAN%^air%^WHITE%^, and swings $O%^BOLD%^%^WHITE%^ down in a %^ORANGE%^arc %^RESET%^striking %^BOLD%^$T again and again before you land and the %^RESET%^wings %^CYAN%^disappears%^BOLD%^%^WHITE%^.%^RESET%^\n");
    target && tell_object(target, "%^BOLD%^%^WHITE%^A%^CYAN%^n%^WHITE%^g%^CYAN%^e%^WHITE%^li%^CYAN%^c %^RESET%^wings %^BOLD%^sprout from you back, and in one %^CYAN%^motion %^WHITE%^you take to the %^CYAN%^air%^WHITE%^, and swings $O%^BOLD%^%^WHITE%^ down in a %^ORANGE%^arc %^RESET%^striking %^BOLD%^$T again and again before you land and the %^RESET%^wings %^CYAN%^disappears%^BOLD%^%^WHITE%^.%^RESET%^\n");
    tell_room(environment(target), "%^BOLD%^%^WHITE%^A%^CYAN%^n%^WHITE%^g%^CYAN%^e%^WHITE%^l%^CYAN%^i%^WHITE%^c %^RESET%^wings %^BOLD%^sprout from $U's%^BOLD%^%^WHITE%^ back, and in one %^CYAN%^motion %^WHITE%^he takes to the %^CYAN%^air %^WHITE%^and brings $O%^BOLD%^%^WHITE%^ down in a %^ORANGE%^arc %^RESET%^striking %^BOLD%^$T before he lands before $T%^BOLD%^%^WHITE%^ and the wings s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^s %^BOLD%^and %^RESET%^%^CYAN%^disappears%^BOLD%^%^WHITE%^.%^RESET%^\n", ({ target, owner }));

    target->do_damage("body", damage);

    return damage;
}

void angelic_aspect(string str)
{
    if(!this_object()->query_wielded())
        return 0;

    new("/cmds/spells/g/_greater_angelic_aspect")->use_spell(owner, 0, 40, 100, "mage");

    return 1;
}

int isMagic() { return 1; }
