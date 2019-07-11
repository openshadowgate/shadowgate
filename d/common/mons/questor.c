#include <std.h>
#include <namegen.h>
#include <daemons.h>

inherit MONSTER;

void create()
{
    ::create();
    make_me();
    set_body_type("human");
    set_class("fighter");
    set_class("mage");    
    set("aggressive",2);    
    set_hd(50,8);
    set_hp(25000);
    set_alignment(5);
    set_class("mage");
    set_mlevel("mage",90);
    set_guild_level("mage",90);
    set_guild_level("fighter",90);    
    set_stats("intelligence",28);
    set_stats("wisdom",20);
    set_stats("strength",20);
    set_stats("charisma",12);
    set_stats("dexterity",20);
    set_stats("constitution",28);
    set_property("magic",1);
    set_new_exp(100,"boss");
    set_property("magic resistance",70);
    set_spells(({"greater shout",
                    "greater shout",
                    "greater shout",
                    "greater dispel magic",
                    "resonating word",
                    "resonating word",                    
                    "powerword kill",
                    "powerword stun"}));
    set_spell_chance(100);    
}

void make_me()
{
    string name;
    name = GENNAM(4,random(4)+1,);
    set_race("outsider");
    set_gender(({"female","male"})[random(2)]);
    set_name(name);
    set_short("%^RESET%^"+({"%^BLUE%^","%^MAGENTA%^","%^RED%^","%^ORANGE%^"})[random(4)]+name+"%^CYAN%^, Collector of various lost things%^RESET%^");
    set_id(({name,lower_case(name),"questor",query_race(),"collector","Collector"}));
    set_long("%^CYAN%^"+name+" is a proprietor of various lost ancient trash. "+capitalize(TO->QS)+" dressed in a simple %^BLUE%^blue%^CYAN%^ robe that lacks any elegance. The merchant has an expression of annoyance of cosmic scale, and glares back at you. "+capitalize(TO->QS)+" stands by the board with a parchments pinned to it.
%^CYAN%^You can %^ORANGE%^<read list>%^CYAN%^ they form to see what antiquary is looking for and where you can obtain such an item.
%^CYAN%^Once the thing is found, you can %^ORANGE%^<claim %^ORANGE%^%^ULINE%^ITEM%^RESET%^%^ORANGE%^>%^CYAN%^ to get a reward.");
}

void thank()
{
    string thanklist;
    thanklist = ({"Thank you for your service, here is your reward.",
                "Thank you, adventurer. Now... Unless you have more, get lost.",
                "What took you so long?.. If you won't be fast others will claim the reward.",
                "Eeeh. Thanks. I guess. Now, get out.",
                "Could you bring something nice next time?",
                "Dont you have anything better to do. Princesses to kill, dragons to bed?",
                "You're wasting your time on these. You should go do something useful.",
                "Do that again and maybe I will hire assassins to kill you.",
                "Are you still here?",
                "You know how to make a dwarf fly?.. Throw him up.",
                "You're not helping anyone but yourself.",
                "Once there was just one moon. Someone killed her.",
                "Did you know that... Nevermind, get lost.",
                "You are not adding any meaning to life, you know.",
                "Perhaps next time you could bring something useful.",
                "Ah, isn't it my favorite useless adventurer.",
                "Next time bring me a drink.",
                "Yes-yes, move along, I don't have all day...",
                "Well?.. Why are you still here. There are more to hunt down.",
                "Perhaps one day you'll be as great as me.",
                "Pathetic weakling, why don't you go kill something instead.",
                "Hmm? Something you said, you worthless scum?",
                "Just die.",
                "Useless.",
                "Bugger off.",
                "Go away."});
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks in annoyed voice:%^RESET%^ "+thanklist[random(sizeof(thanklist))]);
}

void die(object ob)
{
    WORLD_EVENTS_D->kill_event("A rare opportunity");
    WORLD_EVENTS_D->inject_event((["A rare opportunity" : (["start message": "For the next two hours all experience gained will award an additional 50%!","event type" : "exp bonus", "length" : 120, "notification" : "50% Bonus Exp","event name" : "A rare opportunity", "modifier" : 50,"announce" : 1, "announce to" : "world" ]),]));
    ::die(ob);
}

