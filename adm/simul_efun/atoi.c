//	/adm/simul_efun/atoi.c
//	from the Nightmare mudlib
//	converts a string to an int
//	created by Descartes of Borg 16 april 1993

int atoi(string str) {
    int x;

    if(!str) return 0;
    if(!sscanf(str, "%d", x)) return 0;
    return x;
}
