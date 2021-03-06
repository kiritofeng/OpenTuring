#include "include/cinterface"
typedef	TLnat4	TL_TL_priority_t;
struct	TL_TL_ExceptionInfo {
    TLint4	quitCode;
    TLint4	libraryQuitCode;
    TLstring	errorMsg;
};
typedef	TLnat1	__x345[1];
struct	TL_TL_HandlerArea {
    TLint4	quitCode;
    TLnat4	lineAndFile;
    TLaddressint	fileTable;
    struct TL_TL_HandlerArea	*nextHandler;
    __x345	savedState;
};
typedef	TLnat4	TL_TL_hardwarePriority_t;
typedef	TL_TL_hardwarePriority_t	TL_TL_lockStatus_t;
typedef	TLnat4	TL_TL_lock_t;
struct	TL_TL_link_t {
    struct TL_TL_ProcessDescriptor	*flink;
    struct TL_TL_ProcessDescriptor	*blink;
};
struct	TL_TL_ProcessDescriptor {
    TLnat4	lineAndFile;
    TLaddressint	fileTable;
    TLaddressint	stackLimit;
    TLaddressint	stackPointer;
    struct TL_TL_HandlerArea	*handlerQhead;
    struct TL_TL_HandlerArea	*currentHandler;
    TLaddressint	name;
    struct TL_TL_ExceptionInfo	exception;
    TLnat4	waitParameter;
    struct TL_TL_ProcessDescriptor	*monitorQlink;
    TLnat4	timeOutStatus;
    TLnat4	pid;
    TLaddressint	memoryBase;
    TLnat4	timeoutTime;
    TLnat4	timeoutEpoch;
    struct TL_TL_link_t	timeoutQ;
    TLboolean	timedOut;
    TLboolean	pausing;
    TL_TL_priority_t	dispatchPriority;
    struct TL_TL_ProcessDescriptor	*runQlink;
    TLboolean	ready;
    struct TL_TL_ProcessDescriptor	*tsyncWaiter;
    TLnat4	quantum;
    TLnat4	quantumCntr;
    TLnat4	devmonLevel;
    TLaddressint	otherInfo;
};

extern void TL_TLM_TLMUDUMP ();

extern void TL_TLB_TLBMAL ();

extern void TL_TLB_TLBMFR ();

extern void TL_TLB_TLBNWU ();

extern void TL_TLB_TLBFRU ();

extern void TL_TLI_TLIFS ();

extern void TL_TLI_TLIAON ();

extern void TL_TLI_TLIAOFF ();

extern void TL_TLI_TLIUDUMP ();

extern void TL_TLI_TLIFINI ();

extern void TL_TLE_TLELF ();
typedef	TLint4	TL_Cint;
extern TLboolean	TL_TLECU;
extern struct TL_TL_ProcessDescriptor	*TL_TLKPD;

void TL_TLQUIT ();

extern void TL_TLK_TLKINI ();

extern void TL_TLK_TLKFINI ();

extern void TL_TLK_TLKUXRS ();

extern void TL_TLK_TLKUXRE ();

extern void TL_TLK_TLKUEXIT ();

extern void TL_TLK_TLKUDMPP ();

extern void TL_TLK_TLKPFORK ();

extern TLboolean TL_TLK_TLKFRKED ();

extern void TL_TLK_TLKLKON ();

extern void TL_TLK_TLKLKOFF ();

extern void TL_TLK_TLKSSYNC ();

extern void TL_TLK_TLKSWAKE ();

extern void TL_TLK_TLKSTIMO ();

extern void TL_TLK_TLKCINI ();

extern TLnat4 TL_TLK_TLKPGETP ();

extern void TL_TLK_TLKPSETP ();

extern void TL_TLK_TLKIPINI ();

extern void TL_TLK_TLKIPENT ();

extern void TL_TLK_TLKIPEXT ();

extern TLboolean TL_TLK_TLKDMINI ();

extern void TL_TLK_TLKDMENT ();

extern void TL_TLK_TLKDMEXT ();

extern void TL_TLK_TLKPPAUS ();

extern void TL_TLX_TLXPID ();

extern void TL_TLX_TLXTIM ();

extern void TL_TLX_TLXATF ();

extern void TL_TLX_TLXDT ();

extern void TL_TLX_TLXTM ();

extern void TL_TLX_TLXCL ();

extern void TL_TLX_TLXSC ();

extern void TL_TLX_TLXGE ();

extern void TL_TLX_TLXSYS ();
typedef	TLint4	TL_TLB_Timestamp;
struct	TL_TLB_CheckedPointer {
    TLaddressint	objAddress;
    TL_TLB_Timestamp	timestamp;
};
typedef	TLint4	TL_TLB_CountTypeBits;
typedef	TLint4	TL_TLB_OpcodeBits;
typedef	TLint4	TL_TLB_CountByteBits;
typedef	TLint2	TL_TLB_OpcodeType;
extern TL_TLB_Timestamp	TL_TLB_TLBTS;

extern void TL_TLB_TLBMAL ();

extern void TL_TLB_TLBMFR ();

extern void TL_TLB_TLBFRU ();
void TL_TLB_TLBNWC (ptr, objSize)
register struct TL_TLB_CheckedPointer	*ptr;
TLnat4	objSize;
{
    TLaddressint	memAddr;
    TLBINDREG((*objTimestamp), TL_TLB_Timestamp);
    TL_TLB_TLBMAL((TLnat4) (objSize + sizeof(TL_TLB_Timestamp)), &(memAddr));
    objTimestamp = memAddr;
    if ((unsigned long) memAddr != 0) {
	register TLaddressint	p;
	(*ptr).objAddress = (TLaddressint) ((unsigned long) ((unsigned long)&((*objTimestamp))) + sizeof(TL_TLB_Timestamp));
	(*objTimestamp) = TL_TLB_TLBTS;
	(*ptr).timestamp = TL_TLB_TLBTS;
	if (TL_TLB_TLBTS != -1000000000) {
	    TL_TLB_TLBTS += 1;
	} else {
	    TL_TLB_TLBTS = -2000000000;
	};
	p = (TLaddressint) ((*ptr).objAddress);
	{
	    register TLint4	__x344;
	    TLint4	__x349;
	    __x349 = objSize >> 2;
	    __x344 = 1;
	    if (__x344 <= __x349) {
		for(;;) {
		    (* (TLnat4 *) p) = 0x80000000;
		    p += 4;
		    if (__x344 == __x349) break;
		    __x344++;
		}
	    };
	};
    } else {
	(*ptr).objAddress = (TLaddressint) 0;
    };
}
