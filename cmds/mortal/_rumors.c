#include <std.h>
inherit DAEMON;

#define SEARCHES ([ "/d/shadow/room/city" : "Shadow", "/d/shadow/juran/city" : "Juran",\
"/d/shadow/room/muuldaan/rooms/" : "Muul'daan", "/d/darkwood/tabor/room/" : "Tabor", "/d/azha/town/" : "Azha",\
"/d/darkwood/camps/rooms/town/" : "Synoria", "/d/tharis/newtharis/rooms" : "Tharis", "/d/antioch/antioch2/rooms" : "Antioch",\
"/d/dagger/tonovi/town" : "Tonovi", "/d/dagger/Torm/city" : "Torm", "/d/dagger/kinaro/" : "Kinaro",\
"/d/attaya/newseneca/rooms" : "Seneca", "/d/deku/town" : "Verbobone", "/d/undead/rooms/town" : "Graez",\
"/d/darkwood/room/rhapsody" : "the Rhapsody inn", "/d/dagger/exchange/rooms/" : "the Exchange",\
"/d/player_houses/innaeli/rooms/bsb1" : "the Bloody Scourge inn", ])
#define AREAMAP ([ 3 : ({ "Offestry and surrounds" }), 9 : ({ "the Echoes mountains", "the goblin stronghold", "the Meadowlands" }), 11 : ({ "Kildare", "Yntala forest", "Feyren Farm" }), 13 : ({ "Muileann" }), 16 : ({ "the dark trail", "the Barrow Downs" }), 18 : ({ "Berionessa Peak", "Laerad plains", "Deku forest" }), 22 : ({ "northern Drow underdark", "the Moonstone vale", "Derro tunnels" }), 25 : ({ "the Dark Forest", "Kinaro underdark", "Aramanth island" }), 28 : ({ "Tonerra", "the Coral Sea", "Graez island" }), 40 : ({ "Lava tubes", "the Marsh of Fear", "The island of Eldebaro"}), 45 : ({"Within The Ancient Marsh of Dallyh"})])
//I have turned up the azha theather to be a level 16 group area - from a player point of view it seems like lvl 14 or 11 is a bit low for the area - the monsters have a lot of health 
//and some of them stab a lot - Saide - April 2016
#define GROUPMAP ([ 9 : ({ "the orc encampment" }), 16 : ({ "Azha theater" }), 16 : ({ "Archemond's ruins" }), 18 : ({ "Tharis forest", "Deku keep" }), 22 : ({ "Lothwaite barrows", "Laerad caverns", "the Altar of Fire" }), 25 : ({ "the Ogre caverns", "Fire plains", "Sanctuary" }), 28 : ({ "Island of Dreams" }), 32 : ({ "Argentrock island" }), 35 : ({ "Attaya jungle", "Demongate", "the Crystalline Tower" }), 38 : ({ "Arkhon's lair" }), 50 : ({ "Klauth's lair" }) ])
#define QUESTMAP ([ 3 : ({ "Sirith's task, near the graveyard east of Offestry.", "the artifact of Kilgore Keep, in the keep west of Offestry",/* "the Elven Journal, in the forest east of Offestry", "recover the Golden Crown, in the forest east of Offestry"*/ }), \
9 : ({ "Rosinden's mission, in the Ekibi Cavern, north of the meadowlands." }), \
11 : ({ "the Stolen Pipe, from a dwarf or kobold in the Echoes Mountains", "Piaf's dilemma, at Piaf's farm, along the streams north of Tabor" }), \
13 : ({ "the Riddle quest, hidden by the streams north of Tabor", "Muileann's restless soul, in the town of Muileann, east of the crossroads north of Shadow" }), \
14 : ({ "the mystery of the Desert Sun Theater, in the Azha Theater, on the east edge of town" }), \
16 : ({ "Sionne's final rest, in the ruins on a side path towards Lothwaite", "Isolate the Githyanki, in the southern Shadow Desert" }), \
22 : ({ "the Drow temple, in the northern Dagger underdark", "the spirit of Lothwaite, in the barrows beneath Lothwaite", "Friend of the Stones, in the Derro caves in northern Dagger" }), \
25 : ({ "sealing the gate to the Hells, in the caverns of the Ogrish hordes, in northern Dagger", "Hansoth's demise, in the Laerad Caverns" }), \
28 : ({ "Lucid Dreams, on the island of Ovadexel" }), \
38 : ({ "Shar's failed deed, in the lava tubes beneath Tonerra" }) ])

string run_area_query(object myplayer);

