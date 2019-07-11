//	/adm/simul_efun/percent.c
//	from the Nightmare mudlib
//	returns the percent one value is of another
//	created by Descartes of Borg 15 april 1993

float percent(mixed numerator, mixed denominator) 
{
    float a, b;

    if(!floatp(numerator) && !intp(numerator)) return 0.0;
    else a = (floatp(numerator) ? numerator : to_float(numerator));
    if(!floatp(denominator) && !intp(denominator)) return 0.0;
    else b = (floatp(denominator) ? denominator : to_float(denominator));
    return ((a/b)*100);
}

int sum_array(int *arr, int ele)
{
    int sum = 0, i;
    if(!intp(ele)) return sum;
    for(i = 0;i < ele;i++)
    {
        if(i > (sizeof(arr)-1)) continue;
        if(!intp(arr[i])) continue;
        sum += arr[i];
        continue;        
    }
    return sum;
}
