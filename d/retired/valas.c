#include <std.h>
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_id(({"valas","Valas","human"}));
    set_name("valas");
    set_short("%^BOLD%^%^CYAN%^Va%^RESET%^%^WHITE%^l%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^s%^MAGENTA%^ the%^RESET%^ %^CYAN%^arcane %^RED%^magus %^BLUE%^of %^CYAN%^Mystra%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Valas is a man in the%^RESET%^ %^ORANGE%^autumn%^RESET%^ "
"%^BOLD%^%^WHITE%^of his years. Even though his body shows signs of %^CYAN%^age, "
"%^BOLD%^%^WHITE%^he is still in remarkably good shape. %^BLACK%^Graying hair "
"%^BOLD%^%^WHITE%^with%^RESET%^ %^RED%^crimson%^RESET%^ %^BOLD%^%^WHITE%^streaks flows "
"from his head in waves down over his back. His skin is remarkably smooth and fair "
"considering his %^CYAN%^age. %^BOLD%^%^WHITE%^His large eyes are %^GREEN%^deep green "
"%^BOLD%^%^WHITE%^and shine with inner %^BLUE%^wisdom %^BOLD%^%^WHITE%^only gotten by a "
"lifetime of experience. His face is framed by high cheekbones and an aquiline nose which "
"enhances his appearance and make him seem like a warm and friendly old man.%^RESET%^");
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_alignment(2);
    set_diety("mystra");
    set_class("mage");
    set_hd(40,6);
    set_guild_level("mage",40);
    set_mlevel("mage",40);
    set_nogo(({"/d/player_houses/valas/rooms/tower1"}));
    set_max_hp(3000);
    set_hp(3000);
    set_exp(28000);
    set_overall_ac(-4);
    set("aggressive",0);
    set_stats("dexterity",18);
    set_stats("strength",10);
    set_stats("intelligence",10);
    set_wielding_limbs(({"left hand","right hand"}));
    set_emotes(1, ({"%^BOLD%^%^MAGENTA%^Valas says: If you want to be as great as i am you can only have one love and that is the weave for it will always care and love you as long as you're "
"willing to use it.%^RESET%^","%^BOLD%^%^CYAN%^Valas says: I have only ever feared for my life once, And that is after%^RESET%^ %^YELLOW%^Cedric%^RESET%^ %^BOLD%^%^CYAN%^ate something spicy "
"and he thought it would be ok to relieve him self of gas. It took me months to get that smell out of the temple.%^RESET%^","%^BOLD%^%^GREEN%^Valas says: Working with the Weave is no small "
"matter. If you truly want to master the weave ... know, that it is the Weave that will master you, and you will be a conduit for its powers.%^RESET%^","%^BOLD%^%^BLACK%^Valas says: Do not "
"bother me with little matters. I must find a way to remove Durias' godhood and kill him before his evil gets in my way again.%^RESET%^","%^BOLD%^%^RED%^Valas sighs and looks to the floor, "
"saying: I wonder if she even remembers my name. For her this lifetime was a blink of a eye. Don't fall for a elf, they will only watch you die of old age.%^RESET%^","%^BOLD%^%^ORANGE%^"
"Valas says: The use of magic is nothing for the weak minded. You can easily be seduced by the power it offers and lose your soul to corruption ... Batlin is such a poor soul."
"%^RESET%^","%^BOLD%^%^WHITE%^Valas says: Friends are always welcome to visit me here in my final place of retirement. But please do not cause trouble. My golem has a very low tolerance for "
"mischief.%^RESET%^","%^BOLD%^%^YELLOW%^Valas says: A great %^RESET%^%^MAGENTA%^abomination%^BOLD%^%^YELLOW%^ is using the weave for its own petty evil and causing great harm. I cannot tolerate "
"this any more! But I cannot leave my tower at this time. Would you be able to %^RESET%^%^ORANGE%^help%^BOLD%^%^YELLOW%^ me please?%^RESET%^","%^BOLD%^%^YELLOW%^Valas says: A great %^RESET%^"
"%^MAGENTA%^abomination%^BOLD%^%^YELLOW%^ is using the weave for its own petty evil and causing great harm. I cannot tolerate this any more! But I cannot leave my tower at this time. Would you "
"be able to %^RESET%^%^ORANGE%^help%^BOLD%^%^YELLOW%^ me please?%^RESET%^" }), 0);
    add_money("gold", random(100)+400);
    add_money("platinum", random(30)+200);
    add_money("electrum", random(100)+500);
