// heavily revised; this sword trades for the greater sunblade
// but is balanced against a ragnarok. Far too good for the 
// challenge to retrieve it, so reduced to parity with the item
// traded for. Special rate reduced, had 43% overlap specials
// compared to 30% on ragnarok/sunblade. Way too much.
// N, 2/12.
#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/bastard";

int COUNTER,FLAG;
string OWNER;
string summon_mon = "/d/magic/temples/misc/hrotha_soul.c";

void tell_em(string str);

int do_sacrifice(string str) {
    object targ;
    string real_name;
    int bound;

    if(!objectp(ETO)) return 0;  
//    if(!TO->is_wielded()) return 0; //brokkin! N, 2/12
    if(!TO->query_wielded()) return 0;
    if(!stringp(str) || str == "" || str == " ") {
        tell_object(ETO,"The blade will only accept the soul of an adventurer.");
        return 1;
    }

    real_name = ETO->realName(str);
    if(!objectp(targ=present(real_name,EETO))) {
        if(!objectp(targ=present(str,EETO))) {
            tell_object(ETO,"You don't notice that here.");
            return 1;
        }
    }

    if(!interactive(targ)) {
        tell_object(ETO,"The blade will only accept the soul of an adventurer.");
        return 1;
    }

    if(base_name(EETO) != "/d/magic/temples/cyric") {
        tell_object(ETO,"The blade will only take a sacrifice on the altar of Cyric.");
        return 1;
    }

    bound = (int)targ->query_bound();
    if(bound < 25) {
        tell_object(ETO,"Your target must be tied up better first.");
        return 1;
    }

    tell_object(ETO,"%^BOLD%^%^BLACK%^You %^RESET%^%^RED%^thrust%^BOLD%^%^BLACK%^ the sword into "
        ""+targ->QCN+"'s %^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^RED%^art%^BOLD%^%^BLACK%^, "
        "twisting it to inflict "
        "l%^RED%^e%^BLACK%^thal and %^RESET%^%^ORANGE%^gut-"
        "wrenching pain%^BOLD%^%^BLACK%^. "
        "The blade begins to feed on "+targ->QP+" s%^CYAN%^o%^BLACK%^ul%^BOLD%^%^BLACK%^ and "
        "%^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d"
        "%^BOLD%^%^BLACK%^, "
        "sucking both into its abyssal black blade, which "
        "glows black as the blood %^RESET%^%^GREEN%^trickles%^BOLD%^%^BLACK%^ "
        "towards the blood groove."
        " "+targ->QCN+" quickly grows %^RESET%^older%^BOLD%^%^BLACK%^ "
        "before your very eyes, until "+targ->QS+" is nothing more than an "
        "%^RESET%^%^ORANGE%^old, shriveled corpse%^BOLD%^%^BLACK%^, "
        "all %^BOLD%^%^YELLOW%^l%^WHITE%^i%^YELLOW%^ght%^BOLD%^%^BLACK%^ fading from "+targ->QP+" eyes." 
        "The process must have been excruciatingly %^BOLD%^%^RED%^painful%^BLACK%^!%^RESET%^");

    tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" %^RESET%^%^RED%^thrusts%^BOLD%^%^BLACK%^ "
        ""+ETO->QP+" sword into your "
        "%^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^RED%^art%^BOLD%^%^BLACK%^, "
        "twisting it to inflict l%^RED%^e%^BLACK%^thal and %^RESET%^%^ORANGE%^gut-"
        "wrenching pain%^BOLD%^%^BLACK%^. The blade begins to feed on your "
        "s%^CYAN%^o%^BLACK%^ul and "
        "%^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^, "
        "sucking both into its abyssal black blade, which glows black as "
        "the blood %^RESET%^%^GREEN%^trickles%^BOLD%^%^BLACK%^ towards the blood groove. "
        "You quickly feel yourself "
        "%^RESET%^aging%^BOLD%^%^BLACK%^ and know that in a moment, you will be nothing, "
        "but an %^RESET%^%^ORANGE%^old, "
        "shriveled corpse%^BOLD%^%^BLACK%^. "
        "At least, the %^BOLD%^%^RED%^agonizing pain%^BOLD%^%^BLACK%^ will have subsided.%^RESET%^");

    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" %^RESET%^%^RED%^thrusts%^BOLD%^%^BLACK%^ "+ETO->QP+
	  " sword into "+targ->QCN+"'s "
        "%^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^RED%^art%^BOLD%^%^BLACK%^, "
        "twisting it to inflict l%^RED%^e%^BLACK%^thal and %^RESET%^%^ORANGE%^gut-"
        "wrenching pain%^BOLD%^%^BLACK%^. The blade begins to feed on "+targ->QP+" s%^CYAN%^o%^BLACK%^ul "
        "and %^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^, "
        "sucking both into its abyssal black blade, which glows black as the blood %^RESET%^%^GREEN%^trickles%^BOLD%^%^BLACK%^ "
        "towards the blood groove. "+targ->QCN+" quickly grows %^RESET%^older%^BOLD%^%^BLACK%^ before "
        "your very eyes, until "+targ->QS+" is nothing more than an %^RESET%^%^ORANGE%^old, "
        "shriveled corpse%^BOLD%^%^BLACK%^, all %^BOLD%^%^YELLOW%^l%^WHITE%^ig%^YELLOW%^ht%^BOLD%^%^BLACK%^ "
        "fading from "+targ->QP+" eyes. "
        "The process must have been excruciatingly %^BOLD%^%^RED%^painful%^BLACK%^!%^RESET%^",({ETO,targ}));

//    COUNTER += 1000; // instant global special. Bit too much. N, 2/12.
    COUNTER += 200;

    targ->set_hp(-100);
    ETO->force_me("hit "+str+"");
    return 1;
}

void create() {
    ::create();
    set_id(({"sword","soul of the eclipse","hrotha","long sword","longsword","black longsword"}));
    set_name("Hrotha, Soul of the Eclipse");
    set_obvious_short("%^BOLD%^%^BLACK%^A %^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^i"
        "%^BOLD%^%^BLACK%^st%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r "
        "a%^RESET%^b%^BOLD%^%^BLACK%^yss%^RESET%^a%^BOLD%^%^BLACK%^l "
        "bla%^BOLD%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k longsword%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^H%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^ha - "
        "S%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ul of the "
        "E%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^"
        "p%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^e%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^profane%^BOLD%^%^BLACK%^ "
        "a%^WHITE%^u%^BLACK%^ra of utter bi%^RESET%^tt%^BOLD%^%^BLACK%^erness "
        "and %^RESET%^%^GREEN%^m%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^lic%^BOLD%^%^GREEN%^e%^BLACK%^ "
        "permeates the air surrounding this a%^RESET%^b%^BOLD%^%^BLACK%^yss%^RESET%^a%^BOLD%^%^BLACK%^l "
        "bla%^BOLD%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k blade. "
        "Its surface p%^RED%^u%^BLACK%^ls%^RED%^e%^BLACK%^s with the "
        "r%^RESET%^h%^BOLD%^%^BLACK%^yt%^RESET%^h%^BOLD%^%^BLACK%^m of a "
        "%^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^RED%^art%^BOLD%^%^BLACK%^ "
        "beat as %^BOLD%^%^BLACK%^bla%^MAGENTA%^c%^BLACK%^k and "
        "%^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^ "
        "l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ni%^RESET%^%^MAGENTA%^n"
        "%^BOLD%^%^BLACK%^g streak down the flat of the blade towards a "
        "%^RESET%^%^RED%^blood groove%^BOLD%^%^BLACK%^, which is covered with "
        "%^BOLD%^%^WHITE%^s%^RESET%^il%^BOLD%^%^WHITE%^ver etchings%^BOLD%^%^BLACK%^. "
        "%^RESET%^%^GREEN%^Ma%^BOLD%^%^GREEN%^gi%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^ "
        "must have had a hand in the crafting of this weapon as distorted images of "
        "wa%^BLUE%^i%^BLACK%^l%^BLUE%^i%^BLACK%^ng and t%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^red "
        "s%^CYAN%^o%^BOLD%^%^BLACK%^uls "
        "course intermittently down it. The entire sword is more than five feet in length, "
        "nearly four of which form the blade itself. "
        "%^RESET%^%^CYAN%^Li%^RESET%^%^GREEN%^ght%^RESET%^%^CYAN%^er%^BOLD%^%^BLACK%^ than "
        "its size would suggest, the hollow-ground sword has been "
        "deliberately shaped for strength without weight. Perfectly balanced, "
        "the weapon has been honed %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-"
        "s%^RED%^h%^BOLD%^%^BLACK%^arp "
        "with a %^BOLD%^%^BLACK%^w%^RED%^i%^BLACK%^ck%^RED%^e%^BLACK%^dly, "
        "g%^BOLD%^%^MAGENTA%^r%^BLACK%^u%^BLACK%^es%^MAGENTA%^o%^BLACK%^me "
        "serrated edge that tapers into a slightly curved, ja%^RESET%^%^CYAN%^gg%^BOLD%^%^BLACK%^ed point. "
        "%^BOLD%^%^BLACK%^It seems to have been deliberately designed to inflict "
        "as many l%^RED%^e%^BLACK%^thal "
        "and %^RESET%^%^ORANGE%^agonizing%^BOLD%^%^BLACK%^ injuries as possible. "
        "Oddly, its thick blade narrows abruptly to a thin neck just before "
        "the crossguard which %^RESET%^%^RED%^f%^BOLD%^%^RED%^la%^RESET%^%^RED%^res%^BOLD%^%^BLACK%^ "
        "back out again in several "
        "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ ridges "
        "like %^BOLD%^%^WHITE%^t%^BLACK%^e%^BLACK%^n%^WHITE%^d%^BLACK%^r%^WHITE%^ils%^BLACK%^ of "
        "%^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^YELLOW%^m%^RED%^e%^BOLD%^%^BLACK%^. "
        "No leather wraps the hilt, but the "
        "grip is %^BOLD%^%^CYAN%^smooth%^BLACK%^ "
        "and slightly ridged, intentionally shaped as a secure handhold. "
        "At the center of the hilt, a "
        "single %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^BLACK%^ has been embedded. "
        "%^RESET%^White crys%^CYAN%^t%^RESET%^als%^BOLD%^%^BLACK%^ within "
        "the ruby have collapsed to form a "
        "%^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess "
        "sk%^RED%^u%^BLACK%^ll, which sparkles in the "
        "%^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-red%^BOLD%^%^BLACK%^ "
        "surface of the gem.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^A chi%^CYAN%^ll%^WHITE%^ing w%^%^RESET%^CYAN%^i%^BOLD%^%^WHITE%^nd brushes against you. The brutal c%^BOLD%^%^CYAN%^o%^WHITE%^ld forces its way into your mind.\n\n"
"%^BOLD%^%^WHITE%^A thought rasps in a thin, scratchy voice within the depths of your mind:%^RESET%^%^CYAN%^ Hello Stranger, I need your aid.\n\n"
"%^RESET%^%^CYAN%^I'm Hrotha of %^BOLD%^%^WHITE%^A%^CYAN%^u%^WHITE%^r%^CYAN%^i%^WHITE%^l%^RESET%^%^CYAN%^ and I have been trapped within this damn sword.\n\n"
"%^RESET%^%^CYAN%^I was trapped by Alzar of %^BOLD%^%^BLACK%^Cyric%^RESET%^%^CYAN%^ within this blasted sword. He did it for that %^BOLD%^%^RED%^bitch%^RESET%^%^CYAN%^ of a wife.\n\n"
"%^RESET%^%^CYAN%^I remember my soul being ripped from my body and transferred to this forsaken weapon. The reason for this? Simple, I was the unlucky woman who found Dorje when she was, but a "
"baby thrown to the wolves and kept her alive. I trained her in the ways of %^BOLD%^%^WHITE%^A%^CYAN%^u%^WHITE%^r%^CYAN%^i%^WHITE%^l%^RESET%^%^CYAN%^ and aided her. Alzar thought I was overly "
"harsh to his precious wife and decided to return the pain for %^RESET%^eternity%^RESET%^%^CYAN%^.\n\n"
"%^RESET%^%^CYAN%^If you would be willing to help free me, I would. %^BOLD%^%^BLACK%^A searing and mind-numbing pain e%^RED%^r%^BLACK%^upts within your mind.%^RESET%^\n\n"
"%^BOLD%^%^BLACK%^A thought e%^RED%^r%^BLACK%^upts in a %^BOLD%^%^WHITE%^c%^CYAN%^oo%^WHITE%^l%^BOLD%^%^BLACK%^ tone: %^BOLD%^%^BLUE%^'%^BOLD%^%^WHITE%^Hrotha, You do not believe I was wise "
"enough to have created preventive measures for your meddling?%^BOLD%^%^BLUE%^'%^RESET%^\n\n"
"%^BOLD%^%^RED%^The voices recede from your mind, but not before a pa%^RESET%^%^RED%^i%^BOLD%^%^RED%^nful struggle.%^RESET%^");

    set_language("common");
    set_read("%^BOLD%^%^BLACK%^Kneel before the "
        "%^BOLD%^%^WHITE%^S%^BLACK%^u%^WHITE%^p%^BLACK%^r%^WHITE%^e%^BLACK%^m%^WHITE%^e "
        "%^BOLD%^%^BLACK%^P%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^wer%^RESET%^");

    set_value(17600);
    set_property("no curse",1);
    set_property("enchantment",5);
    set_item_bonus("attack bonus",3);
    set_item_bonus("damage bonus",3);
    set_item_bonus("sight bonus",3);
    set_weight(6);
    set_weapon_prof("exotic");
    set_hit((:TO,"strike":));
    set_wield((:TO,"extra_wield":));
    set_unwield((:TO,"removeme":));
    set_heart_beat(1);

}

