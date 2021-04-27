//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/3/13

#include <std.h>
#include "aunuit.h"
#include <daemons.h>

inherit VAULT;

void set_auto_closed();
void guardian_death();

int OPEN, guardians;

string* enemies = SAVE_D->query_array("rilynath_enemies");
string* members = SAVE_D->query_array("rilynath_members");
string* owners = SAVE_D->query_array("rilynath_owners");
string* guests = SAVE_D->query_array("rilynath_guests");
string* leaders = SAVE_D->query_array("rilynath_leaders");

void create()
{
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_name("The Great Gates");
    set_short("%^BOLD%^%^BLACK%^The Great Gates%^RESET%^");
    set_light(2);
    set_indoors(1);
    set_long("%^BOLD%^%^BLACK%^A cavernous tunnel has been borne into "
             "the %^RESET%^%^ORANGE%^e%^RED%^a%^GREEN%^r%^ORANGE%^th "
             "%^BOLD%^%^BLACK%^descending at an angle subtle enough to allow "
             "foot traffic to pass in each direction without much effort. "
             "The passageway is large enough for an %^RESET%^%^RED%^army "
             "%^BOLD%^%^BLACK%^to march through it, both its height and "
             "width nearing a hundred feet. The surface of the tunnel is "
             "composed of a p%^RESET%^i%^BOLD%^%^BLACK%^tch-bl%^RESET%^a"
             "%^BOLD%^%^BLACK%^ck smooth, gl%^WHITE%^o%^BLACK%^ssy dr%^RED%^"
             "a%^BLACK%^gon glass or obs%^WHITE%^i%^BLACK%^d%^WHITE%^i"
             "%^RESET%^a%^BOLD%^%^BLACK%^n as it is better known. It must "
             "have required an incredible amount of %^RED%^h%^ORANGE%^e"
             "%^RESET%^%^RED%^a%^BOLD%^%^RED%^t %^BLACK%^and %^RESET%^"
             "%^ORANGE%^pressure %^BOLD%^%^BLACK%^to burrow through the "
             "b%^RESET%^e%^BOLD%^%^BLACK%^d%^WHITE%^r%^RESET%^%^ORANGE%^o"
             "%^WHITE%^c%^BOLD%^%^BLACK%^k to create this structure. "
             "%^WHITE%^S%^CYAN%^c%^WHITE%^on%^RESET%^c%^BOLD%^%^BLACK%^e"
             "%^WHITE%^s %^BLACK%^have been mounted to the wall and vibrant "
             "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^o%^MAGENTA%^"
             "l%^RESET%^%^MAGENTA%^et f%^BOLD%^%^MAGENTA%^a%^WHITE%^e"
             "%^MAGENTA%^r%^RESET%^%^MAGENTA%^ie f%^BOLD%^%^MAGENTA%^i"
             "%^RESET%^%^MAGENTA%^re %^BOLD%^%^BLACK%^undulates within "
             "casting %^MAGENTA%^eerie %^BLACK%^sh%^WHITE%^a%^BLACK%^d"
             "%^RESET%^o%^BOLD%^%^BLACK%^ws across the reflect%^WHITE%^i"
             "%^BLACK%^ve surfaces of the stone. The gl%^RESET%^a%^BOLD%^"
             "%^WHITE%^s%^BLACK%^sy walls of this massive tunnel arrive "
             "at their end here arching down from their lofty height "
             "into a sheer wall. At the base g%^RESET%^a%^BOLD%^%^BLACK%^"
             "rgant%^WHITE%^u%^RESET%^a%^BOLD%^%^BLACK%^n g%^RESET%^a%^BOLD%^"
             "%^BLACK%^tes have been built directly into the wall. Standing "
             "taller even than the gates themselves two %^RESET%^draconic "
             "sentinels %^BOLD%^%^BLACK%^flank the doors.%^RESET%^\n");
    set_smell("default", "%^RESET%^%^CYAN%^The cool air is tinged with a faint metallic scent.%^RESET%^");
    set_listen("default", "%^BOLD%^%^BLACK%^The tunnel is as silent as a tomb.%^RESET%^");
    set_items(([
                   "mural" : "%^BOLD%^%^BLACK%^Carved into the large ad%^WHITE%^a"
                   "%^BLACK%^mant%^RESET%^i%^BOLD%^%^BLACK%^te gates this %^RESET%^"
                   "%^MAGENTA%^mural %^BOLD%^%^BLACK%^pictures two groups of "
                   "%^GREEN%^e%^RESET%^%^GREEN%^l%^CYAN%^v%^GREEN%^e%^BOLD%^"
                   "%^GREEN%^s %^BLACK%^coming together at the feet of a large "
                   "%^RESET%^dragon%^BOLD%^%^BLACK%^. The %^BLUE%^elves %^BLACK%^"
                   "on the left hand side are emerging from the depths of a "
                   "%^RESET%^c%^ORANGE%^a%^WHITE%^v%^BOLD%^%^BLACK%^e and the "
                   "%^RESET%^%^ORANGE%^elves %^BOLD%^%^BLACK%^on the right hand "
                   "side are stepping out of a %^GREEN%^lush f%^RESET%^%^GREEN%^o"
                   "%^CYAN%^r%^GREEN%^e%^BOLD%^%^GREEN%^st. The %^RESET%^dragon "
                   "%^BOLD%^%^BLACK%^they gather around has spread its we%^RESET%^"
                   "b%^BOLD%^%^WHITE%^b%^BLACK%^ed w%^WHITE%^i%^BLACK%^ngs to "
                   "shelter the %^GREEN%^fey%^BLACK%^.%^RESET%^",
                   ({ "sconce", "sconces" }) : "%^BOLD%^%^BLACK%^Every twenty feet "
                   "triangular ad%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^"
                   "%^BLACK%^nt%^WHITE%^i%^BLACK%^te sc%^RESET%^o%^BOLD%^%^BLACK%^"
                   "n%^WHITE%^c%^BLACK%^es have been mounted to the wall. Vivid "
                   "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^o%^MAGENTA%^l"
                   "%^RESET%^%^MAGENTA%^et f%^BOLD%^%^MAGENTA%^a%^WHITE%^e%^MAGENTA%^"
                   "r%^RESET%^%^MAGENTA%^ie f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^"
                   "re %^BOLD%^%^BLACK%^fli%^MAGENTA%^c%^BLACK%^kers within, casting "
                   "%^MAGENTA%^eerie %^BLACK%^sh%^WHITE%^a%^BLACK%^d%^RESET%^o%^BOLD%^"
                   "%^BLACK%^ws across the surfaces of the tunnel.%^RESET%^",
                   ({ "obsidian", "dragon glass", "walls", "floor", "ceiling" }) : "%^BOLD%^"
                   "%^BLACK%^As bla%^RESET%^c%^BOLD%^%^BLACK%^k as p%^WHITE%^i"
                   "%^BLACK%^tch and fl%^RESET%^a%^BOLD%^%^BLACK%^wl%^WHITE%^e"
                   "%^RESET%^s%^BOLD%^%^BLACK%^s to the touch this st%^RESET%^o%^BOLD%^"
                   "%^BLACK%^ne has a gl%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^sy sh"
                   "%^WHITE%^e%^RESET%^e%^BOLD%^%^BLACK%^n akin to that of a "
                   "%^MAGENTA%^g%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^mst%^RESET%^"
                   "%^MAGENTA%^o%^BOLD%^%^MAGENTA%^ne%^BLACK%^. It has been created "
                   "from a massive explosion of %^RED%^h%^RESET%^%^RED%^e%^BOLD%^"
                   "%^ORANGE%^a%^RED%^t %^BLACK%^and %^RESET%^%^ORANGE%^pressure"
                   "%^BOLD%^%^BLACK%^, the r%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ck "
                   "having c%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^led so "
                   "quickly afterward that the pattern of the sto%^RESET%^n%^BOLD%^"
                   "%^BLACK%^e resembles a rapidly %^CYAN%^fl%^RESET%^%^CYAN%^o%^BOLD%^"
                   "%^CYAN%^w%^WHITE%^i%^CYAN%^ng r%^RESET%^%^CYAN%^i%^GREEN%^v%^BOLD%^"
                   "%^CYAN%^er%^BLACK%^, its surface sw%^WHITE%^e%^BLACK%^lling and "
                   "e%^WHITE%^b%^RESET%^b%^BOLD%^%^BLACK%^ing. The entirety of the "
                   "tunnel is forged from this exquisite sto%^RESET%^n%^BOLD%^%^BLACK%^e.%^RESET%^",
                   ({ "draconic sentinel", "dragon", "construct", "statue", "sentinel", "sentinels", "dragons" }) : "%^RESET%^Standing "
                   "opposite of its twin this %^BOLD%^%^BLACK%^adam%^RESET%^a%^BOLD%^"
                   "%^BLACK%^nt%^WHITE%^i%^BLACK%^te draconic effigy %^RESET%^guards the "
                   "%^BOLD%^%^BLACK%^gargantuan gates%^RESET%^. The lower portion of its "
                   "body is %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^WHITE%^i%^BLACK%^l"
                   "%^RESET%^e%^BOLD%^%^BLACK%^d%^RESET%^, its powerful %^BOLD%^%^BLACK%^"
                   "mus%^RESET%^c%^BOLD%^%^BLACK%^les fle%^RESET%^x%^BOLD%^%^BLACK%^ed "
                   "%^RESET%^with the effort of take-off, and its %^BOLD%^%^BLACK%^wings "
                   "%^RESET%^are arched as they gather %^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^"
                   "%^CYAN%^nd %^WHITE%^beneath them. One of its %^RED%^claws %^WHITE%^"
                   "barely grazes the ground and the other is suspended in the %^BOLD%^"
                   "%^CYAN%^air %^RESET%^before it. The dragon's %^BOLD%^%^BLACK%^h"
                   "%^RESET%^o%^BOLD%^%^BLACK%^rned head %^RESET%^and n%^BOLD%^"
                   "%^BLACK%^e%^RESET%^ck are arched no less elegantly than a %^BOLD%^"
                   "%^WHITE%^swan's %^RESET%^and its sharp %^BOLD%^%^BLACK%^black scales "
                   "gl%^WHITE%^e%^RESET%^a%^BOLD%^%^BLACK%^m %^RESET%^danger%^BOLD%^"
                   "%^RED%^o%^RESET%^usly. Its open mouth is lined with countless ra"
                   "%^BOLD%^%^WHITE%^z%^RED%^o%^WHITE%^r%^RESET%^-sh%^BOLD%^%^WHITE%^a"
                   "%^RESET%^rp teeth and the statue's skilled craftsman has even "
                   "detailed a %^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ptil"
                   "%^CYAN%^i%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^n t%^BOLD%^%^GREEN%^o"
                   "%^RESET%^%^GREEN%^ng%^CYAN%^u%^GREEN%^e %^RESET%^that licks "
                   "restlessly at the air.%^RESET%^"
               ]));
    set_exits(([
                   "gates" : ROOMS "dragons_landing",
                   "west" : ROOMS "tunnel05",
                   "east" : ROOMS "tunnel216",
               ]));
    set_door("gates", ROOMS "dragons_landing", "gates", "aunuit_key_xyz", "runes"); //There is no key
    set_open("gates", 0);
    set_locked("gates", 1, "runes");
    lock_difficulty("gates",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "runes");
    set_lock_description("gates", "runes",
                         "%^BOLD%^%^BLACK%^Inscribed upon the door are various %^CYAN%^r"
                         "%^WHITE%^u%^CYAN%^nes %^BLACK%^of unknown origin.%^RESET%^");
    set_door_description("gates", "%^BOLD%^%^BLACK%^Massive adamantine "
                         "gates have been built into the sheer cavern wall. The %^RESET%^"
                         "%^RED%^maw %^BOLD%^%^BLACK%^of the cavern has been smoothed and "
                         "shaped by humanoid hands so that the man-made m%^WHITE%^e%^BLACK%^"
                         "tal structures that are the gat%^RESET%^e%^BOLD%^%^BLACK%^s fill "
                         "the opening seamlessly. Despite their mammoth size the metal gates "
                         "have been buffed until they sh%^WHITE%^o%^BLACK%^ne like the surface "
                         "of a mi%^RESET%^r%^BOLD%^%^WHITE%^r%^BLACK%^or and a beautiful "
                         "%^RESET%^mural %^BOLD%^%^BLACK%^has been carved into their r%^RESET%^"
                         "e%^BOLD%^%^BLACK%^flect%^WHITE%^i%^RESET%^v%^BOLD%^%^BLACK%^e surfa"
                         "%^WHITE%^c%^BLACK%^e.%^RESET%^");
    set_string("gates", "open", "%^BOLD%^%^BLACK%^The great adamantine gates "
               "shriek and groan in protest as they slide slowly open.%^RESET%^");
    set_string("gates", "close", "%^BOLD%^%^BLACK%^The great adamantine gates "
               "shriek and groan in protest as they slide slowly closed.%^RESET%^");
    OPEN = 0;
    guardians = 2;
    set_pre_exit_functions(({ "GoThroughDoor" }), ({ "gates" }));
    set_property("no phase", 1);
}

