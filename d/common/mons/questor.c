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
    set_mlevel("mage",70);
    set_guild_level("mage",70);
    set_guild_level("fighter",70);    
    set_stats("intelligence",28);
    set_stats("wisdom",20);
    set_stats("strength",20);
    set_stats("charisma",8);
    set_stats("dexterity",20);
    set_stats("constitution",28);
    set_property("magic",1);
    set_new_exp(100,"boss");
    set_property("cast and attack",1);    
    set_spells(({"sunburst",
                    "hellball",
                    "hellball",
                    "greater dispel magic",
                    "horrid wilthing",
                    "weird",}));
    set_spell_chance(100);
    set_funcs(({"mercy"}));
    set_func_chance(5);
}

void mercy(object target)
{
    object *living;
    ::heart_beat();

    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks in an angry voice:%^RESET%^ Not today.");
    tell_room(ETO,query_name()+" snaps her fingers.");
    target->die();
}

void make_me()
{
    string name;
    name = GENNAM(4,random(4)+1,);
    set_race("outsider");
    set_gender("female");
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
    thanklist = ({
            "Ah, isn't it my favorite useless adventurer.",
                "A dwarf walks past a bar... Hey, it could happen.",
                "Are you still here?",
                "Be gone",
                "Bugger off.",
                "Could you bring something nice next time?",
                "Did you know that... Nevermind, get lost.",
                "Do that again and maybe I will hire assassins to kill you.",
                "Dont you have anything better to do. Princesses to kill, dragons to bed?",
                "Eeeh. Thanks. I guess. Now, get out.",
                "Feeling lucky today? Your luck will run out, and you will die.",
                "Freaking dwarfs... I hate them.",
                "Go away.",
                "Go find somewhere else to loiter.",
                "Great, now I have to pay this worthless scum.",
                "Hmm? Something you said, you worthless scum?",
                "Just die.",
                "Next time bring me a drink.",
                "Once there was just one moon. Someone killed her.",
                "Pathetic weakling, why don't you go kill something instead.",
                "Perhaps next time I'll kill you myself.",
                "Perhaps next time you could bring something useful.",
                "Perhaps one day you'll be as great as me.",
                "Thank you for your service, here is your reward.",
                "Thank you, adventurer. Now... Unless you have more, get lost.",
                "Thanks for nothing.",
                "Useless.",
                "Well?.. Why are you still here. There are more to hunt down.",
                "What do you want now?",
                "What has four wheels, is bearded, and flies? Dwarf driving a garbage wagon.",
                "What took you so long?.. If you won't be fast others will claim the reward.",
                "Why do I even bother?",
                "Why won't you go and screw yourself?",
                "Yes-yes, move along, I don't have all day...",
                "You are not adding any meaning to life, you know.",
                "You know how to make a dwarf fly?.. Throw him up.",
                "You're not helping anyone but yourself.",
                "You're wasting your time on these. You should go do something useful.",
                "Your existence is meaningless.",
                });
    tell_room(ETO,"%^RESET%^%^MAGENTA%^"+query_name()+" speaks in an annoyed voice:%^RESET%^ "+thanklist[random(sizeof(thanklist))]);
}

void die(object ob)
{
    WORLD_EVENTS_D->kill_event("A rare opportunity");
    WORLD_EVENTS_D->inject_event((["A rare opportunity" : (["start message": "For the next two hours all experience gained will award an additional 33%!","event type" : "exp bonus", "length" : 120, "notification" : "33% Bonus Exp","event name" : "A rare opportunity", "modifier" : 33,"announce" : 1, "announce to" : "world" ]),]));
    ::die(ob);
}

