//      /std/monster.c
//      from the Nightmare mudlib
//      inheritable code for npc's
//      created by Descartes of Borg september 1992
//  * added set_nogo() and made move_around() query the list of rooms from it to not enter for easier control of wandering mobs.   Note: moving mobs need a set_speed(x) in create - examples I've found all had set_moving(1) also but I don't believe that's actually needed
//  *Styx*  8/6/03
// Ares added ability to open doors in move_around, *Styx* added to do_walk for pathfinder
// Added a to hit bonus in conjunction with Thaco change, to make mobs hit the same AC as
// they always have -Ares 8/22/06

#define PATHFINDER "/daemon/pathfinder_d.c"  // added by Lujke, September 2005

#include <std.h>
#include <move.h>
#include <objects.h>
#include <daemons.h>
#include <new_exp_table.h>

inherit "/std/weaponless_users.c";

int set_heart_beat(int flag); // For slowing down monster's heart beats to sync (sorta) with combat. - g
object tmp;
static int heart_beat_on;
int level,round,numround;
string charmed_by;
int hit_dice, hit_dice_bonus, stage;
static int speed;
static int moving;
string *nogolist;	// * for the addition to move_around()
mapping emotes;
mapping spells;
mapping thief_skill;
string stabbed;
int steal;
string body_type;private static mixed __Die;
int charmed;
mapping charmed_int, offend_int, norm_int;
static int is_npc;
static object master_wiz;
int no_catch_tell;
// going to give them a 1 heart_beat delay between being able to recieve messages, to try to
// prevent two mobs talking and spamming the mud into submission -Ares
static int already_listened;
static int init_pause; // delay of 1 heart_beat after calls to ::init() to stop recursion error spam
string *funcs;
int func_chance;
int max_level;
string * path;       //  These variables added by Lujke, September 2005
string destination;  //  to support the code for mobs to be able to walk to named
int is_walking;      //  destinations
int will_open;	     // addition by Ares for checks in move_around & pathfinder
int will_avoid_traps; 
int BONUS_ADDED;     // global flag to make sure the to hit bonus doesn't get added more than
                     // once.  -Ares 
static string *monster_feats; // added so monsters can have feats, use set_monster_feats(string *feats)

int test_heart();
void set_spell_chance(int x);
void set_body_type(string x);
void set_spells(string *arr);
string return_chat();
string return_achat();
void set_exp(int x);
void set_level(int x);
//
int query_level();
string getParsableName();
void move_around();
void set_nogo(string *list);  	// * these added for use in move_around
string *query_nogo();
void set_emotes(int x, string *arr, int att);
int do_exp(int dice,int bonus);
object find_steal_target();
int query_thief_skill(string skill);
void steal_fun();
void set_interaction_normal(string *action,string *func_name);
void set_interaction_charmed(string *action,string *func_name);
void set_interaction_offended(string *action,string *func_name);
int check_action(string str);
int npc_mon(int npc, object wizard);
int query_is_npc();
int force_NPC(string command);
void disable_catch_tell(int def_tell);
void __TEST_INIT();
void start_walking(string dest);  // These functions added by Lujke, September 2005
void stop_walking();                // to support the code for monsters
void reach_destination();         // to be able to find their way to a 
void do_walk();                   // specified destination
int query_walking();            //
void will_open_doors(int num); // Will make wandering mobs open unlocked doors in their way -Ares 09/18/05
void avoid_traps(int num); // Will make wandering mobs avoid walking into exits that are trapped -Ares 09/18/05
void do_kit_stuff();
void die(object ob);

void set_new_exp(int level,string perc); // new lib level exp function, see function definition for more details -Ares

int is_monster() {return 1;}

string query_sphere() {return "monster sphere";}

void set_languages(string *stuff) {}

int useMonsterFlag;



void create() {
   ::create();
   enable_commands();
   seteuid(getuid(this_object()));
   init_limb_data();
   init_stats();
   init_skills(0);
   init_living();
   set_heart_beat(heart_beat_on = 1);
   speed = 0;
   set_gender("neuter");
   set_gender("male");
   set_alignment(5);
   enable_commands();
   is_npc = 0;
   no_catch_tell = 0;
   emotes = ([]);
   spells = ([]);
   thief_skill = ([]);
   norm_int = ([]);
   charmed_int = ([]);
   offend_int = ([]);
   stage = 60;
   path = ({});
   monster_feats=({});
}

void reset() 
{
    	if(!objectp(TO)) { return; }
	catch("/daemon/quests"->isMon(TO));
    	if(!objectp(ETO)) { return; }
   	::reset();   
}

