// coded by Styx
//updated by Circe to NWP code to hopefully get it in game sooner.  12/21/03
// ported to new skills system, academics for lore and spellcraft for identification. Nienne, 08/09.
//_study.c ///
//Adding the ability to study a room / object in a room -
//basically to support some new stuff in my new area - Saide

#include <std.h>
#include <daemons.h>

int do_potion_study(object myplayer,object obj,string str);
int do_study(object myplayer,object obj,string str);
int do_id(object myplayer,object obj,string str);
int do_room_study(object myplayer, string which);

int cmd_study(string str)
{
   	string *ids, what;
   	object obj;
   	if(TP->query_bound())
	{
      	TP->send_paralyzed_message("info",TP);
      	return 1;
   	}
   	if(TP->query_blind())
	{
      	notify_fail("You can't study something if you can't see it.");
      	return 0;
   	}
   	if((object)TP->query_attackers() != ({}))
	{
		notify_fail("You're too busy to be studying that right now!\n");
        return 0;
   	}
  	if(!str)
	{
        notify_fail("study what?\n");
        return 0;
  	}
	if(sscanf(str, "room %s", what) == 1 || str == "room" && !present(str, TP))
	{
	 	if(!TP->query_time_delay("studying",5) && !avatarp(TP))
		{
            write("You need more time to reflect on your knowledge and "+
                  "research before trying that again.");
            return 1;
	  	}
		if(what)
		{
			if(member_array(what, keys(ETP->query_items())) == -1)
			{
				tell_object(TP, "There is no "+what+" in your general area.");
				return 1;
			}
			tell_object(TP, "You carefully begin studying the "+what+" here.");
			tell_room(ETP, TPQCN+" seems to be carefully studying the "+
                      what+" here.", TP);
			TP->set_time_delay("studying");
			do_room_study(TP, what);
			return 1;
		}
		tell_object(TP, "You carefully begin studying the area around you.");
		tell_room(ETP, TPQCN +" seems to be carefully studying the area.", TP);
		TP->set_time_delay("studying");
		do_room_study(TP, "room");
		return 1;
	}

  	if(!obj = present(str, TP))
	{
        notify_fail("You don't have that.\n");
        return 0;
  	}
  	if(!TP->query_time_delay("studying",5) && !avatarp(TP))
	{
        write("You need more time to reflect on your knowledge and "+
              "research before trying that again.");
        return 1;
  	}
  	ids = obj->query_id();
  	if(!TP->query_invis())
	{
        tell_room(ETP,TPQCN+" seems to be studying the "+str+" carefully.", TP);
  	}
  	TP->set_time_delay("studying");
    if((int)obj->is_brewed()) do_potion_study(TP,obj,str);
  	else {
        do_study(TP,obj,str);
        do_id(TP,obj,str);
    }
  	return 1;
}