int query_counter() { return COUNTER; }

void set_counter(int num) {
    COUNTER = num;
    return;
}

string query_owner() { return OWNER; }

void init(){
    ::init();
    if(!objectp(ETO)) { return; }
    if(!interactive(ETO)) { return; }
    add_action("do_sacrifice","sacrifice");
    if(!OWNER || OWNER == "") {
        if(interactive(ETO) && !ETO->query_true_invis()) {
            OWNER = ETO->query_true_name();
        }
    }
}

void heart_beat() {
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    if(interactive(ETO) && present("hrotha 2",ETO)) {
        if(strsrch(base_name(TO),"hrotha_soul_of_the_eclipse") == -1) { return; }
        tell_object(ETO,"%^RED%^The two swords tremble when brought "
            "together. In a flash, the second blade vanishes!");
        present("hrotha 2",ETO)->remove();
    }
    
    if(!objectp(ETO) || !living(ETO)) return;
    if(!objectp(EETO)) return;
//    if((string)ETO->query_true_name() != "dorje") return;
    if(!objectp(TO->query_wielded())) return; 
    if(!random(50)) {
        switch(random(4)) {
        case 0:
            tell_object(ETO,"%^RESET%^%^CYAN%^A myriad %^BOLD%^%^BLACK%^wa%^BLUE%^i%^BLACK%^ls%^RESET%^%^CYAN%^ "
                "scream out from your blade!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^CYAN%^A myriad of agonizing %^BOLD%^%^BLACK%^wa%^BLUE%^i%^BLACK%^ls%^RESET%^%^CYAN%^ "
                "permeate the air around you!%^RESET%^",({ETO}));
            break;
        case 1:
            tell_object(ETO,"%^RESET%^%^RED%^The %^BOLD%^%^RED%^pain%^RESET%^%^RED%^ of "
                "%^BOLD%^%^BLACK%^t%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^%^red "
                "s%^CYAN%^o%^BLACK%^uls%^RESET%^%^RED%^ flows into your body as they course down your sword.%^RESET%^ ");
            tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+" %^BOLD%^%^RED%^gr%^RESET%^%^RED%^i%^BOLD%^%^RED%^ma%^RESET%^%^RED%^c"
                "%^BOLD%^%^RED%^es%^RESET%^%^RED%^ in %^RESET%^%^ORANGE%^pain%^RESET%^%^RED%^ "
                "as %^BOLD%^%^BLACK%^t%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^%^red "
                "s%^CYAN%^o%^BLACK%^uls%^RESET%^%^RED%^ "
                "courses down "+TO->query_short()+"%^RESET%^",({ETO}));
            break;
        case 2:
            tell_room(EETO,"%^BOLD%^%^WHITE%^The e%^BLACK%^c%^WHITE%^ho%^BLACK%^i%^WHITE%^ng of a "
                "whip %^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^sh%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^ng%^WHITE%^ "
                "against %^RESET%^%^ORANGE%^human f%^RED%^l%^ORANGE%^e%^RED%^s%^RED%^h%^BOLD%^%^WHITE%^ "
                "can be heard in the distance!%^RESET%^");
            break;
        default:
            tell_object(ETO,"%^RESET%^%^MAGENTA%^A t%^CYAN%^r%^MAGENTA%^ans%^CYAN%^l%^MAGENTA%^u%^CYAN%^ce%^MAGENTA%^n%^CYAN%^t "
                "image of a %^RESET%^%^ORANGE%^ha%^RED%^g%^ORANGE%^ga%^RED%^r%^ORANGE%^d-"
                "looking %^BOLD%^%^WHITE%^old%^RESET%^%^ORANGE%^ "
                "woman with %^BOLD%^%^BLACK%^weather-worn%^RESET%^%^ORANGE%^ skin and "
                "%^WHITE%^hard %^BLUE%^c%^CYAN%^o%^BLUE%^ba%^CYAN%^l%^BLUE%^t-b%^CYAN%^l%^BLUE%^ue "
                "ey%^CYAN%^e%^BLUE%^s%^RESET%^%^MAGENTA%^ "
                "shi%^BOLD%^%^MAGENTA%^mm%^RESET%^MAGENTA%^ers near you.%^RESET%^");
            tell_room(EETO,"%^RESET%^%^MAGENTA%^A t%^CYAN%^r%^MAGENTA%^ans%^CYAN%^l%^MAGENTA%^u%^CYAN%^ce%^MAGENTA%^n%^CYAN%^t "
                "image of a %^RESET%^%^ORANGE%^ha%^RED%^g%^ORANGE%^ga%^RED%^r%^ORANGE%^d-"
                "looking %^BOLD%^%^WHITE%^old%^RESET%^%^ORANGE%^ "
                "woman with %^BOLD%^%^BLACK%^weather-worn%^RESET%^%^ORANGE%^ skin and "
                "%^WHITE%^hard %^BLUE%^c%^CYAN%^o%^BLUE%^ba%^CYAN%^l%^BLUE%^t-b%^CYAN%^l%^BLUE%^ue "
                "ey%^CYAN%^e%^BLUE%^s%^RESET%^%^MAGENTA%^ "
                "shi%^BOLD%^%^MAGENTA%^mm%^RESET%^MAGENTA%^ers near "+ETO->QCN+".",({ETO}));
            break;
        }
    }
    return;
}

