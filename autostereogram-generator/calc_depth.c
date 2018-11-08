/*
 * PROJ1-1: YOUR TASK A CODE HERE
 *
 * Feel free to define additional helper functions.
 */

#include "calc_depth.h"
#include "utils.h"
#include <math.h>
#include <limits.h>
#include <stdio.h>

/* Implements the normalized displacement function */
unsigned char normalized_displacement(int dx, int dy,
        int maximum_displacement) {

    double squared_displacement = dx * dx + dy * dy;
    double normalized_displacement = round(255 * sqrt(squared_displacement) / sqrt(2 * maximum_displacement * maximum_displacement));
    return (unsigned char) normalized_displacement;

}

void calc_depth(unsigned char *depth_map, unsigned char *left,
	unsigned char *right, int image_width, int image_height,
	int feature_width, int feature_height, int maximum_displacement) {
		
		int lefti[image_width][image_height],righti[image_width][image_height];// Trans to 2d array

		
		for (int i=0;i<image_width;i++){
			for (int j=0;j<image_height;j++){
				lefti[i][j]=*left;
				righti[i][j]=*right;
				left++;
				right++;
			}
		}

		
		for (int i=0;i<image_width;i++){//loop and set depth map
			for (int j=0;j<image_height;j++){
				
				if((i+feature_width>=image_width)|(i-feature_width<0)|(j+feature_height>=image_height)|(j-feature_height<0)){ // test valid center
					
					*depth_map = 0;
					depth_map++;
				
				}else{//if it is valid center 
					
					int minDf = INT_MAX;
					int mindx = INT_MAX;
					int mindy = INT_MAX;
					
					for(int dx = -maximum_displacement;dx<=maximum_displacement;dx++){//loop search area
						
						for(int dy = -maximum_displacement;dy<=maximum_displacement;dy++){
							
							int x = dx+x, y=dy+y;
							if((x+feature_width>=image_width)|(x-feature_width<0)|(y+feature_height>=image_height)|(y-feature_height<0)){//test valid center
								
							}else{
									int df = 0;
									for(int a=-feature_width;a<=feature_width;a++){
										for(int b=-feature_height;b<=feature_height;b++){
											int temp = lefti[x+a][y+b]-righti[x+a][y+b];
											temp *= temp;
											df += temp;
										}
									}
									
									if(df<minDf){
										minDf = df;
										mindx = x;
										mindy = y;
									}else if(df == minDf){
										if(normalized_displacement(x,y,maximum_displacement)<normalized_displacement(mindx,mindy,maximum_displacement)){
											mindx = x;
											mindy = y;
											minDf =df;
										}
									}
							
							}
						}
					}
					
					*depth_map= normalized_displacement(mindx,mindy,maximum_displacement);
					depth_map++;
				}
			}
		}
	}	