int GoThroughDoor()
{
    if (present("draconic sentinel", TO) && !TP->query_true_invis()) {
        tell_object(TP, "The draconic sentinel is blocking the way!");
        return 0;
    }
    return ::GoThroughDoor();
}

void reset()
{
    ::reset();
    guardians = 2;
}

void init()
{
    ::init();
    add_action("present_em", "present");
}

void guardian_death()
{
    guardians--;
    return;
}

int present_em(string str)
{
    string race, name;
    object sigil, dest;
    int authority;
    enemies = SAVE_D->query_array("rilynath_enemies");
    name = TPQN;
    if (!str || str != "sigil") {
        tell_object(TP, "What are you trying to present?");
        return 1;
    }
    race = TP->query_race();
    sigil = present("rilynath_sigil", TP);
    dest = find_object_or_load("/d/player_houses/aunuit/dragons_landing.c");
    if (!sigil) {
        tell_object(TP, "You don't have any sigil!");
        return 1;
    }
    if (member_array(TP->query_name(), owners) != -1) {
        tell_object(TP, "Before you can even present your sigil, a voice welcomes you home.");
        tell_room(TO, "Before " + TPQCN + " can present " + TP->QP + " sigil, a sibilant voice speaks.", TP);
        if ((string)TP->query_name() == "ryzan") {
            tell_room(TO, "%^RESET%^%^MAGENTA%^The voice murmurs:%^RESET%^ Welcome home, Valuuuk.");
        }else if ((string)TP->query_name() == "aunuit") {
            tell_room(TO, "%^RESET%^%^MAGENTA%^The voice murmurs:%^RESET%^ Welcome home, Valsssharesss.");
        }else {
            tell_room(TO, "%^RESET%^%^MAGENTA%^The voice murmurs:%^RESET%^ Welcome home, massster.");
        }
    }
    authority = "/d/player_houses/aunuit/pool.c"->get_authority(TP);
    tell_room(TO, "%^RESET%^The mural of the %^BOLD%^%^BLACK%^gate "
              "%^RESET%^begins to %^CYAN%^s%^BOLD%^%^CYAN%^h%^WHITE%^i"
              "%^CYAN%^f%^RESET%^%^CYAN%^t %^RESET%^as the sigil is "
              "presented, the %^BOLD%^%^GREEN%^el%^RESET%^%^GREEN%^v"
              "%^BOLD%^%^GREEN%^en %^RESET%^figures turning to gaze at "
              "you as the %^BOLD%^%^BLACK%^dragon %^RESET%^lowers its "
              "head and opens its great %^RED%^m%^BOLD%^%^RED%^a%^RESET%^"
              "%^RED%^w%^WHITE%^. Within the mouth the surface of the gate "
              "%^CYAN%^r%^BOLD%^%^CYAN%^i%^WHITE%^p%^CYAN%^p%^RESET%^"
              "%^CYAN%^les %^WHITE%^and seems to melt away leaving a "
              "%^BOLD%^%^BLACK%^shadowed path %^RESET%^through the thick "
              "adamantine doors open before you.%^RESET%^");
    set_locked("gates", 0, "runes");
    set_open("gates", 1);
    tell_room(dest, "%^RESET%^The mural of the %^BOLD%^%^BLACK%^gate "
              "%^RESET%^begins to %^CYAN%^s%^BOLD%^%^CYAN%^h%^WHITE%^i"
              "%^CYAN%^f%^RESET%^%^CYAN%^t %^RESET%^as the sigil is "
              "presented, the %^BOLD%^%^GREEN%^el%^RESET%^%^GREEN%^v"
              "%^BOLD%^%^GREEN%^en %^RESET%^figures turning to gaze at "
              "you as the %^BOLD%^%^BLACK%^dragon %^RESET%^lowers its "
              "head and opens its great %^RED%^m%^BOLD%^%^RED%^a%^RESET%^"
              "%^RED%^w%^WHITE%^. Within the mouth the surface of the gate "
              "%^CYAN%^r%^BOLD%^%^CYAN%^i%^WHITE%^p%^CYAN%^p%^RESET%^"
              "%^CYAN%^les %^WHITE%^and seems to melt away leaving a "
              "%^BOLD%^%^BLACK%^shadowed path %^RESET%^through the thick "
              "adamantine doors open before you.%^RESET%^");
    dest->set_locked("gates", 0, "runes");
    dest->set_open("gates", 1);
    call_out("set_auto_closed", 15);
    OPEN = 1;
    if (authority < 1) {
        if (race != "drow" || race != "elf" || member_array(name, enemies) != -1) {
            if (guardians && !present("draconic sentinel", TO)) {
                tell_room(TO, "%^BOLD%^%^BLACK%^A deafening commotion of metal "
                          "grinding against metal fills the cavern as the dragons "
                          "begin to move. They let out a shrill, metallic roar "
                          "and move to block the entrance.%^RESET%^");
                tell_room(dest, "%^BOLD%^%^BLACK%^A deafening commotion of metal "
                          "grinding against metal fills the cavern as the dragons "
                          "begin to move. They let out a shrill, metallic roar "
                          "and move to block the entrance.%^RESET%^");
                new(OBJ "draconic_sentinel")->move(TO);
                new(OBJ "draconic_sentinel")->move(TO);
            }
        }
    }
    return 1;
}

