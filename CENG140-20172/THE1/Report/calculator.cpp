#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define maxRoom 8
#define maxWumpus 4

int main()
	{
		srand(time(NULL));
		freopen("log.txt","w",stdout);
		for(int r = 2; r<=maxRoom; r++)
			{
				for(int w = 1; w<=maxWumpus; w++)
					{
						float p = 1.0f;
						for(int n = 1; ; n++)
							{
								if(p*w/(r+2)<pow(10,-3))
									break;
								printf("For room = %d and wumpus = %d, chance of getting killed by a wumpus on turn %d is %f\n",r,w,n,p*w/(r+2));
								p*=1-(p*w/(r+2));
							}
					}
			}
	}
