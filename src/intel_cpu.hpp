#include <iostream>
#include <stdexcept>
#include "cpu.hpp"

#ifndef __INTEL_CPU_HPP__
#define __INTEL_CPU_HPP__

namespace intel{
	
	enum class Register{
		EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI
	};

	enum class SegmentRegister{
		CS, DS, SS, ES, FS, GS
	};

	enum class Flags{
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

	enum class CPUType{
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

	template<typename RegDataType = unsigned int, unsigned int RegAmount = 8>
	class IntelCPU : public CPU <RegDataType, RegAmount>{
		private:
			CPUType type;
		public:
			IntelCPU() : type(CPUType::Intel8086) {
				if(RegAmount < 8){
					throw std::invalid_argument("A number of registers in Intel CPU cannot be lower than 8.");
				}
			}
			
			IntelCPU(CPUType t) : type(t) {
				if(RegAmount < 8){
					throw std::invalid_argument("A number of registers in Intel CPU cannot be lower than 8.");
				}
			}
			
			~IntelCPU(){}

			void printRegisters(){
				std::cout << "Register A: " << this->generalRegisters[(unsigned int)Register::EAX] << std::endl;
				std::cout << "Register B: " << this->generalRegisters[(unsigned int)Register::EBX] << std::endl;
				std::cout << "Register C: " << this->generalRegisters[(unsigned int)Register::ECX] << std::endl;
				std::cout << "Register D: " << this->generalRegisters[(unsigned int)Register::EDX] << std::endl;
				std::cout << "Stack Register: " << this->generalRegisters[(unsigned int)Register::ESP] << std::endl;
				std::cout << "Base Pointer: " << this->generalRegisters[(unsigned int)Register::EBP] << std::endl;
				std::cout << "Source Index: " << this->generalRegisters[(unsigned int)Register::ESI] << std::endl;
				std::cout << "Destination Index: " << this->generalRegisters[(unsigned int)Register::EDI] << std::endl;
				
				if(RegAmount > 8){
					for(unsigned int i = 9; i <= RegAmount; i++){
						std::cout << "General Register " << i << ": " << this->generalRegisters[i] << std::endl;
					}
				}
			}
			
			CPUType getType(){
				return this->type;
			}
	};
}

#endif //__INTEL_CPU_HPP__
