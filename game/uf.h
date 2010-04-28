/*
 *  uf.h
 *  game
 *
 *  Created by DarkNik on 27/04/2010.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <string.h>


char* replaceChar(char* text){
	int i,x=20;
	for(i=0;i<x;i++){
		if(text[i]=='_')
			text[i]=' ';
	}
	return text;
}