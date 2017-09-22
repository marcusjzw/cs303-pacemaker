#ifndef SCCHARTS_H_
#define SCCHARTS_H_

// Functions
void reset();
void tick();

// Inputs
extern char ASense;
extern char AEI_TO;
extern char VSense;
extern char LRI_TO;
extern char URI_TO;
extern char PVARP_TO;
extern char VRP_TO;
extern char AVI_TO;

// Outputs
extern char VPace;
extern char APace;
extern char _DDDPacemaker_local_LRI_ex;
extern char _DDDPacemaker_local_PVARP_ex;
extern char _DDDPacemaker_local_VRP_ex;
extern char _DDDPacemaker_local_AVI_ex;
extern char _DDDPacemaker_local_AEI_ex;
extern char _DDDPacemaker_local_LRI_start;
extern char _DDDPacemaker_local_LRI_stop;
extern char _DDDPacemaker_local_URI_start;
extern char _DDDPacemaker_local_URI_stop;
extern char _DDDPacemaker_local_PVARP_start;
extern char _DDDPacemaker_local_PVARP_stop;
extern char _DDDPacemaker_local_VRP_start;
extern char _DDDPacemaker_local_VRP_stop;
extern char _DDDPacemaker_local_AVI_start;
extern char _DDDPacemaker_local_AVI_stop;
extern char _DDDPacemaker_local_AEI_start;
extern char _DDDPacemaker_local_AEI_stop;

#endif /*SCCHARTS_H_ */
