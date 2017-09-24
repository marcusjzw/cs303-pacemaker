#ifndef SCCHARTS_H_
#define SCCHARTS_H_

// Functions
void tick();
void reset();

// Timeout input
extern char URI_TO;
extern char AVI_TO;
extern char PVARP_TO;
extern char VRP_TO;
extern char AEI_TO;
extern char LRI_TO;

// Inputs
extern char VSense;
extern char ASense;

// Outputs
extern char APace;
extern char VPace;

// Reset timer expiry signals
extern char URI_ex;
extern char AVI_ex;
extern char PVARP_ex;
extern char VRP_ex;
extern char AEI_ex;
extern char LRI_ex;

// Start timers
extern char URI_start;
extern char AVI_start;
extern char PVARP_start;
extern char VRP_start;
extern char AEI_start;
extern char LRI_start;

#endif /*SCCHARTS_H_ */