void set_stabbed_func(mixed val) {
   if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return 0;
   if(functionp(val)) {
      set_property("fstabbed",1);
      stabbed = val[1];
   } else
      stabbed = val;
}

void set_monster_feats(string *feats)
{
    string *valid_feats;
    int i;
    
    if(!pointerp(feats)) { return; }
    
    valid_feats = get_dir("/cmds/feats/");

    for(i=0;i<sizeof(valid_feats);i++)
    {
        valid_feats[i] = replace_string(valid_feats[i],"_","",1);
        valid_feats[i] = replace_string(valid_feats[i],"_"," ");
        valid_feats[i] = replace_string(valid_feats[i],".c","");
    }

    for(i=0;i<sizeof(feats);i++)
    {
        if(member_array(feats[i],valid_feats) == -1) { continue; }
        monster_feats += ({ feats[i] });
    }
}

string *query_monster_feats() { return monster_feats; }

void init() 
{
    mixed tmp;
    int i;
    string *temp=({});

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    ::init();

    if(!objectp(TO))                    { return; }
    if(!objectp(TP))                    { return; }
    if(TP->query_true_invis())          { return; }
    if(TP->query_ghost())               { return; }
    if(TP->query_property("draggee"))   { return; }


    if(!heart_beat_on || !query_heart_beat(TO))
    {
        set_heart_beat(heart_beat_on = 1);
    }

    if(TP->is_player()) 
    {
        if(tmp = query("aggressive")) 
        {
            if(intp(tmp) && tmp > (int)TP->query_stats("charisma")) 
            {
                if(TP->query_invis())
                {
                    if(!query_property("invis attack")) { return; }
                }
                kill_ob(this_player(), 0);
                call_out("kill_msg",1,this_player());         
            } 
            else
            {
                if(!init_pause)
                {
                    if(stringp(tmp)) call_other(this_object(), tmp);
                    init_pause = 1;
                }
            }
        }
    }
   
    if(norm_int) 
    {
        temp += keys(norm_int);        
        if(charmed_int) { temp+=keys(charmed_int); }
        if(offend_int)  { temp+=keys(offend_int); }      
        temp = distinct_array(temp);      
        for(i=0;i<sizeof(temp);i++) 
        {
            add_action("check_action",temp[i],1);
        }
    }
    
// killing this - it's already on creature heartbeat and it's causing bugs mudwide.
/*    if(!TO->query_property("new_exp_set"))
    {
        TO->set_new_exp((int)TO->query_highest_level(),"normal");
    }*/
}

void kill_msg(object tp) 
{
   tell_object(tp,"%^RED%^%^BOLD%^"+capitalize(this_object()->query_name())+" attacks you!%^RESET%^");
}

object make_corpse()
{
     object tmp;
    tmp = new(OB_CORPSE);
     tmp->set_name(capitalize(query_name()));
    tmp->copy_body(this_object());
   return tmp;
}

void set_name(string str) {
   set_living_name(str);
   ::set_name(str);
   if(query_level() < 1) set_level(1);
}

void do_kit_stuff()
{
    int num,level,hp,max_hp,diff,avg,i;
    string type;
    object ob;

    if(!objectp(TO)) { return; }

    num = (int)TO->query_property("add kits");
    if(!present("kitxyz",TO) && num == -1) { return; }
    if(!num) { return; }

    level = (int)TO->query_level();
    switch(level)
    {
    case 0..11:
        type = "/d/common/obj/potion/healing.c";
        avg  = 11;
        break;
    case 12..24:
        type = "/d/common/obj/potion/extra_heal.c";
        avg  = 20;
        break;
    case 25..34:
        type = "/d/common/obj/potion/advanced_heal.c";
        avg  = 30;
        break;
    default:
        type = "/d/common/obj/potion/legendary_heal.c";
        avg  = 50;
        break;
    }
    if(!present("kitxyz",TO) && num != -1)
    {
        ob = new(type);
        ob->set_uses(num);
        ob->move(TO);
        TO->remove_property("add kits");
        TO->set_property("add kits",-1);
    }

    if(!present("kitxyz",TO)) { return; }

    hp     = (int)TO->query_hp();
    max_hp = (int)TO->query_max_hp();
    
    if(hp >= max_hp) { return; }
    
    diff = max_hp - hp;
    diff = diff / avg;
    if(diff > 4) { diff = 4; }
    if(diff)
    {
        for(i=0;i<diff;i++)
        {
            force_me("drink kitxyz");
        }
    }
    return;
}

