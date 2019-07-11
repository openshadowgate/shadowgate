//templefunds_d.c
//adapted from guild_d.c by *Styx*, 6/2002 for tithe boxes in temples

//  be SURE to change the SAVE_FILE

#include <std.h>
#include <security.h>
#include <daemons.h>

#define SAVE_FILE "/daemon/save/templefunds"
// #define SAVE_FILE "/realms/styx/templefunds"
inherit DAEMON;

// string *temples;
mapping tAccounts;
mapping tWithdrawals;
mapping pDonations;

void SAVE();
void clean_up_gone();

void create(){
	::create();
//	temples = ({});    // don't need this after all (??) *Styx* 7/3
	seteuid(UID_DAEMONSAVE);
	restore_object(SAVE_FILE);
	seteuid(getuid());
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
}

int query_temple_account(string temple){
   if(!tAccounts) tAccounts = ([]);
   if(!tAccounts[temple]) tAccounts[temple] = 0;
   return tAccounts[temple];
}

int query_temple_withdrawals(string temple){
   if(!tWithdrawals) tWithdrawals = ([]);
   if(!tWithdrawals[temple]) tWithdrawals[temple] = 0;
   return tWithdrawals[temple];
}

//  in process.... Also needs a clean-up function to remove names by checking for a valid user (per Garrett, user_exits() is the function and it has a man doc

int query_donations(string name) {
   int amount, i, j;
   string *which;
   string temple;
   if(!pDonations)        pDonations = ([]);
   if(!pDonations[name])  pDonations[name] = ([]);
   if(!pDonations[name][temple])  pDonations[name][temple] = 0;
//   which = keys(pDonations[name]);
//   amount = pDonations[name][which];
   j = sizeof(which);
/* Didn't get this working and the other isn't pretty, but it provides the info. so it'll have to do for now  *Styx*  5/3/03  
   write(capitalize(name)+" has made the following donations to temples:\n");
   for(i=0;i < j;i++) {
      temple = which[i];
      write( capitalize(temple)+":  %^YELLOW%^"+pDonations[name][temple]+" gold.");
   }
*/
   if(!pDonations[name])
	return(capitalize(name)+" doesn't seem to have made any donations to temples.");
   return pDonations[name];
}


int clean_up(){return 1;}

int withdraw_funds(string temple, int amount, object who) {
   int ok;
   if(avatarp(who)) {
      if(!tAccounts) tAccounts = ([]);
      if(!tAccounts[temple]) tAccounts[temple] = 0;
      if(!tWithdrawals) tWithdrawals = ([]);
      if(!tWithdrawals[temple]) tWithdrawals[temple] = 0;
      if(tAccounts[temple] < amount) {
         tell_object(who,"This temple only has "+tAccounts[temple]+" gold in "
            "funds.  That's all you get.");
         amount = tAccounts[temple];
      }
      tAccounts[temple]-= amount;
      tWithdrawals[temple]+= amount;
      tell_object(who,"You have withdrawn %^YELLOW%^"+amount+" gold %^RESET%^"
         "of the funds of the temple of "+temple+".");
      log_file("tithes",capitalize(who->query_name())+" withdrew "
        +amount+" gold from the temple of "+capitalize(temple)+
        " on "+ctime(time())+".\n");
      SAVE();
      return 1;
   }
   tell_object(who,"I'm quite sure you are not authorized.");
   return 0;
}

void add_temple_gold(string temple, int amount, string type, object who, string diety, int item) {
   int amt2;
   string name;
   name = who->query_name();
   if(!item)  who->add_money(type, -amount);
   who->force_me("save");
   log_file("tithes",capitalize(who->query_name())+" donated "+amount+" "+type+
        " to the temple of "+capitalize(temple)+" on "+ctime(time())+".\n");
   if(!tAccounts)                 tAccounts = ([]);
   if(!tAccounts[temple])         tAccounts[temple] = 0;
   if(!pDonations)                pDonations = ([]);
   if(!pDonations[name])          pDonations[name] = ([]);
   if(!pDonations[name][diety])   pDonations[name][diety] = 0;
    
   if(type != "gold") {
      amt2 = amount * (int) ECONOMY_D->currency_rate(type);
      amount = amt2/(int)ECONOMY_D->currency_rate("gold");
   }
   tAccounts[temple]+= (amount * 90/100);
   pDonations[name][diety] += amount;
   SAVE();
}