int extra_wield() {
    object obj;

    if((string)ETO->query_true_name() != OWNER && !ETO->query_true_invis()) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l"
            "%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ flame engulfs the hilt, "
            "slowly burning your flesh, forcing you to drop the blade!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l"
            "%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ flame "
            "engulfs the hilt, slowly burning "+ETO->QCN+"'s flesh, forcing "+ETO->QO+" to drop the blade!%^RESET%^",({ETO}));
        TO->move(EETO);
    }

    if(ETO->query_character_level() < 35 || ETO->is_good(ETO)) {
        tell_object(ETO,"%^RESET%^%^MAGENTA%^A mad cackling can be heard as a violet flame "
            "courses down your blade.%^RESET%^");
        tell_room(EETO,"%^RESET%^%^MAGENTA%^A mad cackling can be heard as a violet "
            "flame courses down "+ETO->QCN+"'s blade.%^RESET%^",ETO);
        tell_object(ETO,"%^RESET%^%^MAGENTA%^A rasps in a thin, scratchy voice echoes in "
            "your mind %^RESET%^You aren't crazy enough to wield us!! YOU ARE WEAK!!!%^RESET%^");
        tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" shivers with a look of confusion!!%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^A surge of energy shoots up your arm from the hilt of the "
            "sword and to the base of your skull!%^RESET%^");
        tell_room(EETO,"%^RED%^"+ETO->QCN+" gasps as "+ETO->QP+" body jolts in agonizing pain!%^RESET%^.",ETO);
        tell_object(ETO,"%^BOLD%^%^RED%^Your head throbs with a blinding pain and you collapse to "
            "the ground vomiting!%^RESET%^");
        ETO->set_paralyzed(roll_dice(3,6),"%^RED%^You are vomiting too hard to move!%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" collapses to the ground and starts to "
            "vomit uncontrollably!%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^The sword is jolted from your hand!%^RESET%^");
        tell_room(EETO,"%^BOLD%^The sword is jolted from "+ETO->QCN+"'s hand!%^RESET%^",ETO);
        TO->move(EETO);
        return 0;
    }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"You find it impossible to lift two such mighty weapons!",ETO);
     return 0;
   }

    tell_object(ETO,"%^BOLD%^%^WHITE%^You feel the %^RED%^e%^RESET%^%^RED%^ss%^BOLD%^%^RED%^ence%^WHITE%^ of a "
        "%^BOLD%^%^BLACK%^ch%^RESET%^%^MAGENTA%^ao%^BOLD%^%^BLACK%^tic%^WHITE%^ "
        "p%^RED%^o%^WHITE%^wer course through your body "
        "upon wielding the "+TO->query_short()+".%^RESET%^");

    tell_object(ETO,"%^BOLD%^%^BLACK%^Your body is %^RESET%^%^MAGENTA%^engulfed%^BOLD%^%^BLACK%^ "
        "by %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "
        "%^BOLD%^%^RED%^flames%^BOLD%^%^BLACK%^ for a "
        "few moments as the world takes on a "
        "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ hue.%^RESET%^");

    tell_room(EETO, "%^BOLD%^%^BLACK%^"+ETO->QCN+"'s "
        "eyes %^YELLOW%^l%^WHITE%^ig%^YELLOW%^ht%^BLACK%^ "
        "up with "
        "%^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ic%^BOLD%^%^GREEN%^e%^BLACK%^ as "
        ""+ETO->QS+" grasps the %^RESET%^%^RED%^h%^BOLD%^%^RED%^i%^RESET%^%^RED%^lt%^BOLD%^%^BLACK%^ "
        "of "+TO->query_short()+".%^RESET%^",ETO);

    ETO->set_property("evil item",1);
    ETO->set_property("master weapon",1);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^WHITE%^You miss the t%^CYAN%^a%^WHITE%^ste of %^BLACK%^ch%^BLUE%^a%^BLACK%^os%^WHITE%^ "
        "after releasing the hilt of your sword.%^RESET%^");

    tell_object(ETO,"The %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "
        "light seeps from you eyes, returning your vision to normal.");

    tell_room(EETO,"%^BOLD%^%^BLACK%^The look of %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^i"
        "c%^BOLD%^%^GREEN%^e%^BLACK%^ in "+ETO->QCN+"'s eyes %^BOLD%^%^WHITE%^v%^CYAN%^a%^WHITE%^"
        "nishes%^BLACK%^ as "+ETO->QS+" releases the blade, sighing "
        "l%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ng%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n"
        "g%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^y.%^RESET%^",ETO);

    ETO->set_property("evil item",-1);
    ETO->set_property("master weapon",-1);
    return 1;
}