void heart_beat() 
{
   string lang, pre;
   object ob3,ob2;
   int num,i;

    ::heart_beat();

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    if(already_listened)    { already_listened = 0; }
    if(init_pause)          { init_pause = 0; }

    if(!TO->query_property("new_exp_set"))
    {
        TO->set_new_exp((int)TO->query_highest_level(),"normal");
        TO->set_property("new_exp_set",1);
    }

   player_age +=2;
   ok_to_heal ++;
   if(player_age > ok_to_heal) do_healing(calculate_healing());
   else calculate_healing();
   iterate_combat();
   if(ok_to_attack()) {
      continue_attack();
   }
   if(!stage) {
      if(1) {
// moved objectp check above creation of ob2 so it won't get stranded in memory by the objectp check kicking out of the function (without zapping the ob2 created). *Styx* 3/17/03
         if(!objectp(TO)) return;
         ob2 = new("/std/Object");

         if(this_object()->query_poisoning()) {
            ob2->set_name("Poison");
            do_damage("torso",query_poisoning());
            message("environment","You are getting weaker from Poison!",TO);
            if(objectp(ob3=queryPoisoner())) {
               add_attacker(ob3);
            } else {
               add_attacker(ob2);
            }
            continue_attack();
            remove_attacker(ob2);
            remove_attacker(ob3);
         }
         ob2->remove();
      }
      stage = 60;
   }
   stage--;
   if(!objectp(TO)) return;
   if(speed && moving >= speed) { if(!is_walking) { move_around(); } }
   else moving++;
   if(!query_current_attacker()) pre = "";
   else pre = "attack ";
   if(!emotes) emotes = ([]);
   if(emotes[pre+"chance"] > random(100))
      if(this_object())
         message("environment", emotes[pre+"msg"][random(sizeof(emotes[pre+"msg"]))],
                 environment(this_object()), ({ this_object()}) );
// Checking to see how much damage this does... I really need HB to keep going
   if(!test_heart()) set_heart_beat(heart_beat_on = 0);
   if(steal && random(100) < 2) steal_fun();
   if(!sizeof(query_attackers()) && query("protecting"))
      set("protecting",0);
  // Added by Lujke September 2005, to support code for mobs to walk to a set destination //
  if(is_walking!= 0){
    do_walk();
  }
  do_kit_stuff();
}

void die(object ob) {
   object money_ob;
   object *contents;
   int i, tmp_size;
   string *currs;

   if(functionp(__Die)) {
      if(!((int)((*__Die)(ob)))) return;
   } else
      if(stringp(__Die))
      message("other_action",__Die,environment(this_object()),({this_object()}));
   else message("other_action", "%^RED%^"+query_cap_name()+
                " drops dead before you.%^RESET%^", environment(this_object()),
                ({ this_object()}));
   if(ETO->query_property("arena")) {
      destall(TO);
      return;
   }
    tmp = make_corpse();
   tmp->move(environment(this_object()));
   tmp_size=sizeof(currs=query_currencies());
   if(tmp_size && has_value()) {
      money_ob = new("/std/obj/coins");
      for(i=0; i<tmp_size; i++) {
         money_ob->add_money(currs[i], query_money(currs[i]));
         add_money(currs[i], -query_money(currs[i]));
      }
      money_ob->move(tmp);
   }
   contents = all_inventory(this_object());
   for(i=0;i<sizeof(contents);i++) {
      if(contents[i]->query_property("monsterweapon"))
         continue;
      else
         if(!contents[i]->query_short()) continue;
      else contents[i]->move(tmp);
   }
   contents = all_inventory(this_object());
   for(i=0;i<sizeof(contents);i++) contents[i]->remove();
   if(TO->query_property("riding"))
      if(TO->query_owner() && objectp(TO->query_owner()))
         (TO->query_owner())->remove_pet(TO);

	if(TO->query_property("death effects")) 
	{
		"/daemon/death_effects_d"->get_death_effect(TO);
	}
   remove();
}

int query_npc() {return 1;}

