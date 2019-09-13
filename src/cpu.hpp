#include <stack>
#include <iostream>
#include <type_traits>

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
	IntelCore2,
	IntelCorei7	
};

template <typename RegDataType, unsigned int RegAmount>
class CPU{
	protected:
		RegDataType generalRegisters[RegAmount+1] = {0};
		RegDataType flags = 0;
	public:
		virtual ~CPU() {};
		virtual void printRegisters(){};
};

template<typename RegDataType = unsigned int, unsigned int RegAmount = 8>
class IntelCPU : public CPU<RegDataType, RegAmount>{
	static_assert(RegAmount >= 8, "A number of registers in Intel CPU cannot be lower than 8.");
	private:
		IntelCPUType type;
	public:
		IntelCPU() : type(Intel8086) {};
		IntelCPU(IntelCPUType t) : type(t) {};
		~IntelCPU(){};

		void printRegisters(){
			std::cout << "Register A: " << this->generalRegisters[EAX] << std::endl;
			std::cout << "Register B: " << this->generalRegisters[EBX] << std::endl;
			std::cout << "Register C: " << this->generalRegisters[ECX] << std::endl;
			std::cout << "Register D: " << this->generalRegisters[EDX] << std::endl;
			std::cout << "Stack Register: " << this->generalRegisters[ESP] << std::endl;
			std::cout << "Base Pointer: " << this->generalRegisters[EBP] << std::endl;
			std::cout << "Source Index: " << this->generalRegisters[ESI] << std::endl;
			std::cout << "Destination Index: " << this->generalRegisters[EDI] << std::endl;
			
			if(RegAmount > 8){
				for(unsigned int i = 9; i <= RegAmount; i++){
					std::cout << "General Register " << i << ":" << this->generalRegisters[i] << std::endl;
				}
			}
			
		}
};

#endif //__CPU_HPP__
