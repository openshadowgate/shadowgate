#ifndef __HELP_H
#define __HELP_H

varargs void help(string topic, string category, int menu);
static void help_menu(string category, string *topics, int ind);
static string *query_categories();
static string *query_topics(string category);
static void cmd_help(string topic, string category, int menu);
static int find_help(string topic, string category, int menu);
static void menu_return(string duh, string category);
void endmore(string category);

#endif /* __HELP_H */
