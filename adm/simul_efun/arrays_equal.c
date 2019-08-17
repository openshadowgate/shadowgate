// created by Ares 04/26/2017
// checks if two arrays are exactly equal
// same size, every member is the same and
// in the same order

/**
 * @file
 */

/**
 * Checks if two awways are equal
 */
int arrays_equal(mixed *one, mixed *two)
{
    int i;
    if(!pointerp(one) || !pointerp(two)) { return 0; }
    if(sizeof(one) != sizeof(two)) { return 0; }
    for(i=0;sizeof(one),i<sizeof(one);i++)
    {
        if(one[i] != two[i]) { return 0; }
    }
    return 1;
}
