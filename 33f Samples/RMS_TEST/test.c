#include <p18f4520.h>
#include "stdio.h"
#include "math.h"

int getsign(int data);



void main()
{
	signed char voltage_samples[41] = {-1,0,1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,0,
		-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0};

	signed char current_samples[41] = {-1,0,1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,0,
		-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0};

	float Vrms  = 0;
	float Irms  = 0;
	float Prms  = 0;
	float Phase = 0; 
	int delta_t = 9;  // 360degrees / 40samples per period
	
	int t1_v=0 , t1_i=0;
	int t2_v=0 , t2_i=0;
	int t3_v=0 , t3_i=0;

	int sign1;
	int sign2;

	int count = 1;
	int i = 0;

	
	
	for(i=0 ; i<71 ; i++)
	{
		sign1 = getsign(voltage_samples[i]);
		sign2 = getsign(voltage_samples[i+1]);
		
		if(sign1 != sign2)
		{
			if(count == 1)
			{
				t1_v = i;
				count = count + 1;
			}
			else if(count == 2)
			{
				t2_v = i;
				count = count + 1;

			}
			else if(count == 3)
			{
				t3_v = i;
			    count = count + 1;
			}

		}
			
	}

	count = 1;
	for(i=0 ; i<71 ; i++)
	{
		sign1 = getsign(current_samples[i]);
		sign2 = getsign(current_samples[i+1]);
		
		if(sign1 != sign2)
		{
			
			if(count == 1)
			{
				t1_i = i;
				count = count + 1;
			}
			else if(count == 2)
			{
				t2_i = i;
				count = count + 1;

			}
			else if(count == 3)
			{
				t3_i = i;
			    count = count + 1;
			}

		}
			
	}

	for(i=t1_v ; i<t3_v ;i++)
	{
		Vrms = Vrms + voltage_samples[i] * voltage_samples[i];
	}
	for(i=t1_i ; i<t3_i ;i++)
	{
		Irms = Irms + current_samples[i] * current_samples[i];
	}

	Vrms = sqrt(Vrms/(t3_v - t1_v));
	Irms = sqrt(Irms/(t3_i - t1_i));
	Phase = abs(t3_v-t3_i)*delta_t;

	Prms = (Vrms * Irms * cos(Phase));
	return;

}

int getsign(int data)
{
    if(data>0)      
        return 1;
    else            
        return 0;
}

/*
	for(i=0 ; i<71 ; i++)
	{
		VRms = VRms + abs(voltage_samples[i] * voltage_samples[i]);
	}

	VRms = VRms/70;
	VRms = 0;
	*/