int do_room_study(object myplayer, string which)
{
	int enchant, diff, level, x, baselevel;
  	string message0, message1;
  	string *ppl, who, *room_items, fail_msg, succ_msg, msg, *f_study = ({}), *s_study = ({});
	mixed rlore, info = 0, this_item;
	mapping ri_info, rs_info;

	object where;

	if(!objectp(myplayer)) return 0;
	where = environment(myplayer);
	if(!objectp(where)) return 0;
	rlore = where->query_property("room lore");

	if(!rlore || !mapp(rlore))
	{
		tell_object(myplayer, "%^BOLD%^%^YELLOW%^You "+
                    "study the "+which+" carefully, but can neither recall "+
                    "nor ascertain anything of remark.%^RESET%^");
		return 1;
	}

	diff = 20;
  	baselevel = (int)myplayer->query_skill("academics");
  	level = baselevel + roll_dice(1,20);
	ri_info = where->query_property("room lore");
	room_items = keys(ri_info);

	for(x = 0;x < sizeof(room_items);x++)
	{
		if(sizeof(room_items[x]))
		{
			if(member_array(which, room_items[x]) != -1)
			{
				info = ri_info[room_items[x]];
				this_item = room_items[x];
				break;
			}
		}
		if(room_items[x] == which)
		{
			info = ri_info[room_items[x]];
			this_item = room_items[x];
			break;
		}
		continue;
	}

	if(!info)
	{
		tell_object(myplayer, "%^BOLD%^%^YELLOW%^You "+
                    "study the "+which+" carefully, but can neither recall "+
                    "nor ascertain anything of remark.%^RESET%^");
		return 1;
	}
	if(sizeof(info) == 2)
	{
		diff = info[1];
		msg = info[0];
	}

	if(!sizeof(info))
	{
		msg = info;
	}

	succ_msg = "%^BOLD%^%^YELLOW%^You carefully study the "+
        which+" and are able to determine the following : %^RESET%^"+
        msg;

	fail_msg = "%^BOLD%^%^YELLOW%^You are unable to determine "+
        "anything of relevance about the "+which+"%^RESET%^.  Perhaps "+
        "you need to research more.";
	rs_info = where->query_property("successful study");
	if(mapp(rs_info))
	{
		if(rs_info[this_item])
		{
			s_study = rs_info[this_item];
		}
	}

	rs_info = where->query_property("failed study");
	if(mapp(rs_info))
	{
		if(rs_info[this_item])
		{
			f_study = rs_info[this_item];
		}
	}
	if(member_array(myplayer->query_name(), s_study) != -1)
	{
		tell_object(myplayer, succ_msg);
		return 1;
	}
	if(member_array(myplayer->query_name(), f_study) != -1)
	{
		tell_object(myplayer, "%^BOLD%^%^YELLOW%^You are still unable "+
                    "to determine anything of relevance about the "+which+"%^RESET%^.");
		return 1;
	}


	if(diff > level)
	{
		tell_object(myplayer, fail_msg);
		f_study += ({myplayer->query_name()});
		where->set_property("failed study", ([this_item : f_study]));
		return 1;
	}
	tell_object(myplayer, succ_msg);
	s_study += ({myplayer->query_name()});
	where->set_property("successful study", ([this_item : s_study]));
	return 1;


}


int do_potion_study(object myplayer, object obj, string str) {
// this uses add- and query-identified for tracking if the potion has been recognized.
// it then uses add- and query-studied for tracking the extra information of a botch/non-botch (5DC higher).
// as both are healing-skill based, there was no need for separate rolls for ID'd name and lore. N, 12/11.

    int diff, level, baselevel, failed_level;
    string message0, message1, message2, message3, who;
    mapping failed;

    baselevel = (int)myplayer->query_skill("healing");
    level = baselevel + roll_dice(1,20);
    diff = obj->query_property("lore difficulty");
    if(!diff || !intp(diff)) diff = 1;
    who = myplayer->query_name();

    message0 = "You aren't knowledgeable enough in alchemy to discern the purpose of this brewed item.";
    message1 = "%^BOLD%^%^CYAN%^"+obj->query_lore();
    message2 = message1+"\n%^BOLD%^%^WHITE%^You're fairly sure this particular mix is potent enough to work properly.";
    message3 = message1+"\n%^BOLD%^%^WHITE%^You're fairly sure there is something botched about this particular mix.";

    if(avatarp(myplayer)){
        if((int)obj->is_reversed()) write(message3);
        else write(message2);
        return 1;
    }
    if(member_array(who,obj->query_identified()) != -1){ // success on lore/ID
        if(member_array(who,obj->query_studied()) != -1){ // success on botched/not as well
            if((int)obj->is_reversed()) write(message3);
            else write(message2);
        }
        else write(message1);
        return 1;
    }
    failed = obj->query("identified_failed");
    if(!failed) failed = ([]);
    if(member_array(who,keys(failed)) != -1) {
        failed_level = failed[who];
        if(failed_level >= baselevel){
            write("You haven't improved your knowledge of alchemy since last you examined this specific vial.");
            return 1;
        }
    }

    if(level < diff){
        failed[who] = baselevel;
        write(message0);
    }
    else {
        if(level < (diff+5)) {
            obj->add_studied(who);
            obj->add_identified(who);
            if((int)obj->is_reversed()) write(message3);
            else write(message2);
            return 1;
        }
        obj->add_identified(who);
        map_delete(failed,who);
        write(message1);
    }
    obj->delete("identified_failed");
    obj->set("identified_failed",failed);
    return 1;
}

