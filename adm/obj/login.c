#include <conf.h>
#include <news.h>
#include <flags.h>
#include <security.h>
#include <daemons.h>
#include <objects.h>
#include <ansi.h>
#include <pwgen.h>

static private int __CrackCount;
static private string __Name;
static private object __Player;
static private string subname, xyz, __ob_name;
static private int flag = 0;
static private int __LoginTimeBuffer;

void logon();
void get_name(string str);
void get_password(string str);
int locked_access();
int check_password(string str);
int valid_site(string ip);
int is_copy();
disconnect_copy(string str, object ob);
void exec_user();
void new_user(string str);
void choose_password(string str);
void confirm_password(string str2, string str1);
void choose_gender(string str);
void enter_email(string str);
void enter_real_name(string str);
void idle();
void receive_message(string cl, string msg);
private void internal_remove();
void remove();

void create()
{
    seteuid(UID_ROOT);
    __Name = "";
    __CrackCount = 0;
    __Player = 0;
}

static void logon()
{
    int Z, ttl;
    call_out("idle", LOGON_TIMEOUT);

    if(time() < __LoginTimeBuffer)
    {
        message("logon", "Please wait one second, login time buffer in effect.",TO);
        internal_remove();
        return;
    }
    __LoginTimeBuffer = time() + 1;

    if(catch(__Player = new(OB_USER)))
    {
        if(catch(__Player = new("/adm/failsafe/user_failsafe")))
        {
            message("logon", "Someone appears to be messing with the user object.\n"
                    "Please try again in a few minutes.\n", this_object());
            internal_remove();
            return;
        }
    }
    if (!((int)BANISH_D->block_access(query_ip_number()))) {
        message("logon", read_file("/news/_ip_banished"), this_object());
        internal_remove();
        return;
    }

    Z = random(5)+1;
    //message("logon", read_file(WELCOME+Z),this_object());
    message("logon", "\n", this_object());
    message("logon", "/daemon/welcome_d.c"->get_welcome(), this_object());
    message("logon", "\n\n  Players Online: " +sizeof(real_users())+"\n  Last Reboot: " +last_reboot()+"\n", this_object());
    if ("/adm/daemon/shutdown_d.c"->shuttingDown()) {
        ttl = "/adm/daemon/shutdown_d.c"->query_time_left();
        if(ttl > 0)
            message("logon", "\n<<< The MUD will be rebooting shortly. Reboot in "+ttl/60+" minute(s)! >>>\n", this_object());
        else {
            message("logon", "\n<<< The MUD will reboot in under a minute! >>>\n", this_object());
            message("logon", "\n<<< Please consider waiting for a minute for the game to boot properly!!! >>>\n", this_object());
        }
    }
    message("logon", "  E-mail: law@shadowgate.org\n  Website: https://shadowgate.org/\n", this_object());
    message("logon", "  Host: shadowgate.org\n  Ports: 8080, 8443 (SSL)", this_object());
    message("logon", "\n",this_object());
    message("logon", "\nWhat name do you choose? ", this_object());
    input_to("get_name");
}

static void get_name(string str) {
    if (!str || str == "") {
        message("logon", "\nInvalid entry.  Please try again.\n", this_object());
        internal_remove();
        return;
    }
    __Name = lower_case(str);
    if ("/adm/obj/master.c"->is_locked()) {
        message("logon", read_file(LOCKED_NEWS), this_object());
        if (locked_access())
            message("logon", "\n    >>> Access allowed <<<\n", this_object());
        else {
            message("logon", "\n    >>> Access denied <<<\n", this_object());
            internal_remove();
            return;
        }
    }
    if (!user_exists(__Name)) {
        if (file_exists("/adm/save/users/arrest/"+__Name+".o")) {
            message("logon",read_file("/news/_arrested"),this_object());
            internal_remove();
        }
        if (!((int)BANISH_D->valid_name(__Name))) {
            message("logon", sprintf("\n%s is not a valid name choice for %s.\n",
                                     capitalize(__Name), mud_name()), this_object());
            message("logon", sprintf("Names must be alphabetic characters no "
                                     "longer than %d letters,\nand no less than %d letters.\n",
                                     MAX_USER_NAME_LENGTH, MIN_USER_NAME_LENGTH), this_object());
            message("logon", "\nPlease enter another name: ", this_object());
            input_to("get_name");
            return;
        }
        if (!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) {
            message("logon",read_file("/news/register"), this_object());
            internal_remove();
            return;
        }
        if (!MULTI_D->is_allowed(__Name)) {
            log_file("watch/linked_denial",sprintf("%s at %s from %s\n",__Name,ctime(time()),query_ip_number()));
            message("logon", read_file("/news/_link"), this_object());
            internal_remove();
        }
        if (find_player(__Name) && interactive(find_player(__Name))) {
            message("logon", sprintf("That character is already being created.  Please try again later."), this_object());
            internal_remove();
        }
        message("logon", read_file("/news/newname"), this_object());
        message("logon", sprintf("Do you really wish %s to be your name? (y/n) ",
                                 capitalize(__Name)), this_object());
        input_to("new_user");
        return;
    }
    if (!((int)BANISH_D->allow_logon(__Name, query_ip_number()))) {
        message("logon", read_file("/news/register"), this_object());
        internal_remove();
        return;
    }
    if (!MULTI_D->is_allowed(__Name)) {
        log_file("watch/linked_denial",sprintf("%s at %s from %s\n",__Name,ctime(time()),query_ip_number()));
        message("logon", read_file("/news/_link"), this_object());
        internal_remove();
    }
    message("logon", "Password: ", this_object());
    input_to("get_password", I_NOECHO | I_NOESC);
}

