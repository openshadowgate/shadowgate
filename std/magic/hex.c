#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit DAEMON;

object caster;
object target;
object place;

string hex_desc,
    hex_syntax,
    hex_effect,
    hex_name;
string save_type;
string arg;

int clevel;
int arg_needed;
int non_living_ok;

void set_hex_save(string val)
{
    hex_save = val;
}

string query_hex_save()
{
    return hex_save;
}

void set_hex_syntax(string val)
{
    hex_syntax = val;
}

string query_hex_syntax()
{
    return hex_syntax;
}

void set_hex_effet(string  val)
{
    hex_effet = val;
}

string query_hex_effet()
{
    return hex_effet;
}

int set_save(string str)
{
    save_type = str;
}

void set_hex_name(string str)
{
    hex_name = str;
}

string query_hex_name()
{
    return hex_name;
}

string query_save()
{
    return save_type;
}

void set_arg_needed(int val)
{
    arg_needed = val;
}

int query_arg_needed()
{
    return arg_needed;
}

void set_non_living_ok(int val)
{
    non_living_ok = val;
}

int query_non_living_ok()
{
    return non_living_ok;
}

void use_hex(object user, string targ, int cast_level)
{
    if (!objectp(user)) {
        return;
    }

    clevel = cast_level;
    caster = user;
    place = ENV(user);

    if (targ) {
        if (!arg_needed) {
            if ((targ == "me") || (targ == "self") || (targ == "myself")) {
                target = caster;
            }else{
                if ((targ == "here") || (targ == "room")) {
                    target = environment(caster);
                }
            }
            if (targ == "random" || targ == "rand") {
                object* attackers = caster->query_attackers();
                if (sizeof(attackers)) {
                    target = attackers[random(sizeof(attackers))];
                }
            }
            if (!target && (objectp(targ) || stringp(targ))) {
                target = present(targ, environment(caster));
            }
            if (!target) {
                tell_object(caster, "That is not here!");
                TO->remove();
                return;
            }
            if ((!living(target)) && (!non_living_ok)) {
                tell_object(caster, "That is not a living being!");
                TO->remove();
                return;
            }
        }else {
            arg = targ;
        }
    }

    TO->hex_effect();
}

int do_save(object targ, int mod)
{

    string type;
    int caster_bonus, num;

    if (!objectp(caster)) {
        return 1;
    }
    if (!objectp(targ)) {
        return notify_fail("invalid target object.");
    }
    if (!intp(mod)) {
        mod = 0;
    }

    if (!intp(mod)) {
        mod = 0;
    }

    type = query_save();

    caster_bonus = 10;
    caster_bonus = SAVING_THROW_D->magic_save_throw_adjust(targ, caster);

    caster_bonus = -caster_bonus;

    caster_bonus += mod;

    switch (type) {
    case "fort":
        num = SAVING_THROW_D->fort_save(targ, caster_bonus);
        break;
    case "will":
        num = SAVING_THROW_D->will_save(targ, caster_bonus);
        break;
    case "reflex":
        num = SAVING_THROW_D->will_save(targ, caster_bonus);
        break;
    default:
        num = 0;
        break;
    }

    return num;
}

void help()
{

}
