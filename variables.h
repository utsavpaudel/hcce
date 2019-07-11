#ifndef VARIABLES_H
#define VARIABLES_H
extern double ha;                         //ha=house area
extern int ft,cd;                         // ft=foundation type || dc=dimension of columns
extern double fd,fa;                      //depth of foundation || area of foundation
extern int sn,bt;                            //sn=no. of stories ||brick type
extern double dlo,dli;                    //lod=length of outer dpc || lid=length of inner dpc
extern double costdpc;
extern double ctcp,bkcp,rdcp,sncp,stcp;   //cost price of: cement per unit vol.,brick per piece,rod per kg,sand per unit volume,stone per unit kg
extern double wh_1,wh_2,wh_3,wwo_1,wwo_2,wwo_3,wwi_1,wwi_2,wwi_3;                 //wall height ,wall width outer & inner
extern int dno_1,dno_2,dno_3,dni_1,dni_2,dni_3,wno_1,wno_2,wno_3,wni_1,wni_2,wni_3;               //door no. outer & inner, windows number outer & inner
extern double who_1,whi_1,wnwo_1,wnwi_1,who_2,whi_2,wnwo_2,wnwi_2,who_3,whi_3,wnwo_3,wnwi_3;          // windows height & width inner &outer
extern double dho_1,dhi_1,dwo_1,dwi_1,dho_2,dhi_2,dwo_2,dwi_2,dho_3,dhi_3,dwo_3,dwi_3;            // doors height & width inner &out
extern double st_1,sa_1,st_2,sa_2,st_3,sa_3;                      //slab thickness & area
extern double ws_1,ws_2,ws_3;                         //width of inner staircase
extern int wti_1,wto_1,bd_1,wti_2,wto_2,bd_2,wti_3,wto_3,bd_3;                     //window type inner/outer beam dimension
//database variables
extern double b1p,b2p,opc,ppc,snd,grav,rods,stn;
extern double marble,tile,granite,alum,wood,upvc;
extern double brick_vol,cem_vol,sand_vol,grav_vol,rod_dens,stn_dens,bvcs;
extern int sf,tf;
#endif // VARIABLES_H