int strike(object targ) {
    int rand,roll, i;
    object *targweapon=({}),mon;
    string *ids=({});

	if(!objectp(ETO))  { return 0; }
    if(!sizeof(ETO->query_attackers())) { return 0; }
    targ = (object)ETO->query_current_attacker();
	if(!objectp(EETO)) { return 0; }
    if(roll_dice(1,100) > 37) { COUNTER++; return roll_dice(1,4); }

    if((string)ETO->query_true_name() != "dorje") { rand = random(377); }
    else { rand = random(700); }
    //rand = 699;

    if(rand > 0 && rand < 115)
    {
        tell_object(ETO,"%^RESET%^%^MAGENTA%^V%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^ "
            "flames %^BOLD%^%^RED%^crackle%^BOLD%^%^WHITE%^ along the blade as you cleave through "+targ->QCN+"!%^RESET%^");

        tell_object(targ,"%^RESET%^%^MAGENTA%^V%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^ "
            "flames %^BOLD%^%^RED%^crackle%^BOLD%^%^WHITE%^ along the blade as "+ETO->QCN+" cleaves through you!%^RESET%^");

        tell_room(EETO,"%^RESET%^%^MAGENTA%^V%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^WHITE%^ "
            "flames %^BOLD%^%^RED%^crackle%^BOLD%^%^WHITE%^ along the blades as "+ETO->QCN+" cleaves "
            "through "+targ->QCN+"!%^RESET%^",({targ,ETO}));

        ETO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(1,12));
        ETO->set_property("magic",-1);

        COUNTER--;
    }


    if(rand > 75 && rand < 165)
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^Your blade %^RESET%^%^RED%^crackles%^BOLD%^%^BLACK%^ with "
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "
            "%^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^YELLOW%^m%^RED%^es%^BLACK%^ "
            "and l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^n"
            "i%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^g as it strikes "+targ->QCN+"!%^RESET%^");

        tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s blade %^RESET%^%^RED%^crackles%^BOLD%^%^BLACK%^ with "
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "
            "%^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^YELLOW%^m%^RED%^es%^BLACK%^ and "
            "l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ni%^RESET%^%^MAGENTA%^"
            "n%^BOLD%^%^BLACK%^g as it strikes you!%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s blade %^RESET%^%^RED%^crackles%^BOLD%^%^BLACK%^ with "
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "
            "%^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^YELLOW%^m%^RED%^es%^BLACK%^ and "
            "l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ni%^RESET%^%^MAGENTA%^"
            "n%^BOLD%^%^BLACK%^g as it strikes "+targ->QCN+"!%^RESET%^",({ETO,targ}));

        ETO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(1,12));
        ETO->set_property("magic",-1);

        COUNTER--;
    }


    if(rand > 150 && rand < 215)
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^Si%^RESET%^lv%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^ energy "
            "courses out from the %^BOLD%^%^WHITE%^crystal skull%^BOLD%^%^BLACK%^ on the blade's "
            "hilt and %^BOLD%^%^RED%^expl%^RESET%^%^RED%^o%^BOLD%^%^RED%^des%^BOLD%^%^BLACK%^ into "+targ->QCN+" "
            "with a %^RESET%^%^MAGENTA%^m%^BLUE%^a%^MAGENTA%^els%^BLUE%^t%^MAGENTA%^rom%^BOLD%^BLACK%^ of "
            "%^BOLD%^%^RED%^energy%^BOLD%^%^BLACK%^.%^RESET%^");

        tell_object(targ,"%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^m%^BLUE%^a%^MAGENTA%^els%^BLUE%^t%^MAGENTA%^rom%^BOLD%^BLACK%^ of "
            "%^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^ "
            "energy explodes against you, forcing you to your "
            "knees in %^RESET%^%^ORANGE%^agonizing %^BOLD%^%^RED%^pain%^BOLD%^%^BLACK%^!%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^WHITE%^Si%^RESET%^lv%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^ energy "
            "%^BOLD%^%^RED%^ri%^RESET%^%^RED%^pp%^BOLD%^%^RED%^les%^BOLD%^%^BLACK%^ off "
            ""+ETO->QCN+"'s longsword colliding with "+targ->QCN+" and forcing "+targ->QO+" to "+targ->QP+" knees "
            "with a %^RESET%^%^ORANGE%^painful %^BOLD%^%^BLACK%^wa%^CYAN%^i%^BLACK%^l!%^RESET%^",({ETO,targ}));

        targ->set_paralyzed(roll_dice(1,10) + 10, "%^BOLD%^%^RED%^The agonizing pain clouds your ability to control your body!");
        COUNTER--;    
    }

    if(rand > 200 && rand < 290)
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^Bla%^MAGENTA%^c%^BLACK%^k and %^RESET%^%^MAGENTA%^violet %^BOLD%^%^BLACK%^l"
            "%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ni%^RESET%^%^MAGENTA%^"
            "n%^BOLD%^%^BLACK%^g t%^YELLOW%^w%^BLACK%^i%^YELLOW%^s%^BLACK%^ts%^BOLD%^%^WHITE%^ down your "
            "sword as you become a %^RESET%^%^MAGENTA%^m%^BLUE%^a%^MAGENTA%^els%^BLUE%^t%^MAGENTA%^rom%^BOLD%^WHITE%^ of "
            "ch%^RESET%^%^BLUE%^a%^BOLD%^WHITE%^os, hitting "+targ->QCN+" in %^CYAN%^rapid%^WHITE%^ succession.%^RESET%^");

        tell_object(targ,"%^BOLD%^%^BLACK%^Bla%^MAGENTA%^c%^BLACK%^k and %^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^ l"
            "%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ni%^RESET%^%^MAGENTA%^n"
            "%^BOLD%^%^BLACK%^g t%^YELLOW%^w%^BLACK%^i%^YELLOW%^s%^BLACK%^ts%^BOLD%^%^WHITE%^ down "
            ""+ETO->QCN+"'s sword as they become a %^RESET%^%^MAGENTA%^m%^BLUE%^a%^MAGENTA%^els%^BLUE%^"
            "t%^MAGENTA%^rom%^BOLD%^WHITE%^ of ch%^RESET%^%^BLUE%^a%^BOLD%^WHITE%^os, hitting you "
            "in %^CYAN%^rapid%^WHITE%^ succession.%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^BLACK%^Bla%^MAGENTA%^c%^BLACK%^k and %^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^ "
            "l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ni%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^g "
            "t%^YELLOW%^w%^BLACK%^i%^YELLOW%^s%^BLACK%^ts%^BOLD%^%^WHITE%^ down "+ETO->QCN+"'s sword "
            "as they become a %^RESET%^%^MAGENTA%^m%^BLUE%^a%^MAGENTA%^els%^BLUE%^t%^MAGENTA%^rom%^BOLD%^WHITE%^ of "
            "ch%^RESET%^%^BLUE%^a%^BOLD%^WHITE%^os, hitting "+targ->QCN+" in %^CYAN%^rapid%^WHITE%^ succession.%^RESET%^",({ETO,targ}));

        if(sizeof(ETO->query_attackers())) { ETO->execute_attack(); }
        COUNTER--;    
    }

    if(rand > 250 && rand < 315)
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The si%^RESET%^lv%^BOLD%^%^WHITE%^er etchings%^BOLD%^%^BLACK%^ "
            "begin to glow as you plunge the blade deep into "+targ->QCN+" chest, "
            "leaving you %^BOLD%^%^GREEN%^refreshed%^BOLD%^%^BLACK%^.%^RESET%^");

        tell_object(targ,"%^BOLD%^%^BLACK%^The a%^RESET%^b%^BOLD%^%^BLACK%^yss%^RESET%^a%^BOLD%^%^BLACK%^l black sword "
            "sinks deep into your chest, %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er etchings%^BOLD%^%^BLACK%^ "
            "glowing brightly as it slowly steals your "
            "life %^RESET%^%^RED%^e%^BOLD%^%^RED%^ss%^RESET%^%^RED%^ence%^BOLD%^%^BLACK%^.%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^BLACK%^As "+ETO->QCN+" plunges sword into "+targ->QCN+"'s chest, "
            "the %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er etchings%^BOLD%^%^BLACK%^ of "
            ""+ETO->QP+" blade gl%^YELLOW%^o%^BLACK%^w.%^RESET%^",({ETO,targ}));

        ETO->set_property("magic",1);
        ETO->do_damage("torso",(roll_dice(4,12)*-1));
        ETO->set_property("magic",-1);
        COUNTER--;    
    }

    if(rand > 300 && rand < 365)
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^BOLD%^%^WHITE%^ of your "
            "blade glows a %^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-red%^BOLD%^%^WHITE%^ as it "
            "strikes "+targ->QCN+" "
            "with a %^RESET%^%^CYAN%^br%^BOLD%^%^CYAN%^il%^WHITE%^l%^CYAN%^ia%^RESET%^%^CYAN%^nt%^BOLD%^%^WHITE%^ "
            "flash of %^BOLD%^%^YELLOW%^l%^WHITE%^ig%^YELLOW%^ht%^WHITE%^!%^RESET%^");

        tell_object(targ,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^WHITE%^ on "+ETO->QCN+"'s blade "
            "glows a %^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-red%^BOLD%^%^WHITE%^ as it "
            "strikes you, blinding you with a "
            "%^RESET%^%^CYAN%^br%^BOLD%^%^CYAN%^il%^WHITE%^l%^CYAN%^ia%^RESET%^%^CYAN%^nt%^BOLD%^%^WHITE%^ "
            "flash of %^BOLD%^%^YELLOW%^l%^WHITE%^ig%^YELLOW%^ht%^WHITE%^!%^RESET%^!");

        tell_room(EETO,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^WHITE%^ on "+ETO->QCN+"'s blade "
            "glows a %^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-red%^BOLD%^%^WHITE%^ "
            "as it strikes "+targ->QCN+" with a "
            "%^RESET%^%^CYAN%^br%^BOLD%^%^CYAN%^il%^WHITE%^l%^CYAN%^ia%^RESET%^%^CYAN%^nt%^BOLD%^%^WHITE%^ "
            "flash of %^BOLD%^%^YELLOW%^l%^WHITE%^ig%^YELLOW%^ht%^WHITE%^!%^RESET%^!",({ETO,targ}));

        targ->set_temporary_blind(roll_dice(1,6));
        COUNTER--;    
    }

    if(rand > 364 && rand < 377 && COUNTER > 999) {
		int which,indoors,night;
		object *living;
		mapping info;
		living = all_living(EETO);

        // all specials do the same thing, just have different messages
        if((string)ETO->query_true_name() != "dorje") { which = 1; } // 1 = outdoors at night
        else
        {
            indoors = EETO->query_property("indoors");

            if((string)"/daemon/events_d.c"->query_time_of_day() != "night") { night = 0; }
            else { night = 1; }

            if(indoors) { which = 2; } // 2 = indoors
            else if(!night) { which = 3; } // 3 = outdoors in daytime
            else { which = 1; } // outdoors at night
        }

		info = ([ "living"  : living,
				  "eto"     : ETO,
				  "count"   : 0,
				  "special" : ({}),
				  "delay"   : 0,
				  "targ"    : targ,
				  "eeto"    : EETO,
                  "which"   : which,
				]);

		for(i=0;i<sizeof(living);i++)
		{
			living[i]->set_paralyzed(0);
			living[i]->cease_all_attacks();
		}
		call_out("global_special",2,info);	
		COUNTER = 0;
        return 0;
	}

    else if(rand > 364 && rand < 377 && COUNTER <= 999) { 		
        targ->set_paralyzed(roll_dice(5,5) + 25, "%^BOLD%^BLACK%^You are overcome by the searing pain!%^RESET%^");
        return 0;
	}

    if(rand > 376 && rand < 440) {
        	tell_object(ETO,"%^RESET%^%^RED%^The w%^BOLD%^%^BLACK%^i%^RESET%^"+
		"%^RED%^ck%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^dly, "+
            "%^BOLD%^%^BLACK%^ja%^BOLD%^%^CYAN%^gg%^BOLD%^%^BLACK%^ed%^RESET%^"+
		"%^RED%^ blade %^BOLD%^%^RED%^rends%^RESET%^%^RED%^ "+
            "the %^RESET%^%^ORANGE%^f%^RED%^l%^RESET%^%^RED%^e%^RESET%^"+
		"%^ORANGE%^sh%^RESET%^%^RED%^ from "+targ->QCN+"'s body!%^RESET%^");

        	tell_object(targ,"%^RESET%^%^RED%^"+ETO->QCN+" t%^BOLD%^%^RED%^"+
		"e%^RESET%^%^RED%^ars %^BOLD%^%^WHITE%^sh%^CYAN%^a%^WHITE%^r"+
            "ds%^RESET%^%^RED%^ of %^RESET%^%^ORANGE%^f%^RED%^l%^RESET%^%^RED%^"+
		"e%^RESET%^%^ORANGE%^sh%^RESET%^%^RED%^ from your body with "+
            "the w%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^ck%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^dly, "+
            "%^BOLD%^%^BLACK%^ja%^BOLD%^%^CYAN%^gg%^BOLD%^%^BLACK%^ed%^RESET%^%^RED%^ "+
            "edge of "+ETO->QP+" blade.%^RESET%^");

        	tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+" t%^BOLD%^%^RED%^e%^RESET%^%^RED%^ars "+
            "%^BOLD%^%^WHITE%^sh%^CYAN%^a%^WHITE%^rds%^RESET%^%^RED%^ of %^RESET%^%^ORANGE%^f%^RED%^l"+
            "%^RESET%^%^RED%^e%^RESET%^%^ORANGE%^sh%^RESET%^%^RED%^ "+
            "from "+targ->QCN+"'s body with the w%^BOLD%^%^BLACK%^i%^RESET%^"+
		"%^RED%^ck%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^dly, "+
            "%^BOLD%^%^BLACK%^ja%^BOLD%^%^CYAN%^gg%^BOLD%^%^BLACK%^ed%^RESET%^%^RED%^ "+
            "edge of "+ETO->QP+" blade.%^RESET%^",({ETO,targ}));

        ETO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(1,12));
        ETO->set_property("magic",-1);

        COUNTER--;    
    }

    if(rand > 425 && rand < 490) {
        tell_object(ETO,"%^RESET%^%^MAGENTA%^You %^RED%^thrust%^MAGENTA%^ the blade between "+targ->QCN+"'s legs, "
            "causing them to stumble and fall!%^RESET%^");

        tell_object(targ,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" %^RED%^thrusts%^MAGENTA%^ the blade between your legs "
            "causing you to lose balance and stumble!%^RESET%^");

        tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" %^RED%^thrusts%^MAGENTA%^ the blade between "+targ->QCN+"'s legs "
            "causing them to stumble and fall!%^RESET%^",({ETO,targ}));

        targ->set_tripped(roll_dice(1,3), "%^BOLD%^%^WHITE%^You attempt to stand, but sharp pain rushes through "
            "your lower extremities.",1);
        COUNTER--;
    }

    if(rand > 475 && rand < 540) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^T%^BLACK%^e%^BLACK%^n%^WHITE%^d%^BLACK%^r%^WHITE%^ils%^RESET%^%^CYAN%^ "
            "from your blade wrap about "+targ->QCN+"'s %^RED%^throat%^CYAN%^ as the %^BOLD%^%^BLACK%^ja"
            "w%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^CYAN%^ "
            "seems to %^BOLD%^%^BLACK%^p%^RED%^u%^BLACK%^ls%^RED%^e%^BLACK%^s%^RESET%^%^CYAN%^, "
            "leaving you %^BOLD%^%^GREEN%^refreshed%^RESET%^%^CYAN%^.%^RESET%^");

        tell_object(targ,"%^BOLD%^%^WHITE%^T%^BLACK%^e%^BLACK%^n%^WHITE%^d%^BLACK%^r%^WHITE%^ils%^RESET%^%^CYAN%^ "
            "latched onto your %^RED%^throat%^CYAN%^.  "
            "Your breathing becomes ra%^BOLD%^%^CYAN%^gg%^RESET%^%^CYAN%^ed as the "
            "%^BOLD%^%^BLACK%^jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll%^RESET%^%^CYAN%^ "
            "begins to glow on "+ETO->QCN+"'s sword leaving you drained.%^RESET%^");

        tell_room(EETO,"%^RESET%^%^CYAN%^"+targ->QCN+" grows a %^RESET%^%^ORANGE%^s%^BOLD%^%^GREEN%^i%^RESET%^%^ORANGE%^ckly%^RESET%^%^CYAN%^ "
            "white as %^BOLD%^%^WHITE%^t%^BLACK%^e%^BLACK%^n%^WHITE%^d%^BLACK%^r%^WHITE%^ils%^RESET%^%^CYAN%^ "
            "from "+ETO->QCN+"'s blade "
            "latch onto "+targ->QP+" %^RESET%^%^RED%^throat%^CYAN%^!%^RESET%^",({ETO,targ}));

        targ->set_paralyzed(roll_dice(1,10) + 10, "%^BOLD%^%^RED%^The agonizing pain clouds your ability to control your body!");
        ETO->set_property("magic",1);
        ETO->do_damage("torso",(roll_dice(4,12)*-1));
        ETO->set_property("magic",-1);
        COUNTER--;
    }

    if(rand > 525 && rand < 590) {
        tell_object(ETO,"%^RESET%^%^RED%^You rip the blade from "+targ->QCN+"'s side, "
            "spraying blo%^BOLD%^%^RED%^od%^RESET%^%^RED%^ into "+targ->QP+" eyes!%^RESET%^");

        tell_object(targ,"%^RESET%^%^RED%^"+ETO->QCN+" rips the blade out of you, "
            "spraying blo%^RESET%^%^RED%^o%^BOLD%^%^RED%^d%^RESET%^%^RED%^ into your eyes!%^RESET%^");

        tell_room(EETO,"%^RESET%^%^RED%^Blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d "
            "spatters into "+targ->QCN+"'s eyes as "+ETO->QCN+" rips "+ETO->QP+" blade from "+
		targ->QP+" side!%^RESET%^",({ETO,targ}));

        targ->set_temporary_blind(roll_dice(1,6));
        COUNTER--;
    }

    if(rand > 575 && rand < 640) {
        if(!objectp(targ) || !sizeof(targ->query_wielded())) {
            COUNTER++;
            return roll_dice(1,6);
        }

        tell_object(ETO,"%^BOLD%^%^WHITE%^As you %^BOLD%^%^CYAN%^tap%^BOLD%^%^WHITE%^ "+targ->QCN+" "
            "with the flat of the blade, almost as if %^BOLD%^%^MAGENTA%^toying%^BOLD%^%^WHITE%^ "+
		"with "+targ->QO+", an %^RESET%^%^BLUE%^electrical %^BOLD%^%^YELLOW%^"+
		"sh%^WHITE%^o%^YELLOW%^ck%^WHITE%^ discharges from the blade "+
		"causing "+targ->QO+" to fumble "+targ->QP+" weapon!%^RESET%^");

        tell_object(targ,"%^BOLD%^%^WHITE%^%^BOLD%^%^WHITE%^As "+ETO->QCN+" %^BOLD%^%^CYAN%^"
            "taps%^BOLD%^%^WHITE%^ you "
            "with the flat of the blade, almost as if "
            "%^BOLD%^%^MAGENTA%^toying%^BOLD%^%^WHITE%^ with you, "
            "an %^RESET%^%^BLUE%^electrical %^BOLD%^%^YELLOW%^sh%^WHITE%^o%^YELLOW%^ck%^WHITE%^ discharges "+
		"from the blade causing you to fumble your weapon!%^RESET%^");

        tell_room(EETO,"As "+ETO->QCN+" %^BOLD%^%^CYAN%^taps%^BOLD%^%^WHITE%^ "+
		targ->QCN+" with the flat of the blade, "
            "almost as if %^BOLD%^%^MAGENTA%^toying%^BOLD%^%^WHITE%^ with "+targ->QO+", "
            "an %^RESET%^%^BLUE%^electrical %^BOLD%^%^YELLOW%^sh%^WHITE%^o%^YELLOW%^ck%^WHITE%^ "
            "from the blade causes "+targ->QO+" to fumble "+targ->QP+" weapon!%^RESET%^",({ETO,targ}));

        targweapon = targ->query_wielded();        
        i = random(sizeof(targweapon));
        
        ids = targweapon[i]->query_id();
        targ->force_me("unwield "+ids[0]);
        targ->remove_property("disarm time");
        targ->set_property("disarm time",(time() + (ROUND_LENGTH *roll_dice(1,4))));
        COUNTER--;    
    }

    if(rand > 625 && rand < 699) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^WHITE%^ glows "
            "a %^CYAN%^br%^RESET%^%^CYAN%^il%^BOLD%^%^CYAN%^li%^RESET%^%^CYAN%^ant %^BOLD%^%^WHITE%^s"
            "%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er, accompanied by an overwhelming %^BOLD%^%^BLACK%^"
            "h%^GREEN%^u%^BLACK%^nger%^WHITE%^ for survival coursing through the blade as it strikes "+targ->QCN+"!%^RESET%^");

        tell_object(targ,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^WHITE%^ on "
            ""+ETO->QCN+"'s sword glows a %^CYAN%^br%^RESET%^%^CYAN%^il%^BOLD%^%^CYAN%^li%^RESET%^%^CYAN%^ant "
            "%^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er as "+ETO->QS+" strikes you, "
            "a %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ic%^BOLD%^%^GREEN%^e %^BOLD%^%^BLACK%^"
            "h%^GREEN%^u%^BLACK%^nger%^WHITE%^ pulls at you!%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^WHITE%^ "
            "on "+ETO->QCN+"'s sword glows a %^CYAN%^br%^RESET%^%^CYAN%^il%^BOLD%^%^CYAN%^li%^RESET%^%^CYAN%^ant "
            "%^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er as "+ETO->QS+" strikes "+targ->QCN+"!%^RESET%^",({ETO,targ}));

        mon = new(summon_mon);
        mon->move(EETO);
        ETO->add_protector(mon);
        ETO->add_follower(mon);
        mon->force_me("protect "+ETO->query_true_name()+"");
        mon->force_me("protect "+ETO->query_true_name()+"");
        mon->force_me("protect "+ETO->query_true_name()+"");

        COUNTER--;    
    }

    if(rand == 699) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The sword gl%^YELLOW%^o%^BLACK%^ws pure bla%^MAGENTA%^c%^BLACK%^k as a "
            "wa%^BLUE%^i%^BLACK%^l%^BLUE%^i%^BLACK%^ng t%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^rt%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^red s%^CYAN%^o%^BLACK%^ul courses "
            "down its p%^RED%^u%^BLACK%^l%^RED%^s%^BLACK%^ing blade, cleaving through "+targ->QCN+"'s %^RESET%^%^RED%^neck%^BOLD%^%^BLACK%^ and "
            "sending %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ic%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^ "
            "flowing through you as "+targ->QP+" body %^RESET%^%^ORANGE%^crumples%^BOLD%^%^BLACK%^ to the ground!%^RESET%^");

        tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s sword gl%^YELLOW%^o%^BLACK%^ws pure bla%^MAGENTA%^c%^BLACK%^k as "
            "wa%^BLUE%^i%^BLACK%^l%^BLUE%^i%^BLACK%^ng t%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^r"
            "t%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^red s%^CYAN%^o%^BLACK%^ul "
            "courses down its p%^RED%^u%^BLACK%^l%^RED%^s%^BLACK%^ing blade as "+ETO->QS+" "
            "cleaves through your neck. Your head hits the ground, "
            "pure %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ic%^BOLD%^%^GREEN%^"
            "e%^BOLD%^%^BLACK%^ keeping you alive long enough to see "
            "your %^BOLD%^%^RED%^decapitated%^BOLD%^%^BLACK%^ body %^RESET%^%^ORANGE%^"
            "crumple%^BOLD%^%^BLACK%^ to the floor!%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^BLACK%^Pure %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^i"
            "c%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^ fills the air as "+ETO->QCN+"'s black longsword glows pure "
            "black and wa%^BLUE%^i%^BLACK%^l%^BLUE%^i%^BLACK%^ng t%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^r"
            "t%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^red s%^CYAN%^o%^BLACK%^ul courses down its "
            "p%^RED%^u%^BLACK%^l%^RED%^s%^BLACK%^ing blade, %^BOLD%^%^RED%^decapitating%^BOLD%^%^BLACK%^ "+targ->QCN+" and "
            "leaving the body to %^RESET%^%^ORANGE%^crumple%^BOLD%^%^BLACK%^ lifeless to the "+
		"ground!%^RESET%^",({ETO,targ}));

        ETO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(1000,1000));
        ETO->set_property("magic",-1);
        targ->die();

        COUNTER--;    
    }
    return 0;
}