int do_study(object myplayer,object obj,string str) {
    int enchant, diff, level, baselevel, test, droll, adjlvl, failed_level;
    string message0, message1;
    string *ppl, who;

    baselevel = (int)myplayer->query_skill("academics");
    level = baselevel + roll_dice(1,20);
    enchant = absolute_value(obj->query_property("enchantment"));
    diff = obj->query_property("lore difficulty");
    if(!diff || !intp(diff)) { diff = 1; }
    who = myplayer->query_name();
    message0 = "You haven't seen enough of the world yet to know "
        "anything about this item.";
    message1 = "%^BOLD%^%^CYAN%^After carefully studying the "+str+", you "
        "recall having heard or discovered the following:%^RESET%^\n"
        +obj->query_lore();

    if(!obj->query_lore()){
        switch(random(6)){
        case 0:  write("%^ORANGE%^You don't seem to recall any lore "+
                       "about this item.");
            break;
        case 1:  write("%^CYAN%^You don't find any unusual markings "+
                       "on this item.");
            break;
        case 2:  write("%^GREEN%^This item seems rather ordinary, "+
                       "and you cannot recall anything about it.");
            break;
        case 3:  write("%^RED%^There seem to be no legends or "+
                       "stories surrounding this particular item.");
            break;
        case 4:  write("%^BOLD%^%^BLUE%^You have never run across "+
                       "anything in your studies to tell you anything "+
                       "about this item.");
            break;
        case 5:  write("%^MAGENTA%^This item seems rather mundane "+
                       "in nature, and you cannot recall hearing any "+
                       "stories about it at all.");
            break;
        }
        return 1;
    }
//so wizzes and avs can always find out lore.
    if(avatarp(myplayer)){
        write(message1);
        return 1;
    }
    if(objectp(obj) && pointerp(obj->query_studied()) && member_array(who,obj->query_studied()) != -1){
        write(message1);
        return 1;
    }
    if(obj->is_studied_failed(who)){
        failed_level = obj->is_studied_failed(who);
        if(failed_level >= baselevel){
            write("You still cannot seem to find any stories related "+
                  "to this object.  You might need to research it more.");
            return 1;
        }
    }
    if(!diff){
        diff = enchant*5;
        if(level < diff) {
            obj->add_studied_failed(who,baselevel);
            write(message0);
        }
        else {
            obj->add_studied(who);
            write(message1);
        }
        return 1;
    }
    if(level < diff){
        obj->add_studied_failed(who,baselevel);
        write(message0);
    }
    else {
        obj->add_studied(who);
        write(message1);
    }
    return 1;
}

