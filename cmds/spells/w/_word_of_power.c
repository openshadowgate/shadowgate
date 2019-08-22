//restricted the spell to cleric only 3/16/05 -Tsera
//changed the Seneca exit to unload into new Seneca ~Circe~ 1/9/09

#include <priest.h>
inherit SPELL;

#define ACTIVETEMPLES ({ "jarmila","kreysneothosies","lord shadow", "lysara" , "ryorik", "the faceless one","callimar","kismet","nilith","nimnavanon"})

void create() {
    ::create();
    set_spell_name("word of power");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS word of power [to DESTINATION]");
    set_description("Word of power will teleport you to a church of your choice.  For now, you can reach the following "
"churches:\nShadow\nTharis\nAzha\nTabor\nMuul'daan\nAntioch\nTonovi\nTorm\nJuran\nKinaro\nVerbobone (Deku)\nGraez (Sangri"
")\nAsgard (Laerad)\nSeneca (Attaya)\nEldebaro (East Oasis)\nYou can also go to the temple of your deity by using <Temple> or <temple> as the "
"location.  Areas or items that block teleportation magic will block this spell as well.\n\nThis spell must be cast while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_helpful_spell(1);
}

void spell_effect(int prof) {
    string arg, where, placename, mygod;
    int mypower,startpower,endpower,bonus;

    arg = lower_case(ARG);
    tell_object(CASTER, "You reach your hands out and wave them in strange motions.");
    tell_room(PLACE, YOU+" reaches out and waves "+MINE+" arms in strange motions.", ({ CASTER}));
    switch (arg) {
    case "shadow":
        where = "/d/shadow/city/room/church";
        placename = "Shadow";
        break;
    case "dallyh":
    case "amazons":
        where = "/d/islands/dallyh/forest/rooms/church";
        placename = "Dallyh";
        break;
    case "tharis":
        where = "/d/tharis/newtharis/rooms/tharis_church1.c";
        placename = "Tharis";
        break;
    case "azha":
        where = "/d/azha/town/church";
        placename = "Azha";
        break;
    case "kinaro":
        where = "/d/dagger/kinaro/church";
        placename = "Kinaro";
        break;
    case "seneca":
        where = "/d/attaya/newseneca/rooms/cath_nave";
        placename = "Seneca";
        break;
    case "graez":
    case "sangri":
        where = "/d/undead/rooms/town/church1";
        placename = "Graez";
        break;
    case "asgard":
        where = "/d/laerad/parnelli/asgard/as72";
        placename = "Asgard";
        break;
    case "antioch":
        where = "/d/antioch/wild/forest/chapel_out";
        placename = "Antioch";
        break;
    case "juran":
        where = "/d/shadow/juran/city/church";
        placename = "Juran";
        break;
    case "deku":
    case "verbobone":
        where = "/d/deku/town/church";
        placename = "Verbobone";
        break;
    case "tonovi":
        where = "/d/dagger/tonovi/town/temple1.c";
        placename = "Tonovi";
        break;
    case "eldebaro":
        placename = "Eldebaro";
        where = "/d/islands/common/eldebaro/newrooms/church";
        break;
    case "torm":
      where = "/d/dagger/Torm/city/c101b.c";
      placename = "Torm";
      break;
    case "tabor":
      where = "/d/darkwood/tabor/room/church";
      placename = "Tabor";
      break;
    case "muuldaan":
    case "muul'daan":
        where = "/d/shadow/room/muuldaan/rooms/church";
        placename = "Muul'daan";
        break;
    default:
        mygod = (string)CASTER->query_diety();
        if(member_array(mygod,ACTIVETEMPLES) != -1) {
          placename = "the Temple of "+capitalize(mygod);
          mygod = replace_string(mygod," ","_");
          where = "/d/magic/temples/"+mygod+"/"+mygod;
          break;
        } else {
          where = "/d/shadow/room/city/church";
          placename = "Shadow";
          break;
        }
    }
    if(environment(CASTER)->query_property("no teleport") || where->query_property("no teleport")) {
        tell_object(CASTER,"Nothing happens.");
        dest_effect();
        return;
    }
   if(where &&
      (where->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !where->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = where->query_property("teleport proof");
      bonus = caster->query_stats("wisdom");
      bonus = bonus - 10;
      if((object *)caster->query_attackers() != ({}))
         mypower = CLEVEL + bonus + random(6);
      else
         mypower = CLEVEL + bonus + random(6) + 5;
      if((mypower < startpower) || (mypower < endpower)){
          tell_object(CASTER,"Nothing happens.");
          dest_effect();
          return;
      }
   }

   caster->clear_followers();

    tell_object(CASTER, "You are magically transported to the church in "+placename+".");
// trying just move to get rid of bug from TP not being defined for move.c
    CASTER->move_player(where);
//    CASTER->move(where);
    CASTER->set_casting(0);
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
