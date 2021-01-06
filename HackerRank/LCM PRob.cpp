#include <iostream>


long int getLCM(long int a, long int b) {
	long int lcm{ 1 }, larger, smaller;
	
	if (a > b)
	{
		larger = a;
		smaller = b;
	}
	else
	{
		larger = b;
		smaller = a;
	}

	lcm = larger;
	while (lcm % smaller != 0) { lcm += larger; }
	return lcm;
}


int main(){
	int t{ 0 };
	long int l{ 0 }, r{ 0 }, x{ 0 }, y{ 0 };

	std::cin >> t;

	while (t--) 
	{
		std::cin >> l >> r;
		x = l;
		y = l+1;

		while ((x<r-1) && (getLCM(x,y) > r))
		{
			y = x + 1;
			while ((y <= r) && (getLCM(x, y) > r) )
			{
				y++;
			}
			if (getLCM(x, y) > r)
				x++;
		}

		if (getLCM(x, y) > r) { std::cout << -1 << " " << -1 << "\n"; }
		else
			std::cout << x << " " << y << "\n";
	}
}