int do_id(object myplayer,object obj,string str) {
    int enchant, diff, level, baselevel, failed_level;
    string message0, message1, message2, charges;
    string *ppl, who, myaura;
    mapping failed;

    baselevel = myplayer->query_skill("spellcraft");
    level = baselevel + roll_dice(1,20);
    enchant = absolute_value(obj->query_property("enchantment"));
    diff = obj->query_property("id difficulty");
    who = myplayer->query_name();
    message0 = "You can't detect any magical attributes of this item.";
    message1 = "%^BOLD%^%^GREEN%^You carefully inspect the "+str+", taking "
        "note of any hidden properties.%^RESET%^";
    message2 = "%^BOLD%^%^GREEN%^You carefully inspect the "+str+", but "
        "can't discern an enchantment circle upon it.%^RESET%^";

//so wizzes and avs can always find out lore.
// revoking this section as it's preventing identification of non-enchant items with other bonuses. N, 12/13.
/*  if(!obj->query_obvious_short() && !enchant) {
    write(message2);
    return 1;
    } */
    if(avatarp(myplayer)){
        obj->add_identified(who);
        write(message1);
        if((string)obj->query("effect") == "spell_effect") {
            myaura = (string)obj->query("spell");
            charges = (string)obj->query("uses");
            write("%^BOLD%^%^YELLOW%^You can detect an enchantment of "+myaura+" with "+charges+
                  " charges of " +obj->query("level")+" caster level.%^RESET%^");
        }
        return 1;
    }
    if((string)obj->query("effect") == "spell_effect") {
        if((int)obj->query("level") < (int)myplayer->query_skill("spellcraft")) {
            myaura = (string)obj->query("spell");
            charges = (string)obj->query("uses");
            write("%^BOLD%^%^YELLOW%^You can detect an enchantment of "+myaura+" with "+charges+
                  " charges of "+obj->query("level")+" caster level.%^RESET%^");
        }
    }
    if(member_array(who,obj->query_identified()) != -1){
        write("You are already aware of the magical properties of this item.");
        return 1;
    }
    failed = obj->query("identified_failed");
    if(!failed) failed = ([]);
    if(member_array(who,keys(failed)) != -1) {
        failed_level = failed[who];
        if(failed_level >= baselevel){
            write("You have already studied this item, but cannot detect any "
                  "further hidden attributes until you expand your knowledge of spellcraft.");
            return 1;
        }
    }
    if(!diff){
        diff = (enchant+1)*5;
        if(level < diff) {
            failed[who] = baselevel;
            diff = diff-5;
            if(level < diff) write(message0);
            else {
                switch(enchant) {
                case 1: myaura = "a %^CYAN%^faint blue"; break;
                case 2: myaura = "a %^CYAN%^blue"; break;
                case 3: myaura = "a %^CYAN%^bright blue"; break;
                case 4: myaura = "a %^CYAN%^very bright blue"; break;
                case 5: myaura = "an %^CYAN%^extremely bright blue"; break;
                default: myaura = "a %^CYAN%^nearly blinding blue"; break;
                }
                write("%^BOLD%^%^GREEN%^You're fairly sure you can detect "+
                      myaura+" %^GREEN%^glow around the "+str+".%^RESET%^");
            }
        }
        else {
            obj->add_identified(who);
            map_delete(failed,who);
            write(message1);
        }
        obj->delete("identified_failed");
        obj->set("identified_failed",failed);
        return 1;
    }
    if(level < diff){
        failed[who] = baselevel;
        diff = diff-5;
        if(level < diff) write(message0);
        else {
            switch(enchant) {
            case 1: myaura = "a %^CYAN%^faint blue"; break;
            case 2: myaura = "a %^CYAN%^blue"; break;
            case 3: myaura = "a %^CYAN%^bright blue"; break;
            case 4: myaura = "a %^CYAN%^very bright blue"; break;
            case 5: myaura = "an %^CYAN%^extremely bright blue"; break;
            default: myaura = "a %^CYAN%^nearly blinding blue"; break;
            }
            write("%^BOLD%^%^GREEN%^You're fairly sure you can detect "+
                  myaura+" %^GREEN%^glow around the "+str+".%^RESET%^");
        }
    }
    else {
        obj->add_identified(who);
        map_delete(failed,who);
        write(message1);
    }
    obj->delete("identified_failed");
    obj->set("identified_failed",failed);
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

study - learn some lore

%^CYAN%^SYNTAX%^RESET%^

study [%^ORANGE%^%^ULINE%^ITEM%^RESET%^|room]

%^CYAN%^DESCRIPTION%^RESET%^

Study will try to discern lore and magical properties about an %^ORANGE%^%^ULINE%^ITEM%^RESET%^. Lore check depends on your academics skill, while magical enchanments depend on your knowledge of spellcraft.

If you fail to study an item you may try againonce you have gained higher rank in appropriate skills. There are also spells that replace this command with gaining knowledge through devination or other means.

Some rooms have lore set as well and you may try to %^ORANGE%^<study room>%^RESET%^ to gain lore and knowledge about it.

%^CYAN%^SEE ALSO%^RESET%^

skills, academics, spellcraft, repair, look
"
        );
}