int cmd_rumors()
{
  int i, j, mylevel, mymin, mymax, *mapkeys;
  string *places, theloc, placelist, searchlist, *myareas;
  object *peo, *rp_flags;

// start query for player locations
  places = ({});
  peo = ({});
  peo = users();
  if(member_array(TP,peo) != -1) peo -= ({ TP }); // remove self
  
  if(!sizeof(peo)) 
  {
    tell_object(TP,"%^BOLD%^%^CYAN%^There are no rumors of adventurers passing through any nearby cities.%^RESET%^\n");
  }
  else {
    searchlist = keys(SEARCHES);
    if(!sizeof(searchlist)) {
      tell_object(TP,"%^BOLD%^%^CYAN%^There has been an error generating the player list - please notify a wiz.%^RESET%^\n");
      return 1;
    }
    for(i = 0; i < sizeof(peo); i++) {
      if(!objectp(environment(peo[i]))) continue;
      if(peo[i]->query_true_invis()) continue;
      theloc = base_name(environment(peo[i]));
      for(j = 0;j < sizeof(searchlist); j++) {
        if((strsrch(theloc,searchlist[j]) != -1) && (member_array(SEARCHES[searchlist[j]],places) == -1))
          places += ({ SEARCHES[searchlist[j]] });
      }
    }

    if(!sizeof(places))
      tell_object(TP,"%^BOLD%^%^CYAN%^There are no rumors of adventurers passing through any nearby cities.%^RESET%^\n");
    else {
      placelist = "%^BOLD%^%^CYAN%^There are rumors of adventurers recently passing through "+implode(places,", ")+".%^RESET%^\n";
      tell_object(TP,placelist);
    }
  }

  rp_flags = "/daemon/user_d.c"->get_rp_flags();
  if(i = sizeof(rp_flags)) 
  {
      if(i == 1) tell_object(TP, "There is currently one role play flag flying. In the following location:\n"+rp_flags[0]->query_short()+".\n");
      else 
      {
        tell_object(TP, "There are currently "+i+" role play flags flaying. In the following locations:\n");
        places = rp_flags->query_short();
        tell_object(TP, implode(places[0..(sizeof(places)-2)], ", ")+ " and "+places[sizeof(places)-1]+"\n");
      }
  }  
  places = ({});
// start query for appropriate adventuring areas
  myareas = ({});
  mylevel = TP->query_level();

  switch(mylevel) {
    case 1..20: mymin = mylevel - 3; mymax = mylevel + 3; break;
    default: mymin = mylevel - 4; mymax = mylevel + 4; break;
    break;
  }

// solo areas
  mapkeys = keys(AREAMAP);
  if(!sizeof(mapkeys)) {
    tell_object(TP,"%^BOLD%^%^GREEN%^There has been an error generating base areas - please notify a wiz.%^RESET%^\n");
    return 1;
  }
  for(i = 0; i < sizeof(mapkeys); i++) if(mapkeys[i] >= mymin && mapkeys[i] <= mymax) myareas += AREAMAP[mapkeys[i]];
  if(!sizeof(myareas))
    tell_object(TP,"%^BOLD%^%^GREEN%^There are no well-known areas appropriate alone at your level.%^RESET%^\n");
  else {
    placelist = "%^BOLD%^%^GREEN%^Areas that may be appropriate for you to adventure in alone are "+implode(myareas,", ")+".%^RESET%^\n";
    tell_object(TP,placelist);
  }

// group areas
  mapkeys = ({});
  myareas = ({});
  mapkeys = keys(GROUPMAP);
  if(!sizeof(mapkeys)) {
    tell_object(TP,"%^BOLD%^%^CYAN%^There has been an error generating group areas - please notify a wiz.%^RESET%^\n");
    return 1;
  }
  for(i = 0; i < sizeof(mapkeys); i++) if(mapkeys[i] >= mymin && mapkeys[i] <= mymax) myareas += GROUPMAP[mapkeys[i]];
  if(!sizeof(myareas))
    tell_object(TP,"%^BOLD%^%^CYAN%^There are no well-known areas appropriate for a group of your level.%^RESET%^\n");
  else {
    placelist = "%^BOLD%^%^CYAN%^Areas that may be appropriate for you to adventure in with a group are "+implode(myareas,", ")+".%^RESET%^\n";
    tell_object(TP,placelist);
  }

// quests
  mapkeys = ({});
  myareas = ({});
  mapkeys = keys(QUESTMAP);
  if(!sizeof(mapkeys)) {
    tell_object(TP,"%^BOLD%^%^GREEN%^There has been an error generating the quest list - please notify a wiz.%^RESET%^");
    return 1;
  }
  for(i = 0; i < sizeof(mapkeys); i++) if(mapkeys[i] >= mymin && mapkeys[i] <= mymax) myareas += QUESTMAP[mapkeys[i]];
  if(!sizeof(myareas))
    tell_object(TP,"%^BOLD%^%^GREEN%^There are no quests considered appropriate for your level.%^RESET%^");
  else {
    placelist = "%^BOLD%^%^GREEN%^Quests that may be possible for you to complete include:%^RESET%^\n%^RESET%^%^ORANGE%^-"+implode(myareas,"\n%^RESET%^%^ORANGE%^-")+"%^RESET%^\n";
    tell_object(TP,placelist);
  }

  if(mylevel == 19 && !TP->query_hm_quest()) {
    tell_object(TP,"%^BOLD%^%^CYAN%^You must complete the Quest of the Swords before you can advance to the next level. You've heard that a woman in hut along the road north of Shadow city can get you started.%^RESET%^");
  }
  return 1;
}

int help(){
    write(
@OLI
%^BOLD%^%^CYAN%^    <rumors>%^RESET%^
    This command will reveal any recent rumors of adventurers passing through major city areas, as well as information about regions of the mud that may be of interest to you.  All of this is considered to be in-character information, as rumors that could be gathered from citizens or shopkeepers, psychics, and other roaming NPCs.
OLI
    );
    return 1;
}