void get_password(string str) {
    if (!str || str == "")
    {
        message("logon", "\nYou must enter a password.  Try again later.\n",
                this_object());
        internal_remove();
        return;
    }
    if (!check_password(str))
    {
        message("logon", "\nInvalid password.\n", this_object());
        log_file("watch/bad_password",sprintf("%s at %s from %s\n",__Name,ctime(time()),query_ip_number()));
        if (++__CrackCount > MAX_PASSWORD_TRIES) {
            message("logon", "No more attempts allowed.\n", this_object());
            internal_remove();
            return;
        }
        destruct(__Player);
        __Player = new(OB_USER);
        message("logon", "Password: ", this_object());
        input_to("get_password", I_NOECHO | I_NOESC);
        return;
    }
    seteuid(UID_LOG);
    log_file("watch/logon", sprintf("%s from %s at %s\n",__Name,query_ip_number(),ctime(time())));
    seteuid(getuid());
    if (!is_copy()) exec_user();
}

static private int locked_access() {
    int i;
    string fore, aft;

    if (sscanf(__Name, "%s@%s", fore, aft) == 2)
        if ((int)BANISH_D->is_guest(fore))
            return 1;

    if ((int)BANISH_D->is_guest(__Name)) return 1;
    i = sizeof(LOCKED_ACCESS_ALLOWED);
    while (i--) if (member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) return 1;
    return 0;
}

static private int check_password(string str) {
    string pass;

    master()->load_player_from_file(__Name, __Player);
    if ((pass = (string)__Player->query_password()) != crypt(str, pass)) return 0;
    return valid_site(query_ip_number());
}

static private int valid_site(string ip) {
    string a, b;
    string *miens;
    int i;

    if (!(i = sizeof(miens = (string *)__Player->query_valid_sites()))) return 1;
    while (i--) {
        if (ip == miens[i]) return 1;
        if (sscanf(miens[i], "%s.*s", a) && sscanf(ip, a+"%s", b)) return 1;
    }
    return 0;
}

static private int is_copy() {
    object ob;

    if (!(ob = find_player(__Name))) return 0;
    if (interactive(ob)) {
        message("logon", "\nThere currently exists an interactive copy of you.\n",
                this_object());
        message("logon", "Do you wish to take over this interactive copy? (y/n) ",
                this_object());
        input_to("disconnect_copy", I_NORMAL, ob);
        return 1;
    }
    seteuid(UID_LOG);
    log_file("enter", sprintf("%s (exec): %s\n", __Name, ctime(time())));
    seteuid(getuid());
    if (exec(ob, this_object())) ob->restart_heart();
    else message("logon", "Problem reconnecting.\n", this_object());
    internal_remove();
    return 1;
}

static void disconnect_copy(string str, object ob) {
    object tmp;

    if (str == "") {
      is_copy();
      return;
    }
    if ((str = lower_case(str)) == "" || str[0] != 'y') {
        message("logon", "\nThen please try again later!\n", this_object());
        internal_remove();
        return;
    }
    message("info", "Another person is connecting with your name and password. If this is "+
    "not you, please notify a member of LAW immediately and change your password with the "+
    "passwd command!", ob);
    if(ob->query_property("inactive")) ob->remove_property("inactive");
    tmp = new(OB_USER);
    exec(tmp, ob);
    exec(ob, this_object());
    destruct(tmp);
    message("logon", "\nAllowing relog.\n", ob);
    internal_remove();
}

static private void exec_user() {
    if (MULTI_D->query_prevent_login(__Name)) {
  seteuid(UID_LOG);
        log_file("watch/multilog_denial",sprintf("%s at %s from %s\n",__Name,ctime(time()),query_ip_number()));
          message("logon", read_file("/news/_link_multilog"), this_object());
  seteuid(getuid());
        internal_remove();
        return;
    }
    __Player->set_name(__Name);
    if (!exec(__Player, this_object())) {
        message("logon", "\Problem connecting.\n", this_object());
        internal_remove();
        return;
    }
    __Player->setup();
    if (member_array("neck",__Player->query_limbs()) == -1)
        __Player->add_limb("neck","neck",__Player->query_max_hp(),0,0);
    destruct(this_object());
}

