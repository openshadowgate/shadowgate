#include <std.h>
#include <new_exp_table.h>

#define DELAY 12 * 60 * 60

int cmd_reward(string str)
{
    object target;

    if (TP->query("last_reward") + DELAY > time()) {
        tell_object(TP, "%^BOLD%^%^RED%^You can't use reward yet!");
        tell_object(TP, "%^BOLD%^%^RED%^Delay timer wil expire at:%^RESET%^ " + ctime(TP->query("last_reward") + DELAY) + "UTC");
        return 1;
    }

    if (!str) {
        object * peeps;

        peeps = all_inventory(ETP);
        peeps = filter_array(peeps, (: userp($1) && !avatarp($1) :));
        peeps = filter_array(peeps, (: !$1->query("no_reward") :));
        peeps = filter_array(peeps, (: !$1->query_hidden() :));
        peeps = filter_array(peeps, (: !$1->query_magic_hidden() :));

        if (!sizeof(peeps)) {
            tell_object(TP,"%^BOLD%^%^CYAN%^Nobody here to reward.");
            return 1;
        }

        tell_object(TP,"%^BOLD%^%^CYAN%^You have rewarded everyone in the room with some knowledge.");
        map(peeps, (: $2->reward_person($1) :), TO);

        tell_object(TP, "%^CYAN%^%^BOLD%^You have rewarded everyone here with some knowledge.");

        reward_self();

        return 1;
    }

    if (!objectp(target = present(str, ENV(TP)))) {
        tell_object(TP, "That is not here!");
        return 1;
    }

    if (!userp(target) ||
        avatarp(target)) {
        tell_object(TP, "That is not a player!");
        return 1;
    }

    if (TP == target) {
        tell_object(TP, "You cannot reward yourself.");
        return 1;
    }

    if (target->query("no_reward")) {
        tell_object(TP, "That player wishes no rewards!");
        return 1;
    }

    reward_person(target);
    tell_object(TP, "%^CYAN%^%^BOLD%^You have rewarded " + target->QCN + " with some knowledge.");
    reward_self();

    return 1;
}

void reward_self()
{

    int expdelta;
    int thelevel = TP->query_adjusted_character_level();

    expdelta = abs(EXP_NEEDED[thelevel + 1] - EXP_NEEDED[thelevel]) / 12;

    TP->set_property("ignore tax", 1);
    TP->add_general_exp(TP->query_classes()[0], expdelta);
    TP->remove_property("ignore tax");

    TP->delete("last_reward");
    TP->set("last_reward", time());

    tell_object(TP,"%^BOLD%^%^CYAN%^You feel enlightened performing such an honorable act.");

}

void reward_person(object target)
{
    int expdelta;
    int thelevel = target->query_adjusted_character_level();

    if (!objectp(target)) {
        return;
    }

    // garrett thinks adjusted is right for here, since this is a scaling award.

    expdelta = abs(EXP_NEEDED[thelevel + 1] - EXP_NEEDED[thelevel]) / 8;

    target->set_property("ignore tax", 1);
    target->add_general_exp(target->query_classes()[0], expdelta);
    target->remove_property("ignore tax");

    tell_object(target, "%^CYAN%^%^BOLD%^You feel enlightened as your powers grow.");

}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

reward - reward someone with exp

%^CYAN%^SYNOPSIS%^RESET%^

reward [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow you to reward anyone with 12.5% of exp towards their next level. In addition to that, rewardee will gain 10% of the exp towards your next level.

If you provide no argument to the command it will reward everyone in the room, except for invisibile people.

The reason for use of rewards is left to your discretion. The player won't know who rewarded them, but will see the message about the reward. They also must be present in the room with you. You can do it only once twelve hours.

Player may opt out from receiving rewards with noreward setting in %^ORANGE%^<set>%^RESET%^ command. If they did so, your attempt to reward them won't count.

%^CYAN%^SEE ALSO%^RESET%^

set, score, who, chfn
"
        );
}