int global_special(mapping info) 
{
    int i, delay, count=1, which, num;
    object *living,*special,eto,targ,eeto;
    string which_special;

    living  = info["living"];
    special = info["special"];
    eto     = info["eto"];
    count   = info["count"];
    eeto    = info["eeto"];
    targ    = info["targ"];
    delay   = info["delay"];
    which   = info["which"];


    if(!pointerp(living)) { return 0; }
    if(!objectp(eto))	  { return 0; }
    if(!objectp(eeto))    { return 0; }

    switch(which)
    {
    case 1: which_special = "special_one_messages";   num = 5; break;
    case 2: which_special = "special_two_messages";   num = 6; break;
    case 3: which_special = "special_three_messages"; num = 5; break;
    }

    if(!FLAG)
    {
        for(i=0;i<sizeof(living);i++)
        {
            if(!objectp(living[i])) continue;
            if(living[i]->query_property("no paralyze"))
            {
                special += ({ living[i] });
            }
        }
        if(sizeof(special))
        {
            for(i=0;i<sizeof(special);i++)
            {
                if(!objectp(special[i])) continue;
                special[i]->remove_property("no paralyze");
            }
    	  }
    

    for(i=0;i<sizeof(living);i++)
    {
        if(!objectp(living[i])) continue;
        if(interactive(living[i]) && !living[i]->query_true_invis())
        {
            living[i]->force_me("cls");
        }
        living[i]->cease_all_attacks();
        living[i]->set_paralyzed(1000,"You can't move!");
    }

    // tells first message
    call_out(which_special,0,targ,1);

     info = ([ "living"  : living,
              "eto"     : eto,
              "count"   : 1,
              "special" : special,
              "delay"   : 5,
              "targ"    : targ,
              "eeto"    : eeto,
              "which"   : which,
            ]);

      FLAG = 1;
	call_out("global_special",15,info);
	return 0;
    }
    count++;
    info["count"] = count;
    	if(count < num) 
	{
		call_out("global_special",15,info);  
		call_out(which_special,0,targ,count);
	}
	if(count == num) 
	{
		call_out(which_special,0,targ,count);
		call_out("global_special",0,info);  
	}
    if(count > num)
    {
	  FLAG = 0;
        ETO->set_property("magic",1);
	  if(objectp(targ)) targ->do_damage("torso",roll_dice(1000,1000));
        ETO->set_property("magic",-1);
        if(objectp(targ) && !targ->query_ghost()) targ->die();

        for(i=0;i<sizeof(living);i++)
        {
            if(!objectp(living[i])) { continue; }
            living[i]->set_paralyzed(0);
        }
        for(i=0;i<sizeof(special);i++)
        {
            if(!objectp(special[i])) { continue; }
            special[i]->set_property("no paralyze", 1);
        }
    }

    // sends messages
    return 0;
}

