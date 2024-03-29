#include <stdio.h>
#include "libs/player.h"

Player P_Data[3];
int NextUnit(UnitList *P){
	//I.S = UnitList tidak kosong
	//F.S = Select unit baru yang masih punya movement point atau AtkState==true.
	//			Mengembalikan 0 jika gagal, 1 jika berhasil
	ul_address Current = UL_Curr(*P);
	boolean found=false;
	UL_Curr(*P) = UL_Next(UL_Curr(*P));
	if(UL_Curr(*P)==Nil){
			UL_Curr(*P) = UL_First(*P);
	}
	while(UL_Curr(*P)!=Current&&found==false){
		if(UL_Curr(*P)==Nil){
			UL_Curr(*P) = UL_First(*P);
		}
		if(AtkState(UL_Info(UL_Curr(*P)))!=false ||Steps(UL_Info(UL_Curr(*P)))!=0 ){
			found=true;
		}else
		UL_Curr(*P) = UL_Next(UL_Curr(*P));
	}
	if(found==false){
				printf("There is  no more unit that you can select");
				return 0;
			}else{
				printf("You're now selecting ");
				PrintUnitType(UL_Info(UL_Curr(*P)));
				printf("on ");TulisPOINT(Loc(UL_Info(UL_Curr(*P))));
				printf("\n");
				return 1;
	}
}
