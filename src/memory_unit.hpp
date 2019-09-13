#include <memory>
#include <stdexcept>
#include <cstring>

#ifndef __MEMORY_UNIT_HPP__
#define __MEMORY_UNIT_HPP__

class Memory{
	private:
		std::unique_ptr<unsigned char[]> space;
		unsigned long long max_addr;
	public:
		Memory(unsigned long long size){
			this->max_addr = size;
			this->space = std::make_unique<unsigned char[]>(size);
			
			for(unsigned int i = 0; i < size; i++){
				this->space[i] = 0;
			}
		}
		
		~Memory(){
		}
		
		template<typename U>
		U read(unsigned long long destination, unsigned int numberOfBytes = sizeof(U)){
			if( (destination > this->max_addr) || (destination+numberOfBytes > this->max_addr) ){
				throw std::out_of_range("Error: Invalid address when reading value from the memory.");
			}
			
			U valueToReturn = 0;
														
			std::memcpy(
				(void*)(&valueToReturn), 
				(void*)(&this->space[destination]), 
				(sizeof(valueToReturn) < numberOfBytes) ? sizeof(valueToReturn) : numberOfBytes
			);
			
			return valueToReturn;
		}
		
		template<typename U>
		void write(unsigned long long destination, U value){
			if( (destination > this->max_addr) || (destination+sizeof(value) > this->max_addr) ){
				throw std::out_of_range("Error: Invalid address when writing value to the memory.");
			}
			
			std::memcpy(
				(void*)(&this->space[destination]), 
				(void*)(&value), 
				sizeof(value)
			);
		}
};

#endif //__MEMORY_UNIT_HPP__