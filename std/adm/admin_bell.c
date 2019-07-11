// A bell inheritable that will notify all the admins online that 
// players need help. Even if admins are invisable or in
// quietness. To prevent abuse there is a timer so the
// bell be used only once per RINGDELAY second
//
// /std/adm/admin_bell.c
// Pator@ShadowGate
// Jan 9th 1997

#include <std.h>
#include <daemons.h>
#include "prohibited.h"

inherit OBJECT;

// This sets the default RINGDELAY. The delay can be set longer via the 
// set_delay() function. But they won't be able to set the delay shorter 
// then RINGDELAY seconds 
#define RINGDELAY 150

void set_last_rung(int i);
void set_delay(int i);

int last_rung, ring_delay;

int query_last_rung();
private int check_time();
int allowed_to_ring(object who);
int query_delay();

void init() { 
        add_action("ring","ring"); 
	add_action("check_time_out","check"); 
        add_action("disallowed", "disallowed");
        add_action("report_delay", "delay"); 
		}

int ring(string str) {
int i;
string alarm, where;

// Check if the bell is rung
	if (!str) {
	   notify_fail("%^BOLD%^%^RED%^You wanted to ring something ?\n");
	   return 1; }

// We check if the bell may be rung again.
// If not allowed 0 will be returned, otherwise the current time
// will be returned
        i = check_time();
	if (i) {
	   tell_object(TP, 
		"%^BOLD%^%^YELLOW%^You can't ring the bell yet !\n"+
		"You will have to wait some time longer !");
	   tell_room(ETP,
  "%^BOLD%^%^GREEN%^"+TPQCN+" tried to ring the bell !\n"+
  "As "+TP->query_subjective()+" is impatient the attempt failed utterly !",
		     ({ TO, TP }) );
	   return 1; }

// It will be possible that some players will not be allowed to ring the
// bell, they will be disabled here as are immortals

	if (!allowed_to_ring(TP)) {
		tell_object(TP, "%^BOLD%^%^RED%^"+
		    "You are not allowed to ring this bell !!");
		return 1; }

         else {
		set_last_rung(time());
		where = file_name(ETP);

		alarm = "\n%^BOLD%^%^YELLOW%^"+TPQCN;
		alarm += " notifies you all that "+TP->query_subjective();
		alarm += " needs your attention in ";
		alarm += "%^RED%^"+where+"%^RESET%^\n";

// The actual notification is done here
		BELL_D->bell_notify(alarm, this_object());

// The event will be logged
            log_file("bell_ring", TPQCN+where+" at "+ctime(time())+"\n");
// The room will be notified of the ring
		tell_room(ETP, "%^BOLD%^%^GREEN%^"+
        TPQCN+" rings the bell with a loud %^BLUE%^BONG%^GREEN%^ attempting "+
        "to contact one of the admins.", ({ TP }) );
		tell_object(TP, "%^BOLD%^%^GREEN%^"+
	"You sound the bell with a loud %^BLUE%^BONG%^GREEN%^ trying "+
	"to direct an admins attention to you");
	return 1; 
	}
}

// Check if one can ring the bell again
int check_time_out(string str) {
int time_left,mins, secs;
string story;
	if (!str) {
	   notify_fail("You want to check what ?\n");
	   return 1; }
	if ( member_array(str,({ "bell", "BELL", "gong" })) == -1 ) {
	   notify_fail("You want to check what ?\n");
	   return 1; }
		// Check for the seconds that are left on the timer
	time_left = check_time();
	if (!time_left) {
		tell_object(TP, "%^BOLD%^%^BLUE%^You can ring the bell !");
		return 1; }
	time_left = time() - query_last_rung();
	time_left = query_delay() - time_left;
	mins = time_left / 60;
	secs = time_left % 60;
	story = sprintf("You will have to wait another %d minutes "+
		       "and %d seconds for the next ring !", mins, secs);
	tell_object(TP, story);
	return 1;
}

void set_last_rung(int i){ last_rung = i; }

// This will set the delay to i seconds with a minimum of RINGDELAY seconds
void set_delay(int i){ 
     if ( i< RINGDELAY ) i = RINGDELAY;
     ring_delay = i; }

// Check how long the delay is for this bell
int query_delay() {
	return ring_delay; }

// This will return the time the bell was rung for the last time
int query_last_rung(){ 
	if (!last_rung) last_rung= time() - query_delay(); // Initially the bell
							   // may be rung.
        return last_rung; }

// This is the check if the bell may be rung
private int check_time(){
        if ( time() - query_last_rung() < query_delay() ) { return 1; }
	else { return 0; } }
	  
// Some players may be prohibited to ring the bell
// This function will keep track of those users
// All immortals are not allowed to ring the bell (even admins !)
int allowed_to_ring(object who){
    if ( (member_array(who->query_true_name(), PROHIBITED) != -1 ) ||
		wizardp(TP) )
	 { return 0; }	
    else { return 1; } }

// Tells an admin the current delay between rings
int report_delay() {
string dl;
	if (!archp(TP)) {
		tell_object(TO, "%^BOLD%^%^RED%^"+
			"You are not allowed to check this !"); 
		return 1; }
	else {
        dl = "The delay is "+(int)TO->query_delay()+" seconds.";
		tell_object(TP, dl);
	        return 1; }
}

// Lists all the players who aren't allowed to ring the bell
int disallowed() {
int size,count;
	if (!archp(TP)) {
                tell_object(TO, "%^BOLD%^%^RED%^"+
                        "You are not allowed to check this !");
                return 1; }
        else {
		size = sizeof(PROHIBITED);
		if (!size) {
			tell_object(TP, "There are no disallowed players");
			return 1; }
		for (count=0;count <size;count++) {
			write(PROHIBITED[count]); }
		return 1; }
}
