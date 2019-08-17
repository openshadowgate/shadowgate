//    /adm/simul_efun/distinct_array.c
//    from Nightmare IV
//    a faster, better namedfunction based on Huthar's uniq_array()
//    by Descartes of Borg 940117
/**
 * @file
 */

/**
 * Turns array into a set: array with unique atoms only.
 */
mixed *distinct_array(mixed *arr) {
    mapping tmp;
    int i, maxi;

    for(i = 0, tmp = allocate_mapping(maxi = sizeof(arr)); i<maxi; i++)
      tmp[arr[i]] = 1;
    return keys(tmp);
}
