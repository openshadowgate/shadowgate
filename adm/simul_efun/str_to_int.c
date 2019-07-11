//	String digit converted to integer (ascii to integer)
//	Thorn@ShadowGate
//	3/1/95
//	simul_efuns
//	str_to_int.c

varargs int str_to_int(string num) {
	int x, y , temp, z;
	
	temp = 0;
	for(x=0; x<sizeof(num); x++) {
           y = num[x] - 48;
		if((y>9) || (y<0)) {
			return -1;
		}
		z = y * pow(to_float(10), to_float(x));
		temp = temp + z;
	}
	return to_int(temp);
}