// 5 messages
// Global Special Outdoors @ Night(Dorje) and for everyone else
void special_one_messages(object targ,int num) 
{
    if(!objectp(targ)) return;
    switch(num) {
    	case 1:
        	tell_object(ETO,"%^RESET%^%^MAGENTA%^Your sword "+
		"%^RED%^scr%^BOLD%^%^RED%^ee%^RESET%^%^RED%^ches%^MAGENTA%^ with "
            "the %^BOLD%^%^RED%^cackling%^RESET%^%^MAGENTA%^ of a "
            "%^BOLD%^%^BLACK%^m%^MAGENTA%^a%^BLACK%^dm%^MAGENTA%^a%^BLACK%^"+
		"n%^RESET%^%^MAGENTA%^ as %^BOLD%^%^BLACK%^wa%^BLUE%^i%^BLACK%^"+
		"l%^BLUE%^i%^BLACK%^ng s%^CYAN%^o%^BLACK%^uls%^RESET%^%^MAGENTA%^ course "
            "down its abyssal black blade. The very air around you %^RESET%^%^RED%^screams%^MAGENTA%^ "
            "with the %^BOLD%^%^RED%^pain%^RESET%^%^MAGENTA%^ of those trapped "+
		"in %^RESET%^%^ORANGE%^undeath%^MAGENTA%^, "
            "hurling those around you to the ground!%^RESET%^");

        	tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+"'s sword "+
		"%^RED%^scr%^BOLD%^%^RED%^ee%^RESET%^%^RED%^ches%^MAGENTA%^ with the "+
            "%^BOLD%^%^RED%^cackling%^RESET%^%^MAGENTA%^ of a %^BOLD%^%^BLACK%^"+
		"m%^MAGENTA%^a%^BLACK%^dm%^MAGENTA%^a%^BLACK%^n%^RESET%^%^MAGENTA%^ as "
            "%^BOLD%^%^BLACK%^wa%^BLUE%^i%^BLACK%^l%^BLUE%^i%^BLACK%^ng s%^CYAN%^"+
		"o%^BLACK%^uls%^RESET%^%^MAGENTA%^ course down its abyssal black blade. "
            "The very air around you %^RESET%^%^RED%^screams%^MAGENTA%^ with the "
            "%^BOLD%^%^RED%^pain%^RESET%^%^MAGENTA%^ of those trapped in %^RESET%^"+
		"%^ORANGE%^undeath%^MAGENTA%^, "
            "hurling you to the ground! %^RESET%^", ETO);
        
        	break;
    	case 2:
        	tell_room(EETO,"%^RESET%^%^MAGENTA%^The %^BOLD%^%^WHITE%^crystal %^RESET%^skull%^MAGENTA%^ of "
            ""+ETO->QCN+"'s sword glows a %^CYAN%^br%^BOLD%^%^CYAN%^il%^WHITE%^l%^CYAN%^ia%^RESET%^%^CYAN%^nt "
            "%^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^RESET%^%^MAGENTA%^ as "
            "the %^RED%^scr%^BOLD%^%^RED%^ee%^RESET%^%^RED%^ching%^MAGENTA%^ "
            "wails increase to a deafening level, slicing through the fabric of reality to expose a "
            "%^BOLD%^%^BLACK%^maelstrom%^RESET%^%^MAGENTA%^ that is the "
            "%^BOLD%^%^WHITE%^S%^BLACK%^u%^WHITE%^pr%^BLACK%^e%^WHITE%^m%^BLACK%^e %^WHITE%^"+
		"Thr%^BLACK%^one%^RESET%^%^MAGENTA%^!%^RESET%^", ETO);

		tell_object(ETO,"%^RESET%^%^MAGENTA%^The %^BOLD%^%^WHITE%^crystal %^RESET%^skull%^MAGENTA%^ of "
            "your sword glows a %^CYAN%^br%^BOLD%^%^CYAN%^il%^WHITE%^l%^CYAN%^ia%^RESET%^%^CYAN%^nt "
            "%^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^RESET%^%^MAGENTA%^ as "
            "the %^RED%^scr%^BOLD%^%^RED%^ee%^RESET%^%^RED%^ching%^MAGENTA%^ "
            "wails increase to a deafening level, slicing through the fabric of reality to expose a "
            "%^BOLD%^%^BLACK%^maelstrom%^RESET%^%^MAGENTA%^ that is the "
            "%^BOLD%^%^WHITE%^S%^BLACK%^u%^WHITE%^pr%^BLACK%^e%^WHITE%^m%^BLACK%^e %^WHITE%^"+
		"Thr%^BLACK%^one%^RESET%^%^MAGENTA%^!%^RESET%^");

        	tell_em("%^RESET%^%^MAGENTA%^A %^BOLD%^%^BLACK%^deafening%^RESET%^%^MAGENTA%^ "+
		"wail can be felt across the realm as the fabric of "
            "this %^RESET%^%^CYAN%^plane%^MAGENTA%^ is torn asunder to expose "+
		"the %^BOLD%^%^WHITE%^S%^BLACK%^u%^WHITE%^pr%^BLACK%^e%^WHITE%^m%^BLACK%^e "+
            "%^WHITE%^Thr%^BLACK%^one%^RESET%^%^MAGENTA%^ in all of its %^BOLD%^"+
		"%^WHITE%^magn%^CYAN%^ifi%^WHITE%^cent gl%^BLACK%^o%^WHITE%^ry%^RESET%^%^MAGENTA%^, "+
            "countless %^RESET%^%^ORANGE%^undead%^MAGENTA%^ flocking just on the other "+
		"side of the portal near you! %^RESET%^");

        	break;
    	case 3:
        	tell_object(ETO,"%^RESET%^%^MAGENTA%^Your body is engulfed by v%^BOLD%^"+
		"%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^RED%^flames%^MAGENTA%^, "+
            "which course down you and increase your %^BOLD%^%^WHITE%^m%^RED%^u%^WHITE%^r%^RED%^"+
		"d%^WHITE%^e%^RED%^r%^WHITE%^o%^RED%^u%^WHITE%^s "+
            "%^MAGENTA%^desires%^RESET%^%^MAGENTA%^ as you point the abyssal "+
		"black blade at "+targ->QCN+". An ear-shattering wail bursts "+
            "towards "+targ->QO+" %^RESET%^%^RED%^ri%^BOLD%^%^RED%^pp%^RESET%^"+
		"%^RED%^ing%^MAGENTA%^ through "+targ->QP+" body!%^RESET%^");

        	tell_object(targ,"%^RESET%^%^MAGENTA%^"+ETO->QCN+"'s body is engulfed by "+
            "v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^RED%^"+
		"flames%^MAGENTA%^ as "+ETO->QS+" points "+ETO->QP+" abyssal black blade at "+
		"you. An ear-shattering wail screams "+
            "towards you %^RESET%^%^RED%^ri%^BOLD%^%^RED%^pp%^RESET%^%^RED%^"+
		"ing%^MAGENTA%^ through your body! %^RESET%^");

        	tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+"'s body is engulfed by "+
            "v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t %^RED%^"+
		"flames%^MAGENTA%^ as they point "+ETO->QP+" abyssal black blade at "+
		targ->QCN+" An ear-shattering wail screaming towards "+targ->QO+", "+
            "%^RESET%^%^RED%^ri%^BOLD%^%^RED%^pp%^RESET%^%^RED%^ing%^MAGENTA%^ through "+
		targ->QP+" body! %^RESET%^", ({ETO, targ}));

        	break;
    	case 4:
        	tell_object(ETO,"%^RESET%^%^MAGENTA%^You feel a %^BOLD%^%^BLACK%^"+
		"dark%^RESET%^%^MAGENTA%^ and %^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^"+
		"i%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^st%^RESET%^"+
		"%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ power cackling with "+
		"%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^RED%^ic%^GREEN%^e%^MAGENTA%^ "+
            "as the power of your sword rips through "+targ->QCN+". Nothing happens "+
		"for what seems like a long while, "+
            "but "+targ->QS+" unexpectedly %^RED%^explodes%^MAGENTA%^ into thousands of tiny "
            "little %^BOLD%^%^WHITE%^pieces%^RESET%^%^MAGENTA%^.%^RESET%^!%^RESET%^");

       	tell_object(targ,"%^RESET%^%^MAGENTA%^You flinch, shielding your ears "+
		"as the %^BOLD%^%^CYAN%^vibrations%^RESET%^%^MAGENTA%^ "+
            "almost %^RED%^rip%^MAGENTA%^ you apart. A moment of relief fills you "+
		"as nothing happens until "+
            "the %^RESET%^burning %^BOLD%^%^RED%^energy%^RESET%^%^MAGENTA%^ begins to "+
		"build and burst "
            "forth from your body unexpectedly!%^RESET%^ ");

        	tell_room(EETO,"%^RESET%^%^MAGENTA%^You watch as the sound burst %^CYAN%^"+
		"slams%^MAGENTA%^ into "+targ->QCN+". "
            "You are left disappointed as nothing happens for a while, until "+
		"unexpectedly "+targ->QS+" %^RED%^explodes%^MAGENTA%^ "
            "into a thousand tiny little %^BOLD%^%^WHITE%^pieces%^RESET%^"+
		"%^MAGENTA%^.%^RESET%^ ", ({ETO, targ}));

        	break;
    case 5:
        	tell_room(EETO,"%^RESET%^%^MAGENTA%^The cracked reality slowly reforms and seals "+
		"its self off, leaving only the %^BOLD%^%^RED%^"+
            "cackling%^RESET%^%^MAGENTA%^ of a %^BOLD%^%^BLACK%^m%^MAGENTA%^"+
		"a%^BLACK%^dm%^MAGENTA%^a%^BLACK%^n%^RESET%^%^MAGENTA%^ behind! %^RESET%^");

       	tell_em("%^RESET%^%^MAGENTA%^The %^BOLD%^%^RED%^cackling%^RESET%^%^MAGENTA%^ of "+
            "a %^BOLD%^%^BLACK%^m%^MAGENTA%^a%^BLACK%^dm%^MAGENTA%^a%^BLACK%^n%^RESET%^"+
		"%^MAGENTA%^ can be heard through the exposed plane. "+
            "The end of your life seems evident.  The world reseals itself, "+
            "leaving you with the distance %^BOLD%^%^WHITE%^e%^RED%^c%^WHITE%^"+
		"ho%^RESET%^%^MAGENTA%^ of a %^BOLD%^%^RED%^cackling%^RESET%^%^MAGENTA%^ "+
            "%^BOLD%^%^BLACK%^m%^MAGENTA%^a%^BLACK%^dm%^MAGENTA%^a%^BLACK%^n"+
		"%^RESET%^%^MAGENTA%^!%^RESET%^");

        	break;
    }
    return;
}