static void new_user(string str) {
    if ((str = lower_case(str)) == "" || str[0] != 'y') {
        message("logon", "\nOk, then enter the name you really want: ", this_object());
        input_to("get_name");
        return;
    }
    message("logon", "Please choose a password of at least 6 characters: ", this_object());
    input_to("choose_password", I_NOECHO | I_NOESC);
}

static void choose_password(string str) {
    if (strlen(str) < 6) {
        message("logon", "\nYour password must be at least 6 characters long.\n",
                this_object());
        message("logon", "Please choose another password: ", this_object());
        input_to("choose_password", I_NOECHO | I_NOESC);
    }
    message("logon", "\nPlease confirm your password choice: ", this_object());
    input_to("confirm_password", I_NOECHO | I_NOESC, str);
}

static void confirm_password(string str2, string str1)
{
    string salt;
    salt = PWGEN->random_salt(43);
    if (str1 == str2) {
        __Player->set_password(str2 = crypt(str2, "$5$"+salt));
        message("logon",
"

ANSI color adds very much to your enjoyment of playing.The following
is an ANSI color test. If you see color, then you support ANSI. If you
see garbage, then you do NOT support ANSI. If you don't see color and
you don't see garbage, then ANSI would still probably be a wise
decision.

"
        , this_object());
        message("logon","ANSI color test: "+HIM+"A"+HIG+"N"+HIC+"S"+HIR+"I"+BLU+
                " test"+NOR+"\n\n", this_object());
        message("logon","That should have read 'ANSI test' in multiple colors.\n"+
                "Do you support ANSI? [y/n]: ", this_object());
        input_to("ansi_test");
    } else {
        message("logon", "\nPassword entries do not match.  Choose a password: ",
                this_object());
        input_to("choose_password", I_NOECHO | I_NOESC);
        return;
    }
}
static void ansi_test(string str) {
    str=capitalize(str);
    if (str != "Y" && str != "N") {
        message("logon", "\nPlease enter Y for yes, or N for no.\n",
                this_object());
        message("logon", "Do you support ANSI? [y/n]: ", this_object());
        input_to("ansi_test");
        return;
    }
    if (str == "Y") {
        message("logon", "\nANSI supported turned on.  Use 'set term default' to turn it off later in the game.\n",this_object());
        __Player->setenv("TERM","ansi");
        __Player->reset_terminal();
    }
    if (str =="N") {
        message("logon", "\nANSI supported turned off.  Use <set term "+
                "ansi> to turn it on later in the game.\n",this_object());
        __Player->setenv("TERM","default");
        __Player->reset_terminal();
    }
    message("logon", "\nChoose character gender"+
            " (male, female, neuter) : ", this_player());
    input_to("choose_gender");
    return;

}

static void choose_gender(string str) {
    if (str != "male" &&
        str != "female" &&
        str != "neuter") {
        message("logon", "\nOnly female, male or neuter are available at this time.\n",
                this_object());
        message("logon", "Gender: ", this_object());
        input_to("choose_gender");
        return;
    }
    __Player->set_gender(str);
    message("logon", sprintf("
If you wish to be able to restore your password, enter your email in the
form of user@host. You can later change this setting with <chfn> command.
Your email address:", mud_name()), this_object());
    input_to("enter_email");
}

static void enter_email(string str) {
    string a, b;

    if (!str || str == "" || sscanf(str, "%s@%s", a, b) != 2) {
        message("logon", "\nEmail must be in the "+
                "user@host form.\nEmail: ",
                this_object());
        input_to("enter_email");
        return;
    }
    __Player->set_email(str);
    __Player->set_rname("Unknown");
    seteuid(UID_LOG);
    log_file("enter", sprintf("%s (new player): %s\n", __Name, ctime(time())));
    log_file("watch/new_players",sprintf("%s(%s) <%s> at %s from %s\n",__Name, str, __Player->query_email(),ctime(time()),query_ip_number()));
    seteuid(getuid());
    exec_user();
}

static void idle() {
    message("logon", "\nLogin timed out.\n", this_object());
    internal_remove();
}

static void receive_message(string cl, string msg)
{
    mapping TermInfo;
    if (cl != "logon") return;
    if(!stringp(msg)) return;
    TermInfo = "/daemon/user_d.c"->myTerm(TO, 1);
    msg = terminal_colour(msg, TermInfo, 140, 0);
    receive(msg);
}

static private void internal_remove() {
    if (__Player) destruct(__Player);
    destruct(this_object());
}

void remove() {
    if (geteuid(previous_object()) != UID_ROOT) return;
    internal_remove();
}
