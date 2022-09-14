// integers are signed by default
short s;
int i;
long l;
long long ll;

// can optionally add int suffix but is unessessary
short int si;
long int li;
long long int lli;

// can optionally add signed prefix, again not needed
signed short ss;
signed int si;
signed long sl;
signed long long sll;

// signed ints hold values from -(2^n-1) to 2^(n-1) - 1
// where n is the number of bits

// storing a value too large for the value type causes overflow

// integer division returns the quotiant
int x = 20 / 5; // x = 4
int y = 8 / 5; // y = 1