void set_auto_closed()
{
    object dest;
    dest = find_object_or_load("/d/player_houses/aunuit/dragons_landing.c");
    tell_room(TO, "%^BOLD%^%^BLACK%^The great %^RED%^j%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^ws %^BLACK%^of the dragon snap %^RESET%^shut "
              "%^BOLD%^%^BLACK%^closing the passage as though it never were. "
              "The creature raises itself up to its former position and the "
              "%^RESET%^%^GREEN%^el%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^en "
              "%^BOLD%^%^BLACK%^figures step back into place beneath its "
              "outstretched wings.%^RESET%^");
    set_locked("gates", 1, "runes");
    set_open("gates", 0);
    tell_room(dest, "%^BOLD%^%^BLACK%^The great %^RED%^j%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^ws %^BLACK%^of the dragon snap %^RESET%^shut "
              "%^BOLD%^%^BLACK%^closing the passage as though it never were. "
              "The creature raises itself up to its former position and the "
              "%^RESET%^%^GREEN%^el%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^en "
              "%^BOLD%^%^BLACK%^figures step back into place beneath its "
              "outstretched wings.%^RESET%^");
    dest->set_locked("gates", 1, "runes");
    dest->set_open("gates", 0);
    OPEN = 0;
    return;
}

/*
   Gate functions
   Ok disregard all the gate function stuff from the previous mail. Rewrote this with the idea of the place being broken into equally well by any class while allowing us to still scry/tp proof the area. No longer is there a door in the gate with a gatekeeper. Please replace the gate description in the "Dragons landing" room with this new one along with adding the mural.

   The new function will be "present sigil" at the gate. This will only work if the player has a house sigil(lootable from the wandering guards and assassins which should travel in groups and be strong enough to be a challenge to solo high level players just to make the keys not super easy to get)


   We need a way to list enemies who will be attacked on sight by wandering guards and assassins. All who murder a guard for his sigil should immediately be added to this list. We need to be able to add and remove individuals from the list as well.

   Also a function added to list house members we can add to and remove from and those will be able to "request sigil" from guards to replace any they might have lost or to give to a potential new member.

   You can add a few more tunnel rooms as well, more space for the wandering guards to travel on. The foreboding tunnel generic can be used as many times as you like. Maybe add a line to the thief tunnel it joins that the wall has been melted out to indicate the fire burrowing that was done.




 */