varargs void move_player(mixed dest, string msg) {
   object prev,*inv;
   string here,going,temp1,temp2,temp3;
   int i,bzbd;

   if(!objectp(this_object())) return;
  if (!objectp(prev = ETO)) return;
   here = file_name(prev);
   if(stringp(dest)) {
      if(sscanf(dest,"/%s",temp1)!=1) {
         sscanf(here,"/%s",temp1);
         going = "";
         while(sscanf(temp1,"%s/%s",temp2,temp3)==2) {
            going = going + "/"+temp2;
            temp1 = temp3;
         }
         temp1 = dest;
         if(file_size(going+"/"+temp1+".c") != -1) {
            dest = going+"/"+temp1;
         }
      }
   }
   if(move(dest) == MOVE_OK) {
      if (query_property("posed"))
           remove_property("posed");
      if(!id("summoned monster")) {
         if(!hiddenp(this_object()) && !(avatarp(TO) && query_invis())) {
            inv = all_inventory(prev);
            for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
               if(!living(inv[i]) || inv[i] == this_object()) continue;
               if((query_hidden() || query_magic_hidden())  && !inv[i]->detecting_invis()) {
                  continue;
               }
               if(!msg || msg == "") message("mmout", query_mmout(inv[i]),inv[i]);
               else {
                  if(TO->query_in_vehicle() && objectp(TO->query_in_vehicle())) {
                     message("mout",query_cap_name()+" rides "+TO->query_in_vehicle()->query_cap_name()+" "+msg+".",inv[i]);
                  } else message("mout", query_mout(msg,inv[i]), inv[i]);
               }
            }
          if (!objectp(TO) || !objectp(ETO)) return;
           // If something's fucked up, don't even bother trying.
            inv = all_inventory(environment(this_object()));
            for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
               if(!living(inv[i])) continue;
               if(inv[i] == this_object()) continue;

               if((query_hidden() || query_magic_hidden())  && !inv[i]->detecting_invis()) {
                  continue;
               }
               if(!msg || msg == "") message("mmin",query_mmin(inv[i]),inv[i]);
               else {
                  if(TO->query_in_vehicle() && objectp(TO->query_in_vehicle())) {
                     message("min", query_cap_name()+" enters riding "+TO->query_in_vehicle()->query_cap_name()+".", inv[i]);
                  } else message("min",query_min(inv[i]),inv[i]);
               }
            }
         }
      }
      if(query_followers())
         move_followers(prev);
   }
}

/* Call_out taken out of move_around by Hanse 1/4/93 */
// *changes to respect files in restricted exit list (nogo) by Styx 8/2003
// Added in checks for locked and unlocked doors, and the ability to open 
// unlocked ones -Ares 09/18/05
void move_around() {
   string *exits,door;
   string exit, exitfile;   // *added local exitfile variable for use below

   if(!TO) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(ETO)
        exits = (string*)ETO->query_obvious_exits();
   else exits = 0;
   if(sizeof(exits)) {
      exit = exits[random(sizeof(exits))];
      exitfile = (string)ETO->query_exit(exit);        // *need this to check below
      if(door=ETO->query_door(exit))
      {
          if(member_array(exitfile,query_nogo()) != -1) { return; }
          if(ETO->query_locked(door)) { return; }
          if(!ETO->query_open(door) && !will_open) { return; }
          if(will_open) { command("open "+door); }
      }
      if(will_avoid_traps && ETO->query_trap_status(exit,exit)) { return; }
      if(member_array(exitfile,query_nogo()) == -1) {  // *if it's not in the array, go ahead
//      (ETO->query_exit(exit))->init();  // *was-but we already have filename now, so this saves querying the exit again
         if(objectp(find_object_or_load(exitfile)))
         {
             exitfile->init();                
             if(exit != "temple") { command(exit); }
         }
      }
   }
   moving=0;
}

void set_nogo(string *list) { nogolist = list; }  // *added support for move_around

string *query_nogo() {
   if(!pointerp(nogolist)) nogolist = ({ });    // *make sure we have an array
   return nogolist;
}

void set_moving(int i) {moving = i;}
int query_moving() { return moving; }

void set_speed(int i) {speed = i;}

int query_speed(){ return speed;}

string query_title() {return query_short();}

void __SHINIT() {
   enable_commands();
   seteuid(getuid(this_object()));
   init_limb_data();
   init_stats();
   init_skills(0);
   init_living();
   set_heart_beat(heart_beat_on = 1);
   speed = 0;
   set_gender("neuter");
}

int roll_dice(int num, int sides) {
   int x,cnt;

   cnt = 0;
   for(x=0;x<num;x++) {
      cnt += random(sides)+1;
   }
   return cnt;
}

void set_hd(int dice, int bonus) {      // sets the hit dice of a monster
   hit_dice = dice;                 // 2, 0 would be 2d8 + 0
   hit_dice_bonus = bonus;
   set_max_hp(roll_dice(dice,8));
   set_hp(query_max_hp());
   //do_exp(dice,bonus);
   if(!query_classes() || query_classes() == ({})) set_class("fighter");
   set_level(dice);
}

