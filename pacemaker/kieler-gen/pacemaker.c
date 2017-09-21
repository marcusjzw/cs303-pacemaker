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
char VRP_TO;
char VPace;
char VSense;
char LRI_TO;
char _VVIPacemaker_local_LRI_ex;
char _VVIPacemaker_local_VRP_ex;
char _VVIPacemaker_local_LRI_start;
char _VVIPacemaker_local_LRI_stop;
char _VVIPacemaker_local_VRP_start;
char _VVIPacemaker_local_VRP_stop;
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
char g31;
char g32;
char g33;
char g34;
char PRE_g34;
char g35;
char g35b;
char g36;
char PRE_g36;
char g37;
char g38;
char g39;
char g40;
char g41;
char PRE_g41;
char g42;
char g43;
char g44;
char g45;
char g46;
char PRE_g46;
char g47;
char g48;
char g49;
char _GO;
char _cg4;
char _cg7;
char _cg13;
char _cg9;
char _cg20;
char _cg18;
char _cg21;
char _cg29;
char _cg31;
char _cg26;
char _cg30;
char _cg35;
char _cg37;
char g15_e1;
char g23_e2;
char g32_e3;
char g39_e4;
char g43_e5;
char g44_e1;
char g48_e2;
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
   PRE_g34 = 0;
   PRE_g36 = 0;
   PRE_g41 = 0;
   PRE_g46 = 0;
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
      g3 =((g4&&(!(_cg4)))||g2);
      g40 = g1;
      g42 =(PRE_g41);
      g41 =(g40||g42);
      if(g41){
         _VVIPacemaker_local_LRI_start = 0;
         _VVIPacemaker_local_LRI_stop = 0;
         _VVIPacemaker_local_LRI_ex = 0;
         _VVIPacemaker_local_VRP_start = 0;
         _VVIPacemaker_local_VRP_stop = 0;
         _VVIPacemaker_local_VRP_ex = 0;
      }
      g5 =(g4&&_cg4);
      if(g5){
         _VVIPacemaker_local_LRI_start =(_VVIPacemaker_local_LRI_start||1);
      }
      g12 =(PRE_g11);
      g12b = g12;
      if(g12b){
         _VVIPacemaker_local_LRI_start =(_VVIPacemaker_local_LRI_start||1);
      }
      g37 =(PRE_g36);
      _cg37 = VRP_TO;
      g38 =(g37&&_cg37);
      if(g38){
         _VVIPacemaker_local_VRP_ex =(_VVIPacemaker_local_VRP_ex||1);
      }
      g7 =(PRE_g6);
      g7b = g7;
      _cg7 = _VVIPacemaker_local_VRP_ex;
      g6 =(g12b||g5||(g7b&&(!(_cg7))));
      g9 =(PRE_g8);
      _cg9 = VSense;
      g10 =(g9&&_cg9);
      if(g10){
         _VVIPacemaker_local_LRI_stop =(_VVIPacemaker_local_LRI_stop||1);
      }
      g20 =(PRE_g19);
      g20b = g20;
      _cg20 = _VVIPacemaker_local_LRI_stop;
      g21 =(g20b&&(!(_cg20)));
      _cg21 = LRI_TO;
      g22 =(g21&&_cg21);
      if(g22){
         _VVIPacemaker_local_LRI_ex =(_VVIPacemaker_local_LRI_ex||1);
      }
      g13 =(g9&&(!(_cg9)));
      _cg13 = _VVIPacemaker_local_LRI_ex;
      g8 =((g7b&&_cg7)||(g13&&(!(_cg13))));
      g47 =(PRE_g46);
      g45 = g0;
      g46 =(g47||g45);
      if(g46){
         VPace = 0;
      }
      g14 =(g13&&_cg13);
      if(g14){
         VPace =(VPace||1);
      }
      g11 =(g14||g10);
      g16 = g1;
      g18 =(PRE_g17);
      g18b = g18;
      _cg18 = _VVIPacemaker_local_LRI_start;
      g17 =(g16||(g20b&&_cg20)||(g18b&&(!(_cg18)))||g22);
      g19 =((g18b&&_cg18)||(g21&&(!(_cg21))));
      g24 = g1;
      g29 =(PRE_g28);
      g29b = g29;
      _cg29 = _VVIPacemaker_local_VRP_ex;
      g26 =(PRE_g25);
      _cg26 = VSense;
      g31 =(g26&&(!(_cg26)));
      _cg31 = VPace;
      g25 =(g24||(g29b&&_cg29)||(g31&&(!(_cg31))));
      g27 =((g26&&_cg26)||(g31&&_cg31));
      if(g27){
         _VVIPacemaker_local_VRP_start =(_VVIPacemaker_local_VRP_start||1);
      }
      g30 =(g29b&&(!(_cg29)));
      _cg30 = VSense;
      g28 =((g30&&_cg30)||(g30&&_cg30)||g27);
      g33 = g1;
      g35 =(PRE_g34);
      g35b = g35;
      _cg35 = _VVIPacemaker_local_VRP_start;
      g34 =(g38||g33||(g35b&&(!(_cg35))));
      g36 =((g35b&&_cg35)||(g37&&(!(_cg37))));
      g15_e1 =(!((g4||g7||g9||g12)));
      g23_e2 =(!((g18||g20)));
      g32_e3 =(!((g26||g29)));
      g39_e4 =(!((g35||g37)));
      g43_e5 =(!(g42));
      g44_e1 =(!((g4||g18||g26||g35||g20||g37||g7||g29||g9||g42||g12)));
      g48_e2 =(!(g47));
   }
   PRE_g3 = g3;
   PRE_g6 = g6;
   PRE_g8 = g8;
   PRE_g11 = g11;
   PRE_g17 = g17;
   PRE_g19 = g19;
   PRE_g25 = g25;
   PRE_g28 = g28;
   PRE_g34 = g34;
   PRE_g36 = g36;
   PRE_g41 = g41;
   PRE_g46 = g46;
   _PRE_GO = _GO;
   return;
}
