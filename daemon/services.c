/*    /daemon/services.c
 *    from the Nightmare Mudlib 3.2
 *    daemon to handle all UDP services
 *    created by Descartes of Borg 940130
 */

#include <std.h>
#include <daemons.h> 
#include <security.h> 
#include <network.h> 
 
inherit DAEMON;

static int in_quietness(object ob);

void send_affirmation_a(string host, string port, string de, string a, string msg, string type);
static private string *build_mudlist(mapping muds);

void create() { 
    //daemon::create();
}
/*
void incoming_affirmation_a(mapping info) { 
    object ob; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(!info["WIZTO"] || !(ob = find_player(lower_case(info["WIZTO"])))) return; 
    message("reply", sprintf("Affirmation from %s: %s", 
      (string)NETWORK_D->query_real_name(info["NAME"]), info["MSG"]), ob); 
  } 
 
void send_affirmation_a(string host, string port, string de, string a, 
  string msg, string type) { 
    NETWORK_D->send_udp(host, port, sprintf("@@@%s||NAME:%s||PORTUDP:%d" 
      "||WIZTO:%s||WIZFROM:%s||TYPE:%s||MSG:%s@@@\n", 
      SERVICE_UDP_AFFIRMATION_A, mud_name(), (int)NETWORK_D->query_port("udp"), 
      a, de, type, msg)); 
  } 
 
void incoming_gfinger_a(mapping info) { 
    object ob; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(ob = find_player(info["ASKWIZ"])) message("info",info["MSG"],ob); 
  } 
 
void incoming_gfinger_q(mapping info) { 
    string tmp, msg; 
    string *borg; 
    int i, maxi; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    msg=info["PLAYER"] ? (string)FINGER_D->user_finger_display(info["PLAYER"]): 
      (string)FINGER_D->general_finger_display(); 
    if(!msg) msg = "\n";
    for(i=0, tmp = "", maxi = sizeof(borg=explode(msg, "\n")); i < maxi; i++) { 
        if(strlen(tmp) < 200) tmp += sprintf("%s\n", borg[i]); 
        else { 
            NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
              sprintf("@@@%s||NAME:%s||PORTUDP:%d||ASKWIZ:%s||MSG:%s@@@\n", 
                SERVICE_UDP_FINGER_A, mud_name(), PORT_UDP, info["ASKWIZ"], tmp)); 
            tmp = sprintf("%s\n", borg[i]); 
        } 
    } 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||ASKWIZ:%s||MSG:%s@@@\n", 
        SERVICE_UDP_FINGER_A, mud_name(), PORT_UDP, info["ASKWIZ"], tmp)); 
  } 
 
int send_gfinger_q(string mud, string who, object ob) { 
    mapping info; 
 
    if(!ob && !(ob = this_player())) return 0; 
    if(mud == mud_name()) return 0; 
    if(!(info = (mapping)NETWORK_D->query_mud_info(mud))) return 0; 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"],  
      sprintf("@@@%s||NAME:%s||PORTUDP:%d%s||ASKWIZ:%s@@@\n", 
        SERVICE_UDP_FINGER_Q, mud_name(), PORT_UDP, (who ? "||PLAYER:"+who : ""), 
        (string)ob->query_name())); 
    return 1; 
  } 
 
void incoming_gtell(mapping info) { 
    string msg; 
    object ob; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(ob = find_player(lower_case(info["WIZTO"]))) { 
        replace_string(info["MSG"], " \b|", "|"); 
          message("reply","%^BOLD%^%^RED%^"+capitalize(info["WIZFROM"])+"@"+info["NAME"]+" tells you: %^RESET%^"+info["MSG"],ob);
   ob->set("reply",sprintf("%s@%s", info["WIZFROM"], info["NAME"])); 
      } 
    if(!ob || ob->query_invis() || hiddenp(ob)) 
      msg = sprintf("%s cannot be found in the reality of %s.\n", 
        capitalize(info["WIZTO"]), mud_name()); 
    else if(!interactive(ob))
      msg = sprintf("%s is zoning in nothingness.\n", capitalize(info["WIZTO"]));
    else if(query_idle(ob) > 60)  
      msg = sprintf("%s is currently idle.\n", capitalize(info["WIZTO"])); 
    else if(ob->query_blocked("tell"))  
      msg = sprintf("%s is currently blocking incoming tells.\n", 
        capitalize(info["WIZTO"])); 
    else msg = sprintf("%s has assimilated your message.\n",capitalize(info["WIZTO"])); 
    send_affirmation_a(info["HOSTADDRESS"], info["PORTUDP"],  
      "Something@"+mud_name(), info["WIZFROM"], msg, "gtell");
}  
 
int send_gtell(string mud, string who, string msg) { 
    mapping info; 
 
    if(mud == mud_name() || !(info=(mapping)NETWORK_D->query_mud_info(mud))) 
      return 0; 
    msg = replace_string(replace_string(msg, "|", " \b|"), "@@@", ""); 
    message("tell", sprintf("You tell %s@%s: %s", capitalize(who),  
      (string)NETWORK_D->query_real_name(mud), msg), this_player()); 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||WIZTO:%s||WIZFROM:%s||MSG:%s@@@\n", 
      SERVICE_UDP_TELL, mud_name(), PORT_UDP, who, 
      (string)this_player()->query_cap_name(), msg)); 
    return 1; 
  } 
 
void incoming_gwizmsg(mapping info) { 
    string msg; 
 
    if(file_name(previous_object()) != NETWORK_D || !info["WIZNAME"]) return;
    replace_string(info["GWIZ"], " \b|", "|"); 
    if(info["EMOTE"] && info["EMOTE"] != "0") 
      msg = sprintf("%s@%s: %s", info["WIZNAME"], info["NAME"], info["GWIZ"]); 
    CHAT_D->inter_channels(sprintf("%s@%s", capitalize(info["WIZNAME"]),info["NAME"]), 
      INTERCHANNELS[info["CHANNEL"]], info["GWIZ"], 
      (info["EMOTE"] && info["EMOTE"] != "0")); 
  } 
 
void send_gwizmsg(string msg, int emoted) { 
    mapping  info, borg; 
    string *muds; 
    int i; 
 
    i = sizeof(muds = keys(borg = (mapping)NETWORK_D->query_known_muds())); 
    msg = replace_string(replace_string(msg, "|", " \b|"), "@@@", ""); 
    while(i--) { 
        if(!mapp(info = borg[muds[i]])) continue; 
        if(info["REAL NAME"] == mud_name()) continue; 
        NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
          sprintf("@@@%s||NAME:%s||PORTUDP:%d||WIZNAME:%s||GWIZ:%s" 
          "||CHANNEL:%s%s", SERVICE_UDP_INTERMUD, mud_name(), PORT_UDP, 
          (string)this_player()->query_cap_name(), msg, "CREATOR",
          (emoted ? "||EMOTE:1@@@\n" : "@@@\n"))); 
      } 
  } 
 
void incoming_locate_a(mapping info) { 
    object ob; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(!stringp(info["ASKWIZ"]) || !(ob = find_player(lower_case(info["ASKWIZ"])))) 
      return; 
    switch(info["LOCATE"]) { 
    case "NO": return; 
    case "YES": case "yes": 
        message("info", sprintf("%s was just located on %s.",  
        capitalize(info["TARGET"]), info["NAME"]), ob); 
        break; 
    default: /* log bad answers here if you want */ /*
    } 
  } 
 
void incoming_locate_q(mapping info) { 
    string tmp; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(!info["TARGET"]) tmp = "NO"; 
    else tmp = (find_player(lower_case(info["TARGET"])) ? "YES" : "NO"); 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||LOCATE:%s||TARGET:%s||ASKWIZ:%s@@@\n", 
      SERVICE_UDP_LOCATE_A, mud_name(),PORT_UDP, tmp, info["TARGET"], info["ASKWIZ"])); 
  } 
 
void send_locate_q(string who) { 
    mapping info; 
    string *muds; 
    int i; 
 
    i = sizeof(muds = keys(info = (mapping)NETWORK_D->query_known_muds())); 
    while(i--) { 
        NETWORK_D->send_udp(info[muds[i]]["HOSTADDRESS"], info[muds[i]]["PORTUDP"], 
          sprintf("@@@%s||NAME:%s||PORTUDP:%d||TARGET:%s||ASKWIZ:%s@@@\n", 
          SERVICE_UDP_LOCATE_Q, mud_name(), PORT_UDP, lower_case(who),  
          (string)this_player()->query_name())); 
      } 
  } 
 
void incoming_mail_q(mapping info) { 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(info["CC"]) info["CC"] = explode(info["CC"], ","); 
    else info["CC"] = ({}); 
    info["MSG"] = replace_string(info["MSG"], " \b|", "|"); 
    if(info["WIZTO"]) info["WIZTO"] = explode(info["WIZTO"], ","); 
    if(!((int)REMOTEPOST_D->incoming_post(info))) info["RESEND"] = 1; 
    log_file("reports/incoming_mail", info["NAME"]+" "+info["MSG"]);
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d%s%s@@@\n", SERVICE_UDP_MAIL_A, 
      mud_name(), PORT_UDP, (info["ENDMSG"] ? "||ENDMSG:1" : ""), 
      (info["RESEND"] ? "||RESEND:1" :""))); 
  } 
 
void incoming_mail_a(mapping info) { 
    string str; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    log_file("reports/incoming_confirm", info["NAME"]+"\n");
    if(info["RESEND"]) str = (string)REMOTEPOST_D->resend_post(info["NAME"]); 
    else if(!(str = (string)REMOTEPOST_D->next_post(info["NAME"]))) 
      str = (string)REMOTEPOST_D->postal_check(info["NAME"]); 
    if(!str) return; 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d%s@@@\n", SERVICE_UDP_MAIL_Q, 
      mud_name(), PORT_UDP, str)); 
  } 
     
     
void incoming_mudlist_a(mapping info) { 
    string *borg, *dat; 
    string cle, val; 
    mapping tmp; 
    int i, j; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    i = sizeof(borg = keys(info)); 
    while(i--) { 
        j = sizeof(dat = explode(info[borg[i]], "|")); 
        tmp = ([]); 
        while(j--) if(sscanf(dat[j], "%s:%s", cle, val) ==2) tmp[cle] = val; 
        if(!tmp["NAME"]) continue; 
        if(replace_string(lower_case(tmp["NAME"]), " ", ".") ==  
          replace_string(lower_case(mud_name()), " ", ".")) continue; 
        if((int)NETWORK_D->mud_exists(tmp["NAME"])) continue; 
        NETWORK_D->add_mud(tmp); 
      } 
  } 
        
void incoming_mudlist_q(mapping info) { 
    string *bits; 
    int i; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    i = sizeof(bits = build_mudlist((mapping)NETWORK_D->query_known_muds())); 
    while(i--)  
      NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
        sprintf("@@@%s%s@@@\n", SERVICE_UDP_MUDLIST_A, bits[i])); 
  } 
 
void send_mudlist_q(string host, string port) { 
    NETWORK_D->send_udp(host, port,  
      sprintf("@@@%s||NAME:%s||PORTUDP:%d@@@\n", SERVICE_UDP_MUDLIST_Q, mud_name(), 
      PORT_UDP)); 
  } 
 
void incoming_ping_a(mapping info) { 
    if(file_name(previous_object()) != NETWORK_D) return;
    if((int)NETWORK_D->mud_exists(info["NAME"])) return; 
    NETWORK_D->add_mud(info); 
  } 
 
void incoming_ping_q(mapping info) { 
    string str;

    if(file_name(previous_object()) != NETWORK_D) return;
    log_file("reports/ping_q", info["NAME"]+"\n");
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s%s@@@\n", SERVICE_UDP_PING_A, START_MSG)); 
    if(str = (string)REMOTEPOST_D->postal_check(info["NAME"])) 
      NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
        sprintf("@@@%s||NAME:%s||PORTUDP:%d%s@@@\n",
        SERVICE_UDP_MAIL_Q, mud_name(), PORT_UDP, str));
    if(str)
      log_file("reports/daemon", info["NAME"]+" "+str+"\n");
  } 
 
void send_ping_q(string host, int port) { 
    NETWORK_D->send_udp(host, port,  
      sprintf("@@@%s||NAME:%s||PORTUDP:%d@@@\n", SERVICE_UDP_PING_Q, mud_name(), 
      PORT_UDP)); 
  } 
      
void incoming_rwho_a(mapping info) { 
    object ob; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(!(ob = find_player(lower_case(info["ASKWIZ"])))) return; 
    message("info", "%^RED%^rwho@"+info["NAME"]+":%^RESET%^\n"+info["RWHO"], ob); 
}     
 
int incoming_rwho_q(mapping info) { 
    string tmp, list; 
    string *bits; 
    object *who, *borg; 
    int i, maxi; 
 
    if(file_name(previous_object()) != NETWORK_D) return 0;
    who = filter_array(users(), "filter_invis", this_object()); 
    list = sprintf("%s (driver: %s, mudlib: %s %s)\n", mud_name(), version(), 
      mudlib(), mudlib_version()); 
    if(!sizeof(who)) list += "Reality is void of being.\n"; 
    else { 
        if(maxi=sizeof(borg=filter_array(who,"filter_admins",this_object()))) { 
            for(i=0, tmp="";i<maxi;i++) tmp += (string)borg[i]->query_cap_name()+"  "; 
            list += "Admins: "+wrap(tmp); 
	  } 
        if(maxi=sizeof(borg=filter_array(who,"filter_creators",this_object()))) { 
            for(i=0, tmp="";i<maxi;i++) tmp += (string)borg[i]->query_cap_name()+"  "; 
            list += "Creators: "+wrap(tmp); 
	  } 
        if(maxi=sizeof(borg=filter_array(who,"filter_hm",this_object()))) { 
            for(i=0, tmp="";i<maxi;i++) tmp += (string)borg[i]->query_cap_name()+"  "; 
            list += "High Mortals: "+wrap(tmp); 
	  } 
        if(maxi=sizeof(borg=filter_array(who, "filter_mortals", this_object()))) { 
            for(i=0, tmp="";i<maxi;i++) tmp += (string)borg[i]->query_cap_name()+"  "; 
            list += "Mortals: "+wrap(tmp); 
	  } 
      } 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||RWHO:%s||ASKWIZ:%s@@@\n", 
      SERVICE_UDP_RWHO_A, mud_name(), PORT_UDP, list, info["ASKWIZ"])); 
  } 
 
int send_rwho_q(string mud, object ob) { 
    mapping info; 
 
    if((!ob && !(ob=this_player()))) return 0; 
    if(!(info=(mapping)NETWORK_D->query_mud_info(mud))) return 0; 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||ASKWIZ:%s@@@\n", SERVICE_UDP_RWHO_Q, 
      mud_name(), PORT_UDP, (string)ob->query_name())); 
    return 1; 
  } 
 
void incoming_shutdown(mapping info) { 
    if(file_name(previous_object()) != NETWORK_D) return;
    NETWORK_D->remove_mud(info["NAME"]); 
  } 
 
void send_shutdown(string host, int port) { 
    if(file_name(previous_object()) != NETWORK_D) return;
    NETWORK_D->send_udp(host, port, 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d@@@\n", SERVICE_UDP_SHUTDOWN, 
      mud_name(), PORT_UDP)); 
  } 
 
void incoming_startup(mapping info) { 
    if(file_name(previous_object()) != NETWORK_D) return;
    incoming_ping_a(info); 
    incoming_ping_q(info); 
  } 
 
void incoming_support_a(mapping info) { 
    object ob; 
    string fl, fun, id; 
    return;
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(!info["ANSWERID"] || sscanf(info["ANSWERID"],"%s#%s#%s",fl,fun,id) != 3) 
      return; 
    if(!(ob = find_object(fl))) return; 
    if(info["SUPPORTED"] && lower_case(info["SUPPORTED"]) == "yes") 
      call_other(ob, fun, ({ 1, id })); 
    else call_other(ob, fun, ({ 0, id }) ); 
  } 
 
void incoming_support_q(mapping info) { 
    string ret; 
 
    if(file_name(previous_object()) != NETWORK_D) return;
    if(!stringp(info["PARAM"])) info["PARAM"] = ""; 
    if(!function_exists(sprintf("incoming_%s",info["CMD"]),  
      this_object()) && member_array(info["CMD"], TCP_SERVICES) == -1)
        ret = "||NOTSUPPORTED:yes";
    else ret = "||SUPPORTED:yes"; 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||CMD:%s||PARAM:%s%s||ANSWERID:%s@@@\n", 
      SERVICE_UDP_SUPPORT_A, mud_name(), PORT_UDP, info["CMD"], info["PARAM"], 
      ret, info["ANSWERID"])); 
  } 
 
int send_support_q(string mud, string cmd, string param, string fun, string id) { 
    mapping info;
    string fl; 
     
    if(!param) param = ""; 
    fl = file_name(previous_object()); 
    id = sprintf("%s#%s#%s", fl, fun, id); 
    if(!(info = (mapping)NETWORK_D->query_mud_info(mud))) return 0; 
    NETWORK_D->send_udp(info["HOSTADDRESS"], info["PORTUDP"], 
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||CMD:%s||PARAM:%s||ANSWERID:%s@@@\n", 
      SERVICE_UDP_SUPPORT_Q, mud_name(), PORT_UDP, cmd, param, id)); 
    return 1; 
  } 
     
static int filter_invis(object ob) { 
    return (!((int)ob->query_invis()) && !hiddenp(ob) &&
       (string)ob->query_cap_name() && !in_quietness(ob));
  } 
 
static int filter_admins(object ob) { return archp(ob); } 
 
static int filter_creators(object ob) { return wizardp(ob) && !archp(ob); } 
 
static int filter_hm(object ob) { return high_mortalp(ob); } 
 
static int filter_mortals(object ob) { 
    return (!wizardp(ob) && !high_mortalp(ob)); 
  } 

static int in_quietness(object ob) {
    return (wizardp(ob) && ob->query_quietness()); }

static private string *build_mudlist(mapping muds) { 
    string *noms, *ret; 
    int i, pos, maxi; 
 
    maxi = sizeof(noms = keys(muds)); 
    for(i=0, pos = 0, ret = ({ "" }); i<maxi; i++) { 
        ret[pos] += "||"+i+":"+ 
        "|NAME:"+muds[noms[i]]["REAL NAME"]+ 
        "|HOST:"+muds[noms[i]]["HOST"]+ 
        "|HOSTADDRESS:"+muds[noms[i]]["HOSTADDRESS"]+ 
        "|PORT:"+muds[noms[i]]["PORT"]+ 
        "|TCP:"+(undefinedp(muds[noms[i]]["TCP"]) ? "none" : muds[noms[i]]["TCP"])+ 
        "|PORTUDP:"+muds[noms[i]]["PORTUDP"]+ 
        (muds[noms[i]]["MUDLIB"] ? "|MUDLIB:"+muds[noms[i]]["MUDLIB"] : "") + 
        (muds[noms[i]]["VERSION"] ? "|VERSION:"+muds[noms[i]]["VERSION"] : "") + 
        (muds[noms[i]]["DRIVER"] ? "|DRIVER:"+muds[noms[i]]["DRIVER"] : "") + 
        (muds[noms[i]]["TIME"] ? "|TIME:"+muds[noms[i]]["TIME"] : ""); 
        if(strlen(ret[pos]) > 256) { 
            ret += ({ "" }); 
            pos++; 
	  } 
      } 
    return ret; 
  } 

void new_mail(string mud) {
    mapping info;

    if(file_name(previous_object()) != REMOTEPOST_D) return;
    if(!(info = (mapping)NETWORK_D->query_mud_info(mud))) return;
    this_object()->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
}
*/