void do_exp(int dice,int bonus) 
{
   if(bonus > 0) dice++;
   if(bonus < 0) dice--;
   if(dice < 1) dice = 1;
   if(dice > 13) {
      dice -= 13;
      set_exp((2000+(dice*200)));
      return;
   }
   switch(dice) {
   case 1:  set_exp(15);  return;
   case 2:  set_exp(35);  return;
   case 3:  set_exp(65);  return;
   case 4:  set_exp(120); return;
   case 5:  set_exp(120); return;
   case 6:  set_exp(175); return;
   case 7:  set_exp(270); return;
   case 8:  set_exp(390); return;
   case 9:  set_exp(500); return;
   case 10: set_exp(850);return;
   case 11: set_exp(960);return;
   case 12: set_exp(1150);return;
   case 13: set_exp(1250);return;
   default: set_exp(15);   return;
   }
}

int query_hd_bonus() {return hit_dice_bonus;}

int query_hd() {return hit_dice;}

void set_level(int x) {
   level = x;
   set_hp(query_max_hp());
   set_stats("constitution", x*3/2);
   set_stats("strength", x*3/2);
   set_stats("intelligence", x*3/2);
   set_stats("wisdom", x*3/2);
   set_stats("dexterity", x*3/2);
   set_stats("charisma", x*3/2);
   set_max_mp((query_stats("intelligence")/2)*x);
   set_mp(query_max_mp());
//    set_exp( (int)ADVANCE_D->get_exp(x,"fighter"));
   set_mlevel(TO->query_class(),TO->query_level());
   // Added to give the mobs a bonus to push them back up to the THACO they had before the change
   // -Ares 8/22/06
   // And we don't need it since the thaco has been changed back
   //if(!BONUS_ADDED) { BONUS_ADDED = 1; if(x > 20) { TO->add_attack_bonus((x - 20)/2); } }
}

int query_level() {
    level = query_highest_level();
   if(level == 0) {
      return TO->query_hd();
   }
   return level;
}

// Added by Valodin, June 28, 1993
// Sets the body type to a certain race using the race daemon
void set_race(string  str){
	::set_race(str);
	if(!body_type) set_body_type(str);
}


void set_body_type(string str) 
{
   mapping monster_bod;
   int mag, max_mag;
   string *mon_limbs;
   int i, max;

   if(!str || !RACE_D->is_monster_race(str))
      str = "human";
   init_limb_data();

   monster_bod = (mapping)RACE_D->monster_body(str, query_max_hp());

   for(i = 0, max = sizeof(mon_limbs = keys(monster_bod)); i < max; i++)
   {
      add_limb(mon_limbs[i], monster_bod[mon_limbs[i]]["limb_ref"],
               monster_bod[mon_limbs[i]]["max_dam"], 0, 0);
   }

   set_wielding_limbs((string *)RACE_D->query_monster_wielding_limbs(str));
   TO->set_fingers((int)RACE_D->query_monster_fingers(str));
   
   // from weaponless_monsters.c
   TO->set_attack_limbs((string *)RACE_D->query_monster_wielding_limbs(str));
   TO->set_attacks_num(sizeof(TO->query_attack_limbs()));

   body_type = str;

}

string query_body_type() {
   if (body_type) return body_type;
   else return query_race();
}

void set_func_chance(int x) {
   if(!funcs) funcs = ({});
   func_chance = x;
}

void set_funcs(string *arr) {
   if(!funcs || funcs == ({})) funcs = arr;
}

int query_func_chance() {
   if(funcs)
      return func_chance;
   return 0;
}

string *query_funcs() {
   if(funcs)
      return funcs;
   return 0;
}

string get_random_func() {
   if(!funcs) return 0;
   if(sizeof(funcs) < 2)
      return funcs[0];
   return funcs[random(sizeof(funcs))];
}

void set_spell_chance(int x) {
   if(!spells) spells = ([]);
   spells["chance"] = x;
}

void set_spells(string *arr) {
   if(!spells) spells = ([]);
   spells["commands"] = arr;
}

int query_spell_chance() {
   if(spells)
      return spells["chance"];
   return 0;
}

string *query_spells() {
   if(spells) return spells["commands"];
   return 0;
}

string get_random_spell() {
   if(!spells) return 0;
   if(sizeof(spells["commands"]) <2) return spells["commands"][0];
   return spells["commands"][random(sizeof(spells["commands"]))];
}
 
// These two functions remain for backwards Nightmare 1.* and 2.* compat

void set_chats(int x, string *arr) {set_emotes(x, arr, 0);}

void set_achats(int x, string *arr) {set_emotes(x, arr, 1);}