// 6 messages
//Global Special Indoors (Dorje Only)
void special_two_messages(object targ,int num) {
    if(!objectp(targ)) return;
    switch(num) {
    case 1:
        tell_object(ETO,"%^RESET%^%^RED%^The sword in your hand %^BOLD%^%^RED%^"+
		"blazes%^RESET%^%^RED%^ to life with %^BOLD%^%^BLACK%^n%^GREEN%^e"+
		"%^BLACK%^cro%^GREEN%^m%^BLACK%^ant%^GREEN%^i%^BLACK%^c%^RESET%^%^RED%^, "
            "%^BOLD%^%^BLACK%^bla%^MAGENTA%^c%^BLACK%^k %^BOLD%^%^RED%^energy%^RESET%^%^RED%^. "
            "The floor shakes and buckles as %^ORANGE%^grotesque%^RED%^, undead "+
		"forms begin to crawl forth!%^RESET%^");

        tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+"'s sword %^BOLD%^%^RED%^blazes"+
		"%^RESET%^%^RED%^ to life with %^BOLD%^%^BOLD%^%^BLACK%^n%^GREEN%^e"+
		"%^BLACK%^cro%^GREEN%^m%^BLACK%^ant%^GREEN%^i%^BLACK%^c%^RESET%^%^RED%^, "
            "%^BOLD%^%^BLACK%^bla%^MAGENTA%^c%^BLACK%^k %^BOLD%^%^RED%^energy%^RESET%^%^RED%^. "
            "The floor shakes and buckles as %^RESET%^%^ORANGE%^grotesque%^RED%^ undead forms "+
		"begin to crawl forth!%^RESET%^",ETO);

        break;
    case 2:
        tell_room(EETO,"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^black %^RED%^energy "+
		"%^RESET%^%^RED%^erupts from the blade as thousands of voices begin to "+
		"speak all at once and with varying messages. One single voice, "+
		"its words conveyed coherently in a %^BOLD%^%^WHITE%^c%^CYAN%^oo"+
		"%^WHITE%^l%^RESET%^%^RED%^ tone, is heard above all others "+
		"with a coherent message, %^BOLD%^%^WHITE%^Some chains can't be "+
		"broken.%^RESET%^");

        tell_em("%^RESET%^%^RED%^The air s%^BOLD%^%^RED%^c%^RESET%^%^RED%^reams "+
		"with thousands of voices, all with varying messages. "
            "One voice can be heard above all the others, speaking in a "+
		"%^BOLD%^%^WHITE%^c%^CYAN%^oo%^WHITE%^l%^RESET%^%^RED%^ tone, "
            "repeating, %^BOLD%^%^WHITE%^Some chains can't be broken.%^RESET%^");

        break;
    case 3:
        tell_object(ETO,"%^RESET%^%^RED%^You sense the voices seem to be focusing on "+targ->QCN+", "
            "as you point the blade at "+targ->QO+", %^BOLD%^%^BLACK%^black%^RESET%^%^RED%^ energy flows "
            "into "+targ->QP+" %^BOLD%^%^BLACK%^m%^RESET%^i%^BOLD%^%^BLACK%^nd%^RESET%^%^RED%^!%^RESET%^");

        tell_object(targ,"%^RESET%^%^RED%^The voices are overwhelming and that repeating saying "+
		"is %^BOLD%^%^GREEN%^maddening%^RESET%^%^RED%^! "
            "What was that energy that "+ETO->QCN+"'s blade just shot into your "+
		"%^BOLD%^%^BLACK%^m%^RESET%^i%^BOLD%^%^BLACK%^nd%^RESET%^%^RED%^?  " 
            "You must get it %^BOLD%^%^RED%^out! Out!%^RESET%^");

        tell_room(EETO,"%^BOLD%^%^BLACK%^Black %^RED%^energy%^RESET%^%^RED%^ flows from "
            ""+ETO->QCN+"'s sword into the forehead of "+targ->QCN+"'s %^RESET%^skull!%^RESET%^",({ETO,targ}));

        break;
    case 4:
        tell_object(ETO,"%^RESET%^%^RED%^You watch in %^BOLD%^%^WHITE%^disbelief%^RESET%^%^RED%^ as "
		+targ->QCN+" beings to s%^BOLD%^%^RED%^c%^RESET%^%^RED%^ratch at "+targ->QP+
		" own %^RESET%^skull%^RESET%^%^RED%^. It's as if they "
            "will do anything to stop the %^BOLD%^%^BLACK%^voices%^RESET%^%^RED%^ "+
		"and %^BOLD%^%^RED%^rip%^RESET%^%^RED%^ "
            "out that %^BOLD%^%^BLACK%^black%^RESET%^%^RED%^ energy.%^RESET%^");

        tell_object(targ,"%^RESET%^%^RED%^You think of how the %^BOLD%^%^BLACK%^"+
		"voices%^RESET%^%^RED%^ must %^BOLD%^%^RED%^stop%^RESET%^%^RED%^ and "+
		"%^CYAN%^wonder%^RESET%^%^RED%^ if it isn't the energy of the blade! "
            "You will %^BOLD%^%^RED%^rip%^RESET%^%^RED%^ it from your %^RESET%^"+
		"%^ORANGE%^brain%^RESET%^%^RED%^ as you "
            "begin to pick at your own %^RESET%^skull!%^RESET%^");

        tell_room(EETO,"%^RESET%^%^RED%^You watch in %^BOLD%^%^WHITE%^disbelief"+
		"%^RESET%^%^RED%^ as "+targ->QCN+" begins to %^RESET%^%^RED%^s"+
		"%^BOLD%^%^RED%^c%^RESET%^%^RED%^ratch at "+targ->QP+" own "+
		"%^RESET%^skull!%^RESET%^",({ETO,targ}));

        break;
    case 5:
        tell_object(ETO,"%^RESET%^%^RED%^You can't believe what is happening "+
		"before your very eyes! "+targ->QCN+" has picked clear through "+
            targ->QP+"%^RESET%^ skull%^RESET%^%^RED%^ and is now pulling out "+
		"%^GREEN%^gobs%^RED%^ of "+targ->QP+" own %^ORANGE%^brain%^RED%^ " 
            "before crumbling to the floor as "+targ->QS+" %^BOLD%^%^RED%^"+
		"bleeds%^RESET%^%^RED%^ to d%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ath, "+
		targ->QCN+"'s %^ORANGE%^brains%^RED%^ effectively %^BOLD%^%^WHITE%^"+
		"mashed%^RESET%^%^RED%^ by "+targ->QP+" own %^BOLD%^%^BLACK%^hand!%^RESET%^");

        tell_object(targ,"%^RESET%^%^RED%^You continue to %^ORANGE%^pick%^RED%^, "+
		"completely ignoring the %^BOLD%^%^RED%^pain%^RESET%^%^RED%^ as you "+
		"%^BOLD%^%^RED%^t%^RESET%^%^RED%^e%^BOLD%^%^RED%^ar%^RESET%^%^RED%^, "+
            "s%^BOLD%^%^RED%^c%^RESET%^%^RED%^ratch, and %^GREEN%^crawl%^RED%^ "+
		"to find an escape until utter %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^ "
            "overwhelms you.%^RESET%^");

        	tell_room(EETO,"%^RESET%^%^RED%^You can't believe what is happening before "+
		"your very eyes! "+targ->QCN+" has picked clear "
            "through "+targ->QP+" %^RESET%^skull%^RESET%^%^RED%^ and is now "+
		"pulling out %^RESET%^%^GREEN%^gobs%^RED%^ of "+targ->QP+" own "
            "%^RESET%^%^ORANGE%^brain%^RED%^ before crumbling to the floor as "+
		"they bleed to %^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^ath%^RESET%^%^RED%^, "+
            targ->QCN+"'s %^RESET%^%^ORANGE%^brains%^RED%^ effectively %^BOLD%^"+
		"%^WHITE%^mashed%^RESET%^%^RED%^ by "+targ->QP+" %^RESET%^hand!%^RESET%^",({ETO,targ}));

        break;
    	case 6:
        	tell_room(EETO,"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^voices%^RESET%^%^RED%^ "+
		"suddenly stop and the %^RESET%^%^ORANGE%^undead%^RED%^ which never moved, "+
		"vanish before your very eyes! "
            "What the %^BOLD%^%^RED%^hell%^RESET%^%^RED%^ just happened?%^RESET%^");

        	tell_em("%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^voices%^RESET%^%^RED%^ "+
		"suddenly stop and a %^BOLD%^%^WHITE%^c%^CYAN%^oo%^WHITE%^l%^RESET%^%^RED%^ "
            "toned voice says, %^BOLD%^%^WHITE%^There is only One True Way%^RESET%^%^RED%^ "
            "You have the %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^"+
		"nk%^RESET%^%^ORANGE%^i%^BOLD%^BLACK%^ng%^RESET%^%^RED%^ feeling that "
            "something just went %^BOLD%^%^RED%^terribly%^RESET%^%^RED%^ wrong!%^RESET%^");

        break;
    }
    return;
}

