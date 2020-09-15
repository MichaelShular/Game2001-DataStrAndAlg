#include <iostream>

//Check 2 things return the smallest
template <class T>
T min_func(T Val1, T Val2) {
	if (Val1 < Val2) {
		return Val1;
	}
	else
		return Val2;
}
// Check 2 things and return the Largest 
template <class T>
	T max_func(T Val1, T Val2) {
		if (Val1 > Val2) {
			return Val1;
		}
		else
			return Val2;
	}
//
template<class T>
class TemplateClass
{
public:
	TemplateClass(T val)
	{
		m_val = val;
	}
	bool operator<(TemplateClass& Val2)
	{
		return m_val < Val2.GetVal();
	}
	bool operator>(TemplateClass& Val2)
	{
		return m_val > Val2.GetVal();
	}
	T GetVal()
	{
		return m_val;
	}
private:
	T m_val;

};
int main()
{
	std::cout << "Example\n";
	std::cout << min_func(23, 26) << std::endl;
	std::cout << max_func(23, 26) << std::endl;
	std::cout << "Max " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();
	return 0;
};