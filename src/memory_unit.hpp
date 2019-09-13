#include <memory> /* memory in memory, oh my */
#include <stdexcept>
#ifndef __MEMORY_UNIT_HPP__
#define __MEMORY_UNIT_HPP__

template<typename T = int>
class Memory{
	private:
		std::unique_ptr<T[]> *space;
		unsigned long long max_addr;
	public:
		Memory(unsigned long long size){
			this->max_addr = size;
			this->space = std::make_unique<T[]>(size);
		}
		
		~Memory(){
		}
		
		template<typename U = T>
		U read(unsigned int address, unsigned int numberOfBytes = sizeof(U)){
			if( (address > this->max_addr) || (address+numberOfBytes > this->max_addr) ){
				throw std::out_of_range("Invalid address");
			}
			U valueToReturn;
								
			std::memcpy((void*)valueToReturn, (void*)(this->space[address]), numberOfBytes);
			
		}
		
		template<typename U = T>
		void write(U value, T &destination){
			
		}
};

#endif //__MEMORY_UNIT_HPP__