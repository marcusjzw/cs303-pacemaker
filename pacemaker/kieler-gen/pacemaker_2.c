/*****************************************************************************/
/*                 G E N E R A T E D       C    C O D E                      */
/*****************************************************************************/
/* KIELER - Kiel Integrated Environment for Layout Eclipse RichClient        */
/*                                                                           */
/* http://www.informatik.uni-kiel.de/rtsys/kieler/                           */
/* Copyright 2014 by                                                         */
/* + Kiel University                                                         */
/*   + Department of Computer Science                                        */
/*     + Real-Time and Embedded Systems Group                                */
/*                                                                           */
/* This code is provided under the terms of the Eclipse Public License (EPL).*/
/*****************************************************************************/
char ASense;
char AEI_TO;
char APace;
char VSense;
char LRI_TO;
char URI_TO;
char PVARP_TO;
char VRP_TO;
char AVI_TO;
char VPace;
char _DDDPacemaker_local_LRI_ex;
char _DDDPacemaker_local_URI_ex;
char _DDDPacemaker_local_PVARP_ex;
char _DDDPacemaker_local_VRP_ex;
char _DDDPacemaker_local_AVI_ex;
char _DDDPacemaker_local_AEI_ex;
char _DDDPacemaker_local_LRI_start;
char _DDDPacemaker_local_LRI_stop;
char _DDDPacemaker_local_URI_start;
char _DDDPacemaker_local_URI_stop;
char _DDDPacemaker_local_PVARP_start;
char _DDDPacemaker_local_PVARP_stop;
char _DDDPacemaker_local_VRP_start;
char _DDDPacemaker_local_VRP_stop;
char _DDDPacemaker_local_AVI_start;
char _DDDPacemaker_local_AVI_stop;
char _DDDPacemaker_local_AEI_start;
char _DDDPacemaker_local_AEI_stop;
char g0;
char g1;
char g2;
char g3;
char PRE_g3;
char g4;
char g5;
char g6;
char PRE_g6;
char g7;
char g7b;
char g8;
char PRE_g8;
char g9;
char g10;
char g11;
char PRE_g11;
char g12;
char g12b;
char g13;
char g14;
char g15;
char g16;
char g17;
char PRE_g17;
char g18;
char g18b;
char g19;
char PRE_g19;
char g20;
char g20b;
char g21;
char g22;
char g23;
char g24;
char g25;
char PRE_g25;
char g26;
char g27;
char g28;
char PRE_g28;
char g29;
char g29b;
char g30;
char PRE_g30;
char g31;
char g31b;
char g32;
char PRE_g32;
char g33;
char g33b;
char g34;
char g35;
char g36;
char PRE_g36;
char g37;
char g37b;
char g38;
char PRE_g38;
char g39;
char g40;
char g41;
char g42;
char g43;
char PRE_g43;
char g44;
char g45;
char g46;
char PRE_g46;
char g47;
char g47b;
char g48;
char g49;
char g50;
char g51;
char g52;
char PRE_g52;
char g53;
char g53b;
char g54;
char PRE_g54;
char g55;
char g56;
char g57;
char g58;
char g59;
char PRE_g59;
char g60;
char g61;
char g62;
char PRE_g62;
char g63;
char g63b;
char g64;
char g65;
char g66;
char g67;
char g68;
char PRE_g68;
char g69;
char g69b;
char g70;
char PRE_g70;
char g71;
char g72;
char g73;
char g74;
char g75;
char PRE_g75;
char g76;
char g77;
char g78;
char g79;
char g80;
char PRE_g80;
char g81;
char g82;
char g83;
char _GO;
char _cg4;
char _cg7;
char _cg13;
char _cg9;
char _cg20;
char _cg18;
char _cg21;
char _cg26;
char _cg29;
char _cg31;
char _cg37;
char _cg39;
char _cg47;
char _cg49;
char _cg44;
char _cg48;
char _cg53;
char _cg55;
char _cg63;
char _cg65;
char _cg60;
char _cg64;
char _cg69;
char _cg71;
char g15_e1;
char g23_e2;
char g34_e3;
char g41_e4;
char g50_e5;
char g57_e6;
char g66_e7;
char g73_e8;
char g77_e9;
char g78_fix0;
char g78_fix1;
char g78_e1_fix;
char g78_e1;
char g82_e2;
int _PRE_GO;
void reset(){
   _GO = 1;
   _PRE_GO = 0;
   PRE_g3 = 0;
   PRE_g6 = 0;
   PRE_g8 = 0;
   PRE_g11 = 0;
   PRE_g17 = 0;
   PRE_g19 = 0;
   PRE_g25 = 0;
   PRE_g28 = 0;
   PRE_g30 = 0;
   PRE_g32 = 0;
   PRE_g36 = 0;
   PRE_g38 = 0;
   PRE_g43 = 0;
   PRE_g46 = 0;
   PRE_g52 = 0;
   PRE_g54 = 0;
   PRE_g59 = 0;
   PRE_g62 = 0;
   PRE_g68 = 0;
   PRE_g70 = 0;
   PRE_g75 = 0;
   PRE_g80 = 0;
   return;
}
void tick(){
   if(_PRE_GO == 1){
      _GO = 0;
   }
   {
      g0 = _GO;
      g1 = g0;
      g2 = g1;
      g4 =(PRE_g3);
      _cg4 = VSense;
      g3 =(g2||(g4&&(!(_cg4))));
      g74 = g1;
      g76 =(PRE_g75);
      g75 =(g74||g76);
      if(g75){
         _DDDPacemaker_local_LRI_start = 0;
         _DDDPacemaker_local_LRI_stop = 0;
         _DDDPacemaker_local_LRI_ex = 0;
         _DDDPacemaker_local_URI_start = 0;
         _DDDPacemaker_local_URI_stop = 0;
         _DDDPacemaker_local_URI_ex = 0;
         _DDDPacemaker_local_PVARP_start = 0;
         _DDDPacemaker_local_PVARP_stop = 0;
         _DDDPacemaker_local_PVARP_ex = 0;
         _DDDPacemaker_local_VRP_start = 0;
         _DDDPacemaker_local_VRP_stop = 0;
         _DDDPacemaker_local_VRP_ex = 0;
         _DDDPacemaker_local_AVI_start = 0;
         _DDDPacemaker_local_AVI_stop = 0;
         _DDDPacemaker_local_AVI_ex = 0;
         _DDDPacemaker_local_AEI_start = 0;
         _DDDPacemaker_local_AEI_stop = 0;
         _DDDPacemaker_local_AEI_ex = 0;
      }
      g5 =(g4&&_cg4);
      if(g5){
         _DDDPacemaker_local_LRI_start =(_DDDPacemaker_local_LRI_start||1);
      }
      g12 =(PRE_g11);
      g12b = g12;
      if(g12b){
         _DDDPacemaker_local_LRI_start =(_DDDPacemaker_local_LRI_start||1);
      }
      g55 =(PRE_g54);
      _cg55 = VRP_TO;
      g56 =(g55&&_cg55);
      if(g56){
         _DDDPacemaker_local_VRP_ex =(_DDDPacemaker_local_VRP_ex||1);
      }
      g7 =(PRE_g6);
      g7b = g7;
      _cg7 = _DDDPacemaker_local_VRP_ex;
      g6 =(g12b||(g7b&&(!(_cg7)))||g5);
      g9 =(PRE_g8);
      _cg9 = VSense;
      g10 =(g9&&_cg9);
      if(g10){
         _DDDPacemaker_local_LRI_stop =(_DDDPacemaker_local_LRI_stop||1);
      }
      g20 =(PRE_g19);
      g20b = g20;
      _cg20 = _DDDPacemaker_local_LRI_stop;
      g21 =(g20b&&(!(_cg20)));
      _cg21 = LRI_TO;
      g22 =(g21&&_cg21);
      if(g22){
         _DDDPacemaker_local_LRI_ex =(_DDDPacemaker_local_LRI_ex||1);
      }
      g13 =(g9&&(!(_cg9)));
      _cg13 = _DDDPacemaker_local_LRI_ex;
      g8 =((g13&&(!(_cg13)))||(g7b&&_cg7));
      g81 =(PRE_g80);
      g79 = g0;
      g80 =(g81||g79);
      if(g80){
         VPace = 0;
         APace = 0;
      }
      g14 =(g13&&_cg13);
      if(g14){
         VPace =(VPace||1);
      }
      g11 =(g10||g14);
      g16 = g1;
      g18 =(PRE_g17);
      g18b = g18;
      _cg18 = _DDDPacemaker_local_LRI_start;
      g17 =(g22||(g18b&&(!(_cg18)))||(g20b&&_cg20)||g16);
      g19 =((g21&&(!(_cg21)))||(g18b&&_cg18));
      g24 = g1;
      g26 =(PRE_g25);
      _cg26 = VSense;
      g25 =((g26&&(!(_cg26)))||g24);
      g27 =(g26&&_cg26);
      if(g27){
         _DDDPacemaker_local_URI_start =(_DDDPacemaker_local_URI_start||1);
      }
      g29 =(PRE_g28);
      g29b = g29;
      _cg29 = _DDDPacemaker_local_VRP_ex;
      g33 =(PRE_g32);
      g33b = g33;
      if(g33b){
         _DDDPacemaker_local_URI_start =(_DDDPacemaker_local_URI_start||1);
      }
      g28 =(g27||(g29b&&(!(_cg29)))||g33b);
      g39 =(PRE_g38);
      _cg39 = URI_TO;
      g40 =(g39&&_cg39);
      if(g40){
         _DDDPacemaker_local_URI_ex =(_DDDPacemaker_local_URI_ex||1);
      }
      g31 =(PRE_g30);
      g31b = g31;
      _cg31 = _DDDPacemaker_local_URI_ex;
      g30 =((g29b&&_cg29)||(g31b&&(!(_cg31))));
      g32 =(g31b&&_cg31);
      g35 = g1;
      g37 =(PRE_g36);
      g37b = g37;
      _cg37 = _DDDPacemaker_local_URI_start;
      g36 =(g35||g40||(g37b&&(!(_cg37))));
      g38 =((g39&&(!(_cg39)))||(g37b&&_cg37));
      g42 = g1;
      g44 =(PRE_g43);
      _cg44 = VSense;
      g49 =(g44&&(!(_cg44)));
      _cg49 = VPace;
      g47 =(PRE_g46);
      g47b = g47;
      _cg47 = _DDDPacemaker_local_VRP_ex;
      g43 =(g42||(g49&&(!(_cg49)))||(g47b&&_cg47));
      g45 =((g49&&_cg49)||(g44&&_cg44));
      if(g45){
         _DDDPacemaker_local_VRP_start =(_DDDPacemaker_local_VRP_start||1);
      }
      g48 =(g47b&&(!(_cg47)));
      _cg48 = VSense;
      g46 =((g48&&_cg48)||(g48&&_cg48)||g45);
      g51 = g1;
      g53 =(PRE_g52);
      g53b = g53;
      _cg53 = _DDDPacemaker_local_VRP_start;
      g52 =(g56||g51||(g53b&&(!(_cg53))));
      g54 =((g55&&(!(_cg55)))||(g53b&&_cg53));
      g58 = g1;
      g60 =(PRE_g59);
      _cg60 = ASense;
      g65 =(g60&&(!(_cg60)));
      _cg65 = APace;
      g71 =(PRE_g70);
      _cg71 = PVARP_TO;
      g72 =(g71&&_cg71);
      if(g72){
         _DDDPacemaker_local_PVARP_ex =(_DDDPacemaker_local_PVARP_ex||1);
      }
      g63 =(PRE_g62);
      g63b = g63;
      _cg63 = _DDDPacemaker_local_PVARP_ex;
      g59 =((g65&&(!(_cg65)))||g58||(g63b&&_cg63));
      g61 =((g60&&_cg60)||(g65&&_cg65));
      if(g61){
         _DDDPacemaker_local_PVARP_start =(_DDDPacemaker_local_PVARP_start||1);
      }
      g64 =(g63b&&(!(_cg63)));
      _cg64 = ASense;
      g62 =(g61||(g64&&_cg64)||(g64&&_cg64));
      g67 = g1;
      g69 =(PRE_g68);
      g69b = g69;
      _cg69 = _DDDPacemaker_local_PVARP_start;
      g68 =((g69b&&(!(_cg69)))||g67||g72);
      g70 =((g69b&&_cg69)||(g71&&(!(_cg71))));
      g15_e1 =(!((g4||g7||g9||g12)));
      g23_e2 =(!((g18||g20)));
      g34_e3 =(!((g26||g29||g31||g33)));
      g41_e4 =(!((g37||g39)));
      g50_e5 =(!((g44||g47)));
      g57_e6 =(!((g53||g55)));
      g66_e7 =(!((g60||g63)));
      g73_e8 =(!((g69||g71)));
      g77_e9 =(!(g76));
      g78_fix0 =((g15_e1||g15)&&(g23_e2||g23)&&(g34_e3||g34)&&(g41_e4||g41));
      g78_fix1 =(g15||g23||g34||g41);
      g78_e1_fix =(g20||g39||g55||g71||g7||g29||g47||g63||g9||g31||g33||g12);
      g78_e1 =(!((g4||g18||g26||g37||g44||g53||g60||g69||g76||g78_e1_fix)));
      g82_e2 =(!(g81));
   }
   PRE_g3 = g3;
   PRE_g6 = g6;
   PRE_g8 = g8;
   PRE_g11 = g11;
   PRE_g17 = g17;
   PRE_g19 = g19;
   PRE_g25 = g25;
   PRE_g28 = g28;
   PRE_g30 = g30;
   PRE_g32 = g32;
   PRE_g36 = g36;
   PRE_g38 = g38;
   PRE_g43 = g43;
   PRE_g46 = g46;
   PRE_g52 = g52;
   PRE_g54 = g54;
   PRE_g59 = g59;
   PRE_g62 = g62;
   PRE_g68 = g68;
   PRE_g70 = g70;
   PRE_g75 = g75;
   PRE_g80 = g80;
   _PRE_GO = _GO;
   return;
}
