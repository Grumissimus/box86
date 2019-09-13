#ifndef __CPU_HPP__
#define __CPU_HPP__

template <typename RegDataType, unsigned int RegAmount>
class CPU{
	protected:
		RegDataType generalRegisters[RegAmount+1] = {0};
		RegDataType flags = 0;
	public:
		virtual ~CPU() {}
		virtual void printRegisters(){}
};

#endif //__CPU_HPP__
