#include <iostream>
#include "src/intel_cpu.hpp"
#include "src/memory_unit.hpp"

int main(){
	Memory mem(256);
	try{
		mem.write<int>(0x0, 1<<16);
		int num = mem.read<int>(0x257);
		std::cout << num << std::endl;
	}catch(std::out_of_range e){
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
