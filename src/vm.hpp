#ifndef __CPU_HPP__
#define __CPU_HPP__
enum Register{
	EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI
};

enum SegmentRegister{
	CS, DS, SS, ES, FS, GS
};

enum Flags{
	CF = 1,
	PF = 1 << 2,
	AF = 1 << 4,
	ZF = 1 << 6,
	SF = 1 << 7,
	TF = 1 << 8,
	IF = 1 << 9,
	DF = 1 << 10,
	OF = 1 << 11,
	IOPL = (1 << 12) | (1 << 13),
	NT = 1 << 14,
#ifndef __16_BIT_ONLY__
	RF = 1 << 16,
	VM = 1 << 17,
	AC = 1 << 18,
	VIF = 1 << 19,
	VIP = 1 << 20,
	ID = 1 << 21
#endif
};

enum IntelCPUType{
	Intel8086,
	Intel80186,
	Intel80286,
	Intel80386,
	Intel80486,
        IntelPentium,
	IntelPentiumMMX,
	IntelPentiumPro,
	IntelPentiumII,
	IntelPentiumIII,
	IntelPentium4,
	IntelCore,
	IntelCore2
	IntelCorei7	
};

template <typename RegDataType, unsigned int RegAmount>
class CPU{
	private:
		RegDataType registers[RegAmount];
};	
#endif //__CPU_HPP__