void set_emotes(int x, string *arr, int att) {
   emotes[(att ? "attack chance" : "chance")] = x;
   emotes[(att ? "attack msg" : "msg")] = arr;
}

void set_alignment(int x) {player_data["general"]["alignment"] = x;}

int test_heart() {
   object env;
   object *inv;
   int i;

   if(!objectp(this_object())) return 0;
   if(!objectp(environment(this_object()))) return 0;
   if((query_mp() < query_max_mp()) || (query_hp() < query_max_hp()) || query_poisoning()) return 1;
   if(!(env = environment(this_object()))) return 1;
   if(query_current_attacker() || speed) return 1;
   i = sizeof(inv = all_inventory(env));
   while(i--)
      if(interactive(inv[i]) || inv[i]->query("aggressive")) return 1;
   return 0;
}

int query_heart_status() {return heart_beat_on;}

void receive_message(string cl, string msg) 
{
    if(!already_listened)
    {
        if( is_npc == 1 )
        {
            if(!objectp(master_wiz))
            {
                is_npc = 0;
                return;
            }
            if(interactive(master_wiz))
            {
                tell_object(master_wiz,"%%% "+ msg +"\n");
            }
        }
        if(!no_catch_tell)
        {
            this_object()->catch_tell(msg);
        }
        if(cl == "say" && TP != TO) 
        {
            TO->catch_say(msg);
        }
    }
}

void set(string str, mixed val) {
   ::set(str, val);
}

void set_die(mixed val) {
   if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
   __Die = val;
}

mixed query_die() {return __Die;}

//thief monsters
void set_thief_skill(string skill, int score) {
   thief_skill[skill] = score;
}

int query_thief_skill(string skill) {return thief_skill[skill];}

void toggle_steal() {
   if(!steal) {
      add_search_path("/cmds/mortal");
      steal = 1;
      return;
   }
   if(steal == 1)
      steal = 0;
}

int is_stealer() {
   if(steal) return 1;
   return 0;
}

void steal_fun() {
   string what;
   object who;
   object *items;
   int coin;
   int inven;

   who = "/daemon/find_target_d"->find_player_target(TO);
   if(who == TO) {
      return 1;
   }
   coin = random(2);
   if(coin == 0) what = "money";
   else what = "item";
   if(what == "money")
      TO->force_me("pp "+who->query_name());
   else {
      items = all_inventory(who);
      if(items == ({}))
         return 1;
      inven = random(sizeof(items));
      TO->force_me("steal "+items[inven]->query_name()+" from "+who->query_name());
   }
}
// this function flags the monster as charmed or uncharmed or offended
// thus the values to be used are:
//         charmed = 1
//         normal = 0
//         offended = -1

void set_charmed(int num) {
   set_property("charmed",num);
   return;
}

void set_interaction_normal(string *action,string *func_name) {
   int i;

   if((!action) || (!func_name) || (sizeof(action)!= sizeof(func_name)))
      return;
   if(!norm_int) norm_int = ([]);
   i = sizeof(action);
   while(i--)
      norm_int[action[i]]=func_name[i];
}

void set_interaction_charmed(string *action,string *func_name) {
   int i;

   if((!action) || (!func_name) || (sizeof(action)!= sizeof(func_name)))
      return;
   if(!charmed_int) charmed_int = ([]);
   i = sizeof(action);
   while(i--)
      charmed_int[action[i]]=func_name[i];
}

void set_interaction_offended(string *action,string *func_name) {
   int i;

   if((!action) || (!func_name) || (sizeof(action)!= sizeof(func_name)))
      return;
   if(!offend_int) offend_int = ([]);
   i = sizeof(action);
   while(i--)
      offend_int[action[i]]=func_name[i];
}

int check_action(string str) {
   int charm,num;
   string verb;
   function temp;

   temp = 0;
   verb = query_verb();
   charm = (int)query_property("charmed");
   if(!norm_int[verb]) norm_int[verb] = "function_default";
   switch(charm) {
   case 1: if(charmed_int[verb])
         temp = (:call_other, TO,  charmed_int[verb] :);
      else
         temp = (:call_other, TO, norm_int[verb] :);
      break;
   case 0: temp = (:call_other, TO, norm_int[verb] :);
      break;
   case -1: if(!offend_int[verb])
         temp = (:call_other, TO, norm_int[verb] :);
      else
         temp = (:call_other, TO, offend_int[verb] :);
      break;
   }
   if(temp == 0) return 0;
   num = (*temp)(str);
   return num;
}