/*    ob = new("/d/islands/common/obj/robes");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear robes");
    ob = new("/d/islands/common/obj/windguards");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear bracers");
    ob = new("/d/retired/obj/mercuryscale");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear scale");
    ob = new("/d/retired/obj/valashat");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear hat");
    ob = new("/d/retired/obj/golemrod");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear rod");
    ob = new("/d/attaya/tunnels/obj/magestaff");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield staff"); */

    set_spells(({"magic missile","magic missile","lightning bolt","lightning bolt","cone of cold","fireball","powerword stun","prismatic spray","disintegrate"}));
    set_spell_chance(85);
    set_monster_feats(({
	   "spell focus",
	   "spell penetration",
	   "greater spell penetration",
    }));
    set_property("add kits",50);
    set_property("no steal",1);
}

void catch_say(string msg){
   string spoken;
   spoken = TP->query_spoken();
   call_out("reply_fun",1,msg,TP,spoken);
}

void reply_fun(string msg, object who, string mylang){
   string name;
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(TP->query_invis()) return;

   force_me("speak common");
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"yes") != -1 || strsrch(msg,"help") != -1 || strsrch(msg,"abomination") != -1 || strsrch(msg,"harm") != -1)){
     if((int)who->query_level() > 31) {
       force_me("say %^BOLD%^%^YELLOW%^A Great evil corrupts the %^BOLD%^%^MAGENTA%^Weave%^YELLOW%^. I cannot ask this of you as it would surely mean the %^BLACK%^death%^YELLOW%^ of "
"you!%^RESET%^");
       return;
     }
     force_me("say %^BOLD%^%^YELLOW%^The %^RESET%^%^MAGENTA%^Arch Lich V%^RED%^e%^MAGENTA%^cna%^BOLD%^%^YELLOW%^ still casts his evil %^BOLD%^%^BLACK%^shadow%^YELLOW%^ over this realm "
"on the physical plane, as well as in the %^BOLD%^%^MAGENTA%^Weave.%^YELLOW%^ I fear that if he is not stopped ... his powers will grow to a level where he will corrupt the %^BOLD%^%^MAGENTA%^"
"weave%^YELLOW%^, and cause unspeakable damage to our realm ... He must be stopped!%^RESET%^");
     force_me("say %^BOLD%^%^YELLOW%^This is no easy task I ask of you, I realize this. But this has to be done or I fear the consequences for all of us! You will do this. For all of our "
"sakes?%^RESET%^");
     force_me("say %^BOLD%^%^YELLOW%^If you are willing, bring me the dragonseye amulet held by %^RESET%^%^MAGENTA%^Arch lich V%^BOLD%^%^RED%^e%^RESET%^%^MAGENTA%^cna %^BOLD%^%^YELLOW%^as "
"proof that the deed is done and we can all rest a little more easily in the night. If you do this, I will reward you with something very dear to me. Go now my friend. Go with the blessings of "
"the %^MAGENTA%^Weave!%^RESET%^");
     return;
   }
}

void receive_given_item(object obj){
    string name;
    object ob;
    if(!objectp(obj)) return;
    if(!objectp(TP)) return;
    name = TPQN;
    force_me("speak common");

    if(base_name(obj) != "/d/retired/obj/valasamulet") {
       force_me("say %^BOLD%^%^YELLOW%^I don't need this.%^RESET%^");
       force_me("give "+obj->query_name()+" to "+name+"");
       return;
    }
    force_me("say %^BOLD%^%^YELLOW%^By the %^WHTE%^Blessing %^YELLOW%^of the %^BLUE%^S%^CYAN%t^%^WHITE%^a%^CYAN%^r%^BLUE%^s%^YELLOW%^! You have done it! You have no idea how much this means "
"to me, knowing that %^RESET%^%^MAGENTA%^V%^BOLD%^%^RED%^e%^RESET%^MAGENTA%^cna %^BOLD%^%^YELLOW%^will no longer corrupt the %^BOLD%^%^MAGENTA%^Weave. You have most surely earned your reward."
"%^RESET%^");
    force_me("say %^BOLD%^%^YELLOW%^I hereby give to you my strongest creation which has served me well in so many years! I hope it will serve you as well as it has me. Go and know you have "
"made this old man very happy.");
    if(!present("mithril rod",TO)) new("/d/retired/obj/golemrod")->move(TO);
    ob = present("mithril rod",TO);
    ob->remove_property("monsterweapon");
    command("give mithril rod to "+name);
}