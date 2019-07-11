//

#include <std.h>

#define OFFENSIVE (["thief":6, "ranger":5, "paladin":5, "antipaladin":5,"cavalier":5,"fighter":5,"cleric":3, "mage":1,"bard":4, "psion":1]) 

#define DEFENSIVE (["thief":3, "ranger":5, "paladin":5, "antipaladin":5,"cavalier":5,"fighter":5,"cleric":6, "mage":1,"bard":4,"psion":1])

inherit DAEMON;

string translateDefenseToString(int i);
string translateOffenseToString(int i);
void printCurrentStance();
int calculate_total_offensive(object who);
int calculate_total_defensive(object who);
int help();

void printCurrentStance(){
    
    write("%^BOLD%^%^GREEN%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    write("%^BOLD%^%^GREEN%^Your offensive stance is currently "+translateOffenseToString((int)TP->query_offensive_bonus())+".");
    write("%^BOLD%^%^GREEN%^Your defensive stance is currently "+translateDefenseToString((int)TP->query_defensive_bonus())+".");
    write("%^BOLD%^%^GREEN%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");        
}

int cmd_stance(string str){
    int def, off;
    return 1;

    if(TP->query("new_class_type")) { return 0; }

    if (!str) {
        printCurrentStance();
        return 1;
    }
// added checks for disabled and online time *Styx* 12/5/03, last change 11/19/03
   if (TP->query_bound() || TP->query_unconscious()) {
      write("You're completely vulnerable in your current situation.");
      TP->set_defensive_bonus(0);
      TP->set_offensive_bonus(0);
      return 1;
   }
   if(TP->query_tripped())
      return notify_fail("You aren't able to change your stance in your condition.\n");

// if < 2 days online time, they haven't paid their dues to get this benefit *Styx*
   if(TP->query_age() < 172800) {
      write("You haven't paid your dues to earn this benefit yet.  Try again another day.");
      TP->set_defensive_bonus(0);
      TP->set_offensive_bonus(0);
      return 1;
    }
        
    off = TP->query_offensive_bonus();
    def= TP->query_defensive_bonus();
    if(TP->query_property("raged")) {
        write("The rage of war dictates your battle stance!");
        return 1;
    }
    if (str == "aggressive") {
        if (off >= calculate_total_offensive(TP)) {
            write("%^BOLD%^You can not become more aggressive");
        } else {
            TP->slide_offensive_scale(1);
            tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" assumes a more aggressive stance.",TP);
            if(!TP->query_invis()){
               write("%^BOLD%^%^GREEN%^You assume a more aggressive stance.");
            }
        }
        printCurrentStance();
        return 1;
    } else if (str == "defensive"){
        if (def >= calculate_total_defensive(TP)) {
            write("%^BOLD%^You can not become more defensive");
        } else {
            TP->slide_offensive_scale(-1);
            tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" assumes a more defensive stance.",TP);
            if(!TP->query_invis()){
               write("%^BOLD%^%^GREEN%^You assume a more defensive stance.");
            }
        }
        printCurrentStance();
        return 1;

    } else if (str = "neutral"){
        tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" returns to a normal stance.",TP);
        if(!TP->query_invis()){
           write("%^BOLD%^%^GREEN%^You return to a normal stance.");
        }
        TP->set_defensive_bonus(0);
        TP->set_offensive_bonus(0);
        printCurrentStance();
        return 1;
    } else {
        return help();
    }

}

int calculate_total_offensive(object who){
    string *classes;
    int i;
    int total;

    if(!objectp(who)) who = TP;
    classes = who->query_classes();
    for (i=0;i< sizeof(classes);i++) {
        total += OFFENSIVE[classes[i]];
    }

    if(TP->is_class("warlord")) // temporary
        total += (int)"/std/class/warlord.c"->max_stance_offensive();

    return total/sizeof(classes);
}

int calculate_total_defensive(object who){
    string *classes;
    int i;
    int total;
    if(!objectp(who)) who = TP;
    classes = who->query_classes();
    for (i=0;i< sizeof(classes);i++) {
        total += DEFENSIVE[classes[i]];
    }
    
    if(TP->is_class("warlord")) // temporary
        total += (int)"/std/class/warlord.c"->max_stance_defensive();

    return total/sizeof(classes);
}

string translateOffenseToString(int i){
    switch (i) {
    case -6:
        return "docile";
    case -5:
        return "meek";
    case -4:
        return "timid";
    case -3:
        return "passive";
    case -2:
        return "wary";
    case -1:
        return "careful";
    case 0:
        return "neutral";
    case 1:
        return "offensive";
    case 2:
        return "forceful";
    case 3:
        return "aggressive";
    case 4:
        return "wild";
    case 5:
        return "berserk";
    case 6:
        return "savage";
    default:
        return "error";
    }

}

string translateDefenseToString(int i){

    switch (i) {
    case -6:
        return "reckless";
    case -5:
        return "defenseless";
    case -4:
        return "exposed";
    case -3:
        return "vulnerable";
    case -2:
        return "open";
    case -1:
        return "careless";
    case 0:
        return "neutral";
    case 1:
        return "grounded";
    case 2:
        return "protective";
    case 3:
        return "defensive";
    case 4:
        return "guarded";
    case 5:
        return "impervious";
    case 6:
        return "impenetrable";
    default:
        return "error";
    }
}

int help() {
    write(
@OLI
    This command is currently disabled.  Please refer instead to the
relevant feats.

    See also: help expertise, help powerattack
OLI
    );
}

/*int help(){
    string *k;
    int i;
    write(
@OLI
    stance || stance aggressive || stance defensive || stance neutral

    Stance allows you to set your overall approach to a fight. This 
allows you to specify your level of aggression or defensiveness. As 
you become more aggressive you become less defensive and vise versa.
Please note that if you are out of combat for more than 2 minutes the
stance will reset itself.

In game terms this means that your AC goes up as you become defensive 
and your thaco goes down, and vise versa. This will also effect your 
damage, specifically by altering the damage done through proficiencies.
OLI
    );
    write("The following are the max offensive and defensive settings for a class");
    write(arrange_string("class",13)+arrange_string("offensive",11)+arrange_string("defensive",11));
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    k = keys(OFFENSIVE);

    for (i=0;i< sizeof(k);i++) {
        write(arrange_string(k[i],13)+arrange_string(OFFENSIVE[k[i]],11)+arrange_string(DEFENSIVE[k[i]],11));
    }
    return 1;
}*/