int npc_mon(int npc, object wizard) {
// added check for valid object to stop bugs *Styx*  3/17/03
   if(!objectp(wizard))
      return 0;
   if(!avatarp(wizard))
      return 0;
   if(is_npc == 1 && npc == 1)
      return 0;
   if(npc != 1 && npc != 0)
      return 0;
   if(!interactive(wizard))
       return 0;
   master_wiz = wizard;
   is_npc = npc;
   return 1;
}

int query_is_npc() { return is_npc; }

int force_NPC(string command) {  return this_object()->force_me(command); }

void disable_catch_tell(int def_tell) {   no_catch_tell = def_tell; }

int do_stab_func() {
   if(!objectp(TO)) return 0;
   if(!stringp(stabbed)) return 0;
   if(!query_property("fstabbed")) {
      message("combat",stabbed,environment(TO));
      return 0;
   }
   return call_other(TO,stabbed);
}

int has_stab_func() {
   if(!objectp(TO)) return 0;
   if(!stringp(stabbed)) return 0;
   if(!query_property("fstabbed")) {
      return 0;
    }
     return 1;
}

void set_max_level(int lvl) {   max_level = lvl; }

int query_max_level() {   return max_level; }

string query_short(){
   string descr = ::query_short();
    if (query_unconscious() || query_bound() || query_tripped() || query_gagged()) {
        descr = descr + " (";
        if (query_unconscious()) {
            descr = descr + "unconscious ";
        }
        if (query_bound()) {
            descr = descr + "bound ";
        }
        if (query_tripped()) {
            descr = descr + "prone ";
        }
        if (query_gagged()) {
            descr = descr+ "gagged ";
        }
        if (query_blindfolded()) {
            descr = descr + "blindfolded";
        }
        descr = descr + ")";
    }
    if(query_property("posed"))
        descr = descr + " ["+query_property("posed")+"]";
    return descr;
}

string query_vis_cap_name(){ 
    return query_cap_name();
}
// More quick functions to make monsters act as players of a sort, I guess...
// Garrett 02/02/02
string getNameAsSeen(object ob) { 
    return TO->query_name(); 
}
string getParsableName() { 
    return capitalize(TO->query_name()); 
}

void saveMonster(string path){
    if (!stringp(path)) {
        path = base_name(TO);
    }
    seteuid(getuid());
	"/daemon/yuck_d"->save_inventory(this_object(),path);
    save_me(path);
}

void restoreMonster(string path){
    seteuid(getuid());
    if (!stringp(path)) {
        path = base_name(TO);
    }

    if (!file_exists(path+".o")) {
        return;
    }
    restore_me(path);
    "/daemon/yuck_d"->load_inventory(this_object(),path);
}

void clearMonster(string path){
    string *oldfiles;
    int x;

    seteuid(getuid());

    if (!stringp(path)) {
        path = base_name(TO);
    }

    if (!file_exists(path+".o")) {
        return;
    }
    rm(path+".o");

    oldfiles = get_dir(path+"/");
    for (x=0;x<sizeof(oldfiles);x++) {
        rm(path+"/"+oldfiles[x]);
    }
}

//////////Next few functions added by Lujke September 2005, to support
///////// Mobs being able to find their way to specified destinations
// *Styx* 2/1/06 adding to use will_open_doors() setting, borrowed from Ares' addition to move_around

void do_walk(){
// This function moves the mob along the path towards the destination, if
// the is_walking variable has been set to 1

  string * finalpath, step, allsteps, door;
  object startroom, endroom, * rooms, scanner;
  int i;

  rooms = ({});
  finalpath = ({});

  if (!objectp(TO)||!objectp(ETO)){
    stop_walking();
    return;
  }

  if (is_walking == 0){
    return;
  }
  if(file_name(ETO) == destination) {  
// changed this from a waystation check that wasn't working Lujke September 16 2005
    reach_destination();              
    stop_walking();
    return;
  }

  startroom = ETO; // already done an objectp check on ETO
 
// If there is no path already set, find a the nearest waystation
// if the mob is not already at one. Otherwise, find the next
// waystation nearest the destination.

  if (path==({})){
    endroom = PATHFINDER->find_waystation(startroom, destination, 5);

    if (!objectp(endroom)){
      force_me("say endroom not valid. Stopping walking.");
      is_walking = 0;
      destination = "";
      return;
    }
    path = PATHFINDER->findpath(startroom,endroom,path,finalpath,rooms,5,1);

    if (path == ({})){
      stop_walking();
      return;
    } 
  }
// Once the path is found, or if one was already set, take the next step along it
  step = path[0];
// additions by *Styx* 2/1/06
  if(will_open) {
     if(door=ETO->query_door(path[0])) {
 	if(ETO->query_locked(door)) { 
	   stop_walking();
	   return; 
      	}
        if(!ETO->query_open(door))
	   command("open "+door);
     }
  }
  force_me(step);

// After the mob has taken the next step along the path, check whether it
// has reached its destination and then trigger the appropriate
// function if it has.  Then remove the step that has just been completed
// from the remaining path array.

  if (objectp(ETO)){
    if (file_name(ETO)==destination){
      // This will mean that the mob has reached the destination
      stop_walking();
      reach_destination();
    }
  }else{
    force_me("say my environment is invalid");
  }

  // after walking, remove that step from the 'path' array
  if (sizeof(path)>1){
    path = path[1..(sizeof(path)-1)];
  }else{
    path = ({});
  }
}

