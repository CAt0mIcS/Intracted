
int main()
{
	using namespace Intracted;

	Scope<int> val = MakeScope<int>(3);
	std::cout << *val << '\n';
}