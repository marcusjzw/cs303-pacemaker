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
char URI_TO;
char APace;
char URI_ex;
char URI_start;
char VSense;
char ASense;
char AVI_TO;
char PVARP_TO;
char VRP_TO;
char AEI_TO;
char LRI_TO;
char VPace;
char AVI_ex;
char PVARP_ex;
char VRP_ex;
char AEI_ex;
char LRI_ex;
char AVI_start;
char PVARP_start;
char VRP_start;
char AEI_start;
char LRI_start;
char _DDDPacemaker_local_VP_en;
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
char g8;
char g9;
char g10;
char g11;
char g12;
char g13;
char g14;
char g15;
char g16;
char g17;
char PRE_g17;
char g18;
char g19;
char g20;
char PRE_g20;
char g21;
char g22;
char g23;
char g24;
char g24b;
char g25;
char g26;
char g27;
char g28;
char PRE_g28;
char g29;
char g30;
char g31;
char g32;
char g32b;
char g33;
char g34;
char g34b;
char g35;
char g36;
char g37;
char PRE_g37;
char g38;
char g39;
char PRE_g39;
char g39b;
char g40;
char g40b;
char g40c;
char g40d;
char g40e;
char g40f;
char g40g;
char g41;
char PRE_g41;
char g42;
char g42b;
char g43;
char PRE_g43;
char g44;
char g45;
char g45b;
char g46;
char g47;
char g48;
char g49;
char g49b;
char g50;
char g51;
char g52;
char g53;
char g54;
char g55;
char g56;
char PRE_g56;
char g57;
char g58;
char g59;
char g60;
char g61;
char PRE_g61;
char g62;
char g63;
char g64;
char _GO;
char _cg7;
char _cg13;
char _cg4;
char _cg11;
char _cg8;
char _cg25;
char _cg26;
char _cg18;
char _cg21;
char _cg23;
char _cg33;
char _cg29;
char _cg31;
char _cg52;
char _cg38;
char _cg50;
char _cg42;
char _cg48;
char _cg44;
char _cg46;
char g15_e1;
char g35_e2;
char g54_e3;
char g58_e4;
char g59_e1;
char g63_e2;
int _PRE_GO;
void reset(){
   _GO = 1;
   _PRE_GO = 0;
   PRE_g3 = 0;
   PRE_g6 = 0;
   PRE_g17 = 0;
   PRE_g20 = 0;
   PRE_g28 = 0;
   PRE_g37 = 0;
   PRE_g39 = 0;
   PRE_g41 = 0;
   PRE_g43 = 0;
   PRE_g56 = 0;
   PRE_g61 = 0;
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
      g7 =(PRE_g6);
      _cg7 =(VSense||LRI_TO);
      g4 =(PRE_g3);
      _cg4 = AVI_TO;
      g13 =(g4&&(!(_cg4)));
      _cg13 = URI_TO;
      g55 = g1;
      g57 =(PRE_g56);
      g56 =(g55||g57);
      if(g56){
         _DDDPacemaker_local_VP_en = 0;
      }
      g60 = g0;
      g62 =(PRE_g61);
      g61 =(g60||g62);
      if(g61){
         VPace = 0;
         APace = 0;
         AVI_ex = 0;
         PVARP_ex = 0;
         VRP_ex = 0;
         AEI_ex = 0;
         LRI_ex = 0;
         URI_ex = 0;
         AVI_start = 0;
         PVARP_start = 0;
         VRP_start = 0;
         AEI_start = 0;
         LRI_start = 0;
         URI_start = 0;
      }
      g8 =(g7&&(!(_cg7)));
      _cg8 = AVI_TO;
      g11 =(g8&&(!(_cg8)));
      _cg11 = URI_TO;
      g12 =(g11&&_cg11);
      if(g12){
         URI_ex =(URI_ex||1);
      }
      g9 =(g8&&_cg8);
      if(g9){
         AVI_ex =(AVI_ex||1);
      }
      g10 =(g12||g9);
      if(g10){
         _DDDPacemaker_local_VP_en =(_DDDPacemaker_local_VP_en||1);
      }
      g3 =(g2||(g7&&_cg7)||(g13&&(!(_cg13)))||g10);
      g5 =(g4&&_cg4);
      if(g5){
         AVI_ex =(AVI_ex||1);
      }
      g14 =(g13&&_cg13);
      if(g14){
         URI_ex =(URI_ex||1);
      }
      g6 =((g11&&(!(_cg11)))||g14||g5);
      g16 = g1;
      g21 =(PRE_g20);
      _cg21 = VRP_TO;
      g23 =(g21&&(!(_cg21)));
      _cg23 = AEI_TO;
      g25 =(g23&&(!(_cg23)));
      _cg25 = ASense;
      g29 =(PRE_g28);
      _cg29 = PVARP_TO;
      g31 =(g29&&(!(_cg29)));
      _cg31 = VSense;
      g33 =(g31&&(!(_cg31)));
      _cg33 = AEI_TO;
      g34 =(g33&&_cg33);
      if(g34){
         APace =(APace||1);
      }
      g34b = g34;
      if(g34b){
         VRP_ex =(VRP_ex||1);
      }
      g22 =(g21&&_cg21);
      if(g22){
         VRP_ex =(VRP_ex||1);
      }
      g32 =(g31&&_cg31);
      if(g32){
         PVARP_start =(PVARP_start||1);
      }
      g32b = g32;
      if(g32b){
         VRP_start =(VRP_start||1);
      }
      g18 =(PRE_g17);
      _cg18 = PVARP_TO;
      g26 =(g18&&(!(_cg18)));
      _cg26 = VRP_TO;
      g30 =(g29&&_cg29);
      if(g30){
         PVARP_ex =(PVARP_ex||1);
      }
      g24 =(g23&&_cg23);
      if(g24){
         APace =(APace||1);
      }
      g24b = g24;
      if(g24b){
         VRP_ex =(VRP_ex||1);
      }
      g17 =(g16||(g25&&_cg25)||g34b||g22||g32b||(g26&&(!(_cg26)))||g30||g24b);
      g19 =(g18&&_cg18);
      if(g19){
         PVARP_ex =(PVARP_ex||1);
      }
      g20 =((g25&&(!(_cg25)))||g19);
      g27 =(g26&&_cg26);
      if(g27){
         VRP_ex =(VRP_ex||1);
      }
      g28 =((g33&&(!(_cg33)))||g27);
      g36 = g1;
      g44 =(PRE_g43);
      _cg44 = ASense;
      g46 =(g44&&(!(_cg44)));
      _cg46 = AEI_TO;
      g47 =(g46&&_cg46);
      if(g47){
         APace =(APace||1);
      }
      g42 =(PRE_g41);
      g42b = g42;
      _cg42 =(VRP_ex||PVARP_ex);
      g50 =(g42b&&(!(_cg42)));
      _cg50 = ASense;
      g51 =(g50&&_cg50);
      if(g51){
         VRP_ex =(VRP_ex||1);
      }
      g45 =(g47||(g44&&_cg44)||g51);
      if(g45){
         AVI_start =(AVI_start||1);
      }
      g45b = g45;
      if(g45b){
         AEI_ex =(AEI_ex||1);
      }
      g38 =(PRE_g37);
      _cg38 = VSense;
      g52 =(g38&&(!(_cg38)));
      _cg52 =(_DDDPacemaker_local_VP_en||LRI_TO);
      g37 =(g36||g45b||(g52&&(!(_cg52))));
      g53 =(g52&&_cg52);
      if(g53){
         VPace =(VPace||1);
      }
      g39 =((g38&&_cg38)||g53);
      if(g39){
         LRI_ex =(LRI_ex||1);
      }
      g39b = g39;
      if(g39b){
         URI_ex =(URI_ex||1);
      }
      g40 =(PRE_g39);
      g40b = g40;
      if(g40b){
         AVI_ex =(AVI_ex||1);
      }
      g40c = g40;
      if(g40c){
         PVARP_start =(PVARP_start||1);
      }
      g40d = g40;
      if(g40d){
         VRP_start =(VRP_start||1);
      }
      g40e = g40;
      if(g40e){
         AEI_start =(AEI_start||1);
      }
      g40f = g40;
      if(g40f){
         LRI_start =(LRI_start||1);
      }
      g40g = g40;
      if(g40g){
         URI_start =(URI_start||1);
      }
      g48 =(g46&&(!(_cg46)));
      _cg48 = VSense;
      g49 =(g48&&_cg48);
      if(g49){
         PVARP_start =(PVARP_start||1);
      }
      g49b = g49;
      if(g49b){
         VRP_start =(VRP_start||1);
      }
      g41 =((g50&&(!(_cg50)))||g40g||g49b);
      g43 =((g42b&&_cg42)||(g48&&(!(_cg48))));
      g15_e1 =(!((g4||g7)));
      g35_e2 =(!((g18||g21||g29)));
      g54_e3 =(!((g38||g40||g42||g44)));
      g58_e4 =(!(g57));
      g59_e1 =(!((g4||g18||g38||g57||g7||g21||g29||g40||g42||g44)));
      g63_e2 =(!(g62));
   }
   PRE_g3 = g3;
   PRE_g6 = g6;
   PRE_g17 = g17;
   PRE_g20 = g20;
   PRE_g28 = g28;
   PRE_g37 = g37;
   PRE_g39 = g39;
   PRE_g41 = g41;
   PRE_g43 = g43;
   PRE_g56 = g56;
   PRE_g61 = g61;
   _PRE_GO = _GO;
   return;
}