int * query_walking(){
  //allows other object to check whether the monster is on the move
  return is_walking;
}

void reach_destination(){
  // a virtual function, triggered when the mob gets to where it is going
}

void start_walking(string dest){
  // This function starts the mob walking towards its destination. The
  // string dest should be the filename of the destination room, without
  // the ".c" - i.e, exactly what is returned by file_name(<destination>)
  // *NOTE* The destination MUST have been set up with waypoints, using the
  // destinations_d.c daemon.

  destination = dest;
  is_walking = 1;
}

void stop_walking(){
  // this function stops the mob from walking.
  is_walking = 0;
  destination = "";
}

void will_open_doors(int num)
{
    will_open = num;
    return;
}

void avoid_traps(int num)
{
    will_avoid_traps = num;
    return;
}

int set_heart_beat(int flag) {
   return efun::set_heart_beat((__COMBAT_SPEED__)*flag);
   return efun::set_heart_beat(flag);
    //// if monsters start fucking up the world over, take the first line out.
}


void set_new_exp(int level, string perc)
{
    int exp,div;

    if(!intp(level) || level < 1)
    {
        level = (int)TO->query_level();
    }

    if(!stringp(perc) || perc == "" || perc == " ")
    {
        perc = "normal";
    }

    perc = lower_case(perc);

    switch(perc)
    {
    case "very low":
        div = 40; // 60% lower than normal ( 100 - 60 = 40)
        break;        
    case "low":
        div = 70; // 30% lower than normal ( 100 - 30 = 70)
        break;
    case "normal":
    case "high":
        div = 130; // 30% higher than normal ( 100 + 30 = 130)
        break;
    case "very high":
        div = 160; // 60% higher than normal ( 100 + 60 = 160)
        break;
    case "boss":
        div = 300; // 200% higher than normal ( 100 + 200 = 300)
        break;
    default:
        perc = "normal";
        break;
    }

    if(level == 0) { level = 1; }
    if(level > 43) { level = 43; exp = 20000000; }    // The exp table only goes to level 45, so this can't be set any higher without causing an error
    else
    {
        exp = EXP_NEEDED[level + 1] - EXP_NEEDED[level]; // 1 level worth of exp
    }

    exp = (exp / (level * 9));

    if(perc != "normal")
    {
        exp = (exp * div) / 100;
    }

    TO->set_property("new_exp_set",1);
    TO->set_property("new_exp_amount",exp);
    TO->set_property("new_exp_level",level);
    TO->set_property("new_exp_perc",perc);
    TO->set_exp(exp);
    return;
}



void set_use_monster_flag(int f)
{
   useMonsterFlag = f;
}




// Stuff from weaponless_monsters.c

int is_weaponless()
{
    return ::is_weaponless();
}


void set_hit_funcs(mapping stuff)
{
    ::set_hit_funcs(stuff);
}


void set_damage(int num, int dice)
{
    ::set_damage(num,dice);
}


void set_attacks_num(int number)
{
    ::set_attacks_num(number);
}


int query_attacks_num()
{
    return ::query_attacks_num();
}


void set_nat_weapon_type(string type)
{
    ::set_nat_weapon_type(type);
}


string query_nat_weapon_type() 
{
    return ::query_nat_weapon_type();
}


void set_attack_limbs(string *limbs)
{
    ::set_attack_limbs(limbs);
}


string *query_attack_limbs()
{
    return ::query_attack_limbs();
}


int query_num_natural_attacks()
{
    return ::query_num_natural_attacks();
}


int query_unarmed_damage()
{
    return ::query_unarmed_damage();
}


int get_hand_damage(string limb1, int damage, object attacked) 
{
    return ::get_hand_damage(limb1,damage,attacked);
}
