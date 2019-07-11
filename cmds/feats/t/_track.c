#include <std.h>
#include <terrain.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("NonCombat");
    feat_name("track");
    feat_syntax("track");
    feat_prereq("The track feat allows a character to use the track command. The accuracy is dependant on the character's survival skill, and the difficulty of the terrain they're inspecting. The track feat is required for any non-ranger to use this command.");
    set_target_required(0);
}

int allow_shifted() { return 1; }

int cmd_track(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { str = ""; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    string *tracks;
    int i, size, prof;
    string str, who, didwhat, direction, terrain;

    ::execute_feat(); 
    prof = caster->query_skill("survival")+ roll_dice(1,20);
    prof = prof/2;
    if(caster->query_blind() || caster->query_blindfolded()) {
      tell_object(caster,"You can't see a thing.");
      dest_effect();
      return;
    }
    if(caster->query_bound() || caster->query_tripped()) {
      caster->send_paralyzed_message("info",caster);
      dest_effect();
      return;
    }
    if(caster->light_blind(0)) {
      tell_object(caster,caster->light_blind_fail_message(caster->light_blind(1)));
      dest_effect();
      return;
    }
    if(!caster->query_time_delay("tracking",10)) {
      write("You're going to have to take more time to look around before you can find any more indications of what has passed here.");
      dest_effect();
      return;
    }
    tell_object(caster, "%^GREEN%^%^BOLD%^You peer at the ground and inspect the tracks that have been left here.\n%^RESET%^");
    tell_room(environment(caster), "%^BOLD%^%^GREEN%^"+caster->QCN+" peers at the ground and starts to inspect the tracks that have been left here recently.%^RESET%^", caster);
    tracks = environment(caster)->query_tracks();
    size = sizeof(tracks);
    if (!tracks[0]) {
      dest_effect();
      return;
    }

    //Terrain??
    terrain = environment(caster)->query_terrain();
    if (terrain != "unknown") {
        if (isInside(terrain) && !isCivilization(terrain)) {
            switch (terrain) {
              case HUT:        	  prof -= 1;                break;
              case NAT_CAVE:      prof -= 2;                break;
              case NAT_TUNNEL:    prof -= 2;                break;
              default:            prof -= 4;
            }
        }
        if (isOutside(terrain)) {
          switch (terrain) {
            case SNOW:            prof += 5;                break;
            case BOATS:           prof -= 7;                break;
            case CITY:            prof -= 3;                break;
            case ROCKY:           prof -= 2;                break;
            case MARSH:           prof += 1;                break;
            case DESERT_ROCKS:    prof -= 2;                break;
            case DENSE_JUNGLE:    prof -= 3;                break;
            case VILLAGE:         prof -= 2;                break;
            case SWAMP:           prof += 2;                break;
            case BRANCHES:        prof -= 2;                break;
            default:              prof += 2;
          }
        }
        if (isCivilization(terrain)) {
            switch (terrain) {
            case CITY:
                write("There's too many tracks here to discern where any truly lead.");
                tell_room(environment(caster), caster->QCN+" fumbles around on the ground but only ends up looking confused.",caster);
                dest_effect();
                return;
                break;
            case VILLAGE:
                write("There's too many tracks here to discern where any truly lead.");
                tell_room(environment(caster), caster->QCN+" fumbles around on the ground but only ends up looking confused.",caster);
                dest_effect();
                return;
                break;
            default:               prof -= 3;
            }
        }
        if (isTravel(terrain)) {
            switch (terrain) {
            case DIRT_ROAD:        prof -= 0;                break;
            case FOOT_PATH:        prof += 1;                break;
            case FRESH_BLAZE:      prof += 2;                break;
            default:               prof -= 3;
            }
        }
    }
    for (i=size-1;i>=0;i--) {
        if (random(10)+1 > (prof-i)) continue;
        else {
            if (caster->query_time_delay("tracking",10)) caster->set_time_delay("tracking");
        }
        str = tracks[i];

        if (str) {
            sscanf(str,"%s&%s&%s", who, didwhat, direction);

            if (random(15) > (prof-i)) {
                who = "creature that could not be identified";
            }
            switch (didwhat) {
            case "appeared":
                tell_player(caster, capitalize(article(who))+" "+who+" appeared here.\n");
                break;
            case "entered":
                tell_player(caster, capitalize(article(who))+" "+who+" entered this room from "+direction+".\n");
                break;
            case "left":
                tell_player(caster, capitalize(article(who))+" "+who+" left this room headed "+direction+".\n");
                break;
            default:
                tell_player(caster, "Somthing screwed up.  Contact a wiz.\n");
            }
        }
    }
    caster->set_time_delay("tracking");
    tell_object(caster, "\n%^BOLD%^You can't make out any more tracks here.\n");
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