// 5 messages
// Global Special Outdoors @ Day(Dorje Only)
void special_three_messages(object targ,int num) {
    if(!objectp(targ)) return;
    switch(num) {
    	case 1:
        	tell_object(ETO,"%^BOLD%^%^BLACK%^The sword in your hand "+
		"%^BOLD%^%^RED%^b%^RESET%^%^RED%^la%^BOLD%^%^RED%^zes%^BOLD%^%^BLACK%^ to life, "+
            "filling you with %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^RED%^ic%^BOLD%^"+
		"%^GREEN%^e%^BOLD%^%^BLACK%^ and %^BOLD%^%^WHITE%^m%^RED%^u%^WHITE%^rd%^RED%^"+
		"e%^WHITE%^r%^RED%^o%^WHITE%^us%^BLACK%^ intentions. "+
            "A %^RESET%^%^BLUE%^sh%^BOLD%^%^YELLOW%^o%^RESET%^%^BLUE%^ckw%^BOLD%^"+
		"%^YELLOW%^a%^RESET%^%^BLUE%^ve%^BOLD%^%^BLACK%^ of "+
            "%^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-red%^BOLD%^%^BLACK%^ "+
            "energy %^BOLD%^%^RED%^expl%^RESET%^%^RED%^o%^BOLD%^%^RED%^des%^BOLD%^%^BLACK%^ "+
            "from the %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r ruby%^BOLD%^%^BLACK%^ "+
            "and sends everyone in the room onto the ground as the wa%^BLUE%^i%^BLACK%^"+
		"l%^BLUE%^i%^BLACK%^ng %^WHITE%^scr%^RED%^e%^WHITE%^ams%^BLACK%^ of "+
            "to%^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^tu%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^"+
		"ed s%^CYAN%^o%^BLACK%^uls permeates the area. The ground shakes and wails "+
		"in agony as the star ruby blazes with a %^RESET%^%^MAGENTA%^v%^BOLD%^"+
		"%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^, "+
            "unh%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly %^RESET%^%^RED%^energy%^BOLD%^"+
		"%^BLACK%^!%^RESET%^");

        	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s abyssal black longsword "+
		"%^BOLD%^%^RED%^b%^RESET%^%^RED%^la%^BOLD%^%^RED%^zes%^BOLD%^%^BLACK%^ to "+
            "life with a %^RESET%^%^RED%^profane%^BOLD%^%^BLACK%^ and %^BOLD%^%^WHITE%^"+
		"v%^RED%^i%^WHITE%^l%^RED%^e%^BLACK%^ aura!  "+
            "A %^RESET%^%^BLUE%^sh%^BOLD%^%^YELLOW%^o%^RESET%^%^BLUE%^ckw%^BOLD%^"+
		"%^YELLOW%^a%^RESET%^%^BLUE%^ve%^BOLD%^%^BLACK%^ "
            "of %^RESET%^%^RED%^blo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-red%^BOLD%^ "+
		"%^BLACK%^energy %^BOLD%^%^RED%^expl%^RESET%^%^RED%^o%^BOLD%^%^RED%^des"+
		"%^BOLD%^%^BLACK%^ from the %^RESET%^%^RED%^st%^MAGENTA%^a%^RED%^r "+
		"ruby%^BOLD%^%^BLACK%^, sending you to the ground with wa%^BLUE%^i"+
		"%^BLACK%^l%^BLUE%^i%^BLACK%^ng %^WHITE%^scr%^RED%^e%^WHITE%^ams%^BLACK%^ "+
            "of to%^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^tu%^RESET%^%^BLUE%^r%^BOLD%^"+
		"%^BLACK%^ed s%^CYAN%^o%^BLACK%^uls filling your ears! "+
            "The ground shakes and wails in agony as the star ruby blazes with a "+
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^"+
		"%^MAGENTA%^t%^BOLD%^%^BLACK%^, u%^RESET%^%^%^MAGENTA%^n%^BOLD%^%^BLACK%^"+
		"h%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly e%^RED%^n%^BLACK%^er%^RED%^"+
		"g%^BLACK%^y!%^RESET%^",ETO);
        
        	break;
    	case 2:
        	tell_room(EETO,"%^BOLD%^%^BLACK%^The %^BLACK%^jaw%^RED%^l%^BLACK%^ess "+
		"sk%^RED%^u%^BLACK%^ll blazes to life with pure, "+
            "utter %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^RED%^"+
		"ic%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^ as "+
            "thousands of %^BOLD%^%^WHITE%^i%^BLACK%^n%^WHITE%^sa%^BLACK%^"+
		"n%^WHITE%^e%^BLACK%^ voices whisper around you "+
            "and %^RESET%^%^ORANGE%^un%^RESET%^%^RED%^d%^RESET%^%^ORANGE%^"+
		"ea%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ begin to "+
            "crawl up from the very earth! Pure black %^BOLD%^%^WHITE%^"+
		"t%^BLACK%^e%^BLACK%^n%^WHITE%^d%^BLACK%^r%^WHITE%^ils%^BLACK%^ "+
            "burst from "+ETO->QCN+"'s black longswords hilt, seizing the "+
		"%^BOLD%^%^YELLOW%^sun%^BOLD%^%^BLACK%^ above your head and "+
		"latching onto its surface. Darkness rolls into the world as "+
		"the %^BOLD%^%^YELLOW%^sun%^BOLD%^%^BLACK%^ is %^RESET%^"+
		"%^MAGENTA%^eclipsed%^BOLD%^%^BLACK%^ by a %^RESET%^%^RED%^"+
		"burning%^BOLD%^%^BLACK%^ %^BLACK%^jaw%^RED%^l%^BLACK%^ess "+
		"sk%^RED%^u%^BLACK%^ll with glowing %^BOLD%^%^WHITE%^si%^RESET%^"+
		"lv%^BOLD%^%^BLACK%^er eye s%^WHITE%^o%^BLACK%^ck%^WHITE%^e%^BLACK%^ts!%^RESET%^");

        	tell_em("%^BOLD%^%^BLACK%^Darkness pours into every crevice of the realm. "+
            "The ground shakes with the sound of to%^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^"+
		"tu%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^ed s%^CYAN%^o%^BLACK%^uls "+
            "as the %^BOLD%^%^YELLOW%^sun%^BOLD%^%^BLACK%^ is "+
            "%^RESET%^%^MAGENTA%^eclipsed%^BOLD%^%^BLACK%^ by a %^BLACK%^"+
		"jaw%^RED%^l%^BLACK%^ess sk%^RED%^u%^BLACK%^ll "+
            "with glowing %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^%^BLACK%^"+
		"er eye s%^WHITE%^o%^BLACK%^ck%^WHITE%^e%^BLACK%^ts!%^RESET%^");

        	break;
    	case 3:
        	tell_object(ETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s eyes glow "+
            "with a %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l"+
		"%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "+
            "energy as you point the abyssal black "+
            "blade at "+targ->QCN+" and u%^RESET%^%^MAGENTA%^n"+
		"%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly "+
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^"+
		"e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ sunlight %^BOLD%^%^RED%^"+
		"b%^RESET%^%^RED%^la%^BOLD%^%^RED%^zes%^BOLD%^%^BLACK%^ "+
            "forth from overhead, %^RESET%^%^RED%^t%^BOLD%^%^RED%^e%^RESET%^"+
		"%^RED%^aring%^BOLD%^%^BLACK%^ through "+targ->QP+" body!%^RESET%^");

        	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s eyes glow with a "+
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l"+
		"%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ energy "+
            "as "+ETO->QS+" points the abyssal black blade at you and "+
            "u%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^"+
		"o%^BOLD%^%^BLACK%^ly %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^"+
		"io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ "+
            "sunlight %^BOLD%^%^RED%^b%^RESET%^%^RED%^la%^BOLD%^%^RED%^zes"+
		"%^BOLD%^%^BLACK%^ forth from overhead, %^RESET%^%^RED%^t%^BOLD%^"+
		"%^RED%^e%^RESET%^%^RED%^aring%^BOLD%^%^BLACK%^ through your body!%^RESET%^");

        	tell_room(EETO,""+ETO->QCN+"'s eyes glow with a %^RESET%^%^MAGENTA%^"+
		"v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^e%^RESET%^%^MAGENTA%^t"+
		"%^BOLD%^%^BLACK%^ energy as "+ETO->QS+" points the abyssal black "+
		"blade at "+targ->QCN+" u%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^h"+
		"%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ly "+
            "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^"+
		"e%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^ sunlight "+
            "%^BOLD%^%^RED%^b%^RESET%^%^RED%^la%^BOLD%^%^RED%^zes%^BOLD%^"+
		"%^BLACK%^ forth from overhead, %^RESET%^%^RED%^t%^BOLD%^%^RED%^"+
		"e%^RESET%^%^RED%^aring%^BOLD%^%^BLACK%^ through "+targ->QP+
		" body!%^RESET%^",({ETO,targ}));

        	break;
    	case 4:
        	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel pure and utter %^RESET%^"+
		"%^GREEN%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^RED%^ic%^BOLD%^"+
		"%^GREEN%^e%^BOLD%^%^BLACK%^ flowing through you as the p"+
		"%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^wer"+
            "of %^BOLD%^%^WHITE%^Lord Cyric%^BOLD%^%^BLACK%^ rends "+targ->QCN+
            "'s s%^CYAN%^o%^BLACK%^ul%^BOLD%^%^BLACK%^ from "+targ->QP+" body and "+
            "pulls it into your abyssal black blade!%^RESET%^");

	      tell_object(targ,"%^BOLD%^%^BLACK%^H%^RESET%^%^ORANGE%^o"+
		"%^BOLD%^%^BLACK%^rr%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^r overcomes you as "+
            "the %^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^ sunlight collides with your body! "+
            "The presence of %^BOLD%^%^WHITE%^Lord Cyric%^BOLD%^%^BLACK%^ "+
            "can be felt in your very %^RESET%^core%^BOLD%^%^BLACK%^, "+
		"latching onto your s%^CYAN%^o%^BLACK%^ul and "+
            "yanking it from your body! The %^RESET%^%^RED%^screams, %^BOLD%^"+
		"%^RED%^pain%^BLACK%^ and %^RESET%^%^CYAN%^"+
            "helplessness%^BOLD%^%^BLACK%^ penetrate your "+
            "%^RESET%^%^RED%^e%^BOLD%^%^RED%^ss%^RESET%^%^RED%^ence%^BOLD%^%^BLACK%^ as "+
            "it is dragged into the abyssal black blade!%^RESET%^");

	      tell_room(EETO,"%^BOLD%^%^BLACK%^T%^RED%^e%^BLACK%^rr%^RED%^o%^BLACK%^r and "+
            "%^RESET%^%^CYAN%^curiosity%^BOLD%^%^BLACK%^ keep your "+
            "eyes glued to "+targ->QCN+" as "+targ->QP+" s%^CYAN%^o%^BLACK%^ul is "+
            "rendered from "+targ->QP+" mortal body and dragged "+
            "into the abyssal black blade, wa%^BLUE%^i%^BLACK%^l%^"+
		"BLUE%^i%^BLACK%^ng and %^RED%^screaming%^BLACK%^ "+
            "in %^RESET%^%^ORANGE%^agonizing "+
            "%^RED%^pain%^BOLD%^%^BLACK%^.%^RESET%^",({ETO,targ}));

        	break;
    case 5:
        	tell_room(EETO,"%^BOLD%^%^YELLOW%^L%^WHITE%^ig%^YELLOW%^ht%^BOLD%^"+
		"%^BLACK%^ begins to seep into the area again as the %^BLACK%^jaw"+
		"%^RED%^l%^BLACK%^ess sk%^RED%^u%^BOLD%^%^BLACK%^ll slowly "+
            "fades and the wa%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^l%^RESET%^"+
		"%^BLUE%^i%^BOLD%^%^BLACK%^ng stops, "+
            "leaving the world in an unnatural, %^BOLD%^%^GREEN%^eerie "+
		"%^BOLD%^%^BLACK%^s%^WHITE%^i%^BLACK%^"+
            "l%^WHITE%^e%^BLACK%^nc%^WHITE%^e%^BLACK%^.%^RESET%^");
                    
        	tell_em("%^BOLD%^%^YELLOW%^L%^WHITE%^ig%^YELLOW%^ht%^BOLD%^%^BLACK%^ "+
            "seeps into the world again and the wa%^RESET%^%^BLUE%^i%^BOLD%^"+
		"%^BLACK%^l%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^ng screams stop, "+
            "leaving the world in an unnatural, %^BOLD%^%^GREEN%^eerie %^BOLD%^"+
		"%^BLACK%^s%^WHITE%^i%^BLACK%^l%^WHITE%^e%^BLACK%^nc%^WHITE%^e%^BLACK%^ "+
            "as feelings of %^BOLD%^%^WHITE%^e%^RED%^n%^WHITE%^sla%^RED%^v%^WHITE%^"+
		"em%^RED%^e%^WHITE%^nt%^BLACK%^ "+
            "and %^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^"+
		"lpl%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^ssn%^BOLD%^%^BLACK%^e%^"+
		"RESET%^%^MAGENTA%^ss%^BOLD%^%^BLACK%^ "+
            "leave you to wonder what %^BOLD%^%^RED%^terrible"+
		"%^BOLD%^%^BLACK%^ event just transpired!%^RESET%^");

        	break;
    }
    return;
}

void tell_em(string str) {
    int i;
    object *users;
    users = children("/std/user.c");
    for(i=0;i<sizeof(users);i++) 
    {
        if(!objectp(users[i])) continue;
        if(!interactive(users[i])) continue;
        tell_object(users[i],str);
    }
